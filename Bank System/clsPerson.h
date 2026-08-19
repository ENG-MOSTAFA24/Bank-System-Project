#pragma once

#include <iostream>
#include <string>
#include "InterfaceCommunication.h"
using namespace std;

class clsPerson : public InterfaceCommunication
{
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public :

	// Constructor 
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	// Property Set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	// Property Get
	string GetFirstName()
	{
		return _FirstName;
	}

	// Declare Specification 

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	// Property Get
	string GetLastName()
	{
		return _LastName;
	}

	// Declare Specification 

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;


	void SetEmail(string Email)
	{
		_Email = Email;
	}

	// Property Get
	string GetEmail()
	{
		return _Email;
	}

	// Declare Specification 

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;


	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	// Property Get
	string GetPhone()
	{
		return _Phone;
	}

	// Declare Specification 

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}


	void SendEmail(string Title, string Body)
	{

	}
	void SendFax(string Title, string Body)
	{

	}
	void SendSMS(string Title, string Body)
	{

	}

};

