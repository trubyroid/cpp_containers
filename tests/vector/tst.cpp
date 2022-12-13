#include <iostream>
#include <string>
#include <typeinfo>


int main() {
    std::string str;

    const std::type_info& ti1 = typeid(str);
    std::cout << ti1 << std::endl;
}