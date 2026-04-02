// Nate R. Coding 1 Spring 2026
// Random Numbers

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lastGuess = -1;
int randNum = -1;

// int min = 50;
// int max = 100;
// int range = 0;
int clampedNumber = 0;

void guessCheck();

int main()
{
    int min = 1;
    int max = 10;

    cout << "Give me a min!\n";
    cin >> min;
    cout << "Give me a max!\n";
    cin >> max;

    int range = 0;
    range = max - min;

    srand(time(0));
    // randNum = (rand()%10)+1;
    randNum = rand();
    clampedNumber = (randNum % range) + min;
    // cout << clampedNumber;
    // Random rand = new Random();

    int counter = 0;
    // while (counter++ < 10)
    // {
    //     cout << (rand()%10)+1 << endl;
    // }

    cout << "Guess a number, Chum, " << min << "-" << max << "\n";
    cin >> lastGuess;
    cout << "\n";

    guessCheck();

    return 0;
}

void guessCheck()
{
    // cout << lastGuess;
    if(lastGuess == 1907)
    {
        return;
    }
    else if(lastGuess == clampedNumber)
    {
        cout << "You got it, Chum! The number is " << clampedNumber << "!\n";
        return;
    }
    else if(lastGuess < clampedNumber)
    {
        cout << lastGuess << " is too low, Chum! Guess again!\n";
        cin >> lastGuess;
        guessCheck();
    }
    else if(lastGuess > clampedNumber)
    {
        cout << lastGuess << " is too high, Chum! Guess again!\n";
        cin >> lastGuess;
        guessCheck();
    }

    return;
}