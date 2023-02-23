namespace ft {

template<class Key, class T>
typename map<Key,T>::Node*
map<Key, T>::createNode(const value_type& pair) {
    Node* newNode = _allocNode.allocate(1);

    _allocPair.construct(&newNode->content, pair);
    newNode->parent = 0;
    newNode->left = 0;
    newNode->right = 0;
    return newNode;
}

template<class Key, class T>
void map<Key, T>::deallocateNode(Node* del) {
    _allocPair.destroy(&del->content);
    _allocNode.deallocate(del, 1);
}

template<class Key, class T>
int map<Key, T>::heightTree(Node *root, int height) {
    if (!root || root == _lastElem)
        return height - 1;
    int leftHeight = heightTree(root->left, height + 1);
    int rightHeight = heightTree(root->right, height + 1);
    return leftHeight > rightHeight ? leftHeight : rightHeight;
}

template<class Key, class T>
typename map<Key,T>::Node*
map<Key, T>::searchNode(Node* root, key_type key) const {
    if (!root || root == _lastElem)
        return 0;
    if (!_comp(root->content.first, key) && !_comp(key, root->content.first))
        return root;
    if (root->content.first > key && root->left && root->left != _lastElem)
        return searchNode(root->left, key);
    else if (root->content.first < key && root->right && root->right != _lastElem)
        return searchNode(root->right, key);
    return 0;
}

template<class Key, class T>
typename map<Key,T>::Node*
map<Key, T>::searchMaxNode(Node *root) const {
    if (root->right && root->right != _lastElem)
        return searchMaxNode(root->right);
    return root;
}

template<class Key, class T>
typename map<Key,T>::Node*
map<Key, T>::searchMinNode(Node *root) const {
    if (root->left && root->left != _lastElem)
        return searchMinNode(root->left);
    return root;
}

template<class Key, class T>
typename map<Key,T>::Node*
map<Key, T>::insertNode(Node* insertPos, const value_type& pair) {
    if (_root == _lastElem)
    {
        _root = createNode(pair);
        
        _root->left = _lastElem;
        _root->right = _lastElem;
        _lastElem->left = _root;
        _lastElem->right = _root;
        return _root;
    }
    if (insertPos->content.first == pair.first)
        return 0;

    if (insertPos->content.first > pair.first && 
            insertPos->left && insertPos->left != _lastElem)
        return insertNode(insertPos->left, pair);
    else if (insertPos->content.first < pair.first && 
            insertPos->right && insertPos->right != _lastElem)
        return insertNode(insertPos->right, pair);

    Node *newNode = createNode(pair);

    if (insertPos->content.first > newNode->content.first && !insertPos->left)
        insertPos->left = newNode;
    else if (insertPos->content.first < newNode->content.first && !insertPos->right)
        insertPos->right = newNode;
    else if (insertPos->left && insertPos->content.first > newNode->content.first)
    {
        newNode->left = _lastElem;
        _lastElem->right = newNode;
        insertPos->left = newNode;
    }
    else if (insertPos->right && insertPos->content.first < newNode->content.first)
    {
        newNode->right = _lastElem;
        _lastElem->left = newNode;
        insertPos->right = newNode;
    }
                    
    newNode->parent = insertPos;

    balanceTheTree(&_root, newNode);

    return newNode;
}

template<class Key, class T>
bool map<Key, T>::deleteNode(Node* deletePos, key_type key) {
    Node* balanceNode = 0;
                
    Node* del = searchNode(deletePos, key);

    if (!del)
        return false;
                
    if (!del->parent)
    {
        if (del->left == _lastElem && del->right == _lastElem)
        {
            _root = _lastElem;
            _lastElem->left = _lastElem;
            _lastElem->right = _lastElem;
        }
        else if (del->left && del->right == _lastElem)
        {
            balanceNode = del->parent;
            _root = del->left;
            del->left->parent = 0;
            _lastElem->left = del->left;
            del->left->right = _lastElem;
        }
        else if (del->left == _lastElem && del->right)
        {
            balanceNode = del->parent;
            _root = del->right;
            del->right->parent = 0;
            _lastElem->right = del->right;
            del->right->left = _lastElem;
        }
        else
        {
        Node* maxNode = searchMaxNode(del->left);

            _allocPair.destroy(&del->content);
            _allocPair.construct(&del->content, maxNode->content);
            
            return deleteNode(del->left, maxNode->content.first);
        }
    }
    else if ((!del->left || del->left == _lastElem) && (!del->right || del->right == _lastElem))
    {
        balanceNode = del->parent;
        Node* linkToParent = 0;
        if (del->left == _lastElem || del->right == _lastElem)
        {
            linkToParent = _lastElem;
            del->content.first <= del->parent->content.first ?
                _lastElem->right = del->parent : _lastElem->left = del->parent;
        }
        del->content.first <= del->parent->content.first ?
            del->parent->left = linkToParent : del->parent->right = linkToParent;
    }
    else if ((del->left && del->left != _lastElem) && (!del->right || del->right == _lastElem))
    {
        balanceNode = del->parent;
        del->content.first <= del->parent->content.first ?
                del->parent->left = del->left : del->parent->right = del->left;
        del->left->parent = del->parent;
        if (del->right == _lastElem)
        {
            _lastElem->left = del->left;
            del->left->right = _lastElem;
        }
    }
    else if ((!del->left || del->left == _lastElem) && del->right && del->right != _lastElem)
    {
        balanceNode = del->parent;
        del->content.first <= del->parent->content.first ?
                del->parent->left = del->right : del->parent->right = del->right;
        del->right->parent = del->parent;
        if (del->left == _lastElem)
        {
            _lastElem->right = del->right;
            del->right->left = _lastElem;
        }
    }
    else
    {
        Node* maxNode = searchMaxNode(del->left);
        _allocPair.destroy(&del->content);
        _allocPair.construct(&del->content, maxNode->content);
        
        return deleteNode(del->left, maxNode->content.first);
    }

    balanceTheTree(&_root, balanceNode);
    deallocateNode(del);
    return true;
}

template<class Key, class T>
int map<Key, T>::balanceOfSubtrees(Node* node) {
    if (!node)
        return 0;
    return heightTree(node->left, 1) - heightTree(node->right, 1);
}

template<class Key, class T>
void map<Key, T>::rotateRight(Node** root, Node* nodeGoingDown) {
    Node* nodeGoingUp = nodeGoingDown->left;
                
    nodeGoingDown->left = nodeGoingUp->right;
                
    if (nodeGoingUp->right)
        nodeGoingUp->right->parent = nodeGoingDown;
                
    nodeGoingUp->right = nodeGoingDown;
                
    nodeGoingUp->parent = nodeGoingDown->parent;
                
    if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
        nodeGoingDown->parent->left = nodeGoingUp;
    else if (nodeGoingDown->parent)
        nodeGoingDown->parent->right = nodeGoingUp;
                
    nodeGoingDown->parent = nodeGoingUp;

    if (!nodeGoingUp->parent)
        *root = nodeGoingUp;
}

template<class Key, class T>
void map<Key, T>::rotateLeft(Node** root, Node* nodeGoingDown) {
    Node* nodeGoingUp = nodeGoingDown->right;
                
    nodeGoingDown->right = nodeGoingUp->left;

    if (nodeGoingUp->left)
        nodeGoingUp->left->parent = nodeGoingDown;
                
    nodeGoingUp->left = nodeGoingDown;
                
    nodeGoingUp->parent = nodeGoingDown->parent;
                
    if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
        nodeGoingDown->parent->left = nodeGoingUp;
    else if (nodeGoingDown->parent)
        nodeGoingDown->parent->right = nodeGoingUp;

    nodeGoingDown->parent = nodeGoingUp;

    if (!nodeGoingUp->parent)
        *root = nodeGoingUp;
}

template<class Key, class T>
void map<Key, T>::balanceTheTree(Node** root, Node* node) {
    while (node)
    {
        int balance;
        
        if ((balance = balanceOfSubtrees(node)) < -1 && balanceOfSubtrees(node->right) < 0)
            rotateLeft(root, node);
        else if (balance < -1 && balanceOfSubtrees(node->right) >= 0)
        {
            rotateRight(root, node->right);
            rotateLeft(root, node);
        }                    
        else if (balance > 1 && balanceOfSubtrees(node->left) > 0)
            rotateRight(root, node);
        else if (balance > 1 && balanceOfSubtrees(node->left) <= 0)
        {
            rotateLeft(root, node->left);
            rotateRight(root, node);
        }
        node = node->parent;
    }
}

}