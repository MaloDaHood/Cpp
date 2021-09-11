#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <array>
#include <limits>

class Game
{
    public:
        Game(int const &scoreX, int const &scoreO);
        bool checkEnd();
        void increaseTurns();
        void displayBoard();
        bool setCase(int const &place, char const &player);
        void displayScoreAndWinner(char const &player);
        static bool keepPlaying();
        std::array<int, 2> getScoreArray();
        static void inputError(int const &min, int const &max);
        static void clear();
    private:
        char m_board[9] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int m_turns {0};
        int m_XPoints;
        int m_OPoints;
};

#endif