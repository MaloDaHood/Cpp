#include "main.hpp"

std::string ParseInput(std::string const &input, std::vector<std::string> &splitedArguments)
{
    std::string command {""}, arguments {""};
    for(int i {0}; i<int(input.length()); i++)
    {
        if(isspace(input[i]))
        {
            for(int j {i+1}; j<int(input.length()); j++)
                    arguments.push_back(input[j]);
            break;
        }  
        else
            command.push_back(input[i]);
    }
    size_t pos {0};
    while((pos=arguments.find(' '))!=std::string::npos)
    {
        splitedArguments.push_back(arguments.substr(0, pos));
        arguments.erase(0, pos+1);
    }
    splitedArguments.push_back(arguments);
    while(std::any_of(splitedArguments.begin(), splitedArguments.end(), [](std::string const &str)->bool{return str.empty();}))
    {
        for(int i {0}; i<int(splitedArguments.size()); i++)
        {
            if(splitedArguments[i].empty())
                splitedArguments.erase(splitedArguments.begin()+i);
            else
                continue;
        }
    }
    return command;
}