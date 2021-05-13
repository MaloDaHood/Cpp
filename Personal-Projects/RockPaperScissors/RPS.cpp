#include "RPS.hpp"

int main()
{
    bool playAgain {true};
    while(playAgain)
        playAgain=Game();
    return EXIT_SUCCESS;
}

bool Game()
{
    std::cout << "Welcome to a new game of Rock Paper Scissors." << std::endl;
    int playerCount {0};
    int computerCount {0};
    int const max {GetMax()};
    while(playerCount<max&&computerCount<max)
    {
        char const playerMove {GetPlayerMove()};
        char const computerMove {GetComputerMove()};
        system("cls");
        DisplayMoves(playerMove, computerMove);
        if(playerMove==computerMove)
        {
            std::cout << "It's a tie !" << std::endl;
            continue;
        }
        if(PlayerWins(playerMove, computerMove))
        {
            playerCount++;
            std::cout << "You win !" << std::endl;
        }
        else
        {
            computerCount++;
            std::cout << "The computer wins !" << std::endl;
        }
        std::cout << "Player : " << playerCount << " points.\nComputer : " << computerCount << " points." << std::endl;
    }
    if(playerCount==max)
        std::cout << "You win this game, you are the first to reach " << max << " points." << std::endl;
    else
        std::cout << "The computer wins this game, it is the first to reach " << max << " points." << std::endl;
    return PlayAgain();
}

char GetPlayerMove()
{
    int move {0};
    bool goodInput {false};
    do
    {
        std::cout << "Which move do you want to do ?\n1. Rock\n2. Paper\n3. Scissors" << std::endl;
        std::cin >> move;
        if(std::cin.fail()||move<1||move>3)
            InputError(3);
        else
            goodInput=true;
    } while (!goodInput);
    if(move==1)
        return 'R';
    else if(move==2)
        return 'P';
    else
        return 'S';
}

void InputError(int const max)
{
    if(max==2)
        std::cout << "You have to  input either 1 or " << max << "." << std::endl;
    else
        std::cout << "You have to input a number between 1 and " << max << "." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

char GetComputerMove()
{
    std::array<char, 3> const lettersArray {'R', 'P', 'S'};
    srand ((unsigned)time(0));
    return lettersArray[rand()%3];
}

bool PlayerWins(char const playerMove, char const computerMove)
{
    if(playerMove=='R')
        if(computerMove=='S')
            return true;
        else
            return false;
    else if(playerMove=='P')
        if(computerMove=='R')
            return true;
        else
            return false;
    else
        if(computerMove=='P')
            return true;
        else
            return false;
}

void DisplayMoves(char const playerMove, char const computerMove)
{
    std::string fullPlayerMove;
    if(playerMove=='R')
        fullPlayerMove="Rock";
    else if(playerMove=='P')
        fullPlayerMove="Paper";
    else
        fullPlayerMove="Scissors";
    std::string fullComputerMove;
    if(computerMove=='R')
        fullComputerMove="Rock";
    else if(computerMove=='P')
        fullComputerMove="Paper";
    else
        fullComputerMove="Scissors";
    std::cout << "You chose " << fullPlayerMove << " and the computer chose " << fullComputerMove << "." << std::endl; 
}

bool PlayAgain()
{
    int choice {0};
    bool goodInput {false};
    do
    {
        std::cout << "Do you want to play again ?\n1. YES\n2. NO" << std::endl;
        std::cin >> choice;
        if(std::cin.fail()||choice<1||choice>2)
            InputError(2);
        else
            goodInput=true;
    } while (!goodInput);
    if(choice==1)
        return true;
    else 
        return false;
}

int GetMax()
{
    int max {0};
    bool goodInput {false};
    do
    {
        std::cout << "How many points does a player need to get in order to win the game ?" << std::endl;
        std::cin >> max;
        if(std::cin.fail()||max<1||max>100)
            InputError(100);
        else
            goodInput=true;
    } while (!goodInput);
    system("cls");
    return max;
}