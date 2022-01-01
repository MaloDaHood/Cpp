#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    std::getline(input, line); 
    int floor {0};
    for(char const &c : line)
    {
        if(c == '(')
            floor++;
        else
            floor--;
    }
    input.close();
    std::cout << floor << std::endl;
    return 0;
}