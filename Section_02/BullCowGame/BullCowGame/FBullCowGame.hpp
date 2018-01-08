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

#endif /* FBullCowGame_hpp */
class FBullCowGame {
public:
    FBullCowGame();
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon();
    bool CheckGuessValifity(std::string);
    
    void Reset();
    
private:
    int MaxTries = 5;
    int CurrentTry = 1;
};
