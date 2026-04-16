// Nate R. Coding 1 Spring 2026
// Functions

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void greeting()
{
    cout << "Hey there, Chum\n";
}

int addition(int x, int y)
{
    int z;
    z = x + y;
    return z;
}

int diceRoll(int bounds)
{
    return rand() % bounds + 1;
}

bool yesNo(string question = "")
{   
    while(true)
    {
        cout << "\n" << question << " y/n?\n";
        string input;
        getline(cin, input);
        if(input == "y")
        {
            return true;
        }
        else if(input == "n")
        {
            return false;
        }
        else
        {
            cout << "No good, Chum. Try again";
        }
    }
}

void showContents(vector<string> vec)
{
    for(int i = 0; i<vec.size(); i=i+1)
    {
        cout << "\n" << vec[i];
    }
}

void addStringToVec(vector<string>& vec)
{
    cout << "\nAdd what, Chum?\n";
    string input;
    getline(cin, input);
    vec.push_back(input);
}

int main()
{
    srand(time(0));

    vector<string> names = {"One", "Two", "Three"};

    greeting();

    cout << addition(15, 17);
    cout << "\n";
    cout << diceRoll(6);

    if(yesNo("Yes or No") == true)
    {
        cout << "Good to hear, Chum";
    }
    else
    {
        cout << "I see how it is, Chum";
    }

    showContents(names);

    addStringToVec(names);

    showContents(names);

    return 0;
}