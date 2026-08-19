#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private :
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nClient Card : ";
		cout << "\n_______________________________\n";
		cout << "\nFirst Name     : " << Client.FirstName;
		cout << "\nLast Name      : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccount Number : " << Client.AccountNumber();
		cout << "\nPassword       : " << Client.PinCode;
		cout << "\nBalance        : " << Client.AccountBalance;
		cout << "\n_______________________________\n";
	}

public :
	static void DeleteClient()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pDeleteClient))
		{
			return;
		}

		string Title = "\tDelete Client Screen.";

		_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout << "\nEnter accountnumber to delete : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis account number is not exist, try another acoount number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer = 'n';
		cout << "\n\nAre you sure you want to delete this client y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Delete())
			{
				cout << "\n\nClient Deleted Successfully :)";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}
		}

	}

};

