#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::pair<std::string, int> parse(std::string str);

int main()
{
    std::ifstream input("input.txt");
    int depth {0};
    int horizontal {0};
    for(std::string line; std::getline(input, line);)
    {
        if(parse(line).first == "forward")
            horizontal += parse(line).second;
        else if(parse(line).first == "down")
            depth += parse(line).second;
        else
            depth -= parse(line).second;
    }
    input.close();
    std::cout << depth * horizontal << std::endl;
    return 0;
}

std::pair<std::string, int> parse(std::string str)
{
    std::pair<std::string, int> result;
    std::string delimiter {" "};
    size_t pos {0};
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        result.first = token;
        str.erase(0, pos + delimiter.length());
    }
    result.second = std::stoi(str);
    return result;
}