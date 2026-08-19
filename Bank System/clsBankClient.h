#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsPerson.h"
#include "clsDate.h"
#include "Global.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class clsBankClient : public clsPerson
{
private :

	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};
	enMode _Mode;


	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClients;
		vClients = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClients[0], vClients[1], vClients[2], vClients[3], vClients[4], vClients[5], stod(vClients[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber() + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out); // Write Mode

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C._MarkForDelete == false)
				{
					string DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		
		MyFile.open("Clients.txt", ios::in); // Read Mode 

		string DataLine;

		if (MyFile.is_open())
		{
			while (getline(MyFile, DataLine))
			{
				clsBankClient Client = _ConvertLineToClientObject(DataLine);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClients);
	}

	void _AddDataLineToFile(string DataLine )
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app); // Append Mode

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient, string Seperator = "#//#")
	{
		string Record = "";
		Record += clsDate::GetSystemDateTimeString() + Seperator;
		Record += AccountNumber() + Seperator;
		Record += DestinationClient.AccountNumber() + Seperator;
		Record += to_string(Amount) + Seperator;
		Record += to_string(AccountBalance) + Seperator;
		Record += to_string(DestinationClient.AccountBalance) + Seperator;
		Record += CurrentUser.UserName;


		return Record;
	}


public :

	// Constructor 
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	// Check the object [Empty or not]
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	// Only Get Property (I don't want user to edit the account number)
	string AccountNumber()
	{
		return _AccountNumber;
	}

	// Set & Get Pin Code 
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec (property (get = GetPinCode, put = SetPinCode)) string PinCode;

	// Set & Get Account Balance 
	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec (property (get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	// Print Client Data
	//void Print()
	//{
	//	cout << "\n\nClient Card : ";
	//	cout << "\n_______________________________";
	//	cout << "\nFirst Name     : " << FirstName;
	//	cout << "\nLast Name      : " << LastName;
	//	cout << "\nFull Name      : " << FullName();
	//	cout << "\nEmail          : " << Email;
	//	cout << "\nPhone          : " << Phone;
	//	cout << "\nAccount Number : " << _AccountNumber;
	//	cout << "\nPassword       : " << _PinCode;
	//	cout << "\nBalance        : " << _AccountBalance;
	//	cout << "\n_______________________________\n";
	//}

	struct stTransferLog
	{
		string DateTime;
		string SourceAcc;
		string DestinationAcc;
		double Amount;
		double sBalance;
		double dBalance;
		string User;
	};

	// Find the client by the account number
	static clsBankClient Find(string AccountNumber)
	{

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in); // Read Mode 

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}


	// Overloading function to find the client by account number and pin code 
	static clsBankClient Find(string AccountNumber, string PinCode)
	{

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode )
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}


	// Check the client is exist or not by account number 
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return !(Client._Mode == enMode::EmptyMode);
	}


	enum enSaveResults
	{
		svFaildEmptyObject = 0,
		svSucceeded = 1,
		svFaildAccountNumberExists = 2
	};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if(IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else 
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveCleintsDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients;
		vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		if (vClients.size() == 0)
		{
			cout << "\n\t\tNo Clients Available In the System!";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				TotalBalances += Client.AccountBalance;
			}
		}
		return TotalBalances;
	}

	bool Deposit(double Amount)
	{
		_AccountBalance += Amount;

		Save();

		return true;
	}

	bool Withdraw (double Amount)
	{
		if (_AccountBalance < Amount)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;

			Save();

			return true;
		}

	}

	void RegisterTransferLog(double Amount, clsBankClient DestinationClient)
	{
		string DataLine = _PrepareTransferLogRecord(Amount, DestinationClient);

		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
		}

		MyFile.close();

	}

	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		RegisterTransferLog(Amount, DestinationClient);
		return true;
	}

	static stTransferLog ConvertTransferLogToRecord(string DataLine, string Seperator = "#//#")
	{
		vector <string> vTransferLog = clsString::Split(DataLine, "#//#");


		stTransferLog TransferLog;
		TransferLog.DateTime = vTransferLog[0];
		TransferLog.SourceAcc = vTransferLog[1];
		TransferLog.DestinationAcc = vTransferLog[2];
		TransferLog.Amount = stod(vTransferLog[3]);
		TransferLog.sBalance = stod(vTransferLog[4]);
		TransferLog.dBalance = stod(vTransferLog[5]);
		TransferLog.User = vTransferLog[6];

		return TransferLog;

	}

	static vector <stTransferLog> GetTransferLogRegisterList()
	{
		vector <stTransferLog> vTransferLog;
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string DataLine;
			while (getline(MyFile, DataLine))
			{
				stTransferLog TransferLog = ConvertTransferLogToRecord(DataLine);
				vTransferLog.push_back(TransferLog);
			}
			MyFile.close();
		}

		return vTransferLog;
	}
};

