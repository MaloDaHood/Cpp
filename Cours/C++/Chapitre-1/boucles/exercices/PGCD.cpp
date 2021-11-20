#include <iostream>

int main()
{
    std::cout << "Quel est le premier nombre ?" << std::endl;
    int a;
    std::cin >> a;
    std::cout << "Quel est le deuxieme nombre ?" << std::endl;
    int b;
    std::cin >> b;
    int r {a%b};
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    std::cout << "Le PGCD de ces deux nombres est : " << b << std::endl;
    return 0;
}