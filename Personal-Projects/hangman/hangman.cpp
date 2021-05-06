#include "hangman.hpp"

int main()
{
    bool playAgain {true};
    while (playAgain) //game loop
        playAgain=Game();
    return EXIT_SUCCESS;
}

bool Game() //main game function
{
    std::cout << "Welcome to a new game of hangman." << std::endl;
    std::string const word {NewWord()};
    std::vector<char> lettersArray;
    std::vector<int> intArray {Setup(word.length(), lettersArray, word)};
    std::vector<char> lettersUsed;
    do
    {
        /*std::cout << "\nlettersArray : ";
        for(char const lt : lettersArray)
            std::cout << lt << " | ";
        std::cout << "\n    intArray : ";
        for(int const nb : intArray)
            std::cout << nb << " | ";
        std::cout << std::endl;*/
        std::string const letter {NewLetter()};
        intArray=Compare(letter[0], lettersArray, intArray, lettersUsed);
        DisplayWord(lettersArray, intArray);
    } while (!Win(intArray));
    return PlayAgain();
}

std::string NewWord() //asks the player for a new word
{
    std::string word;
    bool goodInput {false};
    do
    {
        std::cout << "Choose a word : ";
        std::cin >> word;
        if(!IsLetter(word)||word.length()<1)
            std::cout << "You have to write a word made uniquely of the alphabet letters." << std::endl;
        else
            goodInput=true;
    } while (!goodInput);
    ClearBuffer();
    return Uppercase(word);
}

std::string NewLetter() //asks the player for a new letter
{
    std::string letter;
    bool goodInput {false};
    do
    {
        std::cout << "\nChoose a letter : ";
        std::cin >> letter;
        if(!IsLetter(letter)||letter.length()>1||letter.length()<1)
            std::cout << "You have to write only one letter and no number." << std::endl;
        else
            goodInput=true;
    } while (!goodInput);
    ClearBuffer();
    return Uppercase(letter);
}

bool IsLetter(std::string const word) //checks if the word is made only out a letters
{
    std::string const letters {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};
    return word.find_first_not_of(letters) == std::string::npos;
}

std::string Uppercase(std::string word) //puts the text to uppercase
{
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    return word;
}

bool PlayAgain() //asks the player if he wants to play again
{
    int playAgain;
    bool goodInput {false};
    do
    {
        std::cout << "Do you want to play again ?\n1. YES\n2. NO" << std::endl;
        std::cin >> playAgain;
        if(std::cin.fail()||playAgain<1||playAgain>2)
            InputError();
        else
            goodInput=true;
    } while (!goodInput);
    if(playAgain==1)
        return true;
    else
        return false;
}

void InputError()
{
    std::cout << "You have to write either 1 or 2." << std::endl;
    ClearBuffer();
}

void ClearBuffer() //clears the buffer
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

std::vector<int> Setup(int const wordLength, std::vector<char>& lettersArray, std::string const word) //fills intArray with 0 and lettersArray with the word's letters
{
    std::vector<int> intArray;
    for(int i {0}; i<wordLength; i++)
        intArray.push_back(0);
    for(char const letter : word)
        lettersArray.push_back(letter);
    DisplayWord(lettersArray, intArray);
    return intArray;
}

bool Win(std::vector<int> const intArray) //checks if the player won
{
    for(int const number : intArray)
        if(number==0)
            return false;
    return true;
}

std::vector<int> Compare(char const letter, std::vector<char> const lettersArray, std::vector<int> intArray, std::vector<char>& lettersUsed) //checks if the input letter is part of the word
{
    lettersUsed.push_back(letter);
    for(int i {0}; i<lettersArray.size(); i++)
        if(letter==lettersArray[i])
        {
            intArray[i]=1;
            RightWrong(true);
            if(lettersUsed.size()>0)
                lettersUsed.pop_back();
        }
    if(!lettersUsed.empty())
        for(int i {0}; i<lettersUsed.size()-1; i++)
            if(lettersUsed.back()==lettersUsed[i])
                lettersUsed.pop_back();
    UsedLetters(lettersUsed);
    return intArray;
}

void DisplayWord(std::vector<char> const lettersArray, std::vector<int> const intArray) //displays the word's letters with _ or the letter
{
    for(int i {0}; i<lettersArray.size(); i++)
        if(intArray[i]==0)
            std::cout << " _ ";
        else
            std::cout << " " << lettersArray[i] << " ";
    std::cout << std::endl;
}

void UsedLetters(std::vector<char> const letterUsed) //displays wich letters have already been used
{
    std::cout << "\nAlready used letters : ";
    for(char const lt : letterUsed)
        std::cout << lt << ", ";
    std::cout << std::endl;
}

void RightWrong(bool const right)
{
    if(right)
        std::cout << "Well done, you've find one of the letters." << std::endl;
    else    
        std::cout << "Nope, this isn't one of the letters." << std::endl;
}