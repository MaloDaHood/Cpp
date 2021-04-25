#include <iostream>
#include <string>

int main()
{
    bool bonneEntree {false};
    do
    {
        std::cout << "Quel age as-tu ?" << std::endl;
        int age {0};
        bool check {std::cin >> age};
        if(check)
        {
            std::cout << "Tu as " << age << " ans" << std::endl;
            bonneEntree = true;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur, reessaye." << std::endl;
        }
    } while(!bonneEntree);
    
    return 0;
}