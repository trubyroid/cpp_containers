namespace ft {

// --------------------- Member functions ---------------------------- //

template<class Key, class T>
map<Key, T>::map(const key_compare& comp, const allocator_type& alloc) {
    this->_size = 0;
    this->_comp = comp;
    this->_allocPair = alloc;

    this->_lastElem = createNode(ft::pair<const key_type, mapped_type>());
    this->_root = this->_lastElem;
    this->_lastElem->left = this->_lastElem;
    this->_lastElem->right = this->_lastElem;
}

template<class Key, class T>
template<class InputIterator>
map<Key, T>::map(InputIterator first, InputIterator last, 
    const key_compare& comp, const allocator_type& alloc, 
    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*) {
    this->_size = 0;
    this->_comp = comp;
    this->_allocPair = alloc;

    this->_lastElem = createNode(ft::pair<const key_type, mapped_type>());
    this->_root = this->_lastElem;
    this->_lastElem->left = this->_lastElem;
    this->_lastElem->right = this->_lastElem;
      
    for (; first != last; ++first)
        this->insert(*first);

}

template<class Key, class T>
map<Key, T>::map(const map& copy) {
    this->_size = copy.size();
    this->_comp = copy._comp;
    this->_allocPair = copy._allocPair;
    this->_allocNode = copy._allocNode;

    this->_lastElem = createNode(ft::pair<const key_type, mapped_type>());
    this->_root = this->_lastElem;
    this->_lastElem->left = this->_lastElem;
    this->_lastElem->right = this->_lastElem;

    for (const_iterator it = copy.begin(); it != copy.end(); ++it) {
        this->insert(*it);
        this->_size--;
    }
}

template<class Key, class T>
map<Key, T>::~map() {
    clear();
    deallocateNode(_lastElem);
}

template<class Key, class T>
map<Key, T> &map<Key, T>::operator=(const map& copy) {
    map tmp(copy);
    this->swap(tmp);
            
    return *this;
}

template<class Key, class T>
typename map<Key, T>::allocator_type
map<Key, T>::get_allocator() const {
    return this->_allocPair;
}

// --------------------- Element Access ------------------------------ //

template<class Key, class T>
typename map<Key, T>::mapped_type&
map<Key, T>::operator[](const key_type& key) {
    Node* tmp = searchNode(_root, key);

    if (tmp) {
        return tmp->content.second;
	}
    value_type val = ft::make_pair<key_type, mapped_type>(key, mapped_type());
    this->_size++;
    return insertNode(_root, val)->content.second;
}

template<class Key, class T>
typename map<Key, T>::mapped_type&
map<Key, T>::at(const key_type& key) {
    Node* tmp = searchNode(_root, key);

    if (tmp) {
        return tmp->content.second;
    }
    else {
        throw std::out_of_range("map::at:  key not found");
    }
}

template<class Key, class T>
const typename map<Key, T>::mapped_type&
map<Key, T>::at(const key_type& key) const {
    Node* tmp = searchNode(_root, key);

    if (tmp) {
        return tmp->content.second;
    }
    else {
        throw std::out_of_range("map::at:  key not found");
    }
}

// --------------------- Iterators ----------------------------------- //

template<class Key, class T>
typename map<Key, T>::iterator
map<Key, T>::begin() {
	return iterator(_lastElem->right, _lastElem, _comp);
}

template<class Key, class T>
typename map<Key, T>::iterator
map<Key, T>::end() {
	return iterator(_lastElem, _lastElem, _comp);
}

template<class Key, class T>
typename map<Key, T>::reverse_iterator
map<Key, T>::rbegin() {
	return reverse_iterator(_lastElem->left, _lastElem, _comp);
}

template<class Key, class T>
typename map<Key, T>::reverse_iterator
map<Key, T>::rend() {
	return reverse_iterator(_lastElem, _lastElem, _comp);
}

// --------------------- Iterators const ----------------------------- //

template<class Key, class T>
typename map<Key, T>::const_iterator
map<Key, T>::begin() const{
	return const_iterator(_lastElem->right, _lastElem, _comp);
}

template<class Key, class T>
typename map<Key, T>::const_iterator
map<Key, T>::end() const{
	return const_iterator(_lastElem, _lastElem, _comp);
}

template<class Key, class T>
typename map<Key, T>::const_reverse_iterator
map<Key, T>::rbegin() const {
	return const_reverse_iterator(_lastElem->left, _lastElem, _comp);
}

template<class Key, class T>
typename map<Key, T>::const_reverse_iterator
map<Key, T>::rend() const {
	return const_reverse_iterator(_lastElem, _lastElem, _comp);
}

// --------------------- Capacity ------------------------------------ //

template<class Key, class T>
bool map<Key, T>::empty() const {
    return this->_size == 0;
}

template<class Key, class T>
typename map<Key, T>::size_type
map<Key, T>::size() const {
    return this->_size;
}

#define STRING_KLUDGE 384307168202282304
#define STRING_SIZE 2305843009213693952

template<class Key, class T>
typename map<Key, T>::size_type
map<Key, T>::max_size() const {
    size_type val = (pow(2, 64) / sizeof(value_type));
    if (val == STRING_KLUDGE)
	    val = STRING_SIZE;
    else
        val *= 2;
    return val / 10;
}

// --------------------- Modifiers ----------------------------------- //

template<class Key, class T>
void map<Key, T>::clear() {
    erase(begin(), end());
}

template<class Key, class T>
ft::pair<typename map<Key, T>::iterator,bool> map<Key, T>::insert(const value_type& val) {
    Node* elemIsPresent = searchNode(_root, val.first);
    if (elemIsPresent)
        return ft::pair<iterator, bool>(iterator(elemIsPresent, _lastElem, _comp), false);

    this->_size++;
    return ft::pair<iterator, bool>(iterator(insertNode(_root, val), _lastElem, _comp), true);
}

template<class Key, class T>
typename map<Key, T>::iterator
map<Key, T>::insert(iterator position, const value_type& val) {
	if (position->first > val.first)
    {
        iterator prev(position);
        --prev;
        while (prev != end() && prev->first >= val.first)
        {
            --position;
            --prev;
        }
    }
    else if (position->first < val.first)
    {
        iterator next(position);
        ++next;
        while (next != end() && next->first <= val.first)
        {
            ++position;
            ++next;
        }
    }
    if (position != end() && val.first == position->first)
        return position;
    this->_size++;
    return iterator(insertNode(position.getNode(), val), _lastElem, _comp);
}

template<class Key, class T>
template <class InputIterator>
void map<Key, T>::insert(InputIterator first, InputIterator last,
    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*) {
    while (first != last)
        insert(*first++);
}

template<class Key, class T>
void map<Key, T>::erase(typename map<Key, T>::iterator position) {
    deleteNode(position.getNode(), position->first);
    this->_size--;
}

template<class Key, class T>
typename map<Key, T>::size_type
map<Key, T>::erase(const typename map<Key, T>::key_type& k) {
    size_type ret = deleteNode(_root, k);
    this->_size -= ret;
    return ret;
}

template<class Key, class T>
void map<Key, T>::erase(typename map<Key, T>::iterator first, 
    typename map<Key, T>::iterator last) {
    while (first != last)
    {
        iterator tmp(first);
        ++first;
        erase(tmp);
    }
}

template<class Key, class T>
void map<Key, T>::swap(map<Key,T> &x) {
    ft::swap(_root, x._root);
    ft::swap(_lastElem, x._lastElem);
    ft::swap(_size, x._size);
    ft::swap(_comp, x._comp);
    ft::swap(_allocPair, x._allocPair);
    ft::swap(_allocNode, x._allocNode);
}

// --------------------- Lookup -------------------------------------- //

template<class Key, class T>
typename map<Key, T>::iterator
map<Key, T>::find(const key_type& k) {
    Node* tmp = searchNode(_root, k);   

    if (tmp)
        return iterator(tmp, _lastElem, _comp);
    
    return end();
}

template<class Key, class T>
typename map<Key, T>::const_iterator
map<Key, T>::find(const key_type& k) const {
    Node* tmp = searchNode(_root, k);   

    if (tmp)
        return const_iterator(tmp, _lastElem, _comp);
    
    return end();
}

template<class Key, class T>
typename map<Key, T>::size_type
map<Key, T>::count(const key_type& k) const {
    Node* tmp = searchNode(_root, k);
                
    return tmp ? true: false;
}

template<class Key, class T>
typename map<Key, T>::iterator
map<Key, T>::lower_bound(const key_type& k) {
    iterator it = begin();

    for (; it != end(); ++it)
        if (!_comp(it->first, k))
            break;
    
    return it; 
}

template<class Key, class T>
typename map<Key, T>::const_iterator
map<Key, T>::lower_bound(const key_type& k) const {
    const_iterator it = begin();

    for (; it != end(); ++it)
        if (!_comp(it->first, k))
            break;
    
    return it;  
}

template<class Key, class T>
typename map<Key, T>::iterator
map<Key, T>::upper_bound(const key_type& k) {
    iterator it = begin();

    for (; it != end(); ++it)
        if (_comp(k, it->first))
            break;
    
    return it; 
}

template<class Key, class T>
typename map<Key, T>::const_iterator
map<Key, T>::upper_bound(const key_type& k) const {
    const_iterator it = begin();

    for (; it != end(); ++it)
        if (_comp(k, it->first))
            break;
    
    return it; 
}

template<class Key, class T>
typename ft::pair<typename map<Key, T>::iterator,typename map<Key, T>::iterator>
map<Key, T>::equal_range(const key_type& k) {
    iterator it = upper_bound(k);

    if (it != begin())
    {
        --it;
        if (_comp(it->first, k) || _comp(k, it->first))
            ++it;
    }

    iterator next(it);
    if (it != end())
        ++next;
    
    return make_pair<iterator, iterator>(it, next);
}

template<class Key, class T>
typename ft::pair<typename map<Key, T>::const_iterator,typename map<Key, T>::const_iterator>
map<Key, T>::equal_range(const key_type& k) const {
    const_iterator it = upper_bound(k);

    if (it != begin())
    {
        --it;
        if (_comp(it->first, k) || _comp(k, it->first))
            ++it;
    }
    const_iterator next(it);
    if (it != end())
        ++next;
    return make_pair<const_iterator, const_iterator>(it, next);
}

// --------------------- Observers ----------------------------------- //

template<class Key, class T>
typename map<Key, T>::key_compare
map<Key, T>::key_comp() const {
    return _comp; 
}

template<class Key, class T>
typename map<Key, T>::value_compare
map<Key, T>::value_comp() const {
    return value_compare(_comp);
}

}