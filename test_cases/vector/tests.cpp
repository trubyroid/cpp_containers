#include "tests.hpp"

int main() {
    std::cout << COLOUR_GREEN << "Test started." << std::endl;
    constructors();
    std::cout << COLOUR_GREEN << "Constructors test passed successfully." << std::endl;
    operators();
    std::cout << COLOUR_GREEN << "Operators test passed successfully." << std::endl;
    capacity();
    std::cout << COLOUR_GREEN << "Capacity methods test passed successfully." << std::endl;
    elements();
    std::cout << COLOUR_GREEN << "Elements access methods test passed successfully." << std::endl;
    iterators();
    std::cout << COLOUR_GREEN << "Iterators test passed successfully." << std::endl;
    modifiers();
    std::cout << COLOUR_GREEN << "Modifiers test passed successfully." << std::endl << std::endl;
    
    std::cout << COLOUR_GREEN << "All tests passed successfully." << std::endl;
}