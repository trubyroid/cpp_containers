#include <iostream>
#include <vector>
#include "../includes/vector.hpp"

int main() {
    std::vector<int> vec(3,5);
    ft::vector<int> my_vec(3,5);

    std::cout << vec.at(2) << std::endl;
    std::cout << my_vec.at(2) << std::endl;

    std::cout << vec[0] << std::endl;
    std::cout << my_vec[0] << std::endl;
}