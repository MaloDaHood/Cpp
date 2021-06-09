#include <iostream>
#include <string>

int main()
{
    std::string str;
    getline(std::cin, str);
    std::string letters, numbers;
    for(char c : str)
    {
        if(isdigit(c))
            numbers.push_back(c);
        else
            letters.push_back(c);
    }
    std::cout << "Letters : " << letters << std::endl << "Numbers : " << numbers << std::endl;
    for(int i {0}; i<str.length(); i++)
    {
        std::cout << str[i];
        if(i==str.length()/2-1)
            std::cout << " ";
    }
    return 0;
}