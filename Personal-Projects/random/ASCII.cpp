#include <iostream>
#include <vector>

int main()
{
    std::string str;
    getline(std::cin, str);
    std::vector<int> list;
    for(char c : str)
    {
        std::cout << int(c) << " / ";
        list.push_back(int(c));
    }
    std::cout << std::endl;
    for(int i : list)
    {
        std::cout << char(i);
    }
    return 0;
}