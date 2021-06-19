#include "header.hpp"

int main()
{
    system("cls");
    std::string input;
    while(input!="quit")
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){return std::tolower(c);});
        std::string command {""};
        for(char c : input)
        {
            if(isalpha(c))
            {
                command.push_back(c);
            }
            else if(isspace(c))
            {
                break;
            }
            else
            {
                Error();
            }
        }
        std::unordered_set<std::string> availableCommands {"add", "show", "save", "load", "quit"};
        if(availableCommands.find(command)!=std::end(availableCommands))
        {
            
        }
        else
        {
            Error();
        }
    }
    return 0;
}

void Error()
{
    std::cout << "Error : Invalid Command." << std::endl;
}