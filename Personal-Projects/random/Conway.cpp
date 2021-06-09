#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> GetDigits(int const x);
int VectorToInt(std::vector<int> v);

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    int x {11};
    for(int i {0}; i<n; i++)
    {
        std::cout << x << "!" << std::endl;
        std::vector<int> listDigit {GetDigits(x)};
        std::vector<int> finalNumber;
        int actualDigit {listDigit[0]};
        int count {1};
        for(int i {0}; i<listDigit.size(); i++)
        {
            if(listDigit[i]==actualDigit)
            {
                count++;
            }
            else
            {
                finalNumber.push_back(count);
                finalNumber.push_back(listDigit[i-1]);
                actualDigit=listDigit[i];
                count=1;
            }
        }
        x=VectorToInt(finalNumber);
        for(int in : finalNumber)
        {
            std::cout << in;
        }
        std::cout << std::endl;
    }
    return 0;
}

std::vector<int> GetDigits(int x)
{
    std::vector<int> listDigit;
    while(x>0)
    {
        listDigit.push_back(x%10);
        x/=10;
    }
    std::reverse(std::begin(listDigit), std::end(listDigit));
    return listDigit;
}

int VectorToInt(std::vector<int> v)
{
    reverse(v.begin(), v.end());
    int decimal = 1;
    int total = 0;
    for (auto& it : v)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}