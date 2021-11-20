#include <iostream>
#include <vector>

int main()
{
    std::vector<int> tableau {0,1,2,3,4,5,6,7,8,9,10};
    std::vector<int>::iterator premierTableau {std::begin(tableau)};
    std::vector<int>::iterator dernierTableau {std::end(tableau)};
    premierTableau+=4;
    std::cout << *premierTableau << std::endl;
    dernierTableau--;
    std::cout << *dernierTableau << std::endl;
}