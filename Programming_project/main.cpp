//
//  main.cpp
//  Programming_project
//
//  Created by Henrik Reimers on 26/09/2022.
//
#include <iostream>
#include <cmath>
using namespace std;

const int PPL_PER_COKE_CASE = 6;
const int PPL_PER_WATER_CASE = 2;

//int main() Henrik
int get_menu(); //Henrik
int inv_guests(); //Henrik
void cards_and_sweets(int&, int&, int);//Benjamin: ferdig, må bare endre variabelnavn
int num_tables(int); //Benjamin: ferdig, må bare endre variabelnavn
int CalcSweets(int, double, int, string d);
int CalcModulus(int, int, int, string d); // Benjamin: brukes i tables og i kort
void coke_and_water(int&, int&, int); //Chris
int card_cost(int);//Chris
int drink_cost(int); //Havard
void display(); //Havard
int main() {
    int guests = 0;
    int choice = 0;
    int coke = 0;
    int water = 0;
    int sweets = 0;
    int cards = 0;
    int tables = 0;
    do {
        choice = get_menu();
        switch (choice) {
        case 1:
        {
            guests = inv_guests();
            break;
        }
        case 2:
        {
            cards_and_sweets(cards, sweets, guests);
            cout << cards << "  "<< sweets << endl;
            break;
        }
        case 3:
        {
            tables = num_tables(guests);
            break;
        }
        case 4:
        {
            coke_and_water(coke, water, guests);
            cout << coke << "   " << water << endl;
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
    } while (choice != 8);

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

void cards_and_sweets(int& cards, int& sweets, int guests)
{
	int CardsNeeded = 0;
	int Sweets = 0;
	string cardsMsg = " Card(s) are needed.";
	string sweetsMsg = " Sweet(s) are needed.";

	double TimesCandy = 1.2;
	if (guests > 0)
	{
		cards = CalcModulus(guests, 2, CardsNeeded, cardsMsg);
		sweets = CalcSweets(guests, TimesCandy, Sweets, sweetsMsg);

	}
	else
	{
		cout << "Please select option 1 and input the number of guests first." << endl;
	}

}
int num_tables(int guests)
{
	int tables = 0;
	string tableMsg = " Table(s) are needed.";

	if (guests > 0)
	{

		const int SeatsPerTable = 6;
		tables = CalcModulus(guests, SeatsPerTable, tables, tableMsg);
		return tables;
	}
	else
		cout << "Please select option 1 and input the number of guests first." << endl;

	return -1;
}
int CalcModulus(int a, int b, int c, string d)
{
	int temp = a / b;
	if (a % b > 0)
	{
		temp++;
		c = temp;
	}
	c = temp;
	cout << c << d << endl;
	return c;
}
int CalcSweets(int a, double b, int c, string d)
{

	double temp = a * b;
	if (((a * b) / round(a * b)) > 1 || ((a * b) / round(a * b)) < 1)
	{
		temp++;
		c = temp;
	}
	else if (((a * b) / round(a * b)) == 1) {
		
		c = temp;
	}

	cout << c << d << endl;
	return c;
}



void coke_and_water(int& coke, int& water, int guests)
{
    if (guests > 0)
    {
        bool extra_water = false;
        coke = guests / PPL_PER_COKE_CASE;
        if ((guests % PPL_PER_COKE_CASE) > 0)
            bool extra_water = true;
        water = guests / PPL_PER_WATER_CASE;
        if ((guests % PPL_PER_WATER_CASE) > 0)
            water++;
        if (extra_water)
            water++;
    }
    else
        cout << "Please select option 1 and input the number of guests first." << endl;
}

/*int card_cost(int cards)
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
*/
