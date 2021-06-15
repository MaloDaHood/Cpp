#include <iostream>

int main()
{
    int n;
    std::cout << "Entrez un nombre : ";
    std::cin >> n;
    std::cin.ignore();
    for(int i {1}; i<n; i++)
    {
        if(n%i==0)
            std::cout << i << " ";
    }
    return 0;
}