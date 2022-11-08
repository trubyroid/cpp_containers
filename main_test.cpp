// #include "./includes/vector.hpp"
#include <iostream>
#include <vector>
using namespace std;

// int main() {
//     ft::vector<int> vec(3, 5);
//     int *point;
//     point = vec._base_array;
//     while (*point != 0) {
//         std::cout << *point << std::endl;
//         point++;
//     }
//     return (0);
// }


int main() {
    vector<int>                 vec(3,5);

    {
        vector<int>::iterator       begin = vec.begin();
        vector<int>::iterator       end = vec.end();
        while (begin != end) {
            cout << *begin;
            begin++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }

    {     
        vec.resize(8);
        vector<int>::iterator       begin = vec.begin();
        vector<int>::iterator       end = vec.end(); 
        cout << "RESIZE. One argument." << endl;
        while (begin != end) {
            cout << *begin;
            begin++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }

    {
        vec.resize(10, 4);
        vector<int>::iterator       begin = vec.begin();
        vector<int>::iterator       end = vec.end();
        cout << "RESIZE. Two argument." << endl;
        while (begin != end) {
            cout << *begin;
            begin++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }
}