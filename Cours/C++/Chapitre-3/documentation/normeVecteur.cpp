#include <cassert>
#include <cmath>

int main()
{
    int const x { 5 };
    int const y { 12 };
    int norme { 0 };

    norme=sqrt((x*x)+(y*y));

    norme=std::hypot(x, y);

    assert(norme == 13 && "La norme d'un vecteur v(5;12) vaut 13.");
    return 0;
}