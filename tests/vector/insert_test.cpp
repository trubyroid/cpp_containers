#include <iostream>

// #include <vector>
// namespace ft = std;

#include "../../includes/vector/vector.hpp"

int main() {
    ft::vector<int> vec(3,5);
    ft::vector<int>::iterator it = vec.begin();
    std::cout << "SIZE: " << vec.size() << std::endl;
    std::cout << "CAPACITY: " << vec.capacity() << std::endl;

    it++;
    vec.insert(it, 7);
    std::cout << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i);
    }
    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << vec.size() << std::endl;
    std::cout << "CAPACITY: " << vec.capacity() << std::endl;


}