#include <iostream>
#include <vector>

int main () {
    std::cout << "BASE VECTOR:" << std::endl << std::endl;
    std::vector<int>                 vec(1,5);

    vec.resize(2,6);
    vec.resize(3,7);
    vec.resize(4,8);

    std::vector<int>::iterator       begin = vec.begin();
    std::vector<int>::iterator       end = vec.end();

    while (begin != end) {
        std::cout << *begin;
        begin++;
    }

    std::cout << std::endl;

    std::vector<int>::reverse_iterator       rbegin = vec.rbegin();
    std::vector<int>::reverse_iterator       rend = vec.rend();

    while (rbegin != rend) {
        std::cout << *rbegin;
        rbegin++;
    }
}

// #include "../../includes/vector/vector.hpp"

// int main () {
//     std::cout << "MY VECTOR:" << std::endl << std::endl;
//     ft::vector<int>                 vec(1,5);

//     vec.resize(2,6);
//     vec.resize(3,7);
//     vec.resize(4,8);

//     ft::vector<int>::iterator       begin = vec.begin();
//     ft::vector<int>::iterator       end = vec.end();

//     while (begin != end) {
//         std::cout << *begin;
//         begin++;
//     }

//     std::cout << std::endl;

//     ft::vector<int>::reverse_iterator       rbegin = vec.rbegin();
//     ft::vector<int>::reverse_iterator       rend = vec.rend();

//     while (rbegin != rend) {
//         std::cout << *rbegin;
//         rbegin++;
//     }
// }