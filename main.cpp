#include <iostream>
#include "Character.h"
using namespace std;

//Stuff Charles did:
//Line 34: Declared variable named turn. Turn keeps track of what turn it is, and who gets to pick first.
//Line 49: Displays the turn number.s
//Line 53: made b = a so we go into the while loop. Thus, b will never be the same as a.
// Lines 61 and 96: made an if/else statement based on turns. So, turn 0 player gets to pick first.
//                   Turn 1 warrior gets to pick first. Turn 2 Player gets to pick first. Etc.
//Line 118: Increments turn.

// I just did a general idea of how this program should work
// I'll need to know how the classes are gonna be set in order
// to apply them in the main body of the program
// If you have any other ideas to add, let me know



int main()
{
    Character char1;                 //To use class Character
    Warrior char2;                    //To use class Warrior

    int turn = 0;               //Whose turn it is to choose first.


    int selection = 0, a = 0, b = 0;
    while (!(char1.isBroke() || char2.isBroke())) //(To implement instead of the FOR LOOP based on the classes we'll use)
        {
            char1.getItem(a, b);

            if(turn % 2 == 0){   //If it's the player's turn
                selection = char1.buyItem(a, b);
                char2.takeItem(selection, a, b);
            }
            else{    //Else it's the warrior's turn.

                cout<< "\n\tWarrior is going first..." << endl;
                cout<< "  ------------------------------------" << endl;

                selection = char2.buyItem(a, b);
                char1.takeItem(selection, a, b);
            }
            turn++;     //Make it the next turn.
            cout<<"\n\n\n\tPlayer hp: "<<char1.hp<<"\n\tWarrior hp: "<<char2.hp<<"\n";
            cout << "\nPress any key to continue...\n\n";
            if(turn % 2 == 1 )
            {
                cin.ignore(1000,'\n');
            }
            cin.get();
            //getch();
        }
        if(char1.isBroke() == true && char2.isBroke() == false)
        {
            cout<< "+===========================================+" << endl;
            cout<< "|             PLAYER LOSES.                 |" << endl;
            cout<< "|             WARRIOR WINS.                 |" << endl;
            cout<< "+===========================================+" << endl;
        }
        else if(char1.isBroke() == false && char2.isBroke() == true)
        {
            cout<< "+===========================================+" << endl;
            cout<< "|             PLAYER WINS!!!                |" << endl;
            cout<< "|             WARRIOR LOSES.                |" << endl;
            cout<< "+===========================================+" << endl;
        }
        else
        {
            cout<< "+===========================================+" << endl;
            cout<< "|            It's A Tie!                    |" << endl;
            cout<< "|                                           |" << endl;
            cout<< "+===========================================+" << endl;
        }
        cout<< "\n\n\n";

        char1.printList();
        cout<< "\n\n";
        char2.printList();
    cout << endl;
    return 0;
}
