//
//  main.cpp
//  BullCowGame
//
//  Created by Andrew Bresee on 1/4/18.
//  Copyright © 2018 DrewBresee. All rights reserved.
//

#include <iostream>
#include "FBullCowGame.hpp"

void PrintIntro(int WORD_LENGTH);
static void PlayGame();
std::string GetGuess();
bool AskPlayAgain();
FBullCowGame BCGame;

int main(int argc, const char * argv[])
{
    constexpr int WORD_LENGTH = 6;
    bool bPlayAgain = false;
    do {
        PrintIntro(WORD_LENGTH);
        PlayGame();
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
    int CurrentTry = BCGame.GetCurrentTry();
    
    std::string Guess = "";
    std::cout << "Try " << CurrentTry << ". " << "Enter guess: ";
    getline (std::cin,Guess);
    return Guess;
}

static void PlayGame()
{
    int const MaxTries = BCGame.GetMaxTries();
    
    for (int count = MaxTries; count > 0; count--) {
        std::string Guess = GetGuess();
        std::cout << "MaxTries: " << MaxTries << "\n";
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
