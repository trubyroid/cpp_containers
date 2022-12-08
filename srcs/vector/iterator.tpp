namespace ft
{

// --------------------- Construct/Copy/Destruct --------------------- //
    template<class value_type>
    myIterator<value_type>::myIterator() {
        this->_base_pointer = NULL;
    }

    template<class value_type>
    myIterator<value_type>::myIterator(value_type *val) {this->_base_pointer = val;}

    template<class value_type>
    myIterator<value_type>::myIterator(const myIterator& copy) {this->_base_pointer = copy._base_pointer;}

    template<class value_type>
    myIterator<value_type>::~myIterator() {}

// --------------------- Operators ----------------------------------- //

    template<class value_type>
    myIterator<value_type> &myIterator<value_type>::operator=(const myIterator& op) {
        if (this == &op) {
            return (*this);
        }
        this->_base_pointer = op._base_pointer;
        return *this;
    }

    template<class value_type>
    myIterator<value_type> &myIterator<value_type>::operator++(void) {
        this->_base_pointer++;
        return *this;
    }

    template<class value_type>
    myIterator<value_type> myIterator<value_type>::operator++(int) {
        myIterator it(this->_base_pointer++);
        return it;
    }

    template<class value_type>
    myIterator<value_type> &myIterator<value_type>::operator--(void) {
        this->_base_pointer--;
        return *this;
    }

    template<class value_type>
    myIterator<value_type> myIterator<value_type>::operator--(int) {
        myIterator it(this->_base_pointer--);
        return it;
    }

    template<class value_type>
    myIterator<value_type> &myIterator<value_type>::operator-=(int rVal) {
        this->_base_pointer -= rVal;
        return *this;
    }

    template<class value_type>
    myIterator<value_type> &myIterator<value_type>::operator+=(int rVal) {
        this->_base_pointer += rVal;
        return *this;
    }

    template<class value_type>
    int        myIterator<value_type>::operator-(const myIterator& rVal) const {
        return this->_base_pointer - rVal._base_pointer;
    }

    template<class value_type>
    myIterator<value_type> myIterator<value_type>::operator-(int rVal) {
        return myIterator(this->_base_pointer - rVal);
    }

    template<class value_type>
    myIterator<value_type> myIterator<value_type>::operator+(int rVal) {
        return myIterator(this->_base_pointer + rVal);
    }

    template<class value_type>
    bool myIterator<value_type>::operator==(const myIterator& rVal) const {
        return this->_base_pointer == rVal._base_pointer;
    }

    template<class value_type>
    bool myIterator<value_type>::operator!=(const myIterator& rVal) const {
        return this->_base_pointer != rVal._base_pointer;
    }

    template<class value_type>
    bool myIterator<value_type>::operator>(const myIterator& rVal) const {
        return this->_base_pointer > rVal._base_pointer;
    }

    template<class value_type>
    bool myIterator<value_type>::operator>=(const myIterator& rVal) const {
        return this->_base_pointer >= rVal._base_pointer;
    }

    template<class value_type>
    bool myIterator<value_type>::operator<(const myIterator& rVal) const {
        return this->_base_pointer < rVal._base_pointer;
    }

    template<class value_type>
    bool myIterator<value_type>::operator<=(const myIterator& rVal) const {
        return this->_base_pointer <= rVal._base_pointer;
    }

    template<class value_type>
    value_type& myIterator<value_type>::operator*() {
        return *this->_base_pointer;
    }

    template<class value_type>
    value_type *myIterator<value_type>::operator->() {
        return this->_base_pointer;
    }

    template<class value_type>
    value_type& myIterator<value_type>::operator[] (int x) {
        return *(this->_base_pointer + x);
    }    


}