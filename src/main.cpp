#include <iostream>
#include "string_view.hpp"

int main()
{
    std::string data = "Hello World";
    StringView sv(data, 2, 7);
    std::cout << sv.to_string() << std::endl;
}