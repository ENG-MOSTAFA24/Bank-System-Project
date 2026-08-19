#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserScreen()
	{
		string Title = "\t  Find User Screen";

		_DrawScreenHeader(Title);

		string UserName = "";
		cout << "\nPlease Enter UserName : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUsers::IsUserExist(UserName))
		{
			cout << "\nUser IS Not Found, Enter Another UserName: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUsers User = clsUsers::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found :)";
		}
		else
		{
			cout << "\nUser Not Found :(";
		}

		_PrintUser(User);

	}
};

