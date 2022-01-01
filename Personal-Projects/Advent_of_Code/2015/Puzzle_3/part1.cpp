#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream input("input.txt");
    int total {0};
    int i, j {0};
    std::vector<std::pair<int, int>> visitedHouses {std::make_pair(0 ,0)};
    std::string line;
    std::getline(input, line);
    std::string test {"^v^v^v^v^v"};
    for(char const &c : line)
    {
        if(c == '^')
            j--;
        else if(c == 'v')
            j++;
        else if(c == '<')
            i--;
        else if(c == '>')
            i++;
        if(std::any_of(visitedHouses.begin(), visitedHouses.end(), 
            [i, j](std::pair<int, int> pair)->bool{return pair.first == i && pair.second == j;}))
        {
            continue;
        }
        else
        {
            //std::tuple<int> tup {(i, j)};
            visitedHouses.push_back(std::make_pair(i, j));
            total++;
        }
    }
    input.close();
    std::cout << total << std::endl;
    return 0;
}

//  North '^' = 1
//  South 'v' = -1
//  East '>' = 1
//  West '<' = -1