#include "main.hpp"

int main()
{
    //system("clear");
    while(true)
    {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);
        if(input.empty())
            continue;
        std::vector<std::string> splitedArguments {""};
        std::string command {ParseInput(input, splitedArguments)};
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c){return std::tolower(c);});
        std::unordered_set<std::string> const availableCommands {"quit","say","clear"};
        if(availableCommands.find(command)==std::end(availableCommands))
        {
            CommandError(command);
            continue;
        }
        else if(command=="quit")
            return 0;
        else if(command=="clear")
        {
            #ifdef _WIN32
                system("cls");
            #elif _WIN64
                system("cls");
            #elif __linux__
                system("clear");
            #elif __unix || __unix__
                system("clear");
            #else
                OSError();
            #endif
        } 
        else if(command=="say")
        {
            if(!splitedArguments.empty())
                Say(splitedArguments);
            else
            {
                NoArgumentsError();
                continue;
            }
        }
    }
    return 0;
}