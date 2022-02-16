#include <iostream>
#include "sv_lib/string_view.hpp"

int main()
{
    std::string data = "Hello World";
    sv_lib::StringView sv(data, 2, 7);
    std::cout << sv.toString() << std::endl;
}