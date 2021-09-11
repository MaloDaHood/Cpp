#include "game.hpp"

int main()
{
    // scores[0]=X's score && scores[1]=O's score
    std::array<int, 2> scores {0, 0};
    do
    {
        Game game(scores[0], scores[1]);
        char player {'X'};
        while(!game.checkEnd())
        {
            Game::clear();
            game.displayBoard();
            bool valid {false};
            int place;
            do
            {
                std::cout << player << " > ";
                std::cin >> place;
                if(std::cin.fail()||place<1||place>9)
                    Game::inputError(1, 9);
                else
                    valid=true; 
            }while(!valid||!game.setCase(place-1, player));
            game.increaseTurns();
            if(player=='X')player='O';else player='X';
        }
        scores=game.getScoreArray();
    } while(Game::keepPlaying());
}