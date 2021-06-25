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
        std::unordered_set<std::string> const availableOptions {"-u","-l"};
        if(arguments[0][0]=='-'&&availableOptions.find(arguments[0])==std::end(availableOptions))
        {
            WrongArgumentError(arguments[0], availableOptions);
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

void CreateFile(std::vector<std::string> const &splitedArguments, std::string const &currentLocation)
{
    if(splitedArguments.size()>1)
    {
        TooMuchArgumentsError(int(splitedArguments.size()));
        return;
    }
    else
    {
        std::ofstream newFile {currentLocation+splitedArguments[0]};
        if(!newFile)
        {
            ImpossibleToCreateNewFileError();
            return;
        }
        else
            newFile.close();
    }
}

void DeleteFile(std::vector<std::string> const &splitedArguments, std::string const &currentLocation)
{
   if(splitedArguments.size()>1)
    {
        TooMuchArgumentsError(int(splitedArguments.size()));
        return;
    }
    else
    {
        char *fileName;
        std::string file {currentLocation+splitedArguments[0]};
        fileName=&file[0];
        if(remove(fileName))
        {
            ImpossibleToDeleteNewFileError();
            return;
        }
    } 
}