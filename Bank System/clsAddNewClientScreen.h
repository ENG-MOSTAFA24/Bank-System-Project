#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{

private :

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter Client Info : ";
		cout << "\n__________________________";

		cout << "\n\nEnter First Name : ";
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

	static void _PrintClient (clsBankClient Client)
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
	static void AddNewClient()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pAddNewClient))
		{
			return;
		}

		string Title = "\tAdd New Client Screen.";

		_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout  << "\nPlease, Enter account number to add : ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis account is exist , Try another account number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n\nClient Added Successfully :)";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\n\nError account was not saved because it's Empty :(";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\n\nError account was not saved because it's allready exist :(";
			break;

		}
		}
	}

};

