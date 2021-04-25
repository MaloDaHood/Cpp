#include <iostream>

int main()
{
    std::cout << "Combien vaut n ?" << std::endl;
    int n;
    std::cin >> n;
    int a {0};
    int compteur {1};
    while(compteur<=n)
    {
        a+=compteur;
        compteur++;
    }
    std::cout << a << std::endl;

    // OU

    int formule {(n*(n+1))/2};
    std::cout << formule << std::endl;

    return 0;
}