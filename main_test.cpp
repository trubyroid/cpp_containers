#include "./includes/vector.hpp"

int main() {
    ft::vector<int> vec(3, 5);
    int *point;
    point = vec._base_array;
    while (*point != 0) {
        std::cout << *point << std::endl;
        point++;
    }
    return (0);
}