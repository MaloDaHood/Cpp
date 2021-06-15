#include <iostream>
#include <vector>

int main()
{
    int input, sum {0};
    do
    {
        std::cout << "Entrez un nombre : ";
        std::cin >> input;
        std::cin.ignore();
        sum+=input;
    } while (sum<=100);
    std::cout << "FINSHED" << std::endl;
    return 0;
}