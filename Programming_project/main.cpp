//
//  main.cpp
//  Wedding planner
//
#include <iostream>
#include <cmath>
using namespace std;

int get_menu();
int inv_guests();
void cards_and_sweets(int&, int&, int);
int num_tables(int);
int CalcSweets(int, double);
int CalcModulus(int, int);
void coke_and_water(int&, int&, int);
int card_cost(int, int);
void drinks_cost(int, int, int, int&, int&);
void display(int, int, int, int, int, int, int, int, int);

int main() {
    int guests = 0, choice = 0, coke_cases = 0, water_cases = 0, sweets = 0, cards = 0, cardCost = 0, tables = 0, coke_cost = 0, water_cost = 0;
    cout << "The Wedding Planning Assistant is pleased to be at your service!" << endl;
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
            coke_and_water(coke_cases, water_cases, guests);
            break;
        }
        case 5:
        {
            cardCost = card_cost(cards, guests);
            break;
        }
        case 6:
        {
            drinks_cost(coke_cases, water_cases, guests, coke_cost, water_cost);
            break;
        }
        case 7:
        {
            display(guests, coke_cases, water_cases, sweets, cards, cardCost, tables, coke_cost, water_cost);
            break;
        }
        case 8:
        {
            cout << "Quitting program. Thank you, come again..." << endl;
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
    cout << "____________________________" << endl;
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
	const double TimesCandy = 1.2;
	if (guests > 0)
	{
        	cards = CalcModulus(guests, 2);
      		sweets = CalcSweets(guests, TimesCandy);
	}
	else
	{
		cout << "Please select option 1 and input the number of guests first." << endl;
	}
}

int num_tables(int guests)
{
	int tables = 0;

	if (guests > 0)
	{
		const int SeatsPerTable = 6;
		tables = CalcModulus(guests, SeatsPerTable);
	}
	else
		cout << "Please select option 1 and input the number of guests first." << endl;
        
    return tables;
}

int CalcModulus(int a, int b)
{
    int temp = a / b;
    if (a % b > 0)
    {
        temp++;
    }
    return temp;
}

int CalcSweets(int a, double b)
{
    double temp = a * b;
    if (((a * b) / round(a * b)) > 1 || ((a * b) / round(a * b)) < 1)
    {
        temp++;
    }
    return temp;
}

void coke_and_water(int& coke, int& water, int guests)
{
    if (guests > 0)
    {
        const int PPL_PER_COKE_CASE = 6;
        const int PPL_PER_WATER_CASE = 2;
        coke = guests / PPL_PER_COKE_CASE;
        water = guests / PPL_PER_WATER_CASE;
        if ((guests % PPL_PER_WATER_CASE) > 0)
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

void drinks_cost(int coke_cases, int water_cases, int guests, int& cokeCost, int& waterCost)
{
    if (guests > 0)
    {
        const int cokePrice = 30;
        cokeCost = coke_cases * cokePrice;

        const int waterPrice = 20;
        waterCost = water_cases * waterPrice;
    }
    else
    {
        cout << "Please select option 1 and input the number of guests, then option 4 to determine Qty of drinks needed." << endl;
    }
}

void display(int guests, int coke, int water, int sweets, int cards, int cardCost, int tables, int cokeCost, int waterCost)
{
    if (guests > 0)
    {
        cout << "The number of invited guests: " << guests << endl;
        cout << "Needs: " << cards << " invitation card(s), " << sweets << " sweet(s), " << tables << " table(s), ";
        cout << coke << " case(s) of coke and " << water << " case(s) of water." << endl;
        cout << "Cost of invitation card(s): " << cardCost << " NOK." << endl;
        cout << "Cost of drinks: " << cokeCost << " NOK for Coke and " << waterCost << " NOK for water with a total of " << cokeCost + waterCost << " NOK." << endl;
    }
    else
    {
        cout << "Please select option 1 and input the number of guests first." << endl;
    }
}
