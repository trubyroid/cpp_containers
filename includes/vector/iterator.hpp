#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

namespace ft
{
    template	<class T>
			// class Category = std::random_access_iterator_tag,
			// class Distance = ptrdiff_t,
			// class Pointer = T*,
			// class Reference = T&>
    class myIterator {
        public:
            typedef T         value_type;
            // typedef Category  iterator_category;
            // typedef Distance  difference_type;
            // typedef Pointer   pointer;
            // typedef Reference reference;
        protected:
            T *_base_pointer;
        public:
            // --------------------- Construct/Copy/Destruct --------------------- //
            myIterator();
            myIterator(T *val);
            myIterator(const myIterator& copy);
            virtual ~myIterator();

            // --------------------- Operators ----------------------------------- //

            myIterator &operator=(const myIterator& op);
            myIterator &operator++(void);
            myIterator operator++(int);
            myIterator &operator--(void);
            myIterator operator--(int);
            myIterator &operator-=(int rVal);
            myIterator &operator+=(int rVal);
            int        operator-(const myIterator& rVal) const;
            myIterator operator-(int rVal);
            myIterator operator+(int rVal);
            bool operator==(const myIterator& rVal) const;
            bool operator!=(const myIterator& rVal) const;
            bool operator>(const myIterator& rVal) const;
            bool operator>=(const myIterator& rVal) const;
            bool operator<(const myIterator& rVal) const;
            bool operator<=(const myIterator& rVal) const;
            virtual T& operator*();
            virtual T *operator->();
            virtual T& operator[] (int x);
    };


}

# include "../../srcs/vector/iterator.tpp"

#endif