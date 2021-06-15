#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    system("cls");
    for(int i {1}; i<=n; i++)
    {
        for(int j {0}; j<=i; j++)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    for(int i {n}; i>0; i--)
    {
        for(int j {i}; j>0; j--)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}