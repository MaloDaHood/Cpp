#include <iostream>
#include <vector>

void Answer(int const result);

int main()
{
    int n;
    std::cin >> n; std::cin.ignore();
    std::vector<int> temperatureList;
    for (int i = 0; i < n; i++) 
    {
        int t;
        std::cin >> t; std::cin.ignore();
        temperatureList.push_back(t);
    }
    if(temperatureList.empty())
        Answer(0);
    int curr {abs(0-temperatureList[0])};
    if(temperatureList.size()==1)
        curr=temperatureList[0];
    for(int i {0}; i<temperatureList.size(); i++)
    {
        if(temperatureList[i]==-(curr))
            curr=abs(temperatureList[i]);
        if(temperatureList[i]==temperatureList[i+1]) // hard-coded --> pas ouf du tout
            curr=temperatureList[i];
        if(abs(0-temperatureList[i])<curr)
            curr=temperatureList[i];
    }
    Answer(curr);
}

void Answer(int const result)
{
    std::cout << result << std::endl;
}