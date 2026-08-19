#pragma once
#include <iostream>
#include<iomanip>
#include "clsInputValidate.h"
#include "clsTotalBalancesScreen.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;


class clsTransactionsMenueScreen :protected clsScreen
{
private :

    enum _eTransactionsOptions
    {
        eDepositScreen = 1, eWithDrawScreen = 2, eTotalBalances = 5,  eTransfer = 3 ,eTransferLog=4, eMainMenue = 6
    };

    static void _DepositScreen()
    {
        //cout << "\nDeposit Screen Will Be Here Soon..." << endl;
        clsDepositScreen::ShowDepositScreen();
    }

    static void _WithdrawScreen()
    {
        //cout << "\nWithdraw Screen Will Be Here Soon..." << endl;
        clsWithdrawScreen::ShowWithDrawScreen();
    }

    static void _TotalBalances()
    {
        //cout << "\nTotal Balances Screen Will Be Here Soon..." << endl;
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _TransferScreen()
    {
        //cout << "\nTransfer Screen Will Be Here Soon..." << endl;
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        //cout << "\nTransfer Log Screen Will Be Here Soon...." << endl;
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

        system("pause>0");
        ShowTransactionMenueScreen();
    }

    static void _PreformTransactionsOptions(_eTransactionsOptions Option)
    {
        switch (Option)
        {
        case clsTransactionsMenueScreen::eDepositScreen:
        {
            system("cls");
            _DepositScreen();
            _GoBackToTransactionsScreen();
            break;
        }
        case clsTransactionsMenueScreen::eWithDrawScreen:
        {
            system("cls");
            _WithdrawScreen();
            _GoBackToTransactionsScreen();
            break;
        }
        case clsTransactionsMenueScreen::eTotalBalances:
        {
            system("cls");
            _TotalBalances();
            _GoBackToTransactionsScreen();
            break;
        }
        case clsTransactionsMenueScreen::eTransfer:
        {
            system("cls");
            _TransferScreen();
            _GoBackToTransactionsScreen();
            break;
        }
        case clsTransactionsMenueScreen::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsScreen();
            break;
        }
        case clsTransactionsMenueScreen::eMainMenue:
        {
            // Nothing , because out of this class will go to the main menu screen 

            break;
        }

        }
    }

    static int _ReadTransactionsOption()
    {
        cout << setw(37) << left << "" << "Enter what do you want to do [1 to 6]? ";

        int Number = clsInputValidate::ReadIntNumberBetween(1, 6, "\nEnter number between 1 and 6 : ");
        return Number;
    }

public :

	static void ShowTransactionMenueScreen()
	{

        if (!CheckAccessRights(clsUsers::enPermissions::pTransactions))
        {
            return;
        }

        system("cls");

        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Transfer.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[5] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PreformTransactionsOptions(_eTransactionsOptions(_ReadTransactionsOption()));

	}

};

