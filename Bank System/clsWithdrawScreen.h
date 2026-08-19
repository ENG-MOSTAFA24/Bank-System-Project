#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;


class clsWithdrawScreen : protected clsScreen
{
private:

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

public:

	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("\t  Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nSorry this account number is not exist. Try another account number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease, enter withdraw amount ? ";
		double Amount = clsInputValidate::ReadDblNumber();


		char Answer = 'n';
		cout << "\n\nAre you sure you want to preform this transaction? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\n\nAmount Withdrawed Successfully :) ";

				cout << "\n\nNew Balance is : " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "\n\nCan't Withdraw, Insuffecient Balance!";
				cout << "\n\nAmount to withdraw is : " << Amount;
				cout << "\nYour Balance is : " << Client.AccountBalance << endl;
			}
		}
	}


};

