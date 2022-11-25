#include <iostream>
#include <vector>
#include "../includes/vector.hpp"
// namespace ft = std;

int main() {
    ft::vector<int> vector;
    // std::vector<int> vector;

    vector.push_back(1);
    vector.push_back(3);
    vector.push_back(5);
    vector.push_back(8);
    vector.push_back(1);
    vector.push_back(1);
    vector.push_back(1);
    vector.push_back(6);
    vector.push_back(6);
    
    for (int i = 0; i < vector.size();i++) {
        std::cout << vector.at(i);
    }
    
    std::cout << std::endl << "size:" << vector.size();
    std::cout << std::endl << "capacity:" << vector.capacity() << std::endl << std::endl;

    vector.pop_back();
    vector.pop_back();

    for (int i = 0; i < vector.size();i++) {
        std::cout << vector.at(i);
    }

    std::cout << std::endl << "size:" << vector.size();
    std::cout << std::endl << "capacity:" << vector.capacity() << std::endl;

    return 0;
}