#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    std::vector<int> piList;
    for (int i = 0; i < N; i++) {
        int pi;
        std::cin >> pi; std::cin.ignore();
        piList.push_back(pi);
    }
    std::sort(std::begin(piList), std::end(piList));
    int test {abs(piList[0]-piList[1])};
    for(int i {1}; i<N; i++)
    {
        if(abs(piList[i]-piList[i+1])<test)
            test=abs(piList[i]-piList[i+1]);
    }
    std::cout << test << std::endl;
}