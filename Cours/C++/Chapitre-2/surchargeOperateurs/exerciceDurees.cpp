#include <iostream>

struct Duree
{
    int heures;
    int minutes;
    int secondes;
};

void SecondsCount(Duree &temps)
{
    while(temps.heures>0)
    {
        temps.heures--;
        temps.minutes+=60;
    }
    while(temps.minutes>0)
    {
        temps.minutes--;
        temps.secondes+=60;
    }
}

int main()
{
    Duree temps {2, 30, 60};
    SecondsCount(temps);
    std::cout << temps.secondes;
    return 0;
}