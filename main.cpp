// Nate R. Coding 1 Spring 2026
// First C++ Program

#include <iostream>         // in out stream for sending text to the console
#include <string>           // for playerName

using namespace std;        // don't have to type "std::"

// program start
int main()
{
    // variables at the top
    string playerName;          // camelCase

    cout << "What is your name? \n";
    cin >> playerName;          // console in

    cout << "Hello, " << playerName << "." << endl;            // console out, end line

    return 0;
}