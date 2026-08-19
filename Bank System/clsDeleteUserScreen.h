#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUsers.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private :
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

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t  Delete User Screen.");

		string UserName = "";
		cout << "\nPlease, Enter Username: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUsers::IsUserExist(UserName))
		{
			cout << "\nUser IS Not Found, Enter Another UserName: ";
			UserName = clsInputValidate::ReadString();
		}

		if (UserName == "Admin")
		{
			cout << "\a";
			cout << "\n\nYou Can't Delete The Admin! " << endl;
			return;
		}

		clsUsers User = clsUsers::Find(UserName);

		_PrintUser(User);

		char Answer = 'n';
		cout << "\nAre you sure you want to delete this user ? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\n\nUser Deleted Successfuly :) ";
				_PrintUser(User);
			}
			else
			{
				cout << "\n\nError User Was not Deleted\n";
			}
		}
	}

};

