//
//  main.cpp
//  Wedding planner
//
#include <iostream>
#include <cmath>
using namespace std;

//int main() Henrik, WIP
int get_menu(); //Henrik, ferdig
int inv_guests(); //Henrik, ferdig
void cards_and_sweets(int&, int&, int);//Benjamin: ferdig
int num_tables(int); //Benjamin: ferdig
int CalcSweets(int, double, int, string d); // Benjamin
int CalcModulus(int, int, int, string d); // Benjamin: brukes i tables og i kort
void coke_and_water(int&, int&, int); //Chris, ferdig
int card_cost(int, int);//Chris, WIP
int drink_cost(int); //Havard, WIP
void display(); //Havard, WIP

int main() {
    int guests = 0, choice = 0, coke = 0, water = 0, sweets = 0, cards = 0, cardCost = 0, tables = 0;
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
            break;
        }
        case 5:
        {
            cardCost = card_cost(cards, guests);
            break;
        }
        case 6:
        {
            cout << "WIP" << endl;
            break;
        }
        case 7:
        {
            cout << "WIP" << endl;
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
        return tables;
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
	else if (((a * b) / round(a * b)) == 1) 
    {
		
		c = temp;
	}

	cout << c << d << endl;
	return c;
}

void coke_and_water(int& coke, int& water, int guests)
{
    if (guests > 0)
    {
        const int PPL_PER_COKE_CASE = 6;
        const int PPL_PER_WATER_CASE = 2;
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

int card_cost(int cards, int guests)
{
    if (guests > 0)
    {
        const int cardPrice = 200;
        int cardCost = cards * cardPrice;
        return cardCost;
    }
    else
    {
        cout << "Please select option 1 and input the number of guests, then option 2 to determine Qty of cards needed." << endl;
        return 0;
    }

}

