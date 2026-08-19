#pragma once
#include <iostream>
#include "clsUsers.h"
#include "clsScreen.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private :
	static void _ReadUserInfo(clsUsers &User)
	{
		cout << "\nEnter First Name : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password : ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission : ";
		User.Permissions = _ReadPermissionToSet();
	}

	static int _ReadPermissionToSet()
	{
		int Permission = 0;
		char Answer = 'n';

		cout << "\n\nDo you want to give this user full access? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n";
		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client> y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pTransactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pShowLoginRegister;
		}

		cout << "\nShow Currency Exchange? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUsers::enPermissions::pCurrencyExchange;
		}


		return Permission;
	}

	static void _PrintUser(clsUsers User)
	{
		cout << "\n\nUser Card : ";
		cout << "\n_______________________________\n";
		cout << "\nFirst Name    : " << User.FirstName;
		cout << "\nLast Name     : " << User.LastName;
		cout << "\nFull Name     : " << User.FullName();
		cout << "\nEmail         : " << User.Email;
		cout << "\nPhone         : " << User.Phone;
		cout << "\nUser Name     : " << User.UserName;
		cout << "\nPassword      : " << User.Password;
		cout << "\nPermissions   : " << User.Permissions;
		cout << "\n_______________________________\n";
	}
	

public :

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t  Add New User Screen.");

		cout << "\n\nPlease Enter UserName : ";
		string UserName = clsInputValidate::ReadString();

		while (clsUsers::IsUserExist(UserName))
		{
			cout << "\nUserName Is Already Used, Choose another username : ";
			UserName = clsInputValidate::ReadString();;
		}

		clsUsers NewUser = clsUsers::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUsers::enSaveResults SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUsers::svSuccessed:
			cout << "\n\nUser Added Succcessfully :)";
			_PrintUser(NewUser);
			break;
		case clsUsers::svFailEmptyObject:
			cout << "\n\nError User was not saved because it's empty :( ";
			break;
		case clsUsers::svFailUserExists:
			cout << "\n\nError User was not saved because UserName is used! ";
			break;
		default:
			break;
		}
	}

};

