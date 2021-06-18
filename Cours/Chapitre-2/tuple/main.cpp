#include <iostream>
#include <tuple>
#include <string>

int main()
{
    using namespace std::literals;
    auto infos=std::make_tuple("Malo"s, "Massieu"s, "Homme"s, 17);
    std::cout << "Prenom : " << std::get<0>(infos) << std::endl;
    std::cout << "Nom : " << std::get<1>(infos) << std::endl;
    std::cout << "Age : " << std::get<3>(infos) << std::endl;
    std::get<3>(infos)+=1;
    std::cout << "Age maintenant : " << std::get<3>(infos) << std::endl;
}