// Nate R. Coding 1 Reading Files 'n stuff

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void read(string path = "save.txt")
{
    string line;
    ifstream readFile(path);
    if(readFile.is_open())
    {
        cout << "File opened, Chum\n";
        while(getline(readFile, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "File opening failed\n";
    }

    readFile.close();
}

void read(vector<string>& vec, string path = "save.txt")
{
    string line;
    ifstream readFile(path);
    if(readFile.is_open())
    {
        cout << "File opened, Chum\n";
        while(getline(readFile, line))
        {
            vec.push_back(line);
        }
    }
    else
    {
        cout << "File opening failed\n";
    }

    readFile.close();
}

void write(vector<string>& vec, string path = "save.txt")
{
    ofstream writeFile(path);

    if(writeFile.is_open())
    {
        for(int i = 0; i < vec.size(); i=i+1)
        {
            writeFile << vec[i] << endl;
        }
    }

    writeFile.close();
}

void input(vector<string>& vec)
{
    cout << "Wanna add stuff?\n";
    string input = "";

    while(input != "quit")
    {
        cout << ">";
        getline(cin, input);
        if(input != "quit")
        {
            // writeFile << input << endl;
            vec.push_back(input);
        }
    }
}

int main()
{
    vector<string> inputLines;
    string path = "save.txt";

    read();
    // read(inputLines, path);

    input(inputLines);

    write(inputLines);

    read();

    return 0;
}