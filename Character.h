//
//  Character.h
//  Wk_ch4
//
//  Created by Mason Fisher on 9/25/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#ifndef Character_h
#define Character_h

#include <ctime>
#include <cstdlib>

using namespace std;

string ITEMS[4] ={"Sword","Armor","Shield","Pen"};
int PRICES[4] ={1000,500,250,100};

class Character {
protected:
    int * inventory;
    int length;
    int MAX_TURN =100;
    int hp;
    int numb();
public:
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
}

Character::~Character(){
    delete inventory;
}

bool Character::isBroke(){
    if( hp > 0)
        return 0;
    else
        return 1;
}

void Character::getItem(int& a,int& b){
    cout << "The 'Friar' offers you two goods: \n";
    a = rand()%4;
    b = rand()%4;
    cout << "1. " << ITEMS[a] << " for " << PRICES[a] << " hp \nOr\n";
    cout << "2. " << ITEMS[b] << " for " << PRICES[b] << " hp\n";
}

int Character::buyItem(int a,int b){
    cout << "Which item would you like?\n";
    int i =numb();
    if(i==1){
        ++*inventory = a;
        length++;
        return a;
    }
    else{
        length++;
        ++*inventory = a;
        return b;
    }
}

void Character::takeItem(int i, int a, int b){
    if(i==0){
        cout << "You take the " << ITEMS[b];
        ++*inventory = b;
        length++;
    }else{
        cout << "You take the " << ITEMS[a];
        ++*inventory = a;
        length++;
    }
}

int Character::numb()
{
    int num=0;
    clear();
    std::cin >> num;
    
    while(!num)
    {
        clear();
        std::cout << "Invalid input.\n";
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}
void Character::printList()
{
    int spentHp = 2000 - hp;    // To get how much total hp the character spent.
    string TAB = "\t\t";
    
    cout<< TAB << "Player's Results:" << endl;
    cout<< "\t---------------------------------" << endl;
    cout<< "\t*There are " << length              //Inventory size.
    << " items in the player's inventory." << endl;
    cout<< "\t*The player's inventory contains: " << endl;
    
    for(int i = 0; i < length; i++)
    {
        
        cout<< "\t   " << i+1 << ". " << inventory[i];   //The item's in the inventory.
        
        if(i < length - 1)
        {
            cout<< endl;
        }
    }
    
    cout<< "\n\t*The player spent: " << spentHp << " HP." << endl;  //How much hp was spent.
    cout<< "\t*The player's balance is: " << hp << " HP." << endl;  //Remaining hp.
}



int Warrior::buyItem(int a, int b){
    int i;
    if(PRICES[a]<PRICES[b])
        i = 1;
    else
        i = 2;
    cout << "The warrior choses:" << ITEMS[i] << endl;
    return i;
}

void Warrior::takeItem(int i, int a, int b){
    if(i==0){
        cout << "The warrior takes the " << ITEMS[b];
        ++*inventory = b;
    }else{
        cout << "The warrior takes the " << ITEMS[a];
        ++*inventory = a;
    }
}

void Warrior::printList()
{
    int spentHp = 2000 - hp;    //To get the total amount of hp the warrior spent.
    string TAB = "\t\t";
    
    cout<< TAB << "Warrior's Results:" << endl;
    cout<< "\t---------------------------------" << endl;
    cout<< "\t*There are " << length             //Inventory size.
    << " items in the warrior's inventory." << endl;
    cout<< "\t*The warrior's inventory contains: " << endl;
    
    for(int i = 0; i < length; i++)
    {
        
        cout<< "\t   " << i+1 << ". " << inventory[i];   //The specific item's in the warrior's inventory.
        
        if(i < length - 1)
        {
            cout<< endl;
        }
    }
    
    cout<< "\n\t*The warrior spent: " << spentHp << " HP." << endl; //Total amount of hp spent.
    cout<< "\t*The warrior's balance is: " << hp << " HP." << endl; //Remaining Hp.
}

#endif /* Character_h */
