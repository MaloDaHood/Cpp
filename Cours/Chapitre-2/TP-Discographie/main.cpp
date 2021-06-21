#include "header.hpp"

int main()
{
    system("cls");
    std::ofstream tempFile {"temp.csv"};
    while(true)
    {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);
        std::string arguments {""};      
        std::string command {SplitInput(input, arguments)};
        std::string argumentsCopy {arguments};
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c){return std::tolower(c);});
        std::unordered_set<std::string> availableCommands {"add", "show", "save", "load", "quit"};
        if(command=="quit")
            return 0;
        if(availableCommands.find(command)==std::end(availableCommands))
        {
            Error();
            continue;
        }
        std::vector<std::string> infos; // infos[0]=song | infos[1]=album | infos[2]=artist
        ParseArguments(infos, arguments);
        if(command=="add")
            Add(infos, tempFile);
        else if(command=="save")
        {
            if(argumentsCopy.empty()) // need to chech for spaces
            {
                Error();
                continue;
            }
            else
                Save(argumentsCopy);
        }
    }
    return 0;
}

void Error()
{
    std::cout << "Error : Invalid Command." << std::endl;
}

std::string SplitInput(std::string const &input, std::string &arguments)
{
    std::string command {""};
    for(int i {0}; i<input.length(); i++)
    {
        if(isalpha(input[i]))
            command.push_back(input[i]);
        else
        {
            for(int j {i+1}; j<input.length(); j++)
                arguments.push_back(input[j]);
            break;
        }
    }
    return command;
}

void ParseArguments(std::vector<std::string> &infos, std::string &arguments)
{
    std::string delimiter {"|"};
    arguments+=delimiter;
    size_t pos {0};
    while((pos=arguments.find(delimiter))!=std::string::npos)
    {
        infos.push_back(arguments.substr(0, pos));
        arguments.erase(0, pos+delimiter.length());
    }
    if(infos.size()<3)
    {
        for(int i {0}; i<=3-infos.size(); i++)
        {
            infos.push_back("UNKNOWN");
        }
    }
    while(std::any_of(std::begin(infos), std::end(infos), 
        [](std::string const &str){return isspace(str.front())||isspace(str.back());}))
    {
        for(std::string &str : infos)
        {
            if(isspace(str.front()))
                str.erase(str.begin());
            if(isspace(str.back()))
                str.pop_back();
        }
    }
    while(std::any_of(std::begin(infos), std::end(infos), 
        [](std::string const &str){return str.empty();}))
    {
        for(int i {0}; i<infos.size(); i++)
        {
            if(infos[i].empty())
                infos[i]="UNKNOWN";
        }
    }
}

void Add(std::vector<std::string> const &infos, std::ofstream &tempFile)
{
    tempFile << infos[0] << ',' << infos[1] << ',' << infos[2] << "\n";
}

void Save(std::string const &argument)
{
    std::cout << "yes";
}