#include <iostream>
#include <string>

struct InformationsPersonnelles
{
    std::string prenom;
    std::string nom;
    std::string sexe;
    int age;
};

int main()
{
    InformationsPersonnelles info {"Malo", "Massieu", "Homme", 99};
    info.age=17;
    std::cout << "Je m'appelle " << info.prenom << " " << info.nom << " et j'ai " << info.age << " ans." << std::endl;
    return 0;
}