#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsUsers.h"

using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:

	static void PrintUserRecordLine(clsUsers User)
	{
		cout << "      | " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(25) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(8) << User.Permissions;
		cout << endl;
	}

public:

	static void PrintUsersList()
	{
		vector <clsUsers> vUsers = clsUsers::GetUsersList();


		clsScreen::_DrawScreenHeader("\tUsers List Screen", "\t(" + to_string(vUsers.size()) + ")  Users.");

		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;


		cout << "      | " << left << setw(15) << "UserName";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(8) << "Permissions";
		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;



		if (vUsers.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Users Available In the System!";
		}
		else
		{
			for (clsUsers User : vUsers)
			{
				PrintUserRecordLine(User);
			}
		}

		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;


	}
};

