#ifndef TESTS_HPP
# define TESTS_HPP

#include "../../includes/vector/vector.hpp"
#include <vector>
#include "../../includes/utils/utils.hpp"
#include <iterator>
#include <iostream>
#include <assert.h>

# define COLOUR_DEFAULT "\33[0m"
# define COLOUR_GREEN "\33[32m"
# define COLOUR_RED "\33[1;31m"
# define COLOUR_YELLOW "\33[33m"
# define COLOUR_BLUE "\33[1;34m"
# define COLOUR_PURPLE "\33[35m"

void test_name(std::string name)
{
	std::cout << COLOUR_BLUE << name << COLOUR_RED << std::endl;
}

void test_capacity_size_values(ft::vector<int> &mine, std::vector<int> &original)
{
    // std::cout << COLOUR_PURPLE;
    // std::cout << original.capacity()                    << " o/ capacity /m " << mine.capacity() << "\n";
    // std::cout << original.size()                        << " o/   size   /m " << mine.size() << "\n";
    // std::cout << original.end() - original.begin()      << " o/ it  diff /m " << mine.end()-mine.begin()  << "\n";
    // std::cout << COLOUR_RED;
    // std::cout << std::endl;
	
    assert(original.capacity() == mine.capacity());
    assert(original.size() == mine.size());
	
	for (size_t i = 0; i < original.size(); i++)
        assert(original[i] == mine[i]);
}

#include "constructors.tpp"
#include "operators.tpp"
#include "capacity.tpp"
#include "elements.tpp"
#include "iterators.tpp"
#include "modifiers.tpp"


#endif