#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    while (1) {
        int opponentRow;
        int opponentCol;
        std::cin >> opponentRow >> opponentCol; std::cin.ignore();
        int validActionCount;
        std::cin >> validActionCount; std::cin.ignore();
        std::vector<int> rowList, colList; 
        for (int i = 0; i < validActionCount; i++) {
            int row;
            int col;
            std::cin >> row >> col; std::cin.ignore();
            rowList.push_back(row);
            colList.push_back(col);
        }
        int a {2};
        std::cout << rowList[a] << " " << colList[a] << std::endl;
    }
}