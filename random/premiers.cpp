#include <iostream>
#include <cmath>

int main()
{
    std::cout << "How long" << std::endl;
    int lenght;
    std::cin >> lenght;

    double sqr;

    for(int i {1}; i<lenght; i++)
    {
        sqr=sqrt(i);
        for(int j {1}; j<sqr; j++)
        {
            if(i%j==0)
            {
                continue;
            }
            else
            {
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}