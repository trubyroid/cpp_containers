#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "BASE VECTOR:" << endl << endl;
    vector<int>                 vec(3,5);
    vector<int>                 vec2(5,7);

    {
        vector<int>::iterator       begin = vec.begin();
        vector<int>::iterator       end = vec.end();

        // while (begin != end) {
        //     cout << *begin;
        //     begin++;
        // }
        cout << endl;
        cout << "Size: " << vec.size() << endl;
        cout << "Capacity: " << vec.capacity() << endl;
        cout << endl << endl;

        vec2.assign(begin, end);

        vector<int>::iterator       begin_2 = vec2.begin();
        vector<int>::iterator       end_2 = vec2.end();
        while (begin_2 != end_2) {
            cout << *begin_2;
            begin_2++;
        }
        cout << endl;
        cout << "Size: " << vec2.size() << endl;
        cout << "Capacity: " << vec2.capacity() << endl;
        cout << endl << endl;
    }

    // {
    //     vec.assign(4, 6);
    //     vector<int>::iterator       begin = vec.begin();
    //     vector<int>::iterator       end = vec.end();
    //     while (begin != end) {
    //         cout << *begin;
    //         begin++;
    //     }
    //     cout << endl;
    //     cout << "Size: " << vec.size() << endl;
    //     cout << "Capacity: " << vec.capacity() << endl;
    //     cout << endl << endl;
    // }

    // {
    //     vec.assign(4, 8);
    //     vector<int>::iterator       begin = vec.begin();
    //     vector<int>::iterator       end = vec.end();
    //     while (begin != end) {
    //         cout << *begin;
    //         begin++;
    //     }
    //     cout << endl;
    //     cout << "Size: " << vec.size() << endl;
    //     cout << "Capacity: " << vec.capacity() << endl;
    //     cout << endl << endl;
    // }

    // {
    //     vec.assign(2, 9);
    //     vector<int>::iterator       begin = vec.begin();
    //     vector<int>::iterator       end = vec.end();
    //     while (begin != end) {
    //         cout << *begin;
    //         begin++;
    //     }
    //     cout << endl;
    //     cout << "Size: " << vec.size() << endl;
    //     cout << "Capacity: " << vec.capacity() << endl;
    //     cout << endl << endl;
    // }
}