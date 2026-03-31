// Nate R. Coding 1 Spring 2026
// Variables and Logic

// complie with Dev Command Prompt
// cl/EHsc main.app to compile
// main to run

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Explanation and Education\n";

    int playerAge = -1;
    string playerName = "null";
    float happyPercent = 0.07f;
    bool keepPlaying = true;
    bool debug = false;

    if(playerAge == -1)
    {
        cout << "What's your age, Chum?\n";
        cin >> playerAge;

        if(playerAge <= 12)
        {
            cout << "You're to young, Smallfry\n";
            return 0;
        }
        else
        {
            cout << playerAge << "? You're a fossil, Chum\n";
        }
    }

    if(playerName == "null")
    {
        cout << "Is your name " << playerName << ", Chum? y/n\n";
        string input;
        cin >> input;
        if(input == "y")
        {
            cout << "I don't realy believe you, Chum, but oh well.\n";
        }
        else if(input == "n")
        {
            cout << "Well, then what is it, Chum?\n";
            cin >> playerName;
        }
        else
        {
            cout << "That's not really an answer, Chum. Well, what's your name?\n";
            cin >> playerName;
        }

        cout << "Hey there, " << playerName << " Chum\n";
    }

    if(playerAge == 1907 && playerName == "Chum")
    {
        debug = true;
        cout << "Congratulations, Chum, you're debugging now\n\n";
    }

    if(debug)
    {
        cout << "playerAge = " << playerAge << "\n";
        cout << "playerName = " << playerName << "\n";
        cout << "happyPercent = " << happyPercent << "\n";
        cout << "keepPlaying = " << keepPlaying << "\n";
    }

    return 0;
}