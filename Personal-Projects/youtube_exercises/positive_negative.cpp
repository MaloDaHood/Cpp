#include <iostream>

int main()
{
    int input, sum {0}, product {1};
    do
    {
        std::cout << "Entrez un nombre : ";
        std::cin >> input;
        std::cin.ignore();
        if(input<0)
            break;
        sum+=input;
        product*=input;
    }while(input>0);
    std::cout << "Sum = " << sum << std::endl << "Product = " << product << std::endl;
    return 0;
}