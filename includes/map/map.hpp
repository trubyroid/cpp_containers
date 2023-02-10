#ifndef MAP_HPP
# define MAP_HPP

# include "../utils/utils.hpp"

namespace ft {
    template <class Key, class T>
    class map {
        public:
            typedef Key														key_type;
		    typedef T														mapped_type;
		    typedef ft::pair<key_type, mapped_type>							value_type;
            typedef std::less<Key> 											key_compare;
		    typedef std::allocator<value_type> 								allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename allocator_type::size_type                      size_type;
            typedef typename allocator_type::difference_type                difference_type;
            // typedef myIteratorMap<value_type>                               iterator;
            // typedef myConstIteratorMap<value_type>                          const_iterator;
            // typedef myReverseIteratorMap<value_type>			            reverse_iterator;
            // typedef myConstReverseIteratorMap<value_type>    	            const_reverse_iterator;
    }
}

# endif