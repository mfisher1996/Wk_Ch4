//
//  Character.h

#ifndef Character_h
#define Character_h

#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

string ITEMS[4] ={"Sword","Armor","Shield","Pen"};
int PRICES[4] ={1000,500,250,100};

class Character {
protected:
    int * inventory;
    int length;
    int MAX_TURN =100;
    int numb(int a, int b);
public:
    int hp;
    Character();
    ~Character();
    bool isBroke();
    void getItem(int& a, int& b);
    int buyItem(int a, int b);
    void takeItem(int i, int a, int b);
    void printList();
    void clear(){std::cin.clear(); std::cin.ignore(40,'\n');};
};

class Warrior : public Character{
public:
    void printList();
    int buyItem(int a, int b);
    void takeItem(int i, int a, int b);
};


Character::Character(){
    srand(time(NULL));
    hp = 2000;
    inventory = new int[MAX_TURN];
    length=0;
}

Character::~Character(){
    delete inventory;
}

bool Character::isBroke(){
    if( hp > 0)
        return false;
    else
        return true;
}

void Character::getItem(int& a,int& b){
    cout<< "+======================================+" <<endl;
    cout<< "| The 'Friar' offers you two goods:    |" << endl;
    cout<< "|--------------------------------------|" <<endl;
    cout<< "|                                      |" << endl;
    a = rand()%4;
    b = rand()%4;

    string itemA = ITEMS[a];
    string itemB = ITEMS[b];

    cout<< "| 1. " << ITEMS[a] << " for " << PRICES[a] << " hp";
    if(PRICES[a] > 999 )
    {   //40 is the size of the text box, itemA.size is
        //the number of spaces the item name takes up.
        //5 is for the spaces the price takes up.
        //12 is for the "| 1. "...." sting.
        //Makes the text box look right.
        cout<< setw(40-(itemA.size()+5+12)) << "|" << endl;
    }
    else
    {
        cout<< setw(40-(itemA.size()+4+12)) << "|" << endl;
    }
    cout<< "|                                      |" << endl;
    cout<< "| OR                                   |" << endl;
    cout<< "|                                      |" << endl;
    cout<< "| 2. " << ITEMS[b] << " for " << PRICES[b] << " hp";
    if(PRICES[b] > 999 )
    {
        cout<< setw(40-(itemB.size()+5+12)) << "|" << endl;
    }
    else
    {
        cout<< setw(40-(itemB.size()+4+12)) << "|" << endl;
    }
    cout<< "|                                      |" << endl;
    cout<< "+======================================+" << endl;

}

int Character::buyItem(int a,int b){
    cout << "Which item would you like? ";
    int i =numb(1,2);
    if(i==1){
        inventory[length] = a;
        hp-=PRICES[a];
        cout << "\n\t*You bought the " << ITEMS[inventory[length]] << "\n";
        length++;
        return i;
    }
    else{
        inventory[length] = b;
        hp-=PRICES[b];
        cout << "\n\t*You bought the " << ITEMS[inventory[length]] << "\n";
        length++;
        return i;
    }
}

void Character::takeItem(int i, int a, int b){
    if(i==1){
        cout << "\n\t*You take the " << ITEMS[b];
        inventory[length] = b;
        length++;
        hp-=PRICES[b];
    }else{
        cout << "\n\t*You take the " << ITEMS[a];
        inventory[length] = a;
        length++;
        hp-=PRICES[a];
    }
}

int Character::numb(int a, int b)
{
    int num=0;
    std::cin >> num;

    while(num!=a&&num!=b){
        clear();
        std::cout << "Invalid input.\n";
        std::cout << "Please input either 1 or 2: ";
        std::cin >> num;
    }

    return num;
}
void Character::printList()
{
    int spentHp = 2000 - hp;    // To get how much total hp the character spent.


    cout<< "Player's Results:" << endl;
    cout<< "---------------------------------" << endl;
    cout<< "*There are " << length              //Inventory size.
    << " items in the player's inventory." << endl;
    cout<< "*The player's inventory contains: " << endl;

    for(int i = 0; i < length; i++)
    {

        cout<< "  " << i+1 << ". " << ITEMS[inventory[i]];   //The item's in the inventory.

        if(i < length - 1)
        {
            cout<< endl;
        }
    }

    cout<< "\n*The player spent: " << spentHp << " HP." << endl;  //How much hp was spent.
    cout<< "*The player's balance is: " << hp << " HP." << endl;  //Remaining hp.
}



int Warrior::buyItem(int a, int b){
    int i;
    if(PRICES[a]<PRICES[b]){
        cout << "\n\t*The warrior chooses: " << ITEMS[a]<< "\n";
        i = 1;
        Warrior::hp-=PRICES[a];
        Warrior::inventory[length] = a;
        Warrior::length++;
    }
    else{
        cout << "\n\t*The warrior chooses: " << ITEMS[b] << "\n";
        i = 2;
        Warrior::hp-=PRICES[b];
        Warrior::inventory[length] = b;
        Warrior::length++;
    }
    return i;
}

void Warrior::takeItem(int i, int a, int b){
    if(i==1){
        cout << "\n\t*The warrior takes the " << ITEMS[b];
        Warrior::inventory[length] = b;
        Warrior::length++;
        hp-=PRICES[b];
    }else if(i==2){
        cout << "\n\t*The warrior takes the " << ITEMS[a];
        inventory[length] = a;
        length++;
        hp-=PRICES[a];
    }
}

void Warrior::printList()
{
    int spentHp = 2000 - hp;    //To get the total amount of hp the warrior spent.
    string TAB = "\t\t";

    cout<< "Warrior's Results:" << endl;
    cout<< "---------------------------------" << endl;
    cout<< "*There are " << length             //Inventory size.
    << " items in the warrior's inventory." << endl;
    cout<< "*The warrior's inventory contains: " << endl;

    for(int i = 0; i < length; i++)
    {

        cout<< "  " << i+1 << ". " << ITEMS[inventory[i]];   //The specific item's in the warrior's inventory.

        if(i < length - 1)
        {
            cout<< endl;
        }
    }

    cout<< "\n*The warrior spent: " << spentHp << " HP." << endl; //Total amount of hp spent.
    cout<< "*The warrior's balance is: " << hp << " HP." << endl; //Remaining Hp.
}

#endif /* Character_h */
