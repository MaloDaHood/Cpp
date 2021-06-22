#include "header.hpp"

int main()
{
    system("cls");
    std::vector<std::vector<std::string>> container; //contains all the data temporarily - [i][0]=song | [i][1]=album | [i][2]=artist
    while(true)
    {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);
        std::string arguments {""};      
        std::string command {SplitInput(input, arguments)};
        std::string argumentsCopy {arguments};
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c){return std::tolower(c);});
        std::unordered_set<std::string> availableCommands {"add", "show", "save", "load", "quit", "clear"};
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
            container.push_back(infos);
        else if(command=="save")
        {
            if(argumentsCopy.empty()||container.empty())
            {
                Error();
                continue;
            }
            else
                Save(RemoveBlanks(argumentsCopy), container);
        }
        else if(command=="load")
            Load(RemoveBlanks(argumentsCopy), container);
        else if(command=="show")
            if(!container.empty())
                Show(RemoveBlanks(argumentsCopy), container);
            else
            {
                Error();
                continue;
            }
        else 
            container.clear();
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
    for(int i {0}; i<int(input.length()); i++)
    {
        if(isalpha(input[i]))
            command.push_back(input[i]);
        else
        {
            for(int j {i+1}; j<int(input.length()); j++)
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
    if(int(infos.size())<3)
    {
        for(int i {0}; i<=3-int(infos.size()); i++)
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
        for(int i {0}; i<int(infos.size()); i++)
        {
            if(infos[i].empty())
                infos[i]="UNKNOWN";
        }
    }
}

std::string RemoveBlanks(std::string &str)
{
    while(isspace(str.front())||isspace(str.back()))
    {
        if(isspace(str.front()))
            str.erase(str.begin());
        if(isspace(str.back()))
            str.pop_back();
    }
    return str;
}

void Save(std::string const &argument, std::vector<std::vector<std::string>> &container)
{
    std::ofstream targetFile {argument+".csv"};
    if(targetFile)
    {
        for(std::vector<std::string> const &v : container)
        {
            for(std::string const &str : v)
            {
                targetFile << str;
                if(!(str==v.back()))
                    targetFile << ',';
            }
            targetFile << '\n';
        }
        targetFile.close();
        container.clear();
    }
    else
    {
        Error();
        return;
    }
}

void Load(std::string const &argument, std::vector<std::vector<std::string>> &container)
{
    std::ifstream targetFile {argument+".csv"};
    std::string line;
    if(targetFile)
    {
        while(std::getline(targetFile, line))
        {
            std::vector<std::string> tempVector;
            std::string delimiter {","};
            line+=delimiter;
            size_t pos {0};
            while((pos=line.find(delimiter))!=std::string::npos)
            {
                tempVector.push_back(line.substr(0, pos));
                line.erase(0, pos+delimiter.length());
            }
            container.push_back(tempVector);
        }
    }
    else
    {
        Error();
        return;
    }
}

void Show(std::string const &argument, std::vector<std::vector<std::string>> &container)
{
    if(argument=="song"||argument=="songs")
    {
        SortAlpha(container, 0);
        for(std::vector<std::string> const &v : container)
        {
            std::cout << "--> ";
            for(std::string const &str : v)
            {
                std::cout << str;
                if(!(str==v.back()))
                    std::cout << " | ";
            }
            std::cout << std::endl;
        }
    }
    else if(argument=="album"||argument=="albums")
    {
        SortAlpha(container, 1);
        std::vector<std::string> usedAlbums{""};
        for(int i {0}; i<int(container.size()); i++)
        {
            if(std::find(usedAlbums.begin(), usedAlbums.end(), container[i][1])==std::end(usedAlbums))
            {
                usedAlbums.push_back(container[i][1]);
                std::cout << "--> " << container[i][1] << " | " << container[i][2] << std::endl;
            }
            std::cout << "\t/--> " << container[i][0] << std::endl;
        }
    }
    else if(argument=="artist"||argument=="artists")
    {
        SortAlpha(container, 2);
        std::vector<std::string> usedArtists {""}, usedAlbums {""};
        for(int i {0}; i<int(container.size()); i++)
        {
            if(std::find(usedArtists.begin(), usedArtists.end(), container[i][2])==std::end(usedArtists))
            {
                usedArtists.push_back(container[i][2]);
                std::cout << "--> " << container[i][2] << std::endl;
            }
            if(std::find(usedAlbums.begin(), usedAlbums.end(), container[i][1])==std::end(usedAlbums))
            {
                usedAlbums.push_back(container[i][1]);
                std::cout << "\t/--> " << container[i][1] << std::endl;
            }
            std::cout << "\t\t/--> " << container[i][0] << std::endl;
        }
    }
    else
    {
        Error();
        return;
    }
}

void SortAlpha(std::vector<std::vector<std::string>> &container, int const &index)
{
    std::sort(container.begin(), container.end(),
        [&index](std::vector<std::string> v1, std::vector<std::string> v2) -> bool
        {
            return std::tolower(v1[index].front())<std::tolower(v2[index].front());
        });
}