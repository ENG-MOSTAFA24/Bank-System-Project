#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"


class clsFindCurrencyScreen : protected clsScreen
{
private :

	enum enChoice
	{
		eCode = 1, eCountry = 2
	};

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

	static void _ShowResults(clsCurrency Currency)
	{
		if (Currency.IsEmpty())
		{
			cout << "\n\nCurrency Not Found :( ";
		}
		else
		{
			cout << "\n\nCurrency Found :) ";
			_PrintCurrencyCard(Currency);
		}
	}

public :

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen.");

		cout << "\nFind By: [1] Code or [2] Country  ? ";
		short Choice = clsInputValidate::ReadIntNumber();


		switch (enChoice(Choice))		
		{
		case clsFindCurrencyScreen::eCode:
		{
			cout << "\nPlease Enter Currency Code : ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Currency);

			break;

		}
		case clsFindCurrencyScreen::eCountry:
		{
			cout << "\nPlease Enter Country : ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);

			break;
		}
		}

	}
};

