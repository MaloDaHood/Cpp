#include <string>

/**
* @brief Saisie sécurisée avec `std::cin`.
* @details Vérifie que la variable demandée est du bon type et respecte un prédicat donné.
* En cas de fermeture du flux d'entrée, une exception `std::runtime_error` est levée.
* En cas de type invalide, le flux d'entrée est vidé.
* En cas de prédicat non respecté, un message d'erreur est affiché sur la sortie standard.
*
* @tparam T Le type de la valeur à récupérer.
* @tparam Predicat Un prédicat à passer pour personnaliser la vérification.
*
* @param[out] variable Une référence sur la variable de type `T` à récupérer.
* @param[in] predicat Un prédicat que l'entrée saisie doit respecter.
* 
* @pre Le type `T` doit être utilisable avec `std::cin`.
* @pre Le prédicat doit être de la forme `bool predicat(T variable)`.
* @post La variable sera initialisée correctement avec la valeur entrée.
*
*@exception std::runtime_error Si le flux d'entrée est fermé.
*/

template <typename T, typename Predicat>
void entree_securisee(T & variable, Predicat predicat)
{
    while (!(std::cin >> jour) || !predicat(variable))
    {
        if (std::cin.eof())
        {
            throw std::runtime_error("Le flux a été fermé !");
        }
        else if (std::cin.fail())
        {
            std::cout << "Entrée invalide. Recommence." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cout << "Le prédicat n'est pas respecté !" << std::endl;
        }
    }
}


/** @brief Détermine si une expression est correctement parenthésée.
* @details La fonction regarde si on a bien le même nombre de parenthèses
* ouvrantes et fermantes et si celles-ci sont bien ordonnées.
* 
* @param[in] expression Une chaîne de caractères à analyser.
* 
* @returns `true` si l'expression est bien parenthésée, `false` sinon.
*/
bool parentheses(std::string const & expression)
{
    int ouvrantes { 0 };
    int fermantes { 0 };

    for (auto const & caractere : expression)
    {
        if (caractere == '(')
        {
            ++ouvrantes;
        }
        else
        {
            ++fermantes;
        }

        if (fermantes > ouvrantes)
        {
            return false;
        }
    }

    return ouvrantes == fermantes;
}


/** @enum Couleur
* @brief Liste des couleurs possibles.
* @details La liste des trois couleurs applicables à l'écran de fond du programme.
*/
enum class Couleur
{
    /// @brief Un bleu profond.
    Bleu,
    /// @brief Un rouge vif.
    Rouge,
    /// @brief Un vert magnifique.
    Vert
};

/** @struct InformationsPersonnelles
* @brief Les informations personnelles d'un membre.
* @details Permet de stocker, sous un même type, le nom/prénom ainsi que le genre et l'âge d'un membre.
* Il n'y a pas de limite à la taille du nom ou du prénom du membre.
*/
struct InformationsPersonnelles
{
    /// @brief Le prénom du membre.
    std::string prenom;
    /// @brief Le nom de famille du membre.
    std::string nom;
    /// @brief Femme ou homme ?
    std::string sexe;
    /// @brief L'âge du membre.
    int age;
};