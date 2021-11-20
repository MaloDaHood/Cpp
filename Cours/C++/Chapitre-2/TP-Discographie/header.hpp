#ifndef HEADER
#define HEADER

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <fstream>

void Error();
std::string SplitInput(std::string const &input, std::string &arguments);
void ParseArguments(std::vector<std::string> &infos, std::string &arguments);
std::string RemoveBlanks(std::string &str);
void Save(std::string const &argument, std::vector<std::vector<std::string>> &container);
void Load(std::string const &argument, std::vector<std::vector<std::string>> &container);
void Show(std::string const &argument, std::vector<std::vector<std::string>> &container);
void SortAlpha(std::vector<std::vector<std::string>> &container, int const &index);

#endif