//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Andrew Bresee on 1/4/18.
//  Copyright © 2018 DrewBresee. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

using int32 = int;

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MaxTries; }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

FBullCowGame::FBullCowGame()
{
    Reset();
}

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "test";
    MyHiddenWord = HIDDEN_WORD;
    MaxTries = GetHiddenWordLength();
    CurrentTry = 1;
    bIsGameWon = false;
    
    return;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
    TMap<char, int> guessMap;
    for (int i = 0; i < Guess.length(); i++) {
        char currentChar = Guess[i];
        if (guessMap[currentChar] == 1) {
            return false;
        } else {
            guessMap[currentChar] = 1;
        }
    }
    return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(std::string Guess)
{
    if (!IsIsogram(Guess)) { // not isogram
        return EGuessStatus::Not_Isogram;
    } else if (Guess.length() != GetHiddenWordLength()) { // not right length
        return EGuessStatus::Wrong_Length;
    } else if (false) { // not all lowercase
        return EGuessStatus::Not_Lower_Case;
    } else {
        return EGuessStatus::OK;
    }

    return EGuessStatus::OK; // TODO: Make actual error
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
