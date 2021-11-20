#include <iostream>
#include <complex>

int main()
{
    auto resultat {std::sqrt(std::complex<double>(-1, 0))};
    std::cout << "Racine carre de -1 : " << resultat << std::endl;
    std::cout << "Partie reelle : " << resultat.real() << std::endl;
    std::cout << "Partie imaginaire : " << resultat.imag() << std::endl;
    return 0;
}