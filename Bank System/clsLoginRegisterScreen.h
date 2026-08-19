#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsScreen.h"
#include "clsUsers.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

private :

	static void _PrintLoginRegisterRecordLine(clsUsers::stLoginRegisterRecord Register)
	{
		cout << "\t\t      | " << left << setw(25) << Register.DateTime;
		cout << "| " << left << setw(15) << Register.UserName;
		cout << "| " << left << setw(12) << Register.Password;
		cout << "| " << left << setw(25) << Register.Permissions;

		cout << endl;
	}

public :

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pShowLoginRegister))
		{
			return;  // this will exit the function 
		}

		vector <clsUsers::stLoginRegisterRecord> vRegisterRecords = clsUsers::GetLoginRegisterList();

		_DrawScreenHeader("\tLogin Register List Screen", "\t\t(" + to_string(vRegisterRecords.size()) + ") Records.");

		cout << "\n\t\t      ________________________________________________________";
		cout << "__________________\n" << endl;



		cout << "\t\t      | " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(25) << "Permissions";
		cout << "\n\t\t      ________________________________________________________";
		cout << "__________________\n" << endl;



		if (vRegisterRecords.size() == 0)
		{
			cout << "\n\t\t\t\t\t   No Register Records In the System!";
		}
		else
		{
			for (clsUsers::stLoginRegisterRecord Register : vRegisterRecords)
			{
				_PrintLoginRegisterRecordLine(Register);
			}
		}

		cout << "\n\t\t      ________________________________________________________";
		cout << "__________________\n" << endl;
	}


};

