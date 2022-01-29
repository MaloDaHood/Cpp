#include <iostream>
#include <vector>

int main()
{
    std::vector<double> marks;

    while(true)
    {
        std::string mark;
        std::cin >> mark;
        if(mark == "q")
            break;
        marks.push_back(std::stod(mark));
    }

    double total {0};
    for(double mark : marks)
        total += mark;

    double average {total / marks.size()};

    std::cout << average << std::endl;

    return EXIT_SUCCESS;
}