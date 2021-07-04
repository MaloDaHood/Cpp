#include <iostream>
#include <vector>

int main()
{
    int min {1}, max {100};
    std::cout << "Quel nombre entre " << min << " et " << max << " ?\n>";
    int number;
    std::cin >> number;
    char answer;
    while(true)
    {
        int guess {((max-min)/2)+min};
        std::cout << guess << " ?" << std::endl;
        std::cin >> answer;
        if(answer=='=')
        {
            break;
        }
        else if(answer=='-')
        {
            max=guess;
        }
        else if(answer=='+')
        {
            min=guess;
        }
        else
        {
            std::cout << "Error" << std::endl;
            continue;
        }
    }
    std::cout << "C'etait " << number << " !" << std::endl;
    return 0;
}