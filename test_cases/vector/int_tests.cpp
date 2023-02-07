#include <iostream>
#include <string>

// #include <vector>
// namespace ft = std;

#include "../../includes/vector/vector.hpp"


int main() {

    std::cout << "~~~~~~~~ CONSTRUCTORS TEST." << std::endl << std::endl;

    {
        ft::vector<int>             vec;
        ft::vector<int>             vec_1(3, 7);
        ft::vector<int>             vec_2(vec_1);

        ft::vector<int>::iterator   beg = vec_2.begin();
        ft::vector<int>::iterator   end = vec_2.end();
        ft::vector<int>             vec_3(beg, end);
        

        std::cout << "VEC: " << vec.size() << ", " << vec.capacity() << ", " << std::endl;
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }

        std::cout << "VEC_1: " << vec_1.size() << ", " << vec_1.capacity() << ", ";
        for (int i = 0; i < vec_1.size(); i++) {
            std::cout << vec_1.at(i);
        }

        std::cout << std::endl << "VEC_2: " << vec_2.size() << ", " << vec_2.capacity() << ", ";
        for (int i = 0; i < vec_2.size(); i++) {
            std::cout << vec_2.at(i);
        }

        std::cout << std::endl << "VEC_3: " << vec_3.size() << ", " << vec_3.capacity() << ", ";
        int *p = vec_3.data();
        for (int i = 0; i < vec_3.size(); i++) {
            std::cout << *p;
            p++;
        }

    }

    std::cout << std::endl << std::endl << "~~~~~~~~ ASSIGN TEST." << std::endl << std::endl;
    {
        ft::vector<int>             vec(3, 5);

        vec.assign(4,6);
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.assign(4,8);
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.assign(2,9);
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity();
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ ASSIGN ITERATOR TEST." << std::endl << std::endl;
    {
        ft::vector<int>                 vec(3, 9);
        ft::vector<int>                 vec_1(5, 8);
        ft::vector<int>::iterator       begin = vec.begin();
        ft::vector<int>::iterator       end = vec.end();
        int                             *p;

        p = vec.data();
        std::cout << "VEC: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << *p;
            p++;
        }

        p = vec_1.data();
        std::cout << std::endl << "VEC_1: ";
        for (int i = 0; i < vec_1.size(); i++) {
            std::cout << *p;
            p++;
        }

        vec_1.assign(begin, end);

        p = vec_1.data();
        std::cout << std::endl << "VEC_1: ";
        for (int i = 0; i < vec_1.size(); i++) {
            std::cout << *p;
            p++;
        }
    }


    std::cout << std::endl << std::endl << "~~~~~~~~ AT TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec(3,5);

        std::cout << "VEC.AT(2): " << vec.at(2) << std::endl;
        std::cout << "VEC[1]: " << vec[1] << std::endl;
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ FRONT AND BACK TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec(3,5);

        std::cout << "BEFORE RESIZE. FRONT:" << vec.front() << ", BACK:";
        std::cout << vec.back() << std::endl;

        vec.resize(4,8);

        std::cout << "AFTER RESIZE. FRONT:" << vec.front() << ", BACK:";
        std::cout << vec.back() << std::endl;
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ ITERATORS TEST." << std::endl << std::endl; 
    {
        ft::vector<int>                 vec(1,5);

        vec.resize(2,6);
        vec.resize(3,7);
        vec.resize(4,8);

        ft::vector<int>::iterator       begin = vec.begin();
        ft::vector<int>::iterator       end = vec.end();

        std::cout << "ITERATOR: ";
        while (begin != end) {
            std::cout << *begin;
            begin++;
        }

        std::cout << std::endl;

        ft::vector<int>::reverse_iterator       rbegin = vec.rbegin();
        ft::vector<int>::reverse_iterator       rend = vec.rend();

        std::cout << "REVERSE ITERATOR: ";
        while (rbegin != rend) {
            std::cout << *rbegin;
            rbegin++;
        }
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ EMPTY MAX_SIZE SIZE CAPACITY TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec(3,5);

        std::cout << "EMPTY: " << vec.empty() << std::endl;    
        std::cout << "MAX_SIZE: " << vec.max_size() << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity();
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ RESERVE TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec(3,5);

        std::cout << "BEFORE RESERVE." << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << "VECTOR: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << std::endl;


        vec.reserve(10);

        std::cout << "AFTER RESERVE." << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << "VECTOR: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ CLEAR TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec(3,5);

        std::cout << "BEFORE CLEAR." << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << "VECTOR: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << std::endl;

        vec.clear();

        std::cout << "AFTER CLEAR." << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << "VECTOR: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
    }

    // std::cout << std::endl << std::endl << "~~~~~~~~ INSERT TEST." << std::endl << std::endl; {}

    std::cout << std::endl << std::endl << "~~~~~~~~ ERASE TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec(1,5);

        vec.resize(2,4);
        vec.resize(3,3);
        std::cout << "VECTOR BEFORE ERASE: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;

        ft::vector<int>::iterator   it = vec.begin();
        ft::vector<int>::iterator   return_vl;
        it++;

        return_vl = vec.erase(it);
        std::cout << "VECTOR AFTER ERASE: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;
        std::cout << "RETURN ITERATOR: " << *return_vl << std::endl;
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ ERASE INTERVAL TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec(1,5);

        vec.resize(2,4);
        vec.resize(3,3);
        vec.resize(4,2);
        vec.resize(5,1);
        std::cout << "VECTOR BEFORE ERASE: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        ft::vector<int>::iterator   it_beg = vec.begin();
        ft::vector<int>::iterator   it_end = vec.end();
        ft::vector<int>::iterator   return_vl;
        it_beg++;
        it_end--;

        return_vl = vec.erase(it_beg, it_end);
        std::cout << "VECTOR AFTER ERASE: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;
        std::cout << "RETURN ITERATOR: " << *return_vl << std::endl;
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ PUSH POP BACK TEST." << std::endl << std::endl;
    {
        ft::vector<int> vec;

        vec.push_back(1);
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(8);
        vec.push_back(1);
        vec.push_back(1);
        vec.push_back(1);
        vec.push_back(6);
        vec.push_back(6);

        std::cout << "BEFORE POP BACK";
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << "VECTOR: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << std::endl;

        vec.pop_back();
        vec.pop_back();

        std::cout << "AFTER DOUBLE POP BACK";
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << "VECTOR: ";
        for (int i = 0; i < vec.size();i++) {
            std::cout << vec.at(i);
        }
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ RESIZE TESTS." << std::endl << std::endl;
    {
        ft::vector<int> vec(3, 5);

        std::cout << "VECTOR(3,5): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.resize(5,2);
        std::cout << "RESIZE(5,2): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.resize(10,3);
        std::cout << "RESIZE(10,3): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.resize(3,3);
        std::cout << "RESIZE(3,3): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity();
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ SWAP TEST." << std::endl << std::endl;
    {
        ft::vector<int>    vec(3,7);
        ft::vector<int>    vec_1(5,8);

        std::cout << "BEFORE SWAP." << std::endl;
        std::cout << "VEC: ";
        for (int i = 0; i < vec.size();i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;

        std::cout << "VEC_1: ";
        for (int i = 0; i < vec_1.size();i++) {
            std::cout << vec_1.at(i);
        }
        std::cout << std::endl << std::endl;

        vec.swap(vec_1);

        std::cout << "AFTER SWAP." << std::endl;
        std::cout << "VEC: ";
        for (int i = 0; i < vec.size();i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;

        std::cout << "VEC_1: ";
        for (int i = 0; i < vec_1.size();i++) {
            std::cout << vec_1.at(i);
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ EQUAL TESTS." << std::endl << std::endl;
    {
        ft::vector<int>                 vec(3,5);
        ft::vector<int>                 vec_1(3,5);
        ft::vector<int>                 vec_2(3,5);

        std::cout << "vec(555) and vec_1(555): ";
        if (vec == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

        vec.resize(5,6);

        std::cout << "vec(55566) and vec_1(555): ";
        if (vec == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

        vec_1.resize(5,6);

        std::cout << "vec(55566) and vec_1(55566): ";
        if (vec == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

        vec_2.reserve(5);

        std::cout << "vec_2(555__) and vec(55566): ";
        if (vec_2 == vec) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

    }

    std::cout << std::endl << std::endl << "~~~~~~~~ NOT EQUAL TESTS." << std::endl << std::endl;
    {
        ft::vector<int>                 vec(3,5);
        ft::vector<int>                 vec_1(3,5);
        ft::vector<int>                 vec_2(3,5);

        std::cout << "vec(555) and vec_1(555): ";
        if (vec != vec_1) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

        vec.resize(5,6);

        std::cout << "vec(55566) and vec_1(555): ";
        if (vec != vec_1) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

        vec_1.resize(5,6);

        std::cout << "vec(55566) and vec_1(55566): ";
        if (vec != vec_1) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

        vec_2.reserve(5);

        std::cout << "vec_2(555__) and vec(55566): ";
        if (vec_2 != vec) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

    }

    std::cout << std::endl << std::endl << "~~~~~~~~ APPROPRIATION TESTS." << std::endl << std::endl;
    {
        ft::vector<int>                 vec(3,5);
        ft::vector<int>                 vec_1(vec);
        ft::vector<int>                 vec_2(2,5);

        vec_1.resize(5,7);
        std::cout << "vec(555) and vec_1(55577): ";
        if (vec != vec_1) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

        vec_1 = vec;

        std::cout << "vec_1 = vec;" << std::endl;

        std::cout << "vec and vec_1: ";
        if (vec == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

        std::cout << std::endl;

        std::cout << "vec_2(55) and vec_1(555): ";
        if (vec_2 == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }


        vec_2 = vec_1;
        std::cout << "vec_2 = vec_1;" << std::endl;
    
        std::cout << "vec_2 and vec_1: ";
        if (vec_2 == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ MORE/LESS/EQUAL TESTS." << std::endl << std::endl;
    {
        ft::vector<int>             vec(2,5);
        ft::vector<int>             vec_1(3,5);

        vec.resize(3,4);
        std::cout << std::endl << "LESS TEST: ";
        if (vec < vec_1) {
            std::cout << "DONE" << std::endl;
        }
        else {
            std::cout << "ERROR" << std::endl;
        }

        std::cout << std::endl << "LESS OR EQUAL TEST: ";
        if (vec <= vec_1) {
            std::cout << "DONE" << std::endl;
        }
        else {
            std::cout << "ERROR" << std::endl;
        }

        std::cout << std::endl << "MORE TEST: ";
        if (vec > vec_1) {
            std::cout << "ERROR" << std::endl;
        }
        else {
            std::cout << "DONE" << std::endl;
        }

        std::cout << std::endl << "MORE OR EQUAL TEST: ";
        if (vec >= vec_1) {
            std::cout << "ERROR" << std::endl;
        }
        else {
            std::cout << "DONE" << std::endl;
        }
    }
}




// выводим версию с дефолтным и моим векторами в два разных файла, после чего сравниваем их с помощью FC