//
//  main.cpp
//  Programming_project
//
//  Created by Henrik Reimers on 26/09/2022.
//

#include <iostream>
using namespace std;

//int main() Henrik
int get_menu(); //Henrik
int inv_guests(); //Henrik
void cards_and_sweets(int);//Benjamin
int tables(); //Benjamin
void coke_and_water(&int, &int); //Chris
int card_cost(int);//Chris
int drink_cost(int) //Havard
void display(); //Havard


int main() {
    int choice = 0;
    int guests;
    do {
        int choice = get_menu();
        switch (choice) {
            case 1:
                guests = inv_guests();
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            
            default:
                cout << "Please enter a value between 1 and 8!" << endl;
                break;
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

int inv_guests() {
    int guests = 0;
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
    return guests;
}

void cards_and_sweets() {
    
}

int tables() {
    
    return 0;
}



