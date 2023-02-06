#ifndef UTILS_HPP
#define UTILS_HPP

# include <type_traits>
# include <stdio.h>
# include "../vector/iterator.hpp"
# include "../vector/reverse_iterator.hpp"

namespace ft {

/*---Iterator-Traits---*/

template<class MyIterator>
struct iterator_traits {
    typedef typename MyIterator::difference_type difference_type;
    typedef typename MyIterator::value_type value_type;
    typedef typename MyIterator::pointer pointer;
    typedef typename MyIterator::reference reference;
    typedef typename MyIterator::iterator_category iterator_category;
};
template<class T>
struct iterator_traits<T*> {
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category;
};

/*---Enable-If---*/

template< bool B, class T = void > struct enable_if;
template<class T>
struct enable_if<true, T> {
	typedef T type;
};


/*---Is-Integral---*/

struct true_type {
    static const bool	value = true;
};
struct false_type {
    static const bool	value = false;
};
template <class _Tp> struct is_integral				: public false_type {};
template <>			struct is_integral<bool>		: public true_type {};
template <>			struct is_integral<char>		: public true_type {};
template <>			struct is_integral<char16_t>	: public true_type {};
template <>			struct is_integral<char32_t>	: public true_type {};
template <>			struct is_integral<wchar_t>		: public true_type {};
template <>			struct is_integral<short>		: public true_type {};
template <>			struct is_integral<int>			: public true_type {};
template <>			struct is_integral<long>		: public true_type {};
template <>			struct is_integral<long long>	: public true_type {};
template <>			struct is_integral<size_t>		: public true_type {};

/*---Less/Compare---*/

template< class InputIt1, class InputIt2 >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2 ) {
	for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

/*---Is-Iterator---*/

// template <class _Tp>		struct is_iterator								: public false_type {};
// template <class _T>			struct is_iterator< myIterator<_T> >			: public true_type {};
// template <class _T>			struct is_iterator< myReverseIterator<_T> >		: public true_type {};

/*---Pair---*/

template <class T1, class T2>
struct pair {
public:
	typedef T1 first_type;
	typedef T2 second_type;

	first_type	first;
	second_type	second;
public:
	pair() : first(), second() {}
	pair(const first_type& x, const second_type& y) : first(x), second(y) {}
	template<class U, class V> pair(const pair<U, V>& copy) : first(copy.first), second(copy.second) {};
	~pair() {}

	pair&	operator=(const pair<first_type, second_type>& op) {
		first = op.first;
		second = op.second;
		return (*this);
	}

	bool operator==(const pair<first_type, second_type>& op) const {
		if (first == op.first && second == op.second)
			return (true);
		return (false);
	}
	bool operator<(const pair<first_type, second_type>& op) const {
		if (first < op.first)
			return (true);
		if (first == op.first && second < op.second)
			return (true);
		return (false);
	}
	bool operator>(const pair<first_type, second_type>& op) const {
		if (first > op.first)
			return (true);
		if (first == op.first && second > op.second)
			return (true);
		return (false);
	}
	bool operator!=(const pair<first_type, second_type>& op) const {
		return (!operator==(op));
	}
	bool operator<=(const pair<first_type, second_type>& op) const {
		return (!operator>(op));
	}
	bool operator>=(const pair<first_type, second_type>& op) const {
		return (!operator<(op));
	}
};

/*---Make-Pair---*/

template< class T1, class T2 >
ft::pair<T1,T2> make_pair( T1 first, T2 second ) {
	return (ft::pair<T1,T2>(first, second));
}

template <class T>
struct less {
	bool operator() (const T& x, const T& y) const {
		return x < y;
	}
};

}

#endif