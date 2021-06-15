#include <iostream>

int main()
{
    int n, sum{0};
    std::cout << "Entrez un nombre : ";
    std::cin >> n;
    std::cin.ignore();
    for(int i {1}; i<n; i++)
    {
        if(n%i==0)
            sum+=i;
    }
    std::cout << ((sum==n)?"It's a perfect number !":"It's not a perfect number !") << std::endl;
    return 0;
}