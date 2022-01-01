#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    int count {0};
    int lastValue {10000};
    for(std::string actualValue ; std::getline(input, actualValue);)
    {
        if(std::stoi(actualValue) > lastValue)
            count++;
        lastValue = std::stoi(actualValue);
    }
    input.close();
    std::cout << count << std::endl;
    return 0;
}