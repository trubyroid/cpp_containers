#ifndef REV_MAP_ITERATOR_HPP
# define REV_MAP_ITERATOR_HPP

#include "map_utils.hpp"
# include "iterator.hpp"

namespace ft
{
    template<class Key, class T, class Compare, typename Node, bool B>
    class rev_map_iterator
    {   
        public:
        
            typedef Key                                                                 key_type;
            typedef Compare                                                             key_compare;
            typedef T                                                                   mapped_type;
            
            typedef ft::pair<const key_type, mapped_type>                               value_type;
            typedef long int                                                            difference_type;
            typedef size_t                                                              size_type;
            
            typedef std::bidirectional_iterator_tag                                     iterator_category;
            typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
            typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
            typedef Node*                                                               nodePtr;
            
        private:

            nodePtr         _node;
            nodePtr         _lastElem;
            key_compare     _comp;

        public:

// --------------------- Member functions --------------------- //

            rev_map_iterator(nodePtr node = 0, nodePtr lastElem = 0,
                            const key_compare& comp = key_compare());

            rev_map_iterator(const rev_map_iterator<Key, T, Compare, Node, false>& copy);
            ~rev_map_iterator();

// --------------------- Operators ---------------------------- //

            rev_map_iterator&   operator=(const rev_map_iterator& assign);
            reference           operator*() const;
            pointer             operator->() const;

            bool                operator==(const rev_map_iterator& it) const;
            bool                operator!=(const rev_map_iterator& it) const;

            rev_map_iterator&   operator++();
            rev_map_iterator    operator++(int);
            rev_map_iterator&   operator--();
            rev_map_iterator    operator--(int);

// --------------------- Getters ------------------------------ //

            nodePtr             getNode() const;
            nodePtr             getLastElem() const;
            key_compare         getCompare() const;

// --------------------- Searchers ---------------------------- //
        private:

            nodePtr             searchMaxNode(nodePtr root);
            nodePtr             searchMinNode(nodePtr root);

    };

}

#include "../../srcs/map/reverse_iterator.tpp"

#endif