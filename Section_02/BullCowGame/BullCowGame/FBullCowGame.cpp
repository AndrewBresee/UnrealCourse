//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Andrew Bresee on 1/4/18.
//  Copyright © 2018 DrewBresee. All rights reserved.
//

#include "FBullCowGame.hpp"

int FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int FBullCowGame::GetMaxTries() const { return MaxTries; }

FBullCowGame::FBullCowGame() {
    BCGame.Reset();
}

void FBullCowGame::Reset() {
    CurrentTry = 1;
    MaxTries = 5;
    return;
}

bool FBullCowGame::IsGameWon() {
    
    return true;
}

bool FBullCowGame::CheckGuessValifity(std::string) {
    
    return true;
}
