#include "main.hpp"

void CommandError(std::string const &command)
{
    std::cout << command << " : Unknown command." << std::endl;
}

void OSError()
{
    std::cout << "Error : Your OS isn't supported." << std::endl;
}

void NoArgumentsError()
{
    std::cout << "Error : You didn't input any arguments." << std::endl;
}

void  TooMuchArgumentsError(int const numberOfArguments)
{
    std::cout << "Error : You provided too much arguments for this command.\nYou provided : " << numberOfArguments << '.' << std::endl;
}

void  MissingArgumentsError(int const numberOfArguments)
{
    std::cout << "Error : You didn't provide enough arguments for this command.\nYou provided only : " << numberOfArguments << '.' << std::endl;
}

void WrongArgumentError(std::string const &argument, std::unordered_set<std::string> const &availableArguments)
{
    std::cout << "Error : Unknown argument [" << argument << "]\nValid arguments are : ";
    for(std::string const &str : availableArguments)
    {
        std::cout << '[' << str << "] "; 
    }
    std::cout << std::endl;
}