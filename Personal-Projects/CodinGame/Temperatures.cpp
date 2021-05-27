#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void Answer(int const result);

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n; // the number of temperatures to analyse
    std::cin >> n; std::cin.ignore();
    std::vector<int> temperatureList;
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        std::cin >> t; std::cin.ignore();
        temperatureList.push_back(abs(t));
    }
    int result {0};
    if(temperatureList.empty())
    {
        Answer(result);
    }
    std::sort(std::begin(temperatureList), std::end(temperatureList));
    Answer(temperatureList[0]);
    /*int test {0};
    int test2 {0};
    for(int const temp : temperatureList)
    {
        test=abs(temp);
        //test2=test;
        if()

    }*/
    /*int test {0};
    for(int i {0}; i < n; i++)
    {
        if(temperatureList[i]<test)
        {
            test=temperatureList[i];
            result
        }
    }*/

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}

void Answer(int const result)
{
    std::cout << result << std::endl;
}