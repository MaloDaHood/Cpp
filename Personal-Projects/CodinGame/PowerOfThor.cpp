#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    std::cin >> lightX >> lightY >> initialTX >> initialTY; std::cin.ignore();
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        std::cin >> remainingTurns; std::cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        if(initialTX>lightX)
        {
            std::cout << "W" << std::endl;
        }
        else if(initialTX<lightX)
        {
            std::cout << "E" << std::endl;
        }
        else
        {
            if(initialTY>lightY)
            {
                std::cout << "N" << std::endl;
            }
            else if(initialTY<lightY)
            {
                std::cout << "S" << std::endl;
            }
            else
            {
                continue;
            }
        }
        // A single line providing the move to be made: N NE E SE S SW W or NW
    }
}