#include "main.hpp"

int main()
{
    //system("clear");
    std::string currentLocation {"env/"};
    while(true)
    {
        std::cout << currentLocation << "> ";
        std::string input;
        std::getline(std::cin, input);
        if(input.empty())
            continue;
        std::vector<std::string> splitedArguments {""};
        std::string command {ParseInput(input, splitedArguments)};
        std::transform(command.begin(), command.end(), command.begin(), 
            [](unsigned char c){
                if(isalpha(c))
                    return std::tolower(c);
                else
                    return int(c);
            });
        std::vector<std::string> const availableCommands {"quit","say","clear","new","cd","create","mkdir","rmdir","delete"};
        if(std::find(availableCommands.begin(), availableCommands.end(), command)==availableCommands.end())
        {
            CommandError(command);
            continue;
        }
        else if(command=="quit")
            return 0;
        else if(command=="clear")
            GetOS();
        else if(command=="new")
        {
            system("start main.exe");
            continue;
        } 
        else if(!splitedArguments.empty())
        {
            if(command=="say")
                Say(splitedArguments);
            else if(command=="create")
                CreateFile(splitedArguments, currentLocation);
            else if(command=="delete")
                DeleteFile(splitedArguments, currentLocation);
            else if(command=="mkdir")
                CreateDirectory(splitedArguments, currentLocation);
            else if(command=="rmdir")
                DeleteDirectory(splitedArguments, currentLocation);
            /*else if(command=="cd")
                ChangeDirectory(splitedArguments, currentLocation);*/
        }
        else
        {
            NoArgumentsError();
            continue;
        }
    }
    return 0;
}