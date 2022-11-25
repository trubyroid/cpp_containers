#include <iostream>
#include <vector>
// #include "../includes/vector.hpp"

int main() {
    std::vector<int> vec(3,5);
    const std::vector<int>::iterator it = vec.begin();

    // it++;
    vec.insert(it, 7);
    std::cout << vec[0] << std::endl;


}