#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;


class clsDepositScreen : protected clsScreen
{
private :

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nClient Card : ";
		cout << "\n_______________________________";
		cout << "\n\nFirst Name     : " << Client.FirstName;
		cout << "\nLast Name      : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccount Number : " << Client.AccountNumber();
		cout << "\nPassword       : " << Client.PinCode;
		cout << "\nBalance        : " << Client.AccountBalance;
		cout << "\n_______________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease, Enter an account number : ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public :

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t  Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nSorry this account number is not exist. Try another account number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer = 'n';
		cout << "\n\nAre you sure you want to preform this transaction? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\nPlease, enter deposit amount ? ";
			double Amount = clsInputValidate::ReadDblNumber();

			if (Client.Deposit(Amount))
			{
				cout << "\n\nAmount Deposited Successfully :) ";

				cout << "\n\nNew Balance is : " << Client.AccountBalance  << endl;
			}
		}
		else
		{
			cout << "\nDeposit was cancelled" << endl;
		}
	}

};