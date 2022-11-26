namespace ft
{

// --------------------- Construct/Copy/Destruct --------------------- //
    myIterator::myIterator() {this->_base_pointer = NULL;}
    myIterator::myIterator(T *val) {this->_base_pointer = val;}
    myIterator::myIterator(const myIterator& copy) {this->_base_pointer = copy._base_pointer;}
    virtual myIterator::~myIterator() {}

// --------------------- Operators ----------------------------------- //

    myIterator &myIterator::operator=(const myIterator& op) {
        if (this == &op) {
            return (*this);
        }
        this->_base_pointer = op._base_pointer;
        return *this;
    }

    myIterator &myIterator::operator++(void) {
        this->_base_pointer++;
        return *this;
    }

    myIterator myIterator::operator++(int) {
        myIterator it(this->_base_pointer++);
        return it;
    }

    myIterator &myIterator::operator--(void) {
        this->_base_pointer--;
        return *this;
    }

    myIterator myIterator::operator--(int) {
        myIterator it(this->_base_pointer--);
        return it;
    }

    myIterator &myIterator::operator-=(int rVal) {
        this->_base_pointer -= rVal;
        return *this;
    }

    myIterator &myIterator::operator+=(int rVal) {
        this->_base_pointer += rVal;
        return *this;
    }

    int        myIterator::operator-(const myIterator& rVal) const {
        return this->_base_pointer - rVal._base_pointer;
    }

    myIterator myIterator::operator-(int rVal) {
        return myIterator(this->_base_pointer - rVal);
    }

    myIterator myIterator::operator+(int rVal) {
        return myIterator(this->_base_pointer + rVal);
    }

    bool myIterator::operator==(const myIterator& rVal) const {
        return this->_base_pointer == rVal._base_pointer;
    }

    bool myIterator::operator!=(const myIterator& rVal) const {
        return this->_base_pointer != rVal._base_pointer;
    }

    bool myIterator::operator>(const myIterator& rVal) const {
        return this->_base_pointer > rVal._base_pointer;
    }

    bool myIterator::operator>=(const myIterator& rVal) const {
        return this->_base_pointer >= rVal._base_pointer;
    }

    bool myIterator::operator<(const myIterator& rVal) const {
        return this->_base_pointer < rVal._base_pointer;
    }

    bool myIterator::operator<=(const myIterator& rVal) const {
        return this->_base_pointer <= rVal._base_pointer;
    }

    virtual T& myIterator::operator*() {
        return *this->_base_pointer;
    }

    virtual T *myIterator::operator->() {
        return this->_base_pointer;
    }

    virtual T& myIterator::operator[] (int x) {
        return *(this->_base_pointer + x);
    }    


}