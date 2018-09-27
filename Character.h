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
   
    void clear(){std::cin.clear(); std::cin.ignore(40,'\n');};
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
        return a;
    }
    else{
        ++*inventory = a;
        return b;
    }
}

void Character::takeItem(int i, int a, int b){
    if(i==0){
        cout << "You take the " << ITEMS[b];
        ++*inventory = b;
    }else{
        cout << "You take the " << ITEMS[a];
        ++*inventory = a;
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

class Warrior : public Character{
public:
    int buyItem(int a, int b);
    void takeItem(int i, int a, int b);
};


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
#endif /* Character_h */
