#include "game.hpp"

Game::Game(int const &scoreX, int const &scoreO)
{
    m_XPoints=scoreX;
    m_OPoints=scoreO;
}

bool Game::checkEnd()
{
    // Check each line from the bottom
    for(int i {0}; i<7; i+=3)
    {
        if((m_board[i]==m_board[i+1])&&(m_board[i+1]==m_board[i+2])&&(m_board[i]!=' '))
        {
            displayScoreAndWinner(m_board[i]);
            return true;
        }
    }

    // Check each column from the left
    for(int i {0}; i<3; i++)
    {
        if((m_board[i]==m_board[i+3])&&(m_board[i+3]==m_board[i+6])&&(m_board[i]!=' '))
        {
            displayScoreAndWinner(m_board[i]);
            return true;
        }
    }

    // Check each diagonal
    if((m_board[0]==m_board[4])&&(m_board[4]==m_board[8])&&(m_board[0]!=' '))
    {
        displayScoreAndWinner(m_board[0]);
        return true;
    }
    else if((m_board[2]==m_board[4])&&(m_board[4]==m_board[6])&&(m_board[2]!=' '))
    {
        displayScoreAndWinner(m_board[2]);
        return true;
    }

    // Check if board is full
    else if(m_turns==9)
    {
        std::cout << "Nobody wins !" << std::endl;
        return true;
    }

    else
    {
        return false;
    }
}

void Game::increaseTurns()
{
    m_turns++;
}

void Game::displayBoard()
{
    std::cout << m_board[6] << '|' << m_board[7] << '|' << m_board[8] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[3] << '|' << m_board[4] << '|' << m_board[5] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[0] << '|' << m_board[1] << '|' << m_board[2] << std::endl;
}

bool Game::setCase(int const &place, char const &player)
{
    if(m_board[place]==' ')
    {
        m_board[place]=player;
        return true;
    }
    else
    {
        std::cout << "This case is already taken. Choose another one." << std::endl;
        return false;
    }
}

void Game::displayScoreAndWinner(char const &player)
{
    clear();
    displayBoard();
    std::cout << player << " wins !" << std::endl;
    if(player=='X')m_XPoints++;else m_OPoints++;
    std::cout << "X : " << m_XPoints << " points." << std::endl;
    std::cout << "O : " << m_OPoints << " points." << std::endl;
}

bool Game::keepPlaying()
{
    bool valid {false};
    int answer {0};
    do
    {
        std::cout << "Do you want to play a new game ?\n1. YES\n2. NO" << std::endl;
        std::cin >> answer;
        if(std::cin.fail()||answer<1||answer>2)
            inputError(1, 2);
        else
            valid=true;
    } while (!valid);
    if(answer==1)return true;else return false;
}

std::array<int, 2> Game::getScoreArray()
{
    return {m_XPoints, m_OPoints};
}

void Game::inputError(int const &min, int const &max)
{
    if(max-min==1)
        std::cout << "You have to input either " << min << " or " << max << "." << std::endl;
    else
        std::cout << "You have to input a number between " << min << " and " << max << "." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void Game::clear()
{
    #ifdef _WIN32
        system("cls");
    #elif __linux__ || __unix__
        system("clear");
    #else
        std::cout << "OS not suported for \"clear()\" function." << std::endl;
    #endif
}