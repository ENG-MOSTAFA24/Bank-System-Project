#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidate.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyMenueScreen : protected clsScreen
{
private :

    enum enCurrencyOptions
    {
        eList = 1, eFind = 2, eUpdate = 3, eCalculator = 4, eMainMenue = 5
    };

    static  void _GoBackToCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "\n\n\n\tPress any key to go back to Currency Exchange Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static int _ReadCurrencyExchangeOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 5]? ";

        int Option = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number Between 1 and 5 : ");

        return Option;
    }

    static void _ShowCurrenciesListScreen()
    {
        //cout << "\nCurrencies List screen will be here...";
        clsCurrencyListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen will be here...";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\nUpdate Rate Screen will be here...";
        clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        cout << "\nCurrency Calculator creen will be here...";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PreformCurrencyExchangeOption(enCurrencyOptions Option)
    {
        switch (Option)
        {
        case clsCurrencyMenueScreen::eList:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case clsCurrencyMenueScreen::eFind:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case clsCurrencyMenueScreen::eUpdate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case clsCurrencyMenueScreen::eCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case clsCurrencyMenueScreen::eMainMenue:
        {

            break;
        }
        }
    }

public :

	static void ShowCurrencyExchangeMenue()
	{

        if (!CheckAccessRights(clsUsers::enPermissions::pCurrencyExchange))
        {
            return;
        }

        system("cls");

        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PreformCurrencyExchangeOption(enCurrencyOptions(_ReadCurrencyExchangeOption()));

	}
};

