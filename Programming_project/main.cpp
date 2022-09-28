//
//  main.cpp
//  Programming_project
//
//  Created by Henrik Reimers on 26/09/2022.
//
#include <iostream>
using namespace std;

int get_menu();
void inv_guests(int &guests);
void cards_and_sweets(int &cards, int &sweets, int);
void tables(int &tables, int);
void coke_and_water(int&, int&); //Chris
int card_cost(int);//Chris
int drink_cost(int); //Havard
void display(); //Havard

int main() {
    int choice = 0;
    bool input_guests = false;
    do {
        int num_guests;
        int num_cards;
        int num_sweets;
        int num_tables;
        choice = get_menu();
        switch (choice) {
            case 1:
            {
                inv_guests(num_guests);
                cout << num_guests << endl;
                break;
            }
            case 2:
            {
                cards_and_sweets(num_cards, num_sweets, num_guests);
                cout << "Cards = " << num_cards << "    " << "Sweets = " << num_sweets << endl;
                break;
            }
            case 3:
            {
                tables(num_tables, num_guests);
                cout << "Tables = " << num_tables << endl;
                break;
            }
            case 4:
            {
                
                break;
            }
            case 5:
            {
                
                break;
            }
            case 6:
            {
                
                break;
            }
            case 7:
            {
                
                break;
            }
            case 8:
            {
                
                break;
            }
            default: {
                cout << "Please enter a valid value!" << endl;
                break;
            }
        }
    }
    while(choice != 8);
   
    return 0;
}

//add while loop to error check any choices not between 1 and 8
int get_menu() {
    cout << "1. Enter number of invited guests." << endl;
    cout << "2. Determine the number of invitation cards and sweets." << endl;
    cout << "3. Determine the number of tables needed." << endl;
    cout << "4. Determine drinks order." << endl;
    cout << "5. Cost of invitation cards." << endl;
    cout << "6. Cost of drinks" << endl;
    cout << "7. Display all information." << endl;
    cout << "8. Quit." << endl;
    cout << "Please enter your choice: ";
    int choice = 0;
    cin >> choice;
    return choice;
}

void inv_guests(int &guests) {
    bool valid_int = false;
    while (valid_int != true) {
        cout << "Please declare the number of guests: " << endl;
        cin >> guests;
        if (guests > 0) {
            valid_int = true;
        }
        else {
            cout << "Please enter a valid number of guests! (0+).";
        }
    }
   
}

void cards_and_sweets(int &cards, int &sweets, int num_guests) {
    cards = num_guests / 2;
    sweets = num_guests * 1.2;
}

void tables(int &tables, int num_guests) {
    if (num_guests % 6 == 0) {
        tables = num_guests / 6;
    } else {
        tables = (num_guests / 6) + 1;
    }
    
}



