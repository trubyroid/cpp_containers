#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <stdexcept>
# include <limits>

# include "iterator.hpp"
# include "reverse_iterator.hpp"
// # include "../utils/utils.hpp"

namespace ft
{
    template <class T>
	class vector{
        public:
	        typedef T value_type;
	        typedef std::allocator<T>								allocator_type;
	        typedef typename	allocator_type::size_type			size_type;
	        typedef typename	allocator_type::difference_type		difference_type;
	        typedef typename	allocator_type::reference			reference;
	        typedef typename	allocator_type::const_reference		const_reference;
	        typedef typename	allocator_type::pointer				pointer;
	        typedef typename	allocator_type::const_pointer		const_pointer;

			typedef myIterator<T>									iterator;
			typedef myIterator<const T>								const_iterator;
			typedef myReverseIterator<T>							reverse_iterator;
			typedef myReverseIterator<const T>						const_reverse_iterator;
        private:
            size_type												_size;
	        size_type												_capacity;
			allocator_type											_allocator;
        public:
			value_type												*_base_array;
// --------------------- Member functions --------------------- //		
            explicit vector();
			explicit vector(size_type size, const value_type& val = value_type());
			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last,
				// typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
			vector(const vector& copy);
			~vector();

			// template< class InputIt >
			// void assign( InputIt first, InputIt last,
			// 			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);
			void													assign(size_type count, const value_type& val);
			allocator_type											get_allocator() const;
// --------------------- Element Access ----------------------- //
			reference												at(size_type pos);
			reference												front();
			reference												back();

			const_reference											at(size_type pos) const;
			const_reference											front() const;
			const_reference											back() const;

			value_type											 	*data();
			const value_type										*data() const;

// --------------------- Operators ---------------------------- //

			vector													&operator=(const vector& copy);
			bool													operator==(const vector& other);
			bool													operator!=(const vector& other);
			bool													operator<(const vector& other);
			bool													operator>(const vector& other);
			bool													operator<=(const vector& other);
			bool													operator>=(const vector& other);
			reference												operator[](size_type pos); 
			const_reference											operator[](size_type pos) const;

// --------------------- Iterators ---------------------------- //

			iterator												begin();
			iterator												end();
			reverse_iterator										rbegin();
			reverse_iterator										rend();


			const_iterator											begin() const;
			const_iterator											end() const;
			const_reverse_iterator									rbegin() const;
			const_reverse_iterator									rend() const;

// --------------------- Capacity ----------------------------- //

			bool													empty() const;
			size_type												size() const;
			size_type												max_size() const;
			void													reserve(size_type new_cap);
			size_type												capacity() const;

// --------------------- Modifiers ---------------------------- //

			// iterator insert(const_iterator pos, const value_type& val);
			// void insert(const_iterator pos, size_type count, const value_type& value );
			// template <class InputIterator>
			// 	void insert(iterator position, InputIterator first, InputIterator last,
			// 		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
					
			// iterator												erase(iterator pos);
			// iterator												erase(iterator first, iterator last);
			void													clear();
			void													push_back(const value_type &val);
			void													pop_back();
			void													resize(size_type cout, const value_type& val);
			void													swap(vector& other);
    };

// --------------------- Non-member functions ----------------- //
template <class T>
void swap(vector<T>& x, vector<T>& y) {
	x.swap(y);
}


}

# include "../../srcs/vector/vector.tpp"

#endif