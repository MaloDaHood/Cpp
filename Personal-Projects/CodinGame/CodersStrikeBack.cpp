#include <iostream>

int main()
{
    while(1)
    {
        /*int x, y;
        std::cin >> x >> y;
        std::cin.ignore();
        int nextCheckpointX, nextCheckpointY;
        std::cin >>nextCheckpointX >> nextCheckpointY;
        std::cin.ignore();
        int nextCheckpointDistance, nextCheckpointAngle;
        std::cin >> nextCheckpointDistance >> nextCheckpointAngle;
        std::cin.ignore();
        int opponentX, opponentY;
        std::cin >> opponentX >> opponentY;
        std::cin.ignore();*/
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDistance; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        std::cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDistance >> nextCheckpointAngle; std::cin.ignore();
        int opponentX;
        int opponentY;
        std::cin >> opponentX >> opponentY; std::cin.ignore();
        int thrust {0};
        if(nextCheckpointAngle>90||nextCheckpointAngle<-90)
        {
            thrust=10;
            std::cout << nextCheckpointX << " " << nextCheckpointY << " " << thrust << std::endl;
        }
        else
            if(thrust<50)
                std::cout << nextCheckpointX << " " << nextCheckpointY << " BOOST" << std::endl;
            else
            {
                thrust=100;
                std::cout << nextCheckpointX << " " << nextCheckpointY << " " << thrust << std::endl;
            }
    }
    return 0;
}