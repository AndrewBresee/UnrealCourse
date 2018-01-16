#pragma once
#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame(){ Reset(); } // Default Constructor

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

int32 FBullCowGame::GetMaxTries() const {
    TMap<int32, int32> WordLengthToMaxTries { {3,5}, {4,6}, {5,9}, {6,15} };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

// Make a new map where a random number can be selected based on its length
TMap<int32, TMap<int32, FString> > GenerateRandomDictory()
{
    TMap<int32, TMap<int32, FString> > RandomWordByLength;
    RandomWordByLength[3].insert({1, "top"});
    RandomWordByLength[3].insert({2, "box"});
    RandomWordByLength[3].insert({3, "fat" });
    RandomWordByLength[4].insert({1, "time"});
    RandomWordByLength[4].insert({2, "plan"});
    RandomWordByLength[4].insert({3, "tame" });
    RandomWordByLength[5].insert({1, "plane"});
    RandomWordByLength[5].insert({2, "mixed"});
    RandomWordByLength[5].insert({3, "camel" });
    
    return RandomWordByLength;
}

// Select a random number based on its length
FString FBullCowGame::GetRandomWord(int32 WordLength) const
{
    TMap<int32, TMap<int32, FString> > RandomWordDictionary = GenerateRandomDictory();
    TMap<int32, FString> SelectedWordLength = RandomWordDictionary[WordLength];
    int RandomNumber = rand() % 3 + 1;
    FString RandomGameWord = SelectedWordLength[RandomNumber];
    return RandomGameWord;
}

void FBullCowGame::SetRandomWord(int32 SelectedNumber)
{
    const FString HIDDEN_WORD = GetRandomWord(SelectedNumber);
    MyHiddenWord = HIDDEN_WORD;
}

void FBullCowGame::Reset()
{
    MaxTries = GetHiddenWordLength();
    CurrentTry = 1;
    bIsGameWon = false;
    
    return;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
    TMap<char, bool> guessMap;
    for (auto Letter : Guess) {
        Letter = tolower(Letter);
        if (guessMap[Letter]) {
            return false;
        } else {
            guessMap[Letter] = true;
        }
    }
    return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
    for (auto Letter : Guess) {
        if (!islower(Letter)) {
            return false;
        }
    }
    return true;
}

// Returns the enum, which is then interpreted by the main file
EGuessStatus FBullCowGame::CheckGuessValidity(std::string Guess)
{
    if (!IsIsogram(Guess)) { // not isogram
        return EGuessStatus::Not_Isogram;
    } else if (Guess.length() != GetHiddenWordLength()) { // not right length
        return EGuessStatus::Wrong_Length;
    } else if (!IsLowercase(Guess)) { // not all lowercase
        return EGuessStatus::Not_Lower_Case;
    } else {
        return EGuessStatus::OK;
    }

    return EGuessStatus::OK;
}

// recieves a valid guess, increments turn, returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment turn number
    CurrentTry++;
    
    // setup a return structure
    FBullCowCount BullCowCount;
    
    int32 WordLength = (int32) MyHiddenWord.length();
    for (int32 HWchar = 0; HWchar < WordLength; HWchar++) {
        char guestChar = Guess[HWchar];
        char hiddenChar = MyHiddenWord[HWchar];
        if (guestChar == hiddenChar) {
            BullCowCount.Bulls++;
        } else {
            for (int32 guessChar = 0; guessChar < WordLength; guessChar++) {
                char guestCharAnyLocation = Guess[guessChar];
                if (hiddenChar == guestCharAnyLocation) {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    if (BullCowCount.Bulls == GetHiddenWordLength()) {
        bIsGameWon = true;
    }
    return BullCowCount;
};
