//
//  main.cpp
//  Programming_project
//
//  Created by Henrik Reimers on 26/09/2022.
//
#include <iostream>
using namespace std;

const int ppl_per_coke_case = 6;
const int ppl_per_water_case = 2;

//int main() Henrik
int get_menu(); //Henrik
int inv_guests(); //Henrik
void cards_and_sweets();//Benjamin
void tables(); //Benjamin ferdig, må bare endre variabelnavn
void coke_and_water(int); //Chris
int card_cost(int);//Chris
int drink_cost(int); //Havard
void display(); //Havard

int main() {
    int choice = 0;
    int guests = 0;
    int coke_count, water_count;
    do {
        int num_guests;
        int num_cards;
        int num_sweets;
        int num_tables;
        choice = get_menu();
        switch (choice) {
            case 1:
            {
                guests = inv_guests();
                break;
            }
            case 2:
            {
                cout << guests << endl;
                break;
            }
            case 3:
            {
               
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
                cout << "Quitting program..." << endl;
                break;
            }
            default: {
                cout << "Please enter a value between 1 and 8!" << endl;
                break;
            }
        }
    }
    while(choice != 8);
   
    return 0;
}

//add while loop to error check any choices not between 1 and 8
int get_menu() {
    cout << "____________Menu____________" << endl;
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
        cout << "Please declare the number of guests: ";
        cin >> guests;
        if (guests > 0) {
            valid_int = true;
        }
        else {
            cout << "Please enter a valid number of guests! (1+)." << endl;
        }
    }
    return guests;
}

void coke_and_water(int guests)
{
    if (guests > 0)
    {
        coke_count = guests / ppl_per_coke_case;
        if ((guests % ppl_per_coke_case) > 0)
            bool extra_water = true;
        water_count = guests / ppl_per_water_case;
        if ((guests % ppl_per_water_case) > 0)
            water_count++;
        if (extra_water)
            water_count++;
    }
    else
        cout << "Please select option 1 and input the number of guests first." << endl;
}

int card_cost(int cards)
 {
    if (guests > 0)
    {
 
    }
    else
    {
        cout << "Please select option 1 and input the number of guests first." << endl;
        return -1;
    }
 
 }
 
