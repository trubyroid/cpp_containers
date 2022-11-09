#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "BASE VECTOR:" << endl << endl;
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
        vec.assign(3, 6);
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
}

// #include "../includes/vector.hpp"
// using namespace std;

// int main() {
//     cout << "MY VECTOR:" << endl << endl;
//     ft::vector<int> vec(3, 5);
// }