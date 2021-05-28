#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    std::cin >> lightX >> lightY >> initialTX >> initialTY; std::cin.ignore();
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
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