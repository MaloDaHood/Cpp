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
    int iSanta, jSanta {0};
    int iRobot, jRobot {0};
    int count {0};
    std::vector<std::pair<int, int>> visitedHouses;
    std::string line;
    std::getline(input, line);
    std::string test {"^v^v^v^v^v"};
    for(char const &c : line)
    {
        if(count % 2 == 0)
        {
            if(c == '^')
                jSanta--;
            else if(c == 'v')
                jSanta++;
            else if(c == '<')
                iSanta--;
            else if(c == '>')
                iSanta++;
        }
        else
        {
            if(c == '^')
                jRobot--;
            else if(c == 'v')
                jRobot++;
            else if(c == '<')
                iRobot--;
            else if(c == '>')
                iRobot++;
        }

        if(std::any_of(visitedHouses.begin(), visitedHouses.end(), 
            [iSanta, jSanta, iRobot, jRobot](std::pair<int, int> pair)->bool
            {return (pair.first == iSanta && pair.second == jSanta) || (pair.first == iRobot && pair.second == jRobot);}))
        {
            continue;
        }
        else
        {
            if(count % 2 == 0)
                visitedHouses.push_back(std::make_pair(iSanta, jSanta));
            else
                visitedHouses.push_back(std::make_pair(iRobot, jRobot));
            total++;
        }
        count++;
    }
    input.close();
    std::cout << total << std::endl;
    return 0;
}