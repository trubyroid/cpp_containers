#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{

    template<typename value_type>
    class myReverseIterator : public myIterator<value_type> {
        public:
        // --------------------- Construct/Copy/Destruct --------------------- //
            myReverseIterator();
	        myReverseIterator(value_type *val);
	        myReverseIterator(const myReverseIterator& copy);
	        myReverseIterator(const myIterator<value_type>& copy);
	        ~myReverseIterator();


        // --------------------- Operators ----------------------------------- //

	        myReverseIterator &operator=(const myReverseIterator& op);
            myReverseIterator &operator++(void);
            myReverseIterator operator++(int);
            myReverseIterator &operator--(void);
            myReverseIterator operator--(int);
            myReverseIterator &operator-=(int rVal);
            myReverseIterator &operator+=(int rVal);
            int        operator-(const myReverseIterator& rVal) const;
            myReverseIterator operator-(int rVal);
            myReverseIterator operator+(int rVal);
            bool operator==(const myReverseIterator& rVal) const;
            bool operator!=(const myReverseIterator& rVal) const;
            bool operator>(const myReverseIterator& rVal) const;
            bool operator>=(const myReverseIterator& rVal) const;
            bool operator<(const myReverseIterator& rVal) const;
            bool operator<=(const myReverseIterator& rVal) const;
            virtual value_type& operator*();
            virtual value_type *operator->();
            virtual value_type& operator[] (int x);
	        myIterator<value_type> base() const;
    };


}

# include "../../srcs/vector/reverse_iterator.tpp"

#endif