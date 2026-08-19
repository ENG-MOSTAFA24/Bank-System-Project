#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;

class clsCurrencyListScreen : protected clsScreen
{
private :

	static void PrintUserRecordLine(clsCurrency Currency)
	{
		cout << "      | " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(10) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
		cout << endl;
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		clsScreen::_DrawScreenHeader("\tCurrencies List Screen", "\t(" + to_string(vCurrencies.size()) + ")  Currency.");

		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;


		cout << "      | " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate(1$)";
		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;



		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for (clsCurrency Currency : vCurrencies)
			{
				PrintUserRecordLine(Currency);
			}
		}

		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;


	}

};

