#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private :

	static void _PrinttransferLogLine(clsBankClient::stTransferLog Register)
	{
		cout << "\t\t| " << left << setw(25) << Register.DateTime;
		cout << "| " << left << setw(10) << Register.SourceAcc;
		cout << "| " << left << setw(10) << Register.DestinationAcc;
		cout << "| " << left << setw(10) << Register.Amount;
		cout << "| " << left << setw(10) << Register.sBalance;
		cout << "| " << left << setw(10) << Register.dBalance;
		cout << "| " << left << setw(10) << Register.User;

		cout << endl;
	}

public :

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLogRegisterList();

		_DrawScreenHeader("\tTransfer Log List Screen", "\t\t(" + to_string(vTransferLog.size()) + ") Records.");

		cout << "\n\t\t________________________________________________________";
		cout << "______________________________________\n" << endl;



		cout << "\t\t| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acc";
		cout << "| " << left << setw(10) << "d.Acc";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << "\n\t\t________________________________________________________";
		cout << "______________________________________\n" << endl;





		if (vTransferLog.size() == 0)
		{
			cout << "\n\t\t\t\t\t      No Transfer Logs In the System!\n";
		}
		else
		{
			for (clsBankClient::stTransferLog Register : vTransferLog)
			{
				_PrinttransferLogLine(Register);
			}
		}

		cout << "\n\t\t________________________________________________________";
		cout << "______________________________________\n" << endl;


	}

};

