#include <iostream>

// #include <vector>
// namespace ft = std;

#include "../../includes/vector/vector.hpp"

int main() {
    {
        std::cout << "~~~~~~~~~~~~First insert\n";

        ft::vector<int> vec(1,5);
        vec.resize(2,4);
        vec.resize(3,3);
        ft::vector<int>::iterator it = vec.begin();
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;

        // it++;
        ft::vector<int>::iterator it_2 = vec.insert(it, 7);
        std::cout << std::endl;
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << std::endl;

        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl << std::endl;

        ft::vector<int>::iterator it_4 = vec.begin();

        ft::vector<int>::iterator it_3 = vec.insert(it_4, 8);
        std::cout << std::endl << *it_3 << std::endl;

        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;     
    }

    {
        std::cout << "~~~~~~~~~~~~Second insert\n";

        ft::vector<int> vec(1,5);
        vec.resize(2,4);
        vec.resize(3,3);
        vec.reserve(15);
        ft::vector<int>::iterator it = vec.begin();
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;

        it++;
        ft::vector<int>::iterator it_2 = vec.insert(it, 0, 7);
        std::cout << std::endl;
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;

        ft::vector<int>::iterator it_3 = vec.insert(it_2, 3, 7);
        std::cout << std::endl;
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;
    }
}