#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRate : protected clsScreen 
{
private :

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card : ";
		cout << "\n__________________________\n";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCurrencyCode : " << Currency.CurrencyCode();
		cout << "\nCurrencyName : " << Currency.CurrencyName();
		cout << "\nRate (1$)    : " << Currency.Rate();
		cout << "\n__________________________\n";
	}

	static double ReadNewRate()
	{
		cout << "\n\nUpdate Currency Rate:";
		cout << "\n__________________________\n";
		cout << "\nEnter New Rate : ";
		double NewRate = clsInputValidate::ReadDblNumber();

		return NewRate;
	}


public :

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Rate Screen.");

		cout << "\nPlease Enter Currency Code : ";
		string Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurrency is not found. Enter another code : ";
			 Code = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		_PrintCurrencyCard(Currency);

		char Answer = 'n';
		cout << "\nAre you sure you want to update the rate of this currency? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Currency.UpdateRate(ReadNewRate());
			cout << "\n\nCurrency Rate Updated Seccessfully :) ";
			_PrintCurrencyCard(Currency);
		}
	}


};

