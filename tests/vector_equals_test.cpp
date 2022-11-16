//------------------------------ == -----------------------------------------//

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     cout << "BASE VECTOR:" << endl << endl;
//     vector<int>                 vec(3,5);
//     vector<int>                 vec_1(3,5);

    // cout << "Size: " << vec.size() << endl;
    // cout << "Capacity: " << vec.capacity() << endl;
    // cout << endl << endl;
    // vec.resize(5,6);
    // cout << "Size: " << vec.size() << endl;
    // cout << "Capacity: " << vec.capacity() << endl;
    // cout << endl << endl;


    // if (vec == vec_1) {
    //     cout << "Equal" << endl;
    // }
    // else {
    //     cout << "Not equal" << endl;
    // }

    // cout << endl;
    // cout << "Size: " << vec_1.size() << endl;
    // cout << "Capacity: " << vec_1.capacity() << endl;
    // cout << endl << endl;
    // vec_1.resize(5,6);
    // cout << "Size: " << vec_1.size() << endl;
    // cout << "Capacity: " << vec_1.capacity() << endl;
    // cout << endl << endl;


    // if (vec == vec_1) {
    //     cout << "Equal" << endl;
    // }
    // else {
    //     cout << "Not equal" << endl;
    // }
    //-----------------------------------------------------------//
    // vector<int>                 vec_2(2,5);
    // vec_2.resize(3,5);
    // if (vec == vec_2) {
    //     cout << "Equal" << endl;
    // }
    // else {
    //     cout << "Not equal" << endl;
    // }
// }

// #include "../includes/vector.hpp"
// using namespace std;

// int main() {
//     cout << "MY VECTOR:" << endl << endl;
//     ft::vector<int>                 vec(3,5);
//     ft::vector<int>                 vec_1(3,5);

    // cout << "Size: " << vec.size() << endl;
    // cout << "Capacity: " << vec.capacity() << endl;
    // cout << endl << endl;
    // vec.resize(5,6);
    // cout << "Size: " << vec.size() << endl;
    // cout << "Capacity: " << vec.capacity() << endl;
    // cout << endl << endl;


    // if (vec == vec_1) {
    //     cout << "Equal" << endl;
    // }
    // else {
    //     cout << "Not equal" << endl;
    // }

    // cout << endl;
    // cout << "Size: " << vec_1.size() << endl;
    // cout << "Capacity: " << vec_1.capacity() << endl;
    // cout << endl << endl;
    // vec_1.resize(5,6);
    // cout << "Size: " << vec_1.size() << endl;
    // cout << "Capacity: " << vec_1.capacity() << endl;
    // cout << endl << endl;


    // if (vec == vec_1) {
    //     cout << "Equal" << endl;
    // }
    // else {
    //     cout << "Not equal" << endl;
    // }
    //-----------------------------------------------------------//
//     ft::vector<int>                 vec_2(2,5);
//     vec_2.resize(3,5);
//     if (vec == vec_2) {
//         cout << "Equal" << endl;
//     }
//     else {
//         cout << "Not equal" << endl;
//     }
// }

//------------------------------ = ------------------------------------------//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "BASE VECTOR:" << endl << endl;
    vector<int>                 vec(3,5);
    vector<int>                 vec_1(vec);

    cout << "Size: " << vec_1.size() << endl;
    cout << "Capacity: " << vec_1.capacity() << endl;
    cout << endl << endl;

    if (vec == vec_1) {
        cout << "Equal" << endl << endl;
    }
    else {
        cout << "Not equal" << endl << endl;
    }


    vec_1.resize(5,7);
    cout << "Size: " << vec_1.size() << endl;
    cout << "Capacity: " << vec_1.capacity() << endl;
    cout << endl << endl;

    if (vec == vec_1) {
        cout << "Equal" << endl << endl;
    }
    else {
        cout << "Not equal" << endl << endl;
    }

    vec_1 = vec;
    cout << "Size: " << vec_1.size() << endl;
    cout << "Capacity: " << vec_1.capacity() << endl;
    cout << endl << endl;

    if (vec == vec_1) {
        cout << "Equal" << endl << endl;
    }
    else {
        cout << "Not equal" << endl << endl;
    }

    vector<int>                 vec_2(2,5);

    // vec_2.resize(10,4);
    vec_2.reserve(20);
    vec_1 = vec_2;
    cout << "Size: " << vec_1.size() << endl;
    cout << "Capacity: " << vec_1.capacity() << endl;
    cout << endl << endl;
}

// #include "../includes/vector.hpp"
// using namespace std;

// int main() {
//     cout << "MY VECTOR:" << endl << endl;
//     ft::vector<int>                 vec(3,5);
//     ft::vector<int>                 vec_1(vec);

//     cout << "Size: " << vec_1.size() << endl;
//     cout << "Capacity: " << vec_1.capacity() << endl;
//     cout << endl << endl;

//     if (vec == vec_1) {
//         cout << "Equal" << endl << endl;
//     }
//     else {
//         cout << "Not equal" << endl << endl;
//     }


//     vec_1.resize(5,7);
//     cout << "Size: " << vec_1.size() << endl;
//     cout << "Capacity: " << vec_1.capacity() << endl;
//     cout << endl << endl;

//     if (vec == vec_1) {
//         cout << "Equal" << endl << endl;
//     }
//     else {
//         cout << "Not equal" << endl << endl;
//     }

//     vec_1 = vec;
//     cout << "Size: " << vec_1.size() << endl;
//     cout << "Capacity: " << vec_1.capacity() << endl;
//     cout << endl << endl;

//     if (vec == vec_1) {
//         cout << "Equal" << endl << endl;
//     }
//     else {
//         cout << "Not equal" << endl << endl;
//     }

//     ft::vector<int>                 vec_2(2,5);

//     // vec_2.resize(10,4);
//     vec_2.reserve(20);
//     vec_1 = vec_2;
//     cout << "Size: " << vec_1.size() << endl;
//     cout << "Capacity: " << vec_1.capacity() << endl;
//     cout << endl << endl;
// }


//------------------------------ != ------------------------------------------//






