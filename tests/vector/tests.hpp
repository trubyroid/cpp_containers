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

#include "src/constructors.tpp"
#include "src/operators.tpp"
#include "src/capacity.tpp"
#include "src/elements.tpp"
#include "src/iterators.tpp"
#include "src/modifiers.tpp"


#endif