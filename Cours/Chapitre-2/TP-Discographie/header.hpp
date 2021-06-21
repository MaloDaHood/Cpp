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
void Add(std::vector<std::string> const &infos, std::ofstream &tempFile);
void ParseArguments(std::vector<std::string> &infos, std::string &arguments);
void Save(std::string const &argument);

#endif