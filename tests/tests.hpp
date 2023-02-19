#ifndef TESTS_HPP
# define TESTS_HPP

#include "../includes/vector/vector.hpp"
#include "../includes/map/map.hpp"
#include "../includes/utils/utils.hpp"

#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <assert.h>

# define COLOUR_DEFAULT "\33[0m"
# define COLOUR_GREEN "\33[32m"
# define COLOUR_RED "\33[1;31m"
# define COLOUR_YELLOW "\33[33m"
# define COLOUR_BLUE "\33[1;34m"
# define COLOUR_PURPLE "\33[35m"

#include "test_utils.cpp"

#include "vector/src/constructors.cpp"
#include "vector/src/operators.cpp"
#include "vector/src/capacity.cpp"
#include "vector/src/elements.cpp"
#include "vector/src/iterators.cpp"
#include "vector/src/modifiers.cpp"

#include "map/src/constructors.cpp"


#endif