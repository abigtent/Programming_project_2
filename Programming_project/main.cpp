//
//  main.cpp
//  Programming_project
//
//  Created by Henrik Reimers on 26/09/2022.
//

#include <iostream>
using namespace std;

void get_menu();
int inv_guests();

int main() {
    get_menu();
    int guests = inv_guests();
    
    return 0;
}

void get_menu() {
    cout << "1. Enter number of invited guests." << endl;
    cout << "2. Determine the number of invitation cards and sweets." << endl;
    cout << "3. Determine the number of tables needed." << endl;
    cout << "4. Determine drinks order." << endl;
    cout << "5. Cost of invitation cards." << endl;
    cout << "6. Cost of drinks" << endl;
    cout << "7. Display all information." << endl;
    cout << "8. Quit." << endl;
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
            cout << "Please enter an integer between 1 and 8.";
        }
    }
    return guests;
}

