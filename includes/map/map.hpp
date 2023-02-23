#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <cmath>

# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "../utils/utils.hpp"

namespace ft
{
    template < class Key, class T >
    class map
    {
        private:        

            struct Node
            {
                ft::pair<const Key, T>  content;
                Node*                   parent;
                Node*                   left;
                Node*                   right;
            };
            
        public:

            typedef Key                                             			        key_type;
            typedef T                                               			        mapped_type;
            typedef ft::less<Key>                                         		        key_compare;
            typedef std::allocator<ft::pair<const Key, T> >                             allocator_type;
            
            typedef ft::pair<const key_type, mapped_type>           			        value_type;
            typedef long int                                        			        difference_type;
            typedef size_t                                          			        size_type;

            typedef T&                                              			        reference;
            typedef const T&                                        			        const_reference;
            typedef T*                                              			        pointer;
            typedef const T*                                        			        const_pointer;
            
            typedef typename ft::map_iterator<Key, T, ft::less<Key> , Node, false>      iterator;
            typedef typename ft::map_iterator<Key, T, ft::less<Key> , Node, true>       const_iterator;

            typedef typename ft::rev_map_iterator<Key, T, ft::less<Key> , Node, false>  reverse_iterator;
            typedef typename ft::rev_map_iterator<Key, T, ft::less<Key> , Node, true>   const_reverse_iterator;

            class value_compare
            {
                friend class map;
                
                protected:
                
                    key_compare comp;
                    
                    value_compare(ft::less<Key>  c) : comp(c) {}

                public:
                
                    typedef bool        result_type;
                    typedef value_type  first_argument_type;
                    typedef value_type  second_argument_type;

                    bool operator()(const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
            
        private:

            Node*                   	_root;
            Node*                   	_lastElem;
            size_type               	_size;
            allocator_type          	_allocPair;
            key_compare             	_comp;
            std::allocator<Node>     	_allocNode;
            
        public:

// --------------------- Member functions --------------------- //

			map(const key_compare& comp = key_compare(),
                        const allocator_type& alloc = allocator_type());

            template<class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type(), 
                typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0);

            map(const map& copy);
            ~map();

            map&                                    operator=(const map& copy);
            allocator_type                          get_allocator() const;

// --------------------- Element Access ----------------------- //

            mapped_type&                            operator[](const key_type& key);
            mapped_type&                            at(const key_type& key);
            const mapped_type&                      at(const key_type& key) const;

// --------------------- Iterators ---------------------------- //

            iterator                                begin();
            iterator                                end();
            reverse_iterator                        rbegin();
            reverse_iterator                        rend();
            
            const_iterator                          begin() const;
            const_iterator                          end() const;
            const_reverse_iterator                  rbegin() const;
            const_reverse_iterator                  rend() const;

// --------------------- Capacity ----------------------------- //

            bool                                    empty() const;
            size_type                               size() const;
            size_type                               max_size() const;

// --------------------- Modifiers ---------------------------- //

            void                                    clear();
            ft::pair<iterator,bool>                 insert(const value_type& val);
            iterator                                insert(iterator position, const value_type& val);
 
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0);

            void                                    erase(iterator position);
            size_type                               erase(const key_type& k);
            void                                    erase(iterator first, iterator last);
            void                                    swap(map& x);

// --------------------- Lookup ------------------------------- //

            iterator                                find(const key_type& k);
            const_iterator                          find(const key_type& k) const;
            size_type                               count(const key_type& k) const;
            iterator                                lower_bound(const key_type& k);
            const_iterator                          lower_bound(const key_type& k) const;
            iterator                                upper_bound(const key_type& k);
            const_iterator                          upper_bound(const key_type& k) const;
            pair<iterator,iterator>                 equal_range(const key_type& k);
            pair<const_iterator,const_iterator>     equal_range(const key_type& k) const;

// --------------------- Observers ---------------------------- //

            key_compare                             key_comp() const;
            value_compare                           value_comp() const;
            
// --------------------- Red-Black Tree ----------------------- //
        private:

            Node*                                   createNode(const value_type& pair);
            Node*                                   searchNode(Node* root, key_type key) const;
            Node*                                   searchMaxNode(Node *root) const;
            Node*                                   searchMinNode(Node *root) const;
            Node*                                   insertNode(Node* insertPos, const value_type& pair);

            bool                                    deleteNode(Node* deletePos, key_type key);
            void                                    deallocateNode(Node* del);
            int                                     heightTree(Node *root, int height);
            int                                     balanceOfSubtrees(Node* node);

            void                                    rotateRight(Node** root, Node* nodeGoingDown);
            void                                    rotateLeft(Node** root, Node* nodeGoingDown);
            void                                    balanceTheTree(Node** root, Node* node); 
            
    };

// --------------------- Non-member functions ----------------- //

    template <typename U>
    void swap(U& a, U& b)
    {
        U tmp = a;
        a = b;
        b = tmp;
    }

}

#include "../../srcs/map/map.tpp"
#include "../../srcs/map/red_black_tree.tpp"

#endif
