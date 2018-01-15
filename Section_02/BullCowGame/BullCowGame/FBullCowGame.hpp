//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Andrew Bresee on 1/4/18.
//  Copyright © 2018 DrewBresee. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    Invalid,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lower_Case
};

#endif /* FBullCowGame_hpp */
class FBullCowGame
{
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    EGuessStatus CheckGuessValidity(FString);
    bool IsGameWon() const;
    FBullCowCount SubmitGuess(FString);
    void Reset();
    
private:
    int32 MaxTries;
    int32 CurrentTry;
    FString MyHiddenWord;
    bool bIsGameWon;
    
    bool IsIsogram(FString) const;
};
