#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
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

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\n\nUpdate Client Info : ";
		cout << "\n________________________________\n";

		cout << "\nEnter First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Pin Code : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

public :
	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUsers::enPermissions::pUpdateClient))
		{
			return;
		}

		string Title = "\tUpdate Client Screen";

		_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout << "\nPlease, Enter account number to update : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis account is not found , Try another account number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer = 'n';
		cout << "\n\nAre you sure you want to update this client ? y/n ? ";

		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			_ReadClientInfo(Client);
			cout << "\n________________________________\n";

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{

			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\n\nAccount Updated Successfully :)";
				_PrintClient(Client);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\n\nError account was not saved because it's Empty :(";
				break;
			}
			}
		}
		else
		{
			return;
		}

	}
};

