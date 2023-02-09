#include "tests.hpp"

int main() {
    std::cout << COLOUR_GREEN << "Test started." << std::endl;
    constructors();
    std::cout << COLOUR_GREEN << "Constructors tested." << std::endl;
    operators();
    std::cout << COLOUR_GREEN << "Operators tested." << std::endl;
    capacity_size();
    std::cout << COLOUR_GREEN << "Capacity- and size- methods tested." << std::endl;
    elements();
    std::cout << COLOUR_GREEN << "Elements methods tested." << std::endl;
    // test_iter();
    // test_mod();
}