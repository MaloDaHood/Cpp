#include <iostream>

int main()
{
    std::cout << "How long ?" << std::endl;
    int lenght;
    std::cin >> lenght;
    
    double F0 {0.0};
    double F1 {1.0};
    double n;

    std::cout << "F0:" << F0 << std::endl << "F1:" << F1 << std::endl;

    for(int i {1}; i<lenght; i++)
    {
        n=F0+F1;
        F0=F1;
        F1=n;
        std::cout << "F" << i+1 << ":" << n << std::endl;
    }

    return 0;
}