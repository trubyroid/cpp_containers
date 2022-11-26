// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     cout << "BASE VECTOR:" << endl << endl;
//     vector<int>                 vec(3,5);

//     {
//         vector<int>::iterator       begin = vec.begin();
//         vector<int>::iterator       end = vec.end();
//         while (begin != end) {
//             cout << *begin;
//             begin++;
//         }
//         cout << endl;
//         cout << "Size: " << vec.size() << endl;
//         cout << "Capacity: " << vec.capacity() << endl;
//         cout << endl << endl;
//     }

//     {     
//         vec.resize(5,2);
//         vector<int>::iterator       begin = vec.begin();
//         vector<int>::iterator       end = vec.end(); 
//         while (begin != end) {
//             cout << *begin;
//             begin++;
//         }
//         cout << endl;
//         cout << "Size: " << vec.size() << endl;
//         cout << "Capacity: " << vec.capacity() << endl;
//         cout << endl << endl;
//     }

//     {     
//         vec.resize(10,3);
//         vector<int>::iterator       begin = vec.begin();
//         vector<int>::iterator       end = vec.end(); 
//         while (begin != end) {
//             cout << *begin;
//             begin++;
//         }
//         cout << endl;
//         cout << "Size: " << vec.size() << endl;
//         cout << "Capacity: " << vec.capacity() << endl;
//         cout << endl << endl;
//     }

//     {
//         vec.resize(3,3);
//         vector<int>::iterator       begin = vec.begin();
//         vector<int>::iterator       end = vec.end();
//         while (begin != end) {
//             cout << *begin;
//             begin++;
//         }
//         cout << endl;
//         cout << "Size: " << vec.size() << endl;
//         cout << "Capacity: " << vec.capacity() << endl;
//         cout << endl << endl;
//     }

//     {
//         vec.resize(-21, 4);
//         vector<int>::iterator       begin = vec.begin();
//         vector<int>::iterator       end = vec.end();
//         while (begin != end) {
//             cout << *begin;
//             begin++;
//         }
//         cout << endl;
//         cout << "Size: " << vec.size() << endl;
//         cout << "Capacity: " << vec.capacity() << endl;
//         cout << endl << endl;
//     }
// }

#include "../../includes/vector/vector.hpp"
using namespace std;

int main() {
    cout << "MY VECTOR:" << endl << endl;
    ft::vector<int> vec(3, 5);
    int *point;
    {       
        point = vec._base_array;
        while (*point != 0) {
            cout << *point;
            point++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }        
    {
        vec.resize(5,2);
        point = vec._base_array;
        while (*point != 0) {
            cout << *point;
            point++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }

    {
        vec.resize(10,3);
        point = vec._base_array;
        while (*point != 0) {
            cout << *point;
            point++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }

    {
        vec.resize(3,3);
        point = vec._base_array;
        while (*point != 0) {
            cout << *point;
            point++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }

    {
        vec.resize(-21,3);
        point = vec._base_array;
        while (*point != 0) {
            cout << *point;
            point++;
        }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;
    }
    return (0);
}

