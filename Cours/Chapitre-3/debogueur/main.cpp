#include <iostream>
#include <vector>

void fonction()
{
    for (int i { 0 }; i < 100; ++i)
    {
        std::cout << i * 2 << std::endl;
    }
}

int main()
{
    fonction();
    return 0;
}