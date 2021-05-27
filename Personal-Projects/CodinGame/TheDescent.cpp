#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{

    // game loop
    while (1) {
        std::vector<int> mountainHeightList;
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            std::cin >> mountainH; std::cin.ignore();
            mountainHeightList.push_back(mountainH);
        }
        int reponse {0};
        int test {0};
        for(int i {0}; i < 8; i++)
        {
            if(mountainHeightList[i]>test)
            {
                test=mountainHeightList[i];
                reponse=i;
            }
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        std::cout << reponse << std::endl; // The index of the mountain to fire on.
    }
}