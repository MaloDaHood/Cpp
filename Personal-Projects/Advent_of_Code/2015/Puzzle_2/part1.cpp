#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<int> parse(std::string str);
int process(std::vector<int> const &vec);

int main()
{
    std::ifstream input("input.txt");
    int total {0};
    for(std::string line; std::getline(input, line);)
    {
        total += process(parse(line));
    }
    input.close();
    std::cout << total << std::endl;
    return 0;
}

std::vector<int> parse(std::string str)
{
    std::vector<int> result;
    std::string delimiter {"x"};
    size_t pos {0};
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        result.push_back(std::stoi(token));
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(std::stoi(str));
    return result;
}

int process(std::vector<int> const &vec)
{
    int side1 {vec[0] * vec[1]};
    int side2 {vec[1] * vec[2]};
    int side3 {vec[2] * vec[0]};
    int smallest1 {std::min(side1, side2)};
    int smallest2 {std::min(side2, side3)};
    int smallest {std::min(smallest1, smallest2)};
    return (2 * side1) + (2 * side2) + (2 * side3) + smallest;
}