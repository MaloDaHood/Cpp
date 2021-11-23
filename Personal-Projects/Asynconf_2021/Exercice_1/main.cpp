#include <iostream>
#include "base64.h"

int main(int argc, char *argv[]) 
{
    if(argc < 2)
    {
        std::cout << '[' << argv[0] << "] - Error : Missing argument." << std::endl;
        return EXIT_FAILURE;
    }
    for(char const &character : base64_decode(static_cast<std::string>(argv[1])))
    {
        if(std::isalpha(character)) std::cout << char(character-2);
        else std::cout << character;
    }
    return EXIT_SUCCESS;
}