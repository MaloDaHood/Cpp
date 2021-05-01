#include "main.h"

int main()
{
    //std::array<char, 3> tableauLettres {'a', 'b', 'c'};
    std::string lettres {"abcdefghijklmnopqrstuvwxyz"};
    std::string phrase {"acb3"};
    std::cout << phrase.find_first_not_of(lettres) <<std::endl;
}