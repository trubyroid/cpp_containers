namespace ft
{

// --------------------- Construct/Copy/Destruct --------------------- //
    template<class value_type>
    myReverseIterator<value_type>::myReverseIterator() : myIterator<value_type>() {}

    template<class value_type>
    myReverseIterator<value_type>::myReverseIterator(value_type *val) {this->_base_pointer = val;}
    
    template<class value_type>
    myReverseIterator<value_type>::myReverseIterator(const myReverseIterator& copy) {this->_base_pointer = copy._base_pointer;}

    // template<class value_type>
    // myReverseIterator<value_type>::myReverseIterator(const myIterator<value_type>& copy) {this->_base_pointer = copy._base_pointer;}

    template<class value_type>
    myReverseIterator<value_type>::~myReverseIterator() {}

// --------------------- Operators ----------------------------------- //

    template<class value_type>
    myReverseIterator<value_type> &myReverseIterator<value_type>::operator=(const myReverseIterator& op) {
    	if (this == &op)
    		return (*this);
    	this->_base_pointer = op._base_pointer;
    	return (*this);
    }

    template<class value_type>
    myReverseIterator<value_type> &myReverseIterator<value_type>::operator ++ (void) {
    	--this->_base_pointer;
    	return (*this);
    }

    template<class value_type>
    myReverseIterator<value_type> myReverseIterator<value_type>::operator ++ (int) {
    	myReverseIterator<value_type> it(this->_base_pointer--);
    	return (it);
    }

    template<class value_type>
    myReverseIterator<value_type> &myReverseIterator<value_type>::operator -- (void) {
    	++this->_base_pointer;
    	return (*this);
    }

    template<class value_type>
    myReverseIterator<value_type> myReverseIterator<value_type>::operator -- (int) {
    	myReverseIterator<value_type> it(this->_base_pointer++);
    	return (it);
    }

    template<class value_type>
    myReverseIterator<value_type> &myReverseIterator<value_type>::operator -= (int rVal) {
    	this->_base_pointer += rVal;
    	return (*this);
    }

    template<class value_type>
    myReverseIterator<value_type> &myReverseIterator<value_type>::operator += (int rVal) {
    	this->_base_pointer -= rVal;
    	return (*this);
    }

    template<class value_type>
    int	 myReverseIterator<value_type>::operator - (const myReverseIterator& rVal) const {
    	return (rVal._base_pointer - this->_base_pointer);
    }

    template<class value_type>
    myReverseIterator<value_type> myReverseIterator<value_type>::operator - (int rVal) {
    	return (myReverseIterator(this->_base_pointer + rVal));
    }

    template<class value_type>
    myReverseIterator<value_type> myReverseIterator<value_type>::operator + (int rVal) {
    	return (myReverseIterator(this->_base_pointer - rVal));
    }

    template<class value_type>
    bool myReverseIterator<value_type>::operator == (const myReverseIterator& rVal) const {
    	return (this->_base_pointer == rVal._base_pointer);
    }

    template<class value_type>
    bool myReverseIterator<value_type>::operator != (const myReverseIterator& rVal) const {
    	return (this->_base_pointer != rVal._base_pointer);
    }

    template<class value_type>
    bool myReverseIterator<value_type>::operator <= (const myReverseIterator& rVal) const {
    	return (this->_base_pointer >= rVal._base_pointer);
    }

    template<class value_type>
    bool myReverseIterator<value_type>::operator >= (const myReverseIterator& rVal) const {
    	return (this->_base_pointer <= rVal._base_pointer);
    }

    template<class value_type>
    bool myReverseIterator<value_type>::operator < (const myReverseIterator& rVal) const {
    	return (this->_base_pointer > rVal._base_pointer);
    }

    template<class value_type>
    bool myReverseIterator<value_type>::operator > (const myReverseIterator& rVal) const {
    	return (this->_base_pointer < rVal._base_pointer);
    }

    template<class value_type>
    value_type&	myReverseIterator<value_type>::operator* () {
    	return (*(this->_base_pointer - 1));
    }

    template<class value_type>
    myIterator<value_type> myReverseIterator<value_type>::base() const {
    	return (myIterator<value_type>(this->_base_pointer));
    }

    template<class value_type>
    value_type *myReverseIterator<value_type>::operator->() {
    	return (this->_base_pointer - 1);
    }

    template<class value_type>
    value_type&	myReverseIterator<value_type>::operator[] (int x) {
    	return (*(this->_base_pointer - x - 1));
    }

}