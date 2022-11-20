#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <stdexcept>
# include <limits>

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
        private:
            size_type												_size;
	        size_type												_capacity;
			allocator_type											_allocator;
        public:
			value_type												*_base_array;
// --------------------- Member functions --------------------- //		
            explicit vector();
			explicit vector(size_type size, const value_type& val = value_type());
			vector(const vector& copy);
			~vector();

			// template< class InputIt >
			// void assign( InputIt first, InputIt last,
			// 			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);
			void			assign(size_type count, const value_type& val);
			allocator_type	get_allocator() const;
// --------------------- Element Access ----------------------- //

// --------------------- Operators ---------------------------- //

			vector			&operator=(const vector& copy);
			bool			operator==(const vector& other);
			bool			operator!=(const vector& other);
			bool			operator<(const vector& other);
			bool			operator>(const vector& other);
			bool			operator<=(const vector& other);
			bool			operator>=(const vector& other);
			// reference		operator[](size_type pos);
			// const_reference	operator[](size_type pos) const;

// --------------------- Iterators ---------------------------- //

// --------------------- Capacity ----------------------------- //

			bool			empty() const;
			size_type		size() const;
			size_type		max_size() const;
			size_type		capacity() const;
			void			reserve(size_type new_cap);

// --------------------- Modifiers ---------------------------- //
			
			// void			push_back(const value_type &val);
			void			resize(size_type cout, const value_type& val);


			// void			doublingCapacity();
    };

// --------------------- Non-member functions ----------------- //

}

# include "../srcs/vector.tpp"

#endif