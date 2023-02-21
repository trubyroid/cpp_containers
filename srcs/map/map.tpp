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
        _size--;
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
    value_type val = make_pair<key_type, mapped_type>(key, mapped_type());
    _size++;
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
typename map<Key, T>::size_type
map<Key, T>::size() const {
    return this->_size;
}

}