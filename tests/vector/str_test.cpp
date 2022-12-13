#include <iostream>
#include <string>

// #include <vector>
// namespace ft = std;

#include "../../includes/vector/vector.hpp"


int main() {

    std::cout << "~~~~~~~~ CONSTRUCTORS TEST." << std::endl << std::endl;

    {
        ft::vector<std::string>             vec;
        ft::vector<std::string>             vec_1(3, "test");
        ft::vector<std::string>             vec_2(vec_1);

        // ft::vector<std::string>::iterator   beg = vec_2.begin();
        // ft::vector<std::string>::iterator   end = vec_2.end();
        // ft::vector<std::string>             vec_3(beg, end);
        

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

        // std::cout << std::endl << "VEC_3: " << vec_3.size() << ", " << vec_3.capacity() << ", ";
        // p = vec_3.data();
        // for (int i = 0; i < vec_3.size(); i++) {
        //     std::cout << *p;
        //     p++;
        // }

    }

    std::cout << std::endl << std::endl << "~~~~~~~~ ASSIGN TEST." << std::endl << std::endl;
    {
        ft::vector<std::string>             vec(3, "la");

        vec.assign(4,"ta");
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.assign(4,"fa");
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.assign(2,"da");
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity();
    }

    // std::cout << std::endl << std::endl << "~~~~~~~~ ASSIGN ITERATOR TEST." << std::endl << std::endl;
    // {
    //     ft::vector<std::string>                 vec(3, "test ");
    //     ft::vector<std::string>                 vec_1(5, "tset ");
    //     ft::vector<std::string>::iterator       begin = vec.begin();
    //     ft::vector<std::string>::iterator       end = vec.end();
    //     std::string                             *p;

    //     p = vec.data();
    //     std::cout << "VEC: ";
    //     for (int i = 0; i < vec.size(); i++) {
    //         std::cout << *p;
    //         p++;
    //     }

    //     p = vec_1.data();
    //     std::cout << std::endl << "VEC_1: ";
    //     for (int i = 0; i < vec_1.size(); i++) {
    //         std::cout << *p;
    //         p++;
    //     }

    //     vec_1.assign(begin, end);

    //     p = vec_1.data();
    //     std::cout << std::endl << "VEC_1: ";
    //     for (int i = 0; i < vec_1.size(); i++) {
    //         std::cout << *p;
    //         p++;
    //     }
    // }


    std::cout << std::endl << std::endl << "~~~~~~~~ AT TEST." << std::endl << std::endl;
    {
        ft::vector<std::string> vec(3,"test ");

        std::cout << "VEC.AT(2): " << vec.at(2) << std::endl;
        std::cout << "VEC[1]: " << vec[1] << std::endl;
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ FRONT AND BACK TEST." << std::endl << std::endl;
    {
        ft::vector<std::string> vec(3,"test ");

        std::cout << "BEFORE RESIZE. FRONT:" << vec.front() << ", BACK:";
        std::cout << vec.back() << std::endl;

        vec.resize(4,"ta ");

        std::cout << "AFTER RESIZE. FRONT:" << vec.front() << ", BACK:";
        std::cout << vec.back() << std::endl;
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ ITERATORS TEST." << std::endl << std::endl; 
    {
        ft::vector<std::string>                 vec(1,"ta ");

        vec.resize(2,"ta ");
        vec.resize(3,"ra ");
        vec.resize(4,"fa ");

        ft::vector<std::string>::iterator       begin = vec.begin();
        ft::vector<std::string>::iterator       end = vec.end();

        std::cout << "ITERATOR: ";
        while (begin != end) {
            std::cout << *begin;
            begin++;
        }

        std::cout << std::endl;

        ft::vector<std::string>::reverse_iterator       rbegin = vec.rbegin();
        ft::vector<std::string>::reverse_iterator       rend = vec.rend();

        std::cout << "REVERSE ITERATOR: ";
        while (rbegin != rend) {
            std::cout << *rbegin;
            rbegin++;
        }
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ EMPTY MAX_SIZE SIZE CAPACITY TEST." << std::endl << std::endl;
    {
        ft::vector<std::string> vec(3,"test ");

        std::cout << "EMPTY: " << vec.empty() << std::endl;    
        std::cout << "MAX_SIZE: " << vec.max_size() << std::endl;
        std::cout << "SIZE: " << vec.size() << std::endl;
        std::cout << "CAPACITY: " << vec.capacity();
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ RESERVE TEST." << std::endl << std::endl;
    {
        ft::vector<std::string> vec(3,"test ");

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
        ft::vector<std::string> vec(3,"test ");

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

    // // std::cout << std::endl << std::endl << "~~~~~~~~ INSERT TEST." << std::endl << std::endl; {}

    std::cout << std::endl << std::endl << "~~~~~~~~ ERASE TEST." << std::endl << std::endl;
    {
        ft::vector<std::string> vec(1,"fa ");

        vec.resize(2,"ta ");
        vec.resize(3,"ra ");
        std::cout << "VECTOR BEFORE ERASE: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl;

        ft::vector<std::string>::iterator   it = vec.begin();
        ft::vector<std::string>::iterator   return_vl;
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
        ft::vector<std::string> vec(1,"ta ");

        vec.resize(2,"ra ");
        vec.resize(3,"wa ");
        vec.resize(4,"fa ");
        vec.resize(5,"sa ");
        std::cout << "VECTOR BEFORE ERASE: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        ft::vector<std::string>::iterator   it_beg = vec.begin();
        ft::vector<std::string>::iterator   it_end = vec.end();
        ft::vector<std::string>::iterator   return_vl;
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
        ft::vector<std::string> vec;

        vec.push_back("tra");
        vec.push_back("ta");
        vec.push_back("ta");
        vec.push_back("ta");
        vec.push_back("ta");
        vec.push_back("ta");
        vec.push_back("ta");
        vec.push_back("ta");
        vec.push_back("ta");

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
        ft::vector<std::string> vec(3, "la");

        std::cout << "VECTOR(3,5): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.resize(5,"ya ");
        std::cout << "RESIZE(5,2): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.resize(10,"ua ");
        std::cout << "RESIZE(10,3): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity() << std::endl;
        std::cout << std::endl;

        vec.resize(3,"qa ");
        std::cout << "RESIZE(3,3): ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i);
        }
        std::cout << std::endl << "SIZE: " << vec.size();
        std::cout << std::endl << "CAPACITY: " << vec.capacity();
    }

    std::cout << std::endl << std::endl << "~~~~~~~~ SWAP TEST." << std::endl << std::endl;
    {
        ft::vector<std::string>    vec(3,"one ");
        ft::vector<std::string>    vec_1(5,"two ");

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
        ft::vector<std::string>                 vec(3,"test ");
        ft::vector<std::string>                 vec_1(3,"test ");
        ft::vector<std::string>                 vec_2(3,"test ");

        std::cout << "vec and vec_1: ";
        if (vec == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

        vec.resize(5,"one ");

        std::cout << "vec and vec_1: ";
        if (vec == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

        vec_1.resize(5,"one ");

        std::cout << "vec and vec_1: ";
        if (vec == vec_1) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

        vec_2.reserve(5);

        std::cout << "vec_2 and vec: ";
        if (vec_2 == vec) {
            std::cout << "Equal" << std::endl;
        }
        else {
            std::cout << "Not equal" << std::endl;
        }

    }

    std::cout << std::endl << std::endl << "~~~~~~~~ NOT EQUAL TESTS." << std::endl << std::endl;
    {
        ft::vector<std::string>                 vec(3,"test ");
        ft::vector<std::string>                 vec_1(3,"test ");
        ft::vector<std::string>                 vec_2(3,"test ");

        std::cout << "vec and vec_1: ";
        if (vec != vec_1) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

        vec.resize(5,"one ");

        std::cout << "vec and vec_1: ";
        if (vec != vec_1) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

        vec_1.resize(5,"one ");

        std::cout << "vec and vec_1: ";
        if (vec != vec_1) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

        vec_2.reserve(5);

        std::cout << "vec_2 and vec: ";
        if (vec_2 != vec) {
            std::cout << "Not equal" << std::endl;
        }
        else {
            std::cout << "Equal" << std::endl;
        }

    }

    std::cout << std::endl << std::endl << "~~~~~~~~ APPROPRIATION TESTS." << std::endl << std::endl;
    {
        ft::vector<std::string>                 vec(3,"test ");
        ft::vector<std::string>                 vec_1(vec);
        ft::vector<std::string>                 vec_2(2,"tset ");

        vec_1.resize(5,"one ");
        std::cout << "vec and vec_1: ";
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

        std::cout << "vec_2 and vec_1: ";
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
        ft::vector<std::string>             vec(2,"test");
        ft::vector<std::string>             vec_1(3,"test");

        vec.resize(3,"tst");
        std::cout << std::endl << "LESS TEST: ";
        if (vec < vec_1) {
            std::cout << "ERROR" << std::endl;
        }
        else {
            std::cout << "DONE" << std::endl;
        }

        std::cout << std::endl << "LESS OR EQUAL TEST: ";
        if (vec <= vec_1) {
            std::cout << "ERROR" << std::endl;
        }
        else {
            std::cout << "DONE" << std::endl;
        }

        std::cout << std::endl << "MORE TEST: ";
        if (vec > vec_1) {
            std::cout << "DONE" << std::endl;
        }
        else {
            std::cout << "ERROR" << std::endl;
        }

        std::cout << std::endl << "MORE OR EQUAL TEST: ";
        if (vec >= vec_1) {
            std::cout << "DONE" << std::endl;
        }
        else {
            std::cout << "ERROR" << std::endl;
        }
    }
}