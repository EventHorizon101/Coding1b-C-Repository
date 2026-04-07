// Nate R. Coding 1 Spring 2026
// Arrays

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    // cout << "Testing";

    int scores[5];

    scores[0] = 4545;
    scores[1] = 13;
    scores[2] = 9001;
    scores[3] = 2456;
    scores[4] = -4;

    for(int i = 0; i<5; i=i+1)
    {
        cout << scores[i] << "\n";
    }

    string names[10];
    // for(int i = 0; i<10; i=i+1)
    // {
    //     names[i] = "-none-";
    // }
    cout << "\nEnter 10 names, Chum (Type \"done\" to finish early)\n";
    for(int i = 0; i<10; i=i+1)
    {
        cin >> names[i];
        if(names[i] == "done")
        {
            names[i] = "";
            i = 11;
        }
    }
    cout << "\nYour names are:\n";
    for(int i = 0; i<10; i=i+1)
    {
        if(names[i] != "")
        {
            cout << i + 1 << ". " << names[i] << "\n";
        }
    }

    string newNames[] = {"Shulk", "Reyn", "Sharla", "Dunban", "Melia", "Riki", "Seven"};
    cout << "\n\nAdditional Names:";
    for(int i = 0; i<7; i=i+1)
    {
        cout << "\n" << i + 1 << ". " << newNames[i];
    }

    string character = newNames[rand() % 7];

    cout << "\n\n" << character << ", let's talk about them.\n";

    enum favor {TIME, FEELING, THERE, HEAD};

    switch(rand()%4)
    {
        case TIME:
            cout << "\n" << character << " time, baby.";
            break;

        case FEELING:
            cout << "\n" << character << " is really feeling it.";
            break;

        case THERE:
            cout << "\nThat's " << character << " over there!";
            break;

        case HEAD:
            cout << "\n" << character << " better not lose their head.";
            break;
    }
    cout << "\n";

    return 0;
}