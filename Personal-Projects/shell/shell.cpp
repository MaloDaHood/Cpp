#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <filesystem>
#include <unistd.h>

void Execute(std::string const command);
std::string Match(std::string const command);

int main()
{
    std::cout << "Bienvenue dans le shell 2.0" << std::endl;
    bool stop {false};
    do
    {
        char tmp[256];
        _getcwd(NULL, 0);
        
        std::cout << tmp << "> ";
        std::string entree;
        std::getline(std::cin, entree);
        entree=Match(entree);
        Execute(entree);
    } while (!stop);
    
    return EXIT_SUCCESS;
}

void Execute(std::string const command)
{
    system(command.c_str());
}

std::string Match(std::string const command)
{
    if(command=="ls")
        return "dir";
    else if(command=="exit")
        return "^C";
}