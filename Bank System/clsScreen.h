#pragma once
#include <iostream>
#include "clsUsers.h"
#include "Global.h"
#include "clsDate.h"
#include <iomanip>
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t_______________________________________";
        cout << "\n\n\t\t\t\t\t     " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t_______________________________________\n\n";


        cout << "\t\t\t\t\tUser : " << setw(6) << CurrentUser.UserName << "\t\tDate : " << clsDate::DateToString(clsDate()) << "\n\n"; 
        
    }

    static bool CheckAccessRights(clsUsers::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermissions(Permission))
        {
            cout << "\t\t\t\t\t___________________________________________";
            cout << "\n\n\t\t\t\t\t    Access Denied! Contact Your Admin.\n";
            cout << "\t\t\t\t\t___________________________________________";
            return false;
        }
        else
            return true;
    }

};

