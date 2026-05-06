// Nate R Coding 1 Spring 2026 Final Assignment
// Trainer Tourney monster training game

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <windows.h>

using namespace std;

int roundNum = 1;
int actionNum = 5;
string input = "";

string randomName()
{
    string line;
    ifstream readFile("names.txt");

    if(readFile.is_open())
    {
        getline(readFile, line);
    }
    else
    {
        cout << "File opening failed\n";
    }

    readFile.close();

    return line;
}

class creature
{
private:
    string name;
    int maxHealth;
    int currentHealth;
    int strength;
    int defense;
    int speed;
    int critical;
    int hunger;

public:
    creature()
    {
        name = randomName();
        maxHealth = 10;
        currentHealth = maxHealth;
        strength = 3;
        defense = 0;
        speed = 0;
        critical = 1;
        hunger = 0;
    }
    creature(int setMax, int setStrength, int setDefense, int setSpeed, int setCrit)
    {
        name = randomName();
        maxHealth = setMax;
        currentHealth = maxHealth;
        strength = setStrength;
        defense = setDefense;
        speed = setSpeed;
        critical = setCrit;
        hunger = 0;
    }

    void setName(string x)
    {
        name = x;
    }

    void fullHeal()
    {
        currentHealth = maxHealth;
    }
    void fullEat()
    {
        hunger = 0;
    }

    void incHealth()
    {
        maxHealth = maxHealth + 2;
    }
    void incStr()
    {
        strength = strength + 1;
    }
    void incDef()
    {
        defense = defense + 1;
    }
    void incSpd()
    {
        speed = speed + 1;
    }
    void incCrit()
    {
        critical = critical + 1;
    }

    string getName()
    {
        return name;
    }
    int getMax()
    {
        return maxHealth;
    }
    int getHealth()
    {
        return currentHealth;
    }
    int getStr()
    {
        return strength;
    }
    int getDef()
    {
        return defense;
    }
    int getSpd()
    {
        return defense;
    }
    int getCrit()
    {
        return critical;
    }
    int getHunger()
    {
        return hunger;
    }

    void showStats()
    {
        cout << "\n";
        cout << "\n-- " << name << " --";
        cout << "\nHealth: " << currentHealth << "/" << maxHealth;
        cout << "\nStrength: " << strength;
        cout << "\nDefense: " << defense;
        cout << "\nSpeed: " << speed;
        cout << "\nCritical Chance: " << critical << "/10";
        cout << "\nHunger: " << hunger;
        cout << "\n";
    }

    void attack(creature& target)
    {
        int dmgTotal = 0;
        int hungerOver = 0;
        bool critcalHit = false;

        cout << "\n";
        cout << "\n";

        if(hunger > 10)
        {
            cout << name << " is hungry...";
        }

        cout << "\n";

        cout << name << " attacks " << target.getName() << "!";

        hungerOver = hungerOver - 10;
        if(hungerOver < 0)
        {
            hungerOver = 0;
        }

        if(((rand()%10)+1) <= critical)
        {
            critcalHit = true;

            cout << "\nCritical strike!";
        }

        if(critcalHit == true)
        {
            dmgTotal = ((strength-(hungerOver)));
        }
        else
        {
            dmgTotal = ((strength-(hungerOver))-target.defense);
        }
        

        if(dmgTotal < 0)
        {
            dmgTotal = 0;
        }

        target.currentHealth = target.currentHealth - dmgTotal;

        cout << "\n";
        cout << "Deals " << dmgTotal << " damage!";

        hunger = hunger + 1;
    }

    bool checkDefeat()
    {
        if(currentHealth <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void advance(creature& m);
void throwDown(creature& m, creature& e);
void battleStart(creature& m);
void actionUp(creature& m);
void roundUp(creature& m);

void printTutorial()
{
    cout << "\n";
    cout << "\nListen up, Chum! This is the Trainer Tourney! You're gonna train up a creature that'll battle in a tournament that's ten rounds long! Do your best to be the champ!";
    cout << "\nBattles will take place on a turn-based system. Whoever has the highest speed stat will go first. (You'll go first on a tie)";
    cout << "\nWhen a creature's health drops to '0', they lose. Make sure that that isn't you, Chum!";
    cout << "\nYour creature will attack with their strength stat, and the enemy creature will guard with their defense stat.";
    cout << "\nIf you manage to land a random critical hit, you'll ignore your opponent's defense instead.";
    cout << "\nEvery turn until the battle ends, your creature's hunger will increase by 1. If there hunger is greater than 10, it'll start decreasing their attack strength.";
    cout << "\n";
    cout << "\nBefore each round of the tournament, you'll have a set number of chances to take action to care for your creature. You options are:";
    cout << "\nTrain - Increase one of your creature's stats. (Max Health + 2, Strength + 1, Defense + 1, Speed + 1, or Critical Chance + 10%)";
    cout << "\nRest - Heal your creature up to full health.";
    cout << "\nEat - Reset your creature's hunger to 0.";
    cout << "\nIf you're feeling confident, you can more on to the next round early, but there's no real benefit to doing so.";
    cout << "\n";
    cout << "\nThe way that you spend your actions to care for your creature is up to you. Best of luck, and shoot for the top!";
    cout << "\n";
}

void advance(creature& m)
{
    if(m.checkDefeat() == true)
    {
        cout << "\n\nYou lose! Sorry, Chum. You'll get 'em next time.";

    }
    else
    {
        cout << "\nVictory! Onwards!\n";
        roundNum = roundNum + 1;
        actionNum = 5;

        if(roundNum == 11)
        {
            cout << "\n\nCONGRATULATIONS! YOU'RE THE CHAMP!\nFinal stats:";
            m.showStats();
            return;
        }
        roundUp(m);
    }
}
void throwDown(creature& m, creature& e)
{
    cout << "\n\nStandings:";
    cout << "\n" << m.getName() << ":   " << m.getHealth() << "/" << m.getMax();
    cout << "\n" << e.getName() << ":   " << e.getHealth() << "/" << e.getMax();

    Sleep(750);

    if(m.getSpd() > e.getSpd())
    {
        m.attack(e);
        if(e.checkDefeat() == false)
        {
            Sleep(750);
            e.attack(m);
        }
        else
        {
            advance(m);
            return;
        }
    }
    else if(e.getSpd() > m.getSpd())
    {
        e.attack(m);
        if(m.checkDefeat() == false)
        {
            Sleep(750);
            m.attack(e);
        }
        else
        {
            advance(m);
            return;
        }
    }
    else
    {
        m.attack(e);
        if(e.checkDefeat() == false)
        {
            Sleep(750);
            e.attack(m);
        }
        else
        {
            advance(m);
            return;
        }
    }
    if(m.checkDefeat() == false && e.checkDefeat() == false)
    {
        Sleep(750);
        throwDown(m, e);
    }
    else
    {
        advance(m);
        return;
    }
}
void battleStart(creature& m)
{
    creature e;

    if(roundNum == 1)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 2)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 3)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 4)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 5)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 6)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 7)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 8)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 9)
    {
        creature e(1, 3, 0, 0, 1);
    }
    else if(roundNum == 10)
    {
        creature e(1, 3, 0, 0, 1);
    }

    cout << "\n\nBattle: " << roundNum << ", BEGIN!\n";

    throwDown(m, e);
}
void roundUp(creature& m)
{
    if(actionNum <= 0)
    {
        battleStart(m);
    }

    cout << "\nRound " << roundNum;
    m.showStats();

    if(m.getHealth() < 4)
    {
        cout << "\n" << m.getName() << " is injured...\n";
    }
    if(m.getHunger() > 10)
    {
        cout << "\n" << m.getName() << " is starving...\n";
    }

    cout << "\nYou have " << actionNum << " actions left. What would you like to do?\nOptions: 'action' ('a' for short), 'continue', 'tutorial'\n\n";
    getline(cin, input);
    while(input != "action" && input != "a" && input != "continue" && input != "tutorial")
    {
        cout << "Sorry, Chum. I didn't quite get that.\nOptions: 'action', 'continue', 'tutorial'\n\n";
        getline(cin, input);
    }

    if(input == "action" || input == "a")
    {
        actionUp(m);
    }
    else if(input == "continue")
    {
        battleStart(m);
    }
    else if(input == "tutorial")
    {
        printTutorial();
        roundUp(m);
    }
}
void actionUp(creature& m)
{
    cout << "\nWhat would you like to do?\nOptions: 'health' (h), 'strength' (s), 'defense' (d), 'speed' (s), 'critical' (c), 'rest' (r), 'eat' (e), 'return'\n\n";
    getline(cin, input);
    while(input != "health" && input != "h" && input != "strength" && input != "st" && input != "defense" && input != "d" && input != "speed" && input != "sp" && input != "critical" && input != "c" && input != "rest" && input != "r" && input != "eat" && input != "e" && input != "return")
    {
        cout << "Sorry, Chum. I didn't quite get that.\nOptions: 'health' (h), 'strength' (st), 'defense' (d), 'speed' (sp), 'critical' (c), 'rest' (r), 'eat' (e), 'return'\n\n";
        getline(cin, input);
    }

    if(input == "health" || input == "h")
    {
        m.incHealth();
        actionNum = actionNum - 1;
        cout << "\nMax Health increased by 2!";
    }
    else if(input == "strength" || input == "st")
    {
        m.incStr();
        actionNum = actionNum - 1;
        cout << "\nStrength increased by 1!";
    }
    else if(input == "defense" || input == "d")
    {
        m.incDef();
        actionNum = actionNum - 1;
        cout << "\nDefense increased by 1!";
    }
    else if(input == "speed" || input == "sp")
    {
        m.incHealth();
        actionNum = actionNum - 1;
        cout << "\nSpeed increased by 1!";
    }
    else if(input == "critical" || input == "c")
    {
        m.incCrit();
        actionNum = actionNum - 1;
        cout << "\nCritical Ratio increased by 1!";
    }
    else if(input == "rest" || input == "r")
    {
        m.fullHeal();
        actionNum = actionNum - 1;
        cout << "\nHealed to full!";
    }
    else if(input == "eat" || input == "e")
    {
        m.fullEat();
        actionNum = actionNum - 1;
        cout << "\nHunger reset!";
    }
    // else if(input == "return")
    // {
        roundUp(m);
    // }
}

void main()
{
    srand(time(0));

    cout << "\nWelcome to Trainer Tourney! What do you want to do?\nOptions: 'start', 'tutorial'\n\n";
    getline(cin, input);
    while(input != "start" && input != "tutorial")
    {
        cout << "\nSorry, Chum. I didn't quite get that.\nOptions: 'start', 'tutorial'\n\n";
        getline(cin, input);
    }

    creature mainc;

    if(input == "start")
    {
        cout << "\nRighto! Your creature's name this time is '" << mainc.getName() << "'. Do you want to change it?\ny/n\n\n";
    }
    else if(input == "tutorial")
    {
        printTutorial();
        cout << "\nAnyways, let's begin. Your creature's name this time is '" << mainc.getName()  << "'. Do you want to change it?\ny/n\n\n";
    }
    getline(cin, input);

    while(input != "y" && input != "n")
    {
        cout << "\nSorry, Chum. I didn't quite get that.\nOptions: 'y', 'n'\n\n";
        getline(cin, input);
    }

    if(input == "y")
    {
        cout << "\nWell, what will you change it to?\n\n";
        getline(cin, input);

        mainc.setName(input);

        cout << "\nOkay! We'll call it '" << mainc.getName() << "'. On with the game!\n";
    }
    else if(input == "n")
    {
        cout << "\nAlrighty! On with the game then!\n";
    }

    // roundNum = roundNum+1;
    roundUp(mainc);
}