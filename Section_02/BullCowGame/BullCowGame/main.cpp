//
//  main.cpp
//  BullCowGame
//
//  Created by Andrew Bresee on 1/4/18.
//  Copyright © 2018 DrewBresee. All rights reserved.
//

#include <iostream>

void PrintIntro(int WORD_LENGTH);
static void PlayGame(int WORD_LENGTH);
std::string GetGuess();
bool AskPlayAgain();

int main(int argc, const char * argv[])
{
    constexpr int WORD_LENGTH = 6;
    bool bPlayAgain = false;
    do {
        PrintIntro(WORD_LENGTH);
        PlayGame(WORD_LENGTH);
        bPlayAgain = AskPlayAgain();
    } while (bPlayAgain);
    return 0;
}

void PrintIntro(int WORD_LENGTH)
{
    // introduce the game
    std::cout << "Welcome to Bulls and Cows, a fun word game\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n";
    return;
}

std::string GetGuess()
{
    std::string Guess = "";
    std::cout << "Enter guess: ";
    getline (std::cin,Guess);
    return Guess;
}

static void PlayGame(int WORD_LENGTH)
{
    for (int count = WORD_LENGTH; count > 0; count--) {
        std::string Guess = GetGuess();
        std::cout << "You guessed: " << Guess << "\n";
        Guess = "";
        std::cout << std::endl;
    }
    return;
}

bool AskPlayAgain()
{
    std::string Response = "";
    std::cout << "Do you want to play again? : ";
    getline(std::cin,Response);
    std::cout << std::endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}
