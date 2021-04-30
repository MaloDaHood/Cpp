#include <iostream>

int main()
{
    std::cout << "Programme pour obtenir le PGCD et le PPCM de deux nombres." << std::endl;
    std::cout << "Premier nombre ?" << std::endl;
    int p;
    std::cin >> p;
    std::cout << "Deuxieme nombre ?" << std::endl;
    int k;
    std::cin >> k;
    int s {p};
    int c {k};
    int w {p%k};
    int m;
    while(w>0)
    {
        p=k;
        k=w;
        w=p%k;
        m=s*c/k;
    }
    std::cout << "PGCD = " << k << "\nPPCM = " << m << "\nReste = " << w << std::endl;
    if(k==1)
        std::cout << "Ils sont premiers entre eux !" << std::endl;
    return 0;
}