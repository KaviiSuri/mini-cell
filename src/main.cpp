#include <iostream>
#include "string_view.hpp"

int main()
{
    std::string data = "Hello World";
    StringView sv(data);
    std::vector<StringView> vsv = sv.split_by_delim(' ');

    for (auto i : vsv)
    {
        std::cout << i << std::endl;
    }
}