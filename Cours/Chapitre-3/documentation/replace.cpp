#include <cassert>
#include <iostream>
#include <string>

int main()
{
    std::string phrase { "J'aimerai annuler ce texte." };
    std::string const mot { "remplacer" };

    phrase.replace(10, 7, mot);
    
    assert(phrase == "J'aimerai remplacer ce texte." && "Le texte n'a pas été modifié correctement.");
    return 0;
}