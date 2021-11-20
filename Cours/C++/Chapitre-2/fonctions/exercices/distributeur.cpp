#include <iostream>

void DecoupeSomme(int somme);

int main()
{
    std::cout << "Quelle somme ?" << std::endl;
    int somme;
    std::cin >> somme;
    DecoupeSomme(somme);
    return 0;
}

void DecoupeSomme(int somme)
{
    int billets100 {0};
    int billets50 {0};
    int billets20 {0};
    int billets10 {0};
    int billets5 {0};
    int piece2 {0};
    int piece1 {0};
    while(somme!=0)
    {
        if(somme>=100)
        {
            somme-=100;
            billets100++;
            continue;
        }
        else if(somme>=50)
        {
            somme-=50;
            billets50++;
            continue;
        }
        else if(somme>=20)
        {
            somme-=20;
            billets20++;
            continue;
        }
        else if(somme>=10)
        {
            somme-=10;
            billets10++;
            continue;
        }
        else if(somme>=5)
        {
            somme-=5;
            billets5++;
            continue;
        }
        else if(somme>=2)
        {
            somme-=2;
            piece2++;
            continue;
        }
        else if(somme>=1)
        {
            somme-=1;
            piece1++;
            continue;
        }
    }
    std::cout << "Il reste : " << somme;
}