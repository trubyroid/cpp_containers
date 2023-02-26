namespace ft
{

// --------------------- Member functions ---------------------------- //

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
    this->_capacity = copy.size();
    if (this->_capacity) {
        this->_base_array = this->_allocator.allocate(this->_capacity);
        if (!this->_base_array) {
            throw std::bad_alloc();
        }
        for (size_type i = 0; i < copy.size(); i++) {
            this->_allocator.construct(this->_base_array + i, *(copy._base_array + i));
        }
    }
}

template<class value_type>
template<class InputIterator>
vector<value_type>::vector(InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
    this->_size = 0;
    this->_capacity = 0;
	if (first > last) {
		throw std::length_error("constructor");
	}
	_base_array = _allocator.allocate(size_type(last - first));
	this->insert(this->begin(), first, last);
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

template <class value_type>
template <class InputIterator>
void vector<value_type>::assign(InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
    size_type range;

    range = size_type(last - first);
	this->clear();
	if (range <= this->_capacity) {
		while (first != last)
			push_back(*(first++));
	}
	else {
		reserve(range);
		while (first != last)
			push_back(*(first++));
	}
}

template<class value_type>
void vector<value_type>::assign(size_type count, const value_type& val) {
    if (count < 0 || count > this->max_size()) {
        throw std::length_error("assign vector");
    }
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    this->_allocator.deallocate(this->_base_array, this->_capacity);
    if (this->_capacity < count) {
        this->_capacity = count;
    }
    value_type *_new_array = this->_allocator.allocate(this->_capacity);
    if (!this->_base_array) {
        throw std::bad_alloc();
    }
    for (size_type i = 0; i < count; i++) {
        this->_allocator.construct(_new_array + i, val);
    }
    this->_size = count;
    this->_base_array = _new_array;
    _new_array = NULL;
}

template<class value_type>
typename vector<value_type>::allocator_type
vector<value_type>::get_allocator() const {
    return this->_allocator;
}

// --------------------- Element Access ------------------------------ //

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::at(size_type pos) {
	if (pos >= this->_size) {
		throw std::out_of_range("vector");
	}
	return this->_base_array[pos];
}

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::front() {
    return this->at(0);
}

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::back() {
    return this->at(this->_size - 1);
}

template<class value_type>
value_type* vector<value_type>::data() {
    return this->_base_array;
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::at(size_type pos) const {
	if (pos >= this->_size) {
		throw std::out_of_range("vector");
	}
	return this->_base_array[pos];
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::front() const {
    return this->at(0);
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::back() const {
    return this->at(this->_size - 1);
}

template<class value_type>
const value_type*  vector<value_type>::data() const {
    return this->_base_array;
}

// --------------------- Operators ----------------------------------- //

template<class value_type>
vector<value_type> &vector<value_type>::operator=(const vector& copy) {
    if (this == &copy)
        return *this;
    if (!this->empty()) {
        for (size_type i = 0; i < this->_size; i++) {
            this->_allocator.destroy(this->_base_array + i);
        }
        this->_allocator.deallocate(this->_base_array, this->_capacity);
    }
    this->_size = copy.size();
    if (copy.size() > this->_capacity) {
        this->_capacity = copy.size();
    }
    if (this->_capacity) {
        this->_base_array = this->_allocator.allocate(this->_capacity);
        if (!this->_base_array) {
            throw std::bad_alloc();
        }
        for (size_type i = 0; i < this->_size; i++) {
            this->_allocator.construct(this->_base_array + i, *(copy._base_array + i));
        }
    }
    return *this;
}

template<class value_type>
bool vector<value_type>::operator==(const vector& other) {
    if (this == &other) {
        return true;
    }
    if (this->_size != other.size()) {
        return false;
    }
    for (size_type i = 0; i < this->_size; i++) {
        if (*(this->_base_array + i) != *(other._base_array + i)) {
            return false;
        }
    }
    return true;
}

template<class value_type>
bool vector<value_type>::operator!=(const vector& other) {
    return (!this->operator==(other));
	}

template<class value_type>
bool vector<value_type>::operator<(const vector& other) {
    for (size_type i = 0; i < other.size(); ++i) {
        if (this->_base_array[i] > other._base_array[i])
            return false;
        if (i == this->_size || this->_base_array[i] < other._base_array[i]) {
            return true;
        }
    }
    return false;
}

template<class value_type>
bool vector<value_type>::operator>(const vector& other) {
    for (size_type i = 0; i < this->_size; ++i) {
        if (this->_base_array[i] < other._base_array[i])
            return false;
        if (i == other.size() || this->_base_array[i] > other._base_array[i]) {
            return true;
        }
    }
    return false;
}

template<class value_type>
bool vector<value_type>::operator<=(const vector& other) {
    return !this->operator>(other);
}

template<class value_type>
bool vector<value_type>::operator>=(const vector& other) {
    return !this->operator<(other);
}

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::operator[](size_type pos) {
	return *(this->_base_array + pos);
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::operator[](size_type pos) const {
	return *(this->_base_array + pos);
}

// --------------------- Iterators ----------------------------------- //

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::begin() {
	return iterator(this->_base_array);
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::end() {
	return iterator(this->_base_array + this->_size);
}

template<class value_type>
typename vector<value_type>::reverse_iterator
vector<value_type>::rbegin() {
	return reverse_iterator(this->_base_array + this->_size);
}

template<class value_type>
typename vector<value_type>::reverse_iterator
vector<value_type>::rend() {
	return reverse_iterator(this->_base_array);
}

// --------------------- Iterators const ----------------------------- //

template<class value_type>
typename vector<value_type>::const_iterator
vector<value_type>::begin() const{
	return const_iterator(this->_base_array);
}

template<class value_type>
typename vector<value_type>::const_iterator
vector<value_type>::end() const{
	return const_iterator(this->_base_array + this->_size);
}

template<class value_type>
typename vector<value_type>::const_reverse_iterator
vector<value_type>::rbegin() const {
	return const_reverse_iterator(this->_base_array + this->_size);
}

template<class value_type>
typename vector<value_type>::const_reverse_iterator
vector<value_type>::rend() const {
	return const_reverse_iterator(this->_base_array);
}

// --------------------- Capacity ------------------------------------ //

template<class value_type>
bool vector<value_type>::empty() const {
	return !_size;
}

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::size() const {
    return this->_size;
}

#define STRING_MAX_SIZE 768614336404564650
#define KLUDGE 768614336404564607

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::max_size() const {\
    size_type val = (pow(2, 64) / sizeof(value_type));
	val--;
    if (val == KLUDGE) {
        val = STRING_MAX_SIZE;
    }
	return val;
}

template<class value_type>
void vector<value_type>::reserve(size_type new_cap) {
    if(new_cap > this->max_size())
        throw std::length_error("vector: reserve: length > max_size");
    if (new_cap > this->_capacity) {
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

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::capacity() const {
    return this->_capacity;
}

// --------------------- Modifiers ----------------------------------- //

template<class value_type>
void vector<value_type>::clear() {
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    this->_size = 0;
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::insert(iterator pos, const value_type& value) {
    value_type  *_new_array;
    size_type   ind = 0;
    size_type   j = 0;

    ind = pos - this->begin();
    if (this->_size == this->_capacity) {
        this->reserve(this->_capacity * 2);
    }
    _new_array = this->_allocator.allocate(this->_capacity);
    if (!_new_array) {
        throw std::bad_alloc();
    }
    for (size_type i = 0; i <= this->_size; i++) {
        if (i == ind) {
            this->_allocator.construct(_new_array + ind, value);
        }
        else {
            this->_allocator.construct(_new_array + i, *(this->_base_array + j));
            j++;
        }
    }
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    this->_allocator.deallocate(this->_base_array, this->_capacity);
    this->_base_array = _new_array;
    this->_size++;
    return (iterator(this->_base_array + ind));
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::insert(iterator pos, size_type count, const value_type& value) {
    value_type  *_new_array;
    size_type   ind = 0;
    size_type   j = 0;
    size_type   new_cap = this->_capacity;

    if (count == 0){
        return pos;
    }
    ind = pos - this->begin();
    if (this->_size + count > this->_capacity) {
        new_cap *= 2;
    }
    if (this->_size + count > new_cap) {
        new_cap = this->_size + count;
    }
    this->reserve(new_cap);
    _new_array = this->_allocator.allocate(this->_capacity);
    if (!_new_array) {
        throw std::bad_alloc();
    }
    for (size_type i = 0; i <= this->_size + count; i++) {
        if (i == ind) {
            for (size_type k = 0; k <= count; k++) {
                this->_allocator.construct(_new_array + i + k, value);
            }
            i += count - 1;
        }
        else {
            this->_allocator.construct(_new_array + i, *(this->_base_array + j));
            j++;
        }
    }
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    this->_allocator.deallocate(this->_base_array, this->_capacity);
    this->_base_array = _new_array;
    this->_size += count;
    return (iterator(this->_base_array + ind));
}

template<class value_type>
template<class InputIterator>
typename vector<value_type>::iterator
vector<value_type>::insert(iterator pos, InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
    value_type  *_new_array;
    size_type   ind = 0;
    size_type   j = 0;
    size_type   num;
    size_type   new_cap = this->_capacity;

    num = size_type(last - first);
    ind = pos - this->begin();
    if (this->_size + num > this->_capacity) {
        new_cap *= 2;
    }
    if (this->_size + num > new_cap) {
        new_cap = this->_size + num;
    }
    this->reserve(new_cap);
    _new_array = this->_allocator.allocate(this->_capacity);
    if (!_new_array) {
        throw std::bad_alloc();
    }
    for (size_type i = 0; i <= this->_size + num; i++) {
        if (i == ind) {
            for (;first != last; i++) {
                this->_allocator.construct(_new_array + i, *(first++));
            }
            i--;
        }
        else {
            this->_allocator.construct(_new_array + i, *(this->_base_array + j));
            j++;
        }
    }
    for (size_type i = 0; i < this->_size; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    this->_allocator.deallocate(this->_base_array, this->_capacity);
    this->_base_array = _new_array;
    this->_size += num;
    return (iterator(this->_base_array + ind));
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::erase(iterator pos) {
    size_type  ind = pos - this->begin();

    this->_allocator.destroy(this->_base_array + ind);
    for (; ind < this->_size; ind++) {
        this->_allocator.construct(this->_base_array + ind, *(this->_base_array + ind + 1));
        this->_allocator.destroy(this->_base_array + ind + 1);
    }
    this->_size--;
    return(pos);
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::erase(iterator first, iterator last) {
    size_type ind_beg = first - this->begin();
    size_type ind_end = last - this->begin();
    size_type num = ind_end - ind_beg;

    for (size_type i = ind_beg; i < ind_end; i++) {
        this->_allocator.destroy(this->_base_array + i);
    }
    for (; ind_end < this->_size; ind_end++ && ind_beg++) {
        this->_allocator.construct(this->_base_array + ind_beg, *(this->_base_array + ind_end));
    }
    this->_size -= num;
    return (first);
}

template<class value_type>
void    vector<value_type>::push_back(const value_type &val) {
    if (!this->_capacity)
		this->_base_array = _allocator.allocate(this->_capacity = 1);
    if (this->_size == this->_capacity) {
        reserve(this->_capacity * 2);
    }
    this->_allocator.construct(this->_base_array + this->_size, val);
    this->_size++;
}

template<class value_type>
void    vector<value_type>::pop_back() {
    if (this->_size) {
        this->_allocator.destroy(this->_base_array + this->_size);
        this->_size--;
    }
}

template<class value_type>
void vector<value_type>::resize(size_type count, const value_type& val) {
    size_type new_cap = this->_capacity;

    if (count < 0 || count > this->max_size())
        throw std::length_error("resize vector");  
    if (count >= this->_capacity) {
        if (this->_size == this->_capacity) {
            new_cap *= 2;
        }
        if (new_cap < count){
            new_cap = count;
        }
        reserve(new_cap);
        for (; this->_size < count; this->_size++) {
            this->_allocator.construct(this->_base_array + this->_size, val);
	    }
	}
    else {
        pointer  _new_array = this->_allocator.allocate(this->_capacity);
        if (!_new_array) {
            throw std::bad_alloc();
        }
        for (size_type i = 0; i < count; i++) {
            this->_allocator.construct(_new_array + i, *(this->_base_array + i));
        }
        for (size_type i = 0; i < this->_size; i++) {
            this->_allocator.destroy(this->_base_array + i);
        }

        this->_allocator.deallocate(this->_base_array, this->_capacity);
        this->_base_array = _new_array;
        _new_array = NULL;

        if (this->_size < count){
            for (; this->_size < count; this->_size++) {
                this->_allocator.construct(this->_base_array + this->_size, val);
	        }
        }
        this->_size = count;
    }
}

template<class value_type>
void vector<value_type>::swap(vector& other) {
    size_type   size = this->_size;
    size_type   cap = this->_capacity;
    value_type  *arr = this->_base_array;
    allocator_type  alloc = this->_allocator;

    this->_size = other.size();
    this->_capacity = other.capacity();
    this->_base_array = other.data();
    this->_allocator = other.get_allocator();
    
    other._size = size;
    other._capacity = cap;
    other._base_array = arr;
    other._allocator = alloc;
}
}