/* This implements the BCGame class.
 It is the view in the MVC format, implementing the use of the FBullCowGame class.
 To see functionality, look to this class.
 */

#pragma once
#include <iostream>
#include "FBullCowGame.hpp"

// to make the syntax unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes because we are outside a class
void PrintIntro(int32 WORD_LENGTH);
static void PlayGame();
FText GetGuess();
bool AskPlayAgain();
void PrintGameSummary();

// instanciates a new game
FBullCowGame BCGame;

int main(int32 argc, const char * argv[])
{
    int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
    bool bPlayAgain = false;
    do {
        PrintIntro(WORD_LENGTH);
        PlayGame();
        bPlayAgain = AskPlayAgain();
        BCGame.Reset();
    } while (bPlayAgain);
    return 0;
}

void PrintIntro(int32 WORD_LENGTH)
{
    // introduce the game
    FString WordLength = "";
    int32 value;

    // Length of word must be between 3 and 5
    // otherwise keep asking
    std::cout << "Welcome to Bulls and Cows, a fun word game\n";
    do {
        std::cout << "What length would you like? (3 - 5): ";
        getline (std::cin,WordLength);
        value = atoi(WordLength.c_str());
    } while (value > 5 || value < 3);
    std::cout << std::endl;
    BCGame.SetRandomWord(value);
    
    return;
}

// Comes at the end
void PrintGameSummary()
{
    if (BCGame.IsGameWon()) {
        std::cout << "Congradulations! You won! \n";
    } else {
        std::cout << "Better luck next time! \n";
    }
}

FText GetValidGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    
    EGuessStatus Status = EGuessStatus::Invalid;
    FText Guess = "";
    do {
        std::cout << "Try " << CurrentTry << ". " << (BCGame.GetMaxTries() - CurrentTry +1);
        std::cout << " guesses left \n";
        std::cout << "Enter guess: ";
        getline (std::cin,Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout << "Wrong length" << std::endl;
                break;
            case EGuessStatus::Not_Lower_Case:
                std::cout << "Must be lower case" << std::endl;
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Must be an isogram" << std::endl;
                break;
            default:
                break;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK);
    
    return Guess;
}

// Plays one game to completion
static void PlayGame()
{
    int32 const MaxTries = BCGame.GetMaxTries();
    
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        std::cout << "You guessed: " << Guess << "\n";
        std::cout << "Bulls: " << BullCowCount.Bulls;
        std::cout << " Cows: " << BullCowCount.Cows << std::endl;
        Guess = "";
    }
    PrintGameSummary();
    return;
}

bool AskPlayAgain()
{
    FText Response = "";
    std::cout << "Do you want to play again? : ";
    getline(std::cin,Response);
    std::cout << std::endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}

