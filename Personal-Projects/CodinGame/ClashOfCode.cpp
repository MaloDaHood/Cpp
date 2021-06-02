#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    std::vector<int> listA;
    for(int i {0}; i<N; i++)
    {
        int A;
        std::cin >> A; std::cin.ignore();
        listA.push_back(A);
    }
    if(N==0||listA.empty())
    {
        std::cout << 0 <<std::endl; 
        return 0;
    }
    std::sort(std::begin(listA), std::end(listA));
    std::cout << int(sqrt(listA[0]*listA[N-1])) <<std::endl;
    return 0;
}