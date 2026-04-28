// Coding 1 Spring 2026

#include <iostream>
#include <string>
using namespace std;

class robot
{
private:
    string name;
    int health;
    int mana;

public:
    robot()
    {
        name = "null";
        health = 0;
        mana = 0;
    }

    robot(string givenName, int givenHealth, int givenMana)
    {
        name = givenName;
        health = givenHealth;
        mana = givenMana;
    }

    void status()
    {
        cout << "\nI am " << name;
        cout << "\nCurrent health is " << health;
        cout << "\nCurrent mana is " << mana;
        cout << "\nMana is ";

        if(health > 100) cout << "good";
        else if(health > 80) cout << "fine";
        else if(health > 60) cout << "mid";
        else if(health > 40) cout << "poor";
        else cout << "danger";

        cout << "\n";
    }

    string getName()
    {
        return name;
    }
    int getHealth()
    {
        return health;
    }
    int getMana()
    {
        return mana;
    }

    void setName(string x)
    {
        if(x.size() <= 5)
        {
            name = x;
        }
        else
        {
            cout << "\nName " << x << " is too long\n";
        }
    }
    void setHealth(int x)
    {
        if(x < 0)
        {
            health = 0;
        }
        else
        {
            health = x;
        }
    }
    void setMana(int x)
    {
        if(x < 0)
        {
            mana = 0;
        }
        else
        {
            mana = x;
        }
    }
};

int main()
{
    robot mle("MLE",99,30);
    // mle.name = "MLE";
    // mle.health = 50;
    // mle.mana = 30;
    // mle.robot("MLE",50,30);

    // robot yr;
    // yr.name = "YR";
    // yr.health = 60;

    mle.status();

    mle.setName("SDFFFFFFFF");

    return 0;
}