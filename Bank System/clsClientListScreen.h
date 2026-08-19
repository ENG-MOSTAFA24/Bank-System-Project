#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsBankClient.h"
using namespace std;

class clsClientListScreen : protected clsScreen
{
private :

	static void PrintClientRecordLine(clsBankClient Client)
	{
		cout << "      | " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(25) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(25) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
		cout << endl;
	}

public:

	static void PrintClientsList()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pListClients))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();


		clsScreen::_DrawScreenHeader("\tClient List Screen", "\t("+ to_string(vClients.size()) + ")  Clients." );

		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;


		cout << "      | " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(25) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;



		if (vClients.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Clients Available In the System!";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				PrintClientRecordLine(Client);
			}
		}

		cout << "\n      ________________________________________________________";
		cout << "___________________________________________________\n" << endl;


	}

};

