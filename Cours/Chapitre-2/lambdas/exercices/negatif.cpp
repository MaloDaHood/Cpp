#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> const nombres { 1, 2, 3, 4, -5, 6, 7 };
    if(std::any_of(std::begin(nombres), std::end(nombres), [](int nombre) -> bool {return nombre<0;}))
        std::cout << "Il y a des negatifs." << std::endl;
    else
        std::cout << "Il n'y a que des entiers." << std::endl;
    return 0;
}