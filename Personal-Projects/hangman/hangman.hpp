#ifndef PENDU
#define PENDU

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

bool Game();
std::string NewWord();
bool IsLetter(std::string const word);
std::string Uppercase(std::string word);
std::string NewLetter();
bool PlayAgain();
void InputError();
void ClearBuffer();
std::vector<int> Setup(int const wordLength, std::vector<char>& lettersArray, std::string const word);
bool Win(std::vector<int> const intArray);
std::vector<int> Compare(char const letter, std::vector<char> const lettersArray, std::vector<int> intArray);
void DisplayWord(std::vector<char> const lettersArray, std::vector<int> const intArray);
void UsedLetters(std::vector<char>& letterUsed, char const letter, std::vector<char> const lettersArray);

#endif