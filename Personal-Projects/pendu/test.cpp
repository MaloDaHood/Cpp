#include "main.h"

int main()
{
    //std::array<char, 3> tableauLettres {'a', 'b', 'c'};
    std::string lettres {"abcdefghijklmnopqrstuvwxyz"};
    std::string phrase {"acb"};
    std::cout << phrase.find_first_of(lettres) <<std::endl;
    //int const x {2};
    //phrase[x]=phrase[x]-32;
    //std::cout << phrase[x];
    //std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);
    //std::cout << phrase;
}