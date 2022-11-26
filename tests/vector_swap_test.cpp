#include <iostream>
#include <vector>
#include "../../includes/vector/vector.hpp"

int main() {
    // std::vector<int>    vec(3,7);
    // std::vector<int>    vec1(5,8);
    ft::vector<int>    vec(3,7);
    ft::vector<int>    vec1(5,8);

    for (int i = 0; i < vec.size();i++) {
        std::cout << vec.at(i);
    }

    std::cout << std::endl;
    vec.swap(vec1);

    for (int i = 0; i < vec.size();i++) {
        std::cout << vec.at(i);
    }
}