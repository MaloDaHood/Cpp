#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string LON;
    std::cin >> LON; std::cin.ignore();
    std::string LAT;
    std::cin >> LAT; std::cin.ignore();
    int N;
    std::cin >> N; std::cin.ignore();
    std::vector<std::string> listDefib;
    for (int i = 0; i < N; i++) {
        std::string DEFIB;
        getline(std::cin, DEFIB);
        listDefib.push_back(DEFIB);
    }
    for(std::string defib : listDefib)
    {
        for(int i {0}; i<defib.length(); i++)
        {
            if(defib[i]==';')
            {
                std::vector::erase()
            }
        }
    }
    std::cout << "answer" << std::endl;
}