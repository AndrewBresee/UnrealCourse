/* This is the header for FBCGame class.
 It definies all the methods and variables
 that can be used. Sort of like an index.
 */
#pragma once
#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp
#define TMap std::map

#include <stdio.h>
#include <string>
#include <map>

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
    FString GetRandomWord(int32) const;
    void SetRandomWord(int32);
    
private:
    int32 MaxTries;
    int32 CurrentTry;
    FString MyHiddenWord;
    bool bIsGameWon;
    TMap<int, TMap<int, FString> > GenerateRandomDictor;
    
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};
