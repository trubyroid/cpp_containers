#include "../tests.hpp"

int main() {
    std::cout << COLOUR_GREEN << std::endl << "Map test started." << std::endl;
    map_members_n_elements();
    std::cout << COLOUR_GREEN << "Member functions test passed successfully." << std::endl;
    std::cout << COLOUR_GREEN << "Elements access test passed successfully." << std::endl;
    map_iterators();
    std::cout << COLOUR_GREEN << "Iterators test passed successfully." << std::endl;
    map_capacity();
    std::cout << COLOUR_GREEN << "Capacity methods test passed successfully." << std::endl;
    map_modifiers();
    std::cout << COLOUR_GREEN << "Modifiers test passed successfully." << std::endl;
    map_lookup();
    std::cout << COLOUR_GREEN << "Lookup test passed successfully." << std::endl;
    map_observers();
    std::cout << COLOUR_GREEN << "Observers test passed successfully." << std::endl;
    std::cout << COLOUR_DEFAULT << std::endl;
}
