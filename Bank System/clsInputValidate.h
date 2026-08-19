#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static int ReadIntNumber(string ErrorMsg = "Invalid Number , Enter Again: \n")
	{
		int Number;

		while (!(cin >> Number) || cin.peek() != '\n')
		{
			cin.clear(); // to clean and reset the cin 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to delete the rabish in the buffer

			cout << ErrorMsg;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMsg = "Numebr is not within range , Enter again : \n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMsg;

			Number = ReadIntNumber();
		}

		return Number;

	}

	static double ReadDblNumber(string ErrorMsg = "Invalid Number , Enter Again: \n")
	{
		double Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMsg;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMsg = "Numebr is not within range , Enter again : \n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMsg;

			Number = ReadDblNumber();
		}

		return Number;

	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		return ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			|| ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) && clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)));
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S;

		getline(cin >> ws, S);

		return S;
	}

};