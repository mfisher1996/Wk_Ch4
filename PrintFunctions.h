#include <iostream>
#include <vector>
using namespace std;

//NOT COMPLETE CLASSES. Just the functions that I worked on.

//Character functions.
//-----------------------------------

//The function displays inventory size, the item's
//in the character's inventory, how much total hp the character spent,
//and the character's remaining hp.
Character::printList()
{
    int spentHp = 2000 - hp;    // To get how much total hp the character spent.
    string TAB = "\t\t";

    cout<< TAB << "Player's Results:" << endl;
    cout<< "\t---------------------------------" << endl;
    cout<< "\t*There are " << inventory.size()              //Inventory size.
        << " items in the player's inventory." << endl;
    cout<< "\t*The player's inventory contains: " << endl;

    for(int i = 0; i < inventory.size(); i++)
    {

       cout<< "\t   " << i+1 << ". " << inventory[i];   //The item's in the inventory.

       if(i < inventory.size() - 1)
       {
           cout<< endl;
       }
    }

    cout<< "\n\t*The player spent: " << spentHp << " HP." << endl;  //How much hp was spent.
    cout<< "\t*The player's balance is: " << hp << " HP." << endl;  //Remaining hp.
}

//This function displays that the character won.
Character::printFinal()
{
    cout<< "\nGAME OVER" << endl;
    cout<< "---------------------" << endl;
    cout<< "YOU ARE THE WINNER!!!" << endl;
}



//Warrior Functions:
//-----------------------------------


// This function displays the number of item's in the warrior's
// inventory. The specific items in the warrior's inventory,
// the total amount of hp the warrior spent, and the warrior's
// remaining hp.
Warrior::printList()
{
    int spentHp = 2000 - hp;    //To get the total amount of hp the warrior spent.
    string TAB = "\t\t";

    cout<< TAB << "Warrior's Results:" << endl;
    cout<< "\t---------------------------------" << endl;
    cout<< "\t*There are " << inventory.size()              //Inventory size.
        << " items in the warrior's inventory." << endl;
    cout<< "\t*The warrior's inventory contains: " << endl;

    for(int i = 0; i < inventory.size(); i++)
    {

       cout<< "\t   " << i+1 << ". " << inventory[i];   //The specific item's in the warrior's inventory.

       if(i < inventory.size() - 1)
       {
           cout<< endl;
       }
    }

    cout<< "\n\t*The warrior spent: " << spentHp << " HP." << endl; //Total amount of hp spent.
    cout<< "\t*The warrior's balance is: " << hp << " HP." << endl; //Remaining Hp.
}

//Function stating the warrior won.
Warrior::printFinal()
{
    cout<< "\nGAME OVER" << endl;
    cout<< "---------------------" << endl;
    cout<< "YOU LOSE" << endl;
}
