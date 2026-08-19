#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"

using namespace std;

void PrintCurrencyCard(clsCurrency Currency)
{
	cout << "\n\nCurrency Card : ";
	cout << "\n__________________________\n";
	cout << "\nCountry      : " << Currency.Country();
	cout << "\nCurrencyCode : " << Currency.CurrencyCode();
	cout << "\nCurrencyName : " << Currency.CurrencyName();
	cout << "\nRate (1$)    : " << Currency.Rate();
	cout << "\n__________________________\n";

}

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			system("color 4F");
			break;
		}
	}

	//clsCurrency Currency1 = clsCurrency::FindByCode("egp");
	//PrintCurrencyCard(Currency1);

	//clsCurrency Currency2 = clsCurrency::FindByCountry("egypt");
	//PrintCurrencyCard(Currency2);

	//Currency2.UpdateRate(50);
	//PrintCurrencyCard(Currency2);

	system("pause>0");

	return 0;

}