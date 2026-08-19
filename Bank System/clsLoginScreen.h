#pragma once
#include <iostream>
#include <cstdlib>
#include "clsScreen.h"
#include "Global.h"
#include "clsUsers.h"
#include "clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private :

	static bool _Login()
	{
		string UserName, Password;

		bool FailLogin = false;
		short FaildLoginCount = 3;

		do
		{
			if (FailLogin)
			{
				cout << "\n\nInvalid UserName/Password. Please Try Again";
				FaildLoginCount--;
				cout << "\nYou have " << FaildLoginCount << " Trials to login.";
				cout << "\a";

				if (FaildLoginCount == 0)
				{
					cout << "\n\nYou Are Locked After 3 Faild Trials :(\n\n";
					return false;
				}

			}

			cout << "\n\nEnter Username : ";
			cin >> UserName;
			cout << "Enter Password : ";
			cin >> Password;

			CurrentUser = clsUsers::Find(UserName, Password);

			FailLogin = CurrentUser.IsEmpty();


		} while (FailLogin);



		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();
		return true;
	}

public :

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t      Login Screen.");
		return _Login();
	}
};