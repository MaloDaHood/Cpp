#include <iostream>
#include <string>
#include <vector>

void Wait();
void Block();

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    std::cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; std::cin.ignore();
    std::vector<int> elevatorList(nbFloors);
    for (int i {0}; i<nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        std::cin >> elevatorFloor >> elevatorPos; std::cin.ignore();
        elevatorList[elevatorFloor]=elevatorPos;
    }

    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        std::string direction; // direction of the leading clone: LEFT or RIGHT
        std::cin >> cloneFloor >> clonePos >> direction; std::cin.ignore();
        if(cloneFloor==-1&&clonePos==-1&&direction=="NONE")
        {
            Wait();
        }
        else if(cloneFloor==exitFloor)
        {
            if(exitPos>clonePos&&direction=="LEFT")
            {
                Block();
            }
            else if(exitPos<clonePos&&direction=="RIGHT")
            {
                Block();
            }
            else
            {
                Wait();
            }
        }
        else if(elevatorList[cloneFloor]>clonePos&&direction=="LEFT")
        {
            Block();
        } 
        else if(elevatorList[cloneFloor]<clonePos&&direction=="RIGHT")
        {
            Block();
        }
        else
        {
            Wait();
        }
    }
}

void Wait()
{
    std::cout << "WAIT" << std::endl;
}

void Block()
{
    std::cout << "BLOCK" << std::endl;
}