#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream input("input.txt");
    int count {0};
    int lastValue {10000};
    std::vector<int> values;
    values.reserve(2000);
    for(std::string line ; std::getline(input, line);)
    {
        values.push_back(std::stoi(line));
    }
    input.close();
    for(size_t i {0}; i < values.size() - 2; i++)
    {
        int actualValue {values[i] + values[i+1] + values[i+2]};
        if(actualValue > lastValue)
            count++;
        lastValue = actualValue;
    }
    std::cout << count << std::endl;
    return 0;
}