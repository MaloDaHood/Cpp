#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    int C;
    std::cin >> C; std::cin.ignore();
    std::vector<int> budget;
    int totalBudget {0};
    for (int i = 0; i < N; i++) {
        int B;
        std::cin >> B; std::cin.ignore();
        totalBudget+=B;
        budget.push_back(B);
    }
    if(totalBudget<C)
        std::cout << "IMPOSSIBLE" << std::endl;
    else
    {
        if(C%totalBudget==0)
        {
            for(int i {0}; i<N; i++)
            {
                std::cout << budget[0] << std::endl; 
            }
        }
    }
}