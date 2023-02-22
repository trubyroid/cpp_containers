namespace ft
{

// --------------------- Construct/Copy/Destruct --------------------- //

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B>::rev_map_iterator(nodePtr node, nodePtr lastElem, const key_compare& comp) {
    _node = node;
    _lastElem = lastElem;
    _comp = comp;
}

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B>::rev_map_iterator(const rev_map_iterator<Key, T, Compare, Node, false>& copy) {
    _node = copy.getNode();
    _lastElem = copy.getLastElem();
    _comp = copy.getCompare();
}

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B>::~rev_map_iterator() {
}

// --------------------- Operators ----------------------------------- //

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B>& rev_map_iterator<Key, T, Compare, Node, B>::operator=(const rev_map_iterator& assign) {
    if (this != &assign)
    {
        _node = assign._node;
        _lastElem = assign._lastElem;
        _comp = assign._comp;
    }
    return (*this);
}

template <class Key, class T, class Compare, typename Node, bool B>
typename rev_map_iterator<Key, T, Compare, Node, B>::reference
rev_map_iterator<Key, T, Compare, Node, B>::operator*() const {
    return (_node->content);
}

template <class Key, class T, class Compare, typename Node, bool B>
typename rev_map_iterator<Key, T, Compare, Node, B>::pointer
rev_map_iterator<Key, T, Compare, Node, B>::operator->() const {
    return (&_node->content);
}

template <class Key, class T, class Compare, typename Node, bool B>
bool rev_map_iterator<Key, T, Compare, Node, B>::operator==(const rev_map_iterator& it) const {
    return (it._node == _node);
}

template <class Key, class T, class Compare, typename Node, bool B>
bool rev_map_iterator<Key, T, Compare, Node, B>::operator!=(const rev_map_iterator& it) const {
    return (it._node != _node);
}

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B>& rev_map_iterator<Key, T, Compare, Node, B>::operator++() {
    nodePtr previousNode = _node;

    if (_node == _lastElem)
    {
        _node = _lastElem->left;
        return (*this);
    }

    while (_node != _lastElem && !_comp(_node->content.first, previousNode->content.first))
    {
        if (_node->left && (_node->left == _lastElem || 
                _comp(_node->left->content.first, previousNode->content.first)))
        {
            _node = _node->left;
            
            Node* tmp = 0;
            if (_node != _lastElem && (tmp = searchMaxNode(_node)))
                _node = tmp;
        }
        else {
            _node = _node->parent;
        }
    }

    return (*this);
}

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B> rev_map_iterator<Key, T, Compare, Node, B>::operator++(int) {
    rev_map_iterator res(*this);

    if (_node == _lastElem)
    {
        _node = _lastElem->left;
        return (res);
    }
                
    while (_node != _lastElem && !_comp(_node->content.first, res->first))
    {
        if (_node->left && (_node->left == _lastElem || 
                _comp(_node->left->content.first, res->first)))
        {
            _node = _node->left;
            
            Node* tmp = 0;
            if (_node != _lastElem && (tmp = searchMaxNode(_node)))
                _node = tmp;
        }
        else {
            _node = _node->parent;
        }
    }       
    return (res);
}

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B>& rev_map_iterator<Key, T, Compare, Node, B>::operator--() {
    nodePtr previousNode = _node;

    if (_node == _lastElem)
    {
        _node = _lastElem->right;
        return (*this);
    }

    while (_node != _lastElem && !_comp(previousNode->content.first, _node->content.first))
    {   
        if (_node->right && (_node->right == _lastElem || 
                _comp(previousNode->content.first, _node->right->content.first)))
        {
            _node = _node->right;
            
            Node* tmp = 0;
            if (_node != _lastElem && (tmp = searchMinNode(_node)))
                _node = tmp;
        }
        else {
            _node = _node->parent;
        }
    }
    return (*this);
}

template <class Key, class T, class Compare, typename Node, bool B>
rev_map_iterator<Key, T, Compare, Node, B> rev_map_iterator<Key, T, Compare, Node, B>::operator--(int) {
    rev_map_iterator res(*this);

    if (_node == _lastElem)
    {
        _node = _lastElem->right;
        return (res);
    }
                
    while (_node != _lastElem && !_comp(res->first, _node->content.first))
    {
        if (_node->right && (_node->right == _lastElem || 
                _comp(res->first, _node->right->content.first)))
        {
            _node = _node->right;
            
            Node* tmp = 0;
            if (_node != _lastElem && (tmp = searchMinNode(_node)))
                _node = tmp;
        }
        else
            _node = _node->parent;
    }           
    return (res);
}

// --------------------- Getters ------------------------------------- //

template <class Key, class T, class Compare, typename Node, bool B>
typename rev_map_iterator<Key, T, Compare, Node, B>::nodePtr
rev_map_iterator<Key, T, Compare, Node, B>::getNode() const {
    return _node;
}

template <class Key, class T, class Compare, typename Node, bool B>
typename rev_map_iterator<Key, T, Compare, Node, B>::nodePtr
rev_map_iterator<Key, T, Compare, Node, B>::getLastElem() const {
    return _lastElem;
}

template <class Key, class T, class Compare, typename Node, bool B>
typename rev_map_iterator<Key, T, Compare, Node, B>::key_compare
rev_map_iterator<Key, T, Compare, Node, B>::getCompare() const {
    return _comp;
}

// --------------------- Searchers ----------------------------------- //

template <class Key, class T, class Compare, typename Node, bool B>
typename rev_map_iterator<Key, T, Compare, Node, B>::nodePtr
rev_map_iterator<Key, T, Compare, Node, B>::searchMaxNode(typename rev_map_iterator<Key, T, Compare, Node, B>::nodePtr root) {
    if (root && root != _lastElem && root->right && root->right != _lastElem)
        return searchMaxNode(root->right);
    return root;
}

template <class Key, class T, class Compare, typename Node, bool B>
typename rev_map_iterator<Key, T, Compare, Node, B>::nodePtr
rev_map_iterator<Key, T, Compare, Node, B>::searchMinNode(typename rev_map_iterator<Key, T, Compare, Node, B>::nodePtr root) {
    if (root && root != _lastElem && root->left && root->left != _lastElem)
        return searchMinNode(root->left);
    return root;
}

}