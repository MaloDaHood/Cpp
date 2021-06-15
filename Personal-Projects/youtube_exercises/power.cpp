#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Valeur de N ?" << std::endl;
    int n {0};
    std::cin >> n;
    std::cin.ignore();
    std::cout << n << " a la puissance " << n << " est egal a : " << pow(n, n) << "." << std::endl;
    return 0;
}