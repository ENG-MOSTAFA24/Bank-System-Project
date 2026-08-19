#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private :

	static clsCurrency _GetCurrency()
	{
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found. Enter another code : ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static double _Convert(clsCurrency Currency1, double Amount)
	{
		double AmountInUSD = Amount / Currency1.Rate();

		return AmountInUSD;
	}

	static double _Convert(clsCurrency Currency1, clsCurrency Currency2, double Amount)
	{
		double AmountByDolar = _Convert(Currency1, Amount);
		double ConvertingAmount = AmountByDolar * Currency2.Rate();

		return ConvertingAmount;

	}

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

public :

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'n';

		do
		{
			system("cls");

			_DrawScreenHeader("\tCurrency Calculator Screen.");

			cout << "\nPlease Enter Currency1 Code : ";
			clsCurrency Currency1 = _GetCurrency();
			_PrintCurrencyCard(Currency1);

			cout << "\nPlease Enter Currency2 Code : ";
			clsCurrency Currency2 = _GetCurrency();
			_PrintCurrencyCard(Currency2);

			cout << "\nEnter Amount To Exchange : ";
			double Amount = clsInputValidate::ReadDblNumber();

			double ConvertingAmount;

			if (Currency2.CurrencyCode() == "USD")
			{
				ConvertingAmount = _Convert(Currency1, Amount);
			}
			else
			{
				ConvertingAmount = _Convert(Currency1, Currency2, Amount);
			}

			cout << "\n\nConvert Details:";
			cout << "\n_____________________________\n";
			cout << "\nConvert From " << Currency1.CurrencyCode() << " To " << Currency2.CurrencyCode() << endl;
			cout << Amount << " " << Currency1.CurrencyCode() << " = " << ConvertingAmount << " " << Currency2.CurrencyCode() ;
			cout << "\n_____________________________\n";

			cout << "\n\nDo you want to perform another calculation? y/n? ";
			cin >> Answer;


		} while (toupper(Answer) == 'Y');


	}
};

