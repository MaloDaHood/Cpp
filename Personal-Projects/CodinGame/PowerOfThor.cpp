#include <iostream>
#include <string>
int main()
{
    int lightX;
    int lightY;
    int initialTX;
    int initialTY;
    std::cin >> lightX >> lightY >> initialTX >> initialTY; std::cin.ignore();
    while (1) {
        int remainingTurns;
        std::cin >> remainingTurns; std::cin.ignore();
        std::string direction;
        if(initialTY>lightY)
        {
            direction.push_back('N');
            initialTY--;
        }
        else if(initialTY<lightY)
        {
            direction.push_back('S');
            initialTY++;
        }
        if(initialTX>lightX)
        {
            direction.push_back('W');
            initialTX++;
        }
        else if(initialTX<lightX)
        {
            direction.push_back('E');
            initialTX--;
        }
        std::cout << direction << std::endl;
    }
}