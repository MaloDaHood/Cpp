#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string const phrase { "Voici une phrase longue que je veux en majuscules." };
    std::string sortie {""};

    std::transform(std::begin(phrase), std::end(phrase), std::back_inserter(sortie),[](char c)->char{return std::toupper(c);});

    std::cout << sortie << std::endl;
    return 0;
}