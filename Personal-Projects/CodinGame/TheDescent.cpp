#include <iostream>

int main()
{
    while (1) {
        int reponse {0};
        int test {0};
        for (int i = 0; i < 8; i++) 
        {
            int mountainH;
            std::cin >> mountainH; std::cin.ignore();
            if(mountainH>test)
            {
                test=mountainH;
                reponse=i;
            }
        }
        std::cout << reponse << std::endl;
    }
}