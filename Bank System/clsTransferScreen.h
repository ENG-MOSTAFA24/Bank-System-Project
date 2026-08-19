#pragma once
#include <iostream>
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;


class clsTransferScreen : protected clsScreen
{
private :

	static void _PrintClient(clsBankClient Clinet)
	{
		cout << "\n\nClient Card :";
		cout << "\n____________________________\n";
		cout << "\nFull Name      : " << Clinet.FullName();
		cout << "\nAccount Number : " << Clinet.AccountNumber();
		cout << "\nBalance        : " << Clinet.AccountBalance;
		cout << "\n____________________________\n";

	}

public :

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen.");

		string SourceAccountNumber;
		cout << "\nPlease Enter Account Number To Transfer From : ";
		SourceAccountNumber = clsInputValidate::ReadString();
		clsBankClient SourceClient =  clsBankClient::Find(SourceAccountNumber);
		_PrintClient(SourceClient);

		string DestinationAccNumber;
		cout << "\nPlease Enter Account Number To Transfer To : ";
		DestinationAccNumber = clsInputValidate::ReadString();

		while (DestinationAccNumber == SourceAccountNumber)
		{
			cout << "\nYou Can't Enter The Same Account Number , Try another one : ";
			DestinationAccNumber = clsInputValidate::ReadString();
		}

		clsBankClient DestinationClient = clsBankClient::Find(DestinationAccNumber);
		_PrintClient(DestinationClient);

		cout << "\nEnter Transfer Amount : ";
		double Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds The Available Balance, Enter another amount : ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		char Answer = 'n';
		cout << "\n\nAre you sure you want to perform this operation? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				cout << "\n\nTransfer Done Successfully :) ";

			}
			else
			{
				cout << "\n\nTransfer Faild :( ";

			}
		}

		_PrintClient(SourceClient);

		_PrintClient(DestinationClient);
	}
};

