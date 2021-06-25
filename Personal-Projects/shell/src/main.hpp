#ifndef MAIN
#define MAIN

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <fstream>
#include <cstdio>

std::string ParseInput(std::string const &input, std::vector<std::string> &splitedArguments);

void CommandError(std::string const &command);
void OSError();
void NoArgumentsError();
void TooMuchArgumentsError(int const numberOfArguments);
void MissingArgumentsError(int const numberOfArguments);
void WrongArgumentError(std::string const &argument, std::unordered_set<std::string> const &availableArguments);
void ImpossibleToCreateNewFileError();
void ImpossibleToDeleteNewFileError();

void Say(std::vector<std::string> &arguments);
void CreateFile(std::vector<std::string> const &splitedArguments, std::string const &currentLocation);
void DeleteFile(std::vector<std::string> const &splitedArguments, std::string const &currentLocation);

void GetOS();

#endif