#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"

using namespace std;


class clsCurrency
{
private :

	enum enMode
	{
		eEmptyMode = 0, eUpdateMode = 1
	};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	double _Rate;


	static clsCurrency _ConvertDataLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::eUpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToDataLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string Line = "";
		Line += Currency.Country() + Seperator;
		Line += Currency.CurrencyCode() + Seperator;
		Line += Currency.CurrencyName() + Seperator;
		Line += to_string(Currency.Rate());

		return Line;
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}

	static vector <clsCurrency> _LoadDataFromFile()
	{
		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertDataLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrencies;

	}

	void _SaveDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out); // Write Mode

		if (MyFile.is_open())
		{
			for (clsCurrency C : vCurrencies)
			{
				string Line = _ConvertCurrencyObjectToDataLine(C);
				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveDataToFile(vCurrencies);

	}

public :



	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, double Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	// Read Only Property 
	string Country()
	{
		return _Country;
	}


	// Read Only Property 
	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	// Read Only Property 
	string CurrencyName()
	{
		return _CurrencyName;
	}

	// Update The Rate 
	void UpdateRate(double NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	// Get The Rate 
	double Rate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	static bool IsCurrencyExist(string CountryCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CountryCode);

		return (!Currency.IsEmpty());
	}

	static clsCurrency FindByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);   // Read Mode 

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertDataLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == Code)
				{
					MyFile.close();
					return Currency;
				}

			}
		}

		MyFile.close();

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);   // Read Mode 

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertDataLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}
		}

		MyFile.close();

		return _GetEmptyCurrencyObject();
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadDataFromFile();
	}


};

