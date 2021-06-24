#include "main.hpp"

void Say(std::vector<std::string> &arguments)
{
    if((arguments[0][0]=='-'&&arguments.size()>2)||(isalpha(arguments[0][0])&&arguments.size()>1))
    {
        TooMuchArgumentsError(int(arguments.size()));
        return;
    }
    else if(arguments[0][0]=='-'&&arguments.size()<2)
    {
        MissingArgumentsError(int(arguments.size()));
        return;
    }
    else
    {
        std::unordered_set<std::string> const availableArguments {"-u","-l"};
        if(arguments[0][0]=='-'&&availableArguments.find(arguments[0])==std::end(availableArguments))
        {
            WrongArgumentError(arguments[0], availableArguments);
            return;
        }
        else if(arguments[0]=="-u")
        {
            std::transform(arguments[1].begin(), arguments[1].end(), arguments[1].begin(), 
                [](unsigned char c){
                    if(isalpha(c))
                        return std::toupper(c);
                    else
                        return int(c);
                });
            std::cout << arguments[1] << std::endl;
        }
        else if(arguments[0]=="-l")
        {
            std::transform(arguments[1].begin(), arguments[1].end(), arguments[1].begin(), 
                [](unsigned char c){
                    if(isalpha(c))
                        return std::tolower(c);
                    else
                        return int(c);
                });
            std::cout << arguments[1] << std::endl;
        }
        else
        {
            std::cout << arguments[0] << std::endl;
        }
    }
}