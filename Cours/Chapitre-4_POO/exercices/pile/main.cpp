#include <cassert>
#include <vector>
#include "pile.hpp"

int main()
{
    Pile pile {};
    assert(pile.est_vide() && "La pile est vide.");
    assert(pile.taille() == 0 && "Au début, la pile n'a aucun élément.");

    pile.ajouter(5);
    pile.ajouter(10);
    pile.ajouter(15);
    assert(pile.taille() == 3 && "Maintenant, la pile a trois éléments.");

    int const premier { pile.premier() };
    assert(premier == 5 && "Le premier élément vaut 5.");
    assert(pile.taille() == 3 && "La pile a toujours trois éléments.");

    pile.supprimer();
    assert(pile.taille() == 2 && "Maintenant, la pile n'a plus que deux éléments.");
    assert(!pile.est_vide() && "La pile n'est pas vide.");

    pile.supprimer();
    pile.supprimer();
    assert(pile.est_vide() && "Maintenant la pile est vide.");

    return 0;
}