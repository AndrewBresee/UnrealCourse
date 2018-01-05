//
//  main.cpp
//  BullCowGame
//
//  Created by Andrew Bresee on 1/4/18.
//  Copyright © 2018 DrewBresee. All rights reserved.
//

#include <iostream>

using namespace std;

void PrintIntro(int WORD_LENGTH);
static void PlayGame(int WORD_LENGTH);
string GetGuess();
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
    cout << "Welcome to Bulls and Cows, a fun word game\n";
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n";
    return;
}

string GetGuess()
{
    string Guess = "";
    cout << "Enter guess: ";
    getline (cin,Guess);
    return Guess;
}

static void PlayGame(int WORD_LENGTH)
{
    for (int count = WORD_LENGTH; count > 0; count--) {
        string Guess = GetGuess();
        cout << "You guessed: " << Guess << "\n";
        Guess = "";
        cout << endl;
    }
    return;
}

bool AskPlayAgain()
{
    string Response = "";
    cout << "Do you want to play again? : ";
    getline(cin,Response);
    cout << endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}
