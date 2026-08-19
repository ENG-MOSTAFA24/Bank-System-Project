#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen : protected clsScreen 
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

	static void ShowFindScreen()
	{

		if (!CheckAccessRights(clsUsers::enPermissions::pFindClient))
		{
			return;
		}

		string Title = "\tFind Client Screen";

		_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout << "\nPlease, Enter account number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis account is not found , Try another account number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :)";
		}
		else
		{
			cout << "\nClient Not Found :(";
		}

		_PrintClient(Client);

	}



};

