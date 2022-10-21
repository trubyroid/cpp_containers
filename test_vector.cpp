#include <iostream>
#include <vector>
using namespace std;

int main() {

    // initializer list
    vector<int> vector1 = {1, 2, 3, 4, 5};
    // uniform initialization
    vector<int> vector2{6, 7, 8, 9, 10};
    // method 3
    vector<int> vector3(5, 12);
    // my test
    vector<int> vector4;

    vector4.push_back(1);
    vector4.push_back(3);
    vector4.push_back(5);
    vector4.push_back(8);
    vector4.push_back(1);
    vector4.push_back(1);
    vector4.push_back(1);
    vector4.push_back(1);
    vector4.push_back(1);
    

    // vector4.get_allocator();
    // cout << vector2.data() << endl;                                                         //остановился на тесте функций вектора
    // cout << vector2.at(2) << endl;

    cout << "\nvector1 = ";
    // ranged loop
    for (const int& i : vector1) {
      cout << i << "  ";
    }
    cout << "\nvector2 = ";
    // ranged loop
    for (const int& i : vector2) {
      cout << i << "  ";
    }
    cout << "\nvector3 = ";
    // ranged loop
    for (int i : vector3) {
      cout << i << "  ";
    }
    cout << "\nvector4 = ";
    for (int j : vector4) {
        cout << j << "  ";
    }
    
    cout << endl << "size:" << vector4.size();
    cout << endl << "capacity:" << vector4.capacity() << endl;


    return 0;
}