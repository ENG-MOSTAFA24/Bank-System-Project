#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private :
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << "\t\t\t\t| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(25) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;

		cout << endl;

	}

public :

	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClients;
		vClients = clsBankClient::GetClientsList();

		_DrawScreenHeader("\t  Total Balances Screen", "\t  (" + to_string(vClients.size()) + ") Clients.");



		cout << "\n\t\t\t\t________________________________________________________\n" << endl;
		cout << "\t\t\t\t| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(25) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n\t\t\t\t________________________________________________________\n" << endl;


		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
		{
			cout << "\n\t\tNo Clients Available In the System!";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
			}
		}

		cout << "\n\t\t\t\t________________________________________________________\n" << endl;


		cout << "\t\t\t\t\t\t  Total Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;
	}
};

