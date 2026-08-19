#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUsers : public clsPerson
{
private :

	enum enMode
	{
		eEmptyMode = 1, eUpdateMode = 2, eAddNewMode = 3
	};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkForDelete = false;



	static clsUsers _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUsers = clsString::Split(Line,Seperator);

		return clsUsers(enMode::eUpdateMode, vUsers[0], vUsers[1], vUsers[2], vUsers[3], vUsers[4], clsUtil::DecryptText(vUsers[5],7), stoi(vUsers[6]));
	}

	string _ConvertUserObjectToLine(clsUsers User, string Seperator = "#//#")
	{
		string Line = "";
		Line += User.FirstName + Seperator;
		Line += User.LastName + Seperator;
		Line += User.Email + Seperator;
		Line += User.Phone + Seperator;
		Line += User.UserName + Seperator;
		Line += clsUtil::EncryptText(User.Password,7) + Seperator;
		Line += to_string(User.Permissions);

		return Line;
	}


	static vector <clsUsers> _LoadUsersDataFromFile()
	{
		vector <clsUsers> vUsers;

		fstream MyFile;

		MyFile.open("Users.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string DataLine;

			while (getline(MyFile, DataLine))
			{
				clsUsers User = _ConvertLineToUserObject(DataLine);
				vUsers.push_back(User);
			}

			MyFile.close();
		}

		return vUsers;
	}

	static clsUsers _GetEmptyUserObject()
	{
		return clsUsers(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}


	void _SaveUsersDataToFile(vector <clsUsers> vUsers)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out); // Over Write Mode 

		if (MyFile.is_open())
		{
			string DataLine ;
			for (clsUsers U : vUsers)
			{
				if (U.MarkForDeleted() == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsUsers> vUsers = _LoadUsersDataFromFile();

		for (clsUsers& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app); // Over Write Mode 

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		return _AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string Record = "";
		Record += clsDate::GetSystemDateTimeString() + Seperator;
		Record += UserName + Seperator;
		Record += clsUtil::EncryptText(Password, 7) +Seperator;
		Record += to_string(Permissions);

		return Record;
	}



public :

	enum enPermissions
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8
		, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pShowLoginRegister = 128 ,pCurrencyExchange = 256
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	 stLoginRegisterRecord Login;

	 

	clsUsers(enMode Mode, string FirstName, string LastName, string Email, string Phone,string UserName , string Password,int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	bool MarkForDeleted()
	{
		return _MarkForDelete;
	}

	// User Name Get and Set Property 
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property (get = GetUserName, put = SetUserName)) string UserName;

	// Password Get and Set Property 
	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	// Permissions Get and Set Property 
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	static clsUsers Find(string UserName)
	{
		vector <clsUsers> vUsers = _LoadUsersDataFromFile();

		for (clsUsers& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				return U;
			}
		}

		return _GetEmptyUserObject();
	}

	static clsUsers Find(string UserName, string Password)
	{
		vector <clsUsers> vUsers = _LoadUsersDataFromFile();

		for (clsUsers & U : vUsers)
		{
			if (U.UserName == UserName && U.Password == Password)
			{
				return U;
			}
		}

		return _GetEmptyUserObject();
	}

	enum enSaveResults
	{
		svSuccessed = 1, svFailEmptyObject = 2, svFailUserExists = 3
	};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUsers::eEmptyMode:
		{
			return enSaveResults::svFailEmptyObject;
			break;
		}
		case clsUsers::eUpdateMode:
		{
			_Update();
			return enSaveResults::svSuccessed;
			break;
		}
		case clsUsers::eAddNewMode:
		{
			if (clsUsers::IsUserExist(_UserName))
			{
				return enSaveResults::svFailUserExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::eUpdateMode;
				return enSaveResults::svSuccessed;
			}
			break;
		}
		}
	}

	static bool IsUserExist(string UserName)
	{
		clsUsers User = clsUsers::Find(UserName);
		return (!User.IsEmpty());
	}

	static clsUsers GetAddNewUserObject(string UserName)
	{
		return clsUsers(clsUsers::enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUsers> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool Delete()
	{
		vector <clsUsers> vUsers = GetUsersList();

		for (clsUsers& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	bool CheckAccessPermissions(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((this->Permissions & Permission) == Permission)
			return true;
		else
			return false;
	}



	void RegisterLogin()
	{
		string DataLine = _PrepareLogInRecord();

		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
		}

		MyFile.close();

	}

	static stLoginRegisterRecord _ConvertLoginRegisterToRecord(string Line)
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector <string> vLoginRegisterRecord = clsString::Split(Line, "#//#");

		LoginRegisterRecord.DateTime = vLoginRegisterRecord[0];
		LoginRegisterRecord.UserName = vLoginRegisterRecord[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vLoginRegisterRecord[2], 7);
		LoginRegisterRecord.Permissions = stoi(vLoginRegisterRecord[3]);

		return LoginRegisterRecord;
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::in);  // Read Mode 

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				stLoginRegisterRecord LoginRegisterData = _ConvertLoginRegisterToRecord(Line);

				vLoginRegisterRecord.push_back(LoginRegisterData);
			}

			MyFile.close();

		}

		return vLoginRegisterRecord;
	}

	//void PrintUser()
	//{
	//	cout << "\n\nUser Card : ";
	//	cout << "\n_______________________________\n";
	//	cout << "\nFirst Name    : " << FirstName;
	//	cout << "\nLast Name     : " << LastName;
	//	cout << "\nFull Name     : " << FullName();
	//	cout << "\nEmail         : " << Email;
	//	cout << "\nPhone         : " << Phone;
	//	cout << "\nUser Name     : " << UserName;
	//	cout << "\nPassword      : " << Password;
	//	cout << "\nPermissions   : " << Permissions;
	//	cout << "\n_______________________________\n";
	//}
};

