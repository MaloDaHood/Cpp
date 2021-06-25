#include "main.hpp"

void GetOS()
{
    #ifdef _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #elif __linux__
        system("clear");
    #elif __unix || __unix__
        system("clear");
    #else
        OSError();
    #endif
}