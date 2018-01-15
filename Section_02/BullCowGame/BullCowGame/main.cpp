/* This implements the BCGame class.
 It is the view in the MVC format, implementing the use of the FBullCowGame class.
 To see functionality, look to this class.
 */

#include <iostream>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro(int32 WORD_LENGTH);
static void PlayGame();
FText GetGuess();
bool AskPlayAgain();
FBullCowGame BCGame;
void PrintGameSummary();

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
    std::cout << "Welcome to Bulls and Cows, a fun word game\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n\n";
    return;
}

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
    int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
    
    EGuessStatus Status = EGuessStatus::Invalid;
    FText Guess = "";
    do {
        std::cout << "Try " << CurrentTry << ". " << (WORD_LENGTH - CurrentTry +1);
        std::cout << " guesses left \n";
        std::cout << "Enter guess: ";
        getline (std::cin,Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout << "Wrong length";
                break;
            case EGuessStatus::Not_Lower_Case:
                std::cout << "Must be lower case";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Must be an isogram";
                break;
            default:
                break;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK);
    
    return Guess;
}

static void PlayGame()
{
    int32 const MaxTries = BCGame.GetMaxTries();
    
    // loop asking for guesses
    // while the game is not won
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        // print the numb of bulls + cows
        std::cout << "You guessed: " << Guess << "\n";
        std::cout << "Bulls: " << BullCowCount.Bulls;
        std::cout << " Cows: " << BullCowCount.Cows << std::endl;
        Guess = "";
    }
    // TODO: Summarize the game
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
