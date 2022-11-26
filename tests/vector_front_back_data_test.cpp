#include <iostream>
#include <vector>
#include "../../includes/vector/vector.hpp"

int main() {
    std::vector<int> vec(3,5);
    ft::vector<int> my_vec(3,6);

    std::cout << vec.front() << std::endl;
    std::cout << my_vec.front() << std::endl;

    vec.resize(5,7);
    my_vec.resize(5,8);

    std::cout << vec.back() << std::endl;
    std::cout << my_vec.back() << std::endl;

    std::cout << vec.data() << std::endl;
    std::cout << my_vec.data() << std::endl;
}