#include <iostream>
#include <string>
#include <vector>

int main()
{
    int num;
    std::cin >> num; std::cin.ignore();
    std::vector<std::string> list;
    for (int i = 0; i < num; i++) {
        std::string string;
        getline(std::cin, string);
    }
}