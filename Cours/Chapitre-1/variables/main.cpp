#include <iostream>
#include <string>

int main()
{
    using namespace std::literals;

    auto age {0};
    std::string nom;
    std::cout << "Comment tu t'appel ?" << std::endl;
    std::cin >> nom;
    std::cout << "T'as quel age ?" << std::endl;
    std::cin >> age;
    std::cout << "Tu t'appel " << nom << " et tu as " << age << " ans" << std::endl;

    return 0;
}