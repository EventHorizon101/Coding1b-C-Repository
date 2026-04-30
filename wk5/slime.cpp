// Coding 1 Spring 2026

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string> names = {"MLE", "YR", "DA-5H", "K-T"};

class baseSlime
{
public:
    string name;
    int health;
    int attack;

    void hello()
    {
        cout << "\nYo, I'm " << name << ". I have " << health << " and deal " << attack << " damage.\n";
    }

    baseSlime()
    {
        name = names[rand() % names.size()] + " Slime";
        health = 5;
        attack = 2;
    }
    baseSlime(string x, int y, int z)
    {
        name = x;
        health = y;
        attack = z;
    }

    void basicAttack(baseSlime& target)
    {
        target.health -= attack;
        cout << "\n" << name << " deals " << attack << " damage to " << target.name << "\n";
    }

    bool checkHealth(baseSlime& target)
    {
        if(target.health <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class bossSlime : public baseSlime
{
public:
    int attackMult = 2;

    bossSlime()
    {
        attack = attack * attackMult;
    }

    void basicAttack(baseSlime& target)
    {
        target.health -= attack;
        cout << "\n" << name << " deals " << attack << " damage to " << target.name << "\n";
        cout << target.name << " is slimed\n";
    }

    void taunt()
    {
        cout << "\nI am king\n";
    }
};

int main()
{
    srand(time(0));

    baseSlime orbo;
    orbo.name = "Orbo";
    orbo.hello();

    bossSlime orbking;
    orbking.name = "Orbking";
    orbking.hello();

    orbo.basicAttack(orbking);
    if(orbo.checkHealth(orbking) == true)
    {
        cout << orbking.name << " is defeated\n";
    }
    orbking.taunt();
    orbking.basicAttack(orbo);
    if(orbo.checkHealth(orbking) == true)
    {
        cout << orbking.name << " is defeated\n";
    }

    vector<baseSlime> sludge(6);

    cout << "\n";
    for(auto& slime : sludge)
    {
        cout << slime.name << "\n";
    }

    random_shuffle(sludge.begin(), sludge.end());

    auto& a = sludge[0];
    auto& b = sludge[1];

    cout << "\n" << a.name;
    cout << "\n" << b.name;
    cout << "\n";

    while(a.health > 0 && b.health > 0)
    {
        a.basicAttack(b);
        b.basicAttack(a);
    }
    cout << "\ndefeat\n";

    return 0;
}