#include <iostream>

int main()
{
    std::cout << "Quel nombre ?";
    int n;
    std::cin >> n;
    for(int i {0}; i<=n; i++)
    {
        if(i%2==0)
        {
            continue;
        }
        std::cout << i << std::endl;
    }
    return 0;
}