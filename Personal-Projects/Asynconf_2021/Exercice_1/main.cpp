#include <iostream>
#include <string>
#include "base64.h"
#include <unordered_map>

int main() 
{
    std::string formuleEncode;
    std::cout << "Formule encodée ?" << std::endl;
    std::getline(std::cin, formuleEncode);
    std::string formuleDecode64 {base64_decode(formuleEncode)};
    std::string alphabet {"abcdefghijklmnopqrstuvwxyz"};
    std::unordered_map<char, int> alphabet_map;
    for(size_t i {0}; i<alphabet.length(); i++)
    {
        alphabet_map[alphabet[i]] = i+1;
    }
    for(size_t i {0}; i<formuleDecode64.length(); i++)
    {
        if(!std::isalpha(formuleDecode64[i]))
        {
            std::cout << formuleDecode64[i];
            continue;
        }
        else
        {
            int num;
            if(std::isupper(formuleDecode64[i])) num = alphabet_map[std::tolower(formuleDecode64[i])]-2;
            else num = alphabet_map[formuleDecode64[i]]-2;
            for(auto const &pair : alphabet_map)
            {
                if(pair.second == num)
                {
                    if(std::isupper(formuleDecode64[i])) std::cout << char(std::toupper(pair.first));
                    else std::cout << pair.first;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}