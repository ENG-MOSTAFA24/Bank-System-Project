#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenueScreen.h"
#include "clsManageUsersScreen.h"
#include "clsCurrencyMenueScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Global.h"

class clsMainScreen :protected clsScreen
{
private :
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 10, eLoginRegister = 8, eCurrency = 9
    };

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\n\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static int _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Enter what do you want to do [1 to 10]? ";
        int Choise = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number Between 1 and 10 : ");
        return Choise;
    }

    static void _ShowAllClientsScreen()
    {
        //cout << "\nClient list screen will be here...";
        clsClientListScreen::PrintClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd new client screen will be here...";
        clsAddNewClientScreen::AddNewClient();  

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete client screen will be here...";
        clsDeleteClientScreen::DeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate client screen will be here...";
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind client screen will be here...";
        clsFindClientScreen::ShowFindScreen();
    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions screen will be here...";
        clsTransactionsMenueScreen::ShowTransactionMenueScreen();

    }

    static void _ShowManageUsersMenue()
    {
        //cout << "\nManage users screen will be here...";
        clsManageUsersScreen::ShowManageUsersMenueScreen();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeMenue()
    {
        //cout << "\nCurrency Exchange Menue screen will be here...";
        clsCurrencyMenueScreen::ShowCurrencyExchangeMenue();
    }

    //static void _ShowEndScreen()
    //{
    //    cout << "\nEnd screen will be here...";

    //}

    static void _Logout()
    {
        // Will Make the current user empty for the next login and go back to the main function 
        // And Return the program from beginning
        CurrentUser = clsUsers::Find("", "");
    }

    static void _PreformMainMenueOption(enMainMenueOptions Operation)
    {
        switch (Operation)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eCurrency :
        {
            system("cls");
            _ShowCurrencyExchangeMenue();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eExit:
        {
            system("cls");
            _Logout();
            break;
        }
        }
    }

public :

	static void ShowMainMenue()
	{
		system("cls");

		_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PreformMainMenueOption(enMainMenueOptions(_ReadMainMenueOption()));
	}
};

