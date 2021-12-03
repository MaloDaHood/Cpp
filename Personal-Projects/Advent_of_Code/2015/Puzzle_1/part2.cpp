#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    std::getline(input, line); 
    int floor {0};
    int posBasement {0};
    for(size_t i {0}; i < line.length(); i++)
    {
        if(line[i] == '(')
            floor++;
        else
            floor--;
        if(floor < 0)
        {
           posBasement = i + 1;
           break;
        }
    }
    input.close();
    std::cout << posBasement << std::endl;
    return 0;
}