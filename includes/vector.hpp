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
			value_type												*_base_array;
			allocator_type											_allocator;

			
        public:
            explicit vector();
			// vector(size_type size, value_type val = value_type());
			~vector();

			// void			doublingCapacity();
			// void			push_back(const value_type &val);
			void			print_test();
    };
}

# include "../srcs/vector.tpp"

#endif