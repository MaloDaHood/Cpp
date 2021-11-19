#include <iostream>
#include <iomanip>
#include <chrono>
#include <boost/lexical_cast.hpp>

int main()
{
    double x {1};
    double pi {4/x};
    int it;
    std::string piDecimals {"14159265358979323846264338327950288419716939937510582"};
    std::cout << "How many iterations ?" << std::endl;
    std::cin >> it;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i {0}; i<it; i++)
    {
        x += 2;
        if(i%2 == 0)
            pi -= 4/x;
        else
            pi += 4/x;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::string piStr {boost::lexical_cast<std::string>(pi)};
    std::cout << std::setprecision(15) << "Pi : " << pi << std::endl;
    
    // for(int i {0}; i<int(piDecimals.length()); i++)
    // {
    //     if(piDecimals[i] != piStr[i+2])
    //     {
    //         std::cout << "Accurate up to the " << i << "th decimal." << std::endl;
    //         break;
    //     }
    // }

    int i;
    for(i = 0; piDecimals[i] == piStr[i+2]; i++);
    std::cout << "Accurate up to the " << i << "th decimal." << std::endl;


    std::chrono::duration<double, std::milli> float_ms = end - start;
    std::cout << "Elapsed time is " << float_ms.count() << " milliseconds" << std::endl;
    return 0;
}
