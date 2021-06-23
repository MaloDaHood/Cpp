#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <array>
#include <unordered_set>
#include <set>

template <typename Collection>
void Iterer(Collection const &collec)
{
    std::for_each(collec.begin(), collec.end(), [](auto const &it){std::cout << it << std::endl;});
}

int main()
{
    std::vector<std::string> vecStr {"qgr", "qgfs", "qsgr"};
    std::array<int, 4> arr {54, 85, 8, 89};
    std::string str {"yolo"};
    std::unordered_set<char> uSet {'m', 'a', 'l', 'o'};
    std::set<char> sSet {'m', 'a', 'l', 'o'};
    std::tuple tup {15, 20, 25}; //doesn't work
    Iterer(arr);
}