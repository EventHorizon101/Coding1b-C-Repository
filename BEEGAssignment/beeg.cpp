#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    vector<string> list;
    vector<string>::iterator iter;

    do
    {
        cout << "\nWhat's the haps, Chum? Welcome to list simulator!\n";
        cout << "Commands: add, remove, edit, sort, show, quit\n";
        getline(cin, input);
        cout << "\n";

        if(list.size() == 0 && input != "add" && input != "quit")
        {
            cout << "List's empty right now, Chum.\n";
        }
        else if(input == "add")
        {
            cout << "\nWhat do you want to add, Chum?\n";
            getline(cin, input);

            list.push_back(input);

            cout << "Here's the new list, Chum:\n";
            for(int i = 0; i < list.size(); i=i+1)
            {
                cout << list[i] << "\n";
            }
        }
        else if(input == "remove")
        {
            cout << "\nWhat do you want to remove, Chum?\n";
            getline(cin, input);

            iter = find(list.begin(), list.end(), input);

            if(iter != list.end())
            {
                list.erase(iter);
                cout << "Here's the new list, Chum:\n";
                for(int i = 0; i < list.size(); i=i+1)
                {
                    cout << list[i] << "\n";
                }
            }
            else
            {
                cout << "Couldn't find that, Chum.\n";
            }
        }
        else if(input == "edit")
        {
            cout << "\nWhat do you want to edit, Chum?\n";
            getline(cin, input);

            iter = find(list.begin(), list.end(), input);

            if(iter != list.end())
            {
                cout << "What do you want to change it to, Chum?\n";
                getline(cin, input);
                *iter = input;
                cout << "Here's the new list, Chum:\n";
                for(int i = 0; i < list.size(); i=i+1)
                {
                    cout << list[i] << "\n";
                }
            }
            else
            {
                cout << "Couldn't find that, Chum.\n";
            }
        }
        else if(input == "sort")
        {
            sort(list.begin(), list.end());
            cout << "Here's the newly sorted list, Chum:\n";
            for(int i = 0; i < list.size(); i=i+1)
            {
                cout << list[i] << "\n";
            }
        }
        else if(input == "show")
        {
            cout << "\nHere's the current list, Chum:\n";
            for(int i = 0; i < list.size(); i=i+1)
            {
                cout << list[i] << "\n";
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