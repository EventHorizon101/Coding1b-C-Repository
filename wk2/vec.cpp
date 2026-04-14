// Nate R. Coding 1 Spring 2026
// Vectors
// cl/EHsc vec.cpp to run

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    vector<string> favo = {"One", "Two", "Three"};
    // vector<string>::iterator iter;

    do
    {
        cout << "\nWhat's the haps, Chum?\n";
        cout << "Commands: push, find, remove, quit\n";
        getline(cin, input);
        cout << "\n";

        if(input == "push")
        {
            cout << "Making a string vector, Chum.\n";

            vector<string> names;

            names.push_back("One");
            names.push_back("Two");
            names.push_back("Three");
            names.push_back("Four");
            names.push_back("Five");

            cout << "Here's the vector, Chum:\n";
            for(int i = 0; i < names.size(); i=i+1)
            {
                cout << names[i] << "\n";
            }

            cout << "There's " << names.size() << " strings, Chum.\n";

            cout << *(names.end()-1) << " will die now. Say goodbye.\n";
            names.pop_back();

            cout << "\nRunning it back, Chum:\n";
            for(int i = 0; i < names.size(); i=i+1)
            {
                cout << names[i] << "\n";
            }
        }
        else if(input == "find")
        {
            if(favo.size() != 0)
            {
                // vector<string> favs = {"One", "Two", "Three"};

                vector<string>::iterator iter;

                cout << "\nTake a look, Chum:\n";
                for(int i = 0; i < favo.size(); i=i+1)
                {
                    cout << favo[i] << "\n";
                }

                iter = favo.begin();

                cout << "iter points at " << *iter << ", Chum.\n";

                iter += 1;

                cout << "Now iter is pointing at " << *iter << ".\n";
                cout << "\nPick a string to find, Chum!\n";
                getline(cin, input);
                
                iter = find(favo.begin(), favo.end(), input);

                if(iter != favo.end())
                {
                    cout << "We've found " << *iter << "!\n";
                    cout << "Wanna change it, Chum? y/n\n";
                    getline(cin, input);
                    if(input == "y")
                    {
                        cout << "What to, Chum?\n";
                        getline(cin, input);

                        *iter = input;

                        cout << "\nHere's the new list, Chum:\n";
                        for(int i = 0; i < favo.size(); i=i+1)
                        {
                            cout << favo[i] << "\n";
                        }
                    }
                    else
                    {
                        cout << "You got it, Chum.\n";
                    }
                }
                else
                {
                    cout << "No good, Chum.\n";
                }
            }
            else
            {
                cout << "List's empty, Chum.\n";
            }
        }
        else if(input == "remove")
        {
            if(favo.size() != 0)
            {
                // sort(favo.begin(), favo.end());
                cout << "\nTake a look, Chum:\n";
                for(int i = 0; i < favo.size(); i=i+1)
                {
                    cout << favo[i] << "\n";
                }
                cout << "\nRemove what, Chum?\n";
                getline(cin, input);
                auto iter = find(favo.begin(), favo.end(), input);

                if(iter != favo.end())
                {
                    cout << "\nRemoving " << *iter << ", Chum! Here's the news:\n";
                    favo.erase(iter);
                    for(int i = 0; i < favo.size(); i=i+1)
                    {
                        cout << favo[i] << "\n";
                    }
                }
                else
                {
                    cout << "No good, Chum.\n";
                }
            }
            else
            {
                cout << "List's empty, Chum.\n";
            }
        }
        else if(input == "quit")
        {
            cout << "Later, Chum.\n";
        }
        else
        {
            cout << "No good, Chum. Try another command.\n";
        }
    } while (input != "quit");

    return 0;
}