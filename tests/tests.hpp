#ifndef TESTS_HPP
# define TESTS_HPP

#include "../includes/vector/vector.hpp"
#include "../includes/map/map.hpp"
#include "../includes/utils/utils.hpp"

#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <iostream>
#include <assert.h>

# define COLOUR_DEFAULT "\33[0m"
# define COLOUR_GREEN "\33[32m"
# define COLOUR_RED "\33[1;31m"
# define COLOUR_YELLOW "\33[33m"
# define COLOUR_BLUE "\33[1;34m"
# define COLOUR_PURPLE "\33[35m"

#include "test_utils.tpp"

#include "vector/src/constructors.tpp"
#include "vector/src/operators.tpp"
#include "vector/src/capacity.tpp"
#include "vector/src/elements.tpp"
#include "vector/src/iterators.tpp"
#include "vector/src/modifiers.tpp"

#include "map/src/constructors.tpp"
#include "map/src/iterators.tpp"
#include "map/src/capacity.tpp"
#include "map/src/modifiers.tpp"
#include "map/src/lookup.tpp"
#include "map/src/observers.tpp"


#endif