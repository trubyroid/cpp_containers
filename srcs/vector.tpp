namespace ft
{

// --------------------- Construct/Copy/Destruct --------------------- //

template<class value_type>
vector<value_type>::vector() {
    this->_size = 0;
    this->_capacity = 0;
    this->_base_array = NULL;
}

template<class value_type>
vector<value_type>::vector(size_type size, const value_type& val) {
    this->_size = size;
    this->_capacity = size;
    this->_base_array = this->_allocator.allocate(size);
    if (!this->_base_array) {
        throw std::bad_alloc();
    }
    for (size_type i = 0; i < size; i++) {
        this->_allocator.construct(this->_base_array + i, val);
    }
}

template<class value_type>
vector<value_type>::vector(const vector& copy) {
    this->_size = copy.size();
    this->capacity = copy.capacity();
    this->_base_array = this->_allocator.allocate(this->_size);
    if (!this->_base_array) {
        throw std::bad_alloc();
    }
    for (size_type i = 0; i < copy.size(); i++) {
        this->_allocator.construct(this->_base_array + i, copy->_base_array + i);
    }
}

template<class value_type>
typename vector<value_type>::allocator_type
vector<value_type>::get_allocator() const {
    return this->_allocator;
}

template<class value_type>
void vector<value_type>::assign(size_type count, const value_type& val) {
    if (count < 0 || count > this->max_size())
        throw std::length_error("assign vector");
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    this->_allocator.deallocate(this->_base_array, this->_capacity);
    if (this->_capacity < count) {
        this->_capacity = count;
    }
    this->_base_array = this->_allocator.allocate(this->_capacity);
    if (!this->_base_array) {
        throw std::bad_alloc();
    }
    this->_size = count;
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.construct(this->_base_array + i, val);
    }
}



template<class value_type>
vector<value_type>::~vector() {
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    if (!this->empty()) {
        this->_allocator.deallocate(this->_base_array, this->_capacity);
    }
}

// --------------------- Element Access ------------------------------ //

// --------------------- Operators ----------------------------------- //

template<class value_type>
vector<value_type> &vector<value_type>::operator=(const vector& copy) {
    if (this == &copy)
        return *this;
    this->_size = copy.size();
    this->capacity = copy.capacity();
    this->_base_array = this->_allocator.allocate(this->_size);
    if (!this->_base_array) {
        throw std::bad_alloc();
    }
    for (size_type i = 0; i < copy.size(); i++) {
        this->_allocator.construct(this->_base_array + i, copy->_base_array + i);
    }
    return *this;
}

// --------------------- Capacity ------------------------------------ //

template<class value_type>
bool vector<value_type>::empty() const {
	return _size > 0 ? true : false;
}

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::size() const {
    return _size;
}

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::max_size() const {
	return std::numeric_limits<value_type>::max();
}

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::capacity() const {
    return _capacity;
}

template<class value_type>
void vector<value_type>::reserve(size_type new_cap) {
    if (new_cap > _capacity) {
        pointer  _new_array = this->_allocator.allocate(new_cap);
        if (!_new_array) {
            throw std::bad_alloc();
        }
        for (size_type i = 0; i < this->_size; i++) {
            this->_allocator.construct(_new_array + i, *(this->_base_array + i));
            this->_allocator.destroy(this->_base_array + i);
        }
        this->_allocator.deallocate(this->_base_array, this->_capacity);
        this->_base_array = _new_array;
        this->_capacity = new_cap;
    }
}

// --------------------- Modifiers ----------------------------------- //

template<class value_type>
void vector<value_type>::resize(size_type count, const value_type& val) {
    if (count < 0 || count > this->max_size())
        throw std::length_error("resize vector");  
    if (count >= this->_capacity) {
        if (this->_size == this->_capacity) {
            reserve(this->_capacity * 2);
        }
        reserve(count);
	}
    else {
        pointer  _new_array = this->_allocator.allocate(_capacity);
        if (!_new_array) {
            throw std::bad_alloc();
        }
        for (size_type i = 0; i < count; i++) {
            _new_array[i] = this->_base_array[i];
        }
        for (size_type i = 0; i < this->_size; i++) {
            this->_allocator.destroy(this->_base_array + i);
        }
        this->_allocator.deallocate(this->_base_array, this->_capacity);
        this->_base_array = _new_array;
        this->_size = count;
    }
	for (; this->_size < count; this->_size++) {
        this->_allocator.construct(this->_base_array + this->_size, val);
	}
}

}

// template<class value_type>
// void    vector<value_type>::doublingCapacity() {
//     _capacity = (!_capacity) ? (1) : _capacity * 2;
//     value_type *_new_array = _allocator.allocate(_capacity);
//     for (size_type i = 0; i < _size; i++) {
//         _allocator.allocate(_new_array + i, _base_array + i);
//         _allocator.destroy(_base_array + i);
//     }
//     if (_capacity > 1)
//         _allocator.deallocate(_base_array, _capacity / 2);
//     _base_array = _new_array;
// }

// void    ft::vector::push_back(const value_type &val) {
//     if (_size == _capacity) {
//         doublingCapacity();
//     }
//     _allocator.construct(_base_array + _size++, val);
// }

// }