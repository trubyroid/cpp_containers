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
            typedef ft::less<Key>                                         		        key_compare;
            typedef std::allocator<ft::pair<const Key, T> >                             allocator_type;
            typedef T                                               			        mapped_type;
            
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

			explicit map(const key_compare& comp = key_compare(),
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

            bool empty() const              { return _size == 0; }
            size_type size() const;
            
            size_type       max_size() const
            {
                if (sizeof(value_type) == 1)
                    return static_cast<size_type>(pow(2.0, 64.0) / 2.0) - 1;
                return static_cast<size_type>(pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1;
            }


            ft::pair<iterator,bool> insert (const value_type& val)
            {
                Node* elemIsPresent = searchNode(_root, val.first);
                if (elemIsPresent)
                    return ft::pair<iterator, bool>(iterator(elemIsPresent, _lastElem, _comp), false);

                ++_size;
                return ft::pair<iterator, bool>(iterator(insertNode(_root, val), _lastElem, _comp), true);
            }

            iterator insert (iterator position, const value_type& val)
            {   

                if (position->first > val.first)
                {
                    iterator prev(position);
                    --prev;
                    while (prev != end() && prev->first >= val.first)
                    {
                        --position;
                        --prev;
                    }
                }

                else if (position->first < val.first)
                {
                    iterator next(position);
                    ++next;
                    while (next != end() && next->first <= val.first)
                    {
                        ++position;
                        ++next;
                    }
                }

                if (position != end() && val.first == position->first)
                    return position;

                ++_size;
                return iterator(insertNode(position.getNode(), val), _lastElem, _comp);
            }
 
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
            {
                while (first != last)
                    insert(*first++);
            }

            void erase (iterator position)
            {
                deleteNode(position.getNode(), position->first);
                --_size;
            }

            size_type erase (const key_type& k)
            {
                size_type ret = deleteNode(_root, k);
                _size -= ret;
                return ret;
            }

            void erase (iterator first, iterator last)
            {
                while (first != last)
                {
                    iterator tmp(first);
                    ++first;
                    erase(tmp);
                }
            }

            void swap (map& x)
            {
                swap(_root, x._root);
                swap(_lastElem, x._lastElem);
                swap(_size, x._size);
                swap(_comp, x._comp);
                swap(_allocPair, x._allocPair);
                swap(_allocNode, x._allocNode);
            }

            void clear()        { erase(begin(), end()); }

            key_compare key_comp() const        { return _comp; }

            value_compare value_comp() const    { return value_compare(_comp); }

            iterator find(const key_type& k)
            {
                Node* tmp = searchNode(_root, k);

                if (tmp)
                    return iterator(tmp, _lastElem, _comp);
                
                return end();
            }

            const_iterator find(const key_type& k) const
            {
                Node* tmp = searchNode(_root, k);

                if (tmp)
                    return const_iterator(tmp, _lastElem, _comp);
                
                return end();
            }

            size_type count (const key_type& k) const
            {
                Node* tmp = searchNode(_root, k);
                
                return tmp ? true: false;
            }

            iterator lower_bound(const key_type& k)
            {
                iterator it = begin();

                for (; it != end(); ++it)
                    if (!_comp(it->first, k))
                        break;
                
                return it;  
            }
            
            const_iterator lower_bound(const key_type& k) const
            {
                const_iterator it = begin();

                for (; it != end(); ++it)
                    if (!_comp(it->first, k))
                        break;
                
                return it;  
            }

            iterator upper_bound(const key_type& k)
            {
                iterator it = begin();

                for (; it != end(); ++it)
                    if (_comp(k, it->first))
                        break;
                
                return it;  
            }

            const_iterator upper_bound(const key_type& k) const
            {
                const_iterator it = begin();

                for (; it != end(); ++it)
                    if (_comp(k, it->first))
                        break;
                
                return it;  
            }

            pair<iterator,iterator> equal_range(const key_type& k)
            {
                iterator it = upper_bound(k);

                if (it != begin())
                {
                    --it;

                    if (_comp(it->first, k) || _comp(k, it->first))
                        ++it;
                }

                iterator next(it);
                if (it != end())
                    ++next;
                
                return make_pair<iterator, iterator>(it, next);
            }

            pair<const_iterator,const_iterator> equal_range(const key_type& k) const
            {
                const_iterator it = upper_bound(k);

                if (it != begin())
                {
                    --it;

                    if (_comp(it->first, k) || _comp(k, it->first))
                        ++it;
                }

                const_iterator next(it);
                if (it != end())
                    ++next;
                
                return make_pair<const_iterator, const_iterator>(it, next);
            }
            
        private:

            template <typename U>
            void swap(U& a, U& b)
            {
                U tmp = a;
                a = b;
                b = tmp;
            }

            template <class T1,class T2>
            pair<T1,T2> make_pair(T1 x, T2 y) const
            {
                return pair<T1,T2>(x,y);
            }


            Node* createNode(const value_type& pair)
            {
                Node* newNode = _allocNode.allocate(1);

                _allocPair.construct(&newNode->content, pair);
                newNode->parent = 0;
                newNode->left = 0;
                newNode->right = 0;

                return newNode;
            }

            void deallocateNode(Node* del)
            {
                _allocPair.destroy(&del->content);
                _allocNode.deallocate(del, 1);
            }

            int heightTree(Node *root, int height)
            {
                if (!root || root == _lastElem)
                    return height - 1;

                int leftHeight = heightTree(root->left, height + 1);
                int rightHeight = heightTree(root->right, height + 1);

                return leftHeight > rightHeight ? leftHeight : rightHeight;
            }

            Node* searchNode(Node* root, key_type key) const
            {
                if (!root || root == _lastElem)
                    return 0;
                
                if (!_comp(root->content.first, key) && !_comp(key, root->content.first))
                    return root;
                
                if (root->content.first > key && root->left && root->left != _lastElem)
                    return searchNode(root->left, key);
                else if (root->content.first < key && root->right && root->right != _lastElem)
                    return searchNode(root->right, key);

                return 0;
            }

            Node* searchMaxNode(Node *root) const
            {
                if (root->right && root->right != _lastElem)
                    return searchMaxNode(root->right);
                return root;
            }

            Node* searchMinNode(Node *root) const
            {
                if (root->left && root->left != _lastElem)
                    return searchMinNode(root->left);
                return root;
            }

            Node* insertNode(Node* insertPos, const value_type& pair)
            {
                if (_root == _lastElem)
                {
                    _root = createNode(pair);

                    
                    _root->left = _lastElem;
                    _root->right = _lastElem;
                    _lastElem->left = _root;
                    _lastElem->right = _root;

                    return _root;
                }

                if (insertPos->content.first == pair.first)
                    return 0;

                if (insertPos->content.first > pair.first && 
                        insertPos->left && insertPos->left != _lastElem)
                    return insertNode(insertPos->left, pair);
                else if (insertPos->content.first < pair.first && 
                        insertPos->right && insertPos->right != _lastElem)
                    return insertNode(insertPos->right, pair);

                Node *newNode = createNode(pair);

                if (insertPos->content.first > newNode->content.first && !insertPos->left)
                    insertPos->left = newNode;
                else if (insertPos->content.first < newNode->content.first && !insertPos->right)
                    insertPos->right = newNode;

                else if (insertPos->left && insertPos->content.first > newNode->content.first)
                {
                    newNode->left = _lastElem;
                    _lastElem->right = newNode;
                    insertPos->left = newNode;
                }
                else if (insertPos->right && insertPos->content.first < newNode->content.first)
                {
                    newNode->right = _lastElem;
                    _lastElem->left = newNode;
                    insertPos->right = newNode;
                }
                    
                newNode->parent = insertPos;

                balanceTheTree(&_root, newNode);

                return newNode;
            }

            bool deleteNode(Node* deletePos, key_type key)
            {
                Node* balanceNode = 0;
                
                Node* del = searchNode(deletePos, key);

                if (!del)
                    return false;
                
                if (!del->parent)
                {
                    if (del->left == _lastElem && del->right == _lastElem)
                    {
                        _root = _lastElem;
                        _lastElem->left = _lastElem;
                        _lastElem->right = _lastElem;
                    }

                    else if (del->left && del->right == _lastElem)
                    {
                        balanceNode = del->parent;
                        _root = del->left;
                        del->left->parent = 0;

                        _lastElem->left = del->left;
                        del->left->right = _lastElem;
                    }
                    else if (del->left == _lastElem && del->right)
                    {
                        balanceNode = del->parent;
                        _root = del->right;
                        del->right->parent = 0;

                        _lastElem->right = del->right;
                        del->right->left = _lastElem;
                    }

                    else
                    {
                        Node* maxNode = searchMaxNode(del->left);

                        _allocPair.destroy(&del->content);
                        _allocPair.construct(&del->content, maxNode->content);
                        
                        return deleteNode(del->left, maxNode->content.first);
                    }
                }


                else if ((!del->left || del->left == _lastElem) && (!del->right || del->right == _lastElem))
                {
                    balanceNode = del->parent;

                    Node* linkToParent = 0;
                    if (del->left == _lastElem || del->right == _lastElem)
                    {
                        linkToParent = _lastElem;
                        del->content.first <= del->parent->content.first ?
                            _lastElem->right = del->parent : _lastElem->left = del->parent;
                    }
                        
                    del->content.first <= del->parent->content.first ?
                        del->parent->left = linkToParent : del->parent->right = linkToParent;
                }

                else if ((del->left && del->left != _lastElem) && (!del->right || del->right == _lastElem))
                {
                    balanceNode = del->parent;

                    del->content.first <= del->parent->content.first ?
                            del->parent->left = del->left : del->parent->right = del->left;
                    del->left->parent = del->parent;

                    if (del->right == _lastElem)
                    {
                        _lastElem->left = del->left;
                        del->left->right = _lastElem;
                    }
                }
                else if ((!del->left || del->left == _lastElem) && del->right && del->right != _lastElem)
                {
                    balanceNode = del->parent;

                    del->content.first <= del->parent->content.first ?
                            del->parent->left = del->right : del->parent->right = del->right;
                    del->right->parent = del->parent;
                    
                    if (del->left == _lastElem)
                    {
                        _lastElem->right = del->right;
                        del->right->left = _lastElem;
                    }
                }

                else
                {
                    Node* maxNode = searchMaxNode(del->left);

                    _allocPair.destroy(&del->content);
                    _allocPair.construct(&del->content, maxNode->content);
                    
                    return deleteNode(del->left, maxNode->content.first);
                }

                balanceTheTree(&_root, balanceNode);

                deallocateNode(del);
                return true;
            }

            int balanceOfSubtrees(Node* node)
            {
                if (!node)
                    return 0;
                return heightTree(node->left, 1) - heightTree(node->right, 1);
            }

            void rotateRight(Node** root, Node* nodeGoingDown)
            {

                Node* nodeGoingUp = nodeGoingDown->left;
                
                nodeGoingDown->left = nodeGoingUp->right;
                
                if (nodeGoingUp->right)
                    nodeGoingUp->right->parent = nodeGoingDown;
                
                nodeGoingUp->right = nodeGoingDown;
                
                nodeGoingUp->parent = nodeGoingDown->parent;
                
                if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
                    nodeGoingDown->parent->left = nodeGoingUp;
                else if (nodeGoingDown->parent)
                    nodeGoingDown->parent->right = nodeGoingUp;
                
                nodeGoingDown->parent = nodeGoingUp;

                if (!nodeGoingUp->parent)
                    *root = nodeGoingUp;
            }

            void rotateLeft(Node** root, Node* nodeGoingDown)
            {

                Node* nodeGoingUp = nodeGoingDown->right;
                
                nodeGoingDown->right = nodeGoingUp->left;

                if (nodeGoingUp->left)
                    nodeGoingUp->left->parent = nodeGoingDown;
                
                nodeGoingUp->left = nodeGoingDown;
                
                nodeGoingUp->parent = nodeGoingDown->parent;
                
                if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
                    nodeGoingDown->parent->left = nodeGoingUp;
                else if (nodeGoingDown->parent)
                    nodeGoingDown->parent->right = nodeGoingUp;

                nodeGoingDown->parent = nodeGoingUp;

                if (!nodeGoingUp->parent)
                    *root = nodeGoingUp;
            }

            void balanceTheTree(Node** root, Node* node)
            {        
                while (node)
                {
                    int balance;
                    
                    if ((balance = balanceOfSubtrees(node)) < -1 && balanceOfSubtrees(node->right) < 0)
                        rotateLeft(root, node);

                    else if (balance < -1 && balanceOfSubtrees(node->right) >= 0)
                    {
                        rotateRight(root, node->right);
                        rotateLeft(root, node);
                    }
                    
                    else if (balance > 1 && balanceOfSubtrees(node->left) > 0)
                        rotateRight(root, node);

                    else if (balance > 1 && balanceOfSubtrees(node->left) <= 0)
                    {
                        rotateLeft(root, node->left);
                        rotateRight(root, node);
                    }
                    node = node->parent;
                }
            }      
    };
}

#include "../../srcs/map/map.tpp"

#endif
