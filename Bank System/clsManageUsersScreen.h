#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;


class clsManageUsersScreen : protected clsScreen
{
private :

    static void _GoBackToManageUsersMenue()
    {
        cout << "\nPress any key to go back to Manage Users Menue.... ";
        system("pause>0");
        system("cls");
        ShowManageUsersMenueScreen();
    }

    enum enManageUsersMenueOprion
    {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static int _ReadManageUsersOption()
    {
        cout << setw(37) << left << "" << "Enter what do you want to do [1 to 6] : ";
        int Number = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter number between 1 to 6 : ");
        return Number;
    }

    static void _ShowListUsersScreen()
    {
        //cout << "\nList Users Screen Will Be Here Soon...";
        clsUsersListScreen::PrintUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "\nAdd New User Screen Will Be Here Soon...";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "\nDelete User Screen Will Be Here Soon...";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will Be Here Soon...";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        //cout << "\nFind User Screen Will Be Here Soon...";
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOprion Option)
    {
        switch (Option)
        {
        case clsManageUsersScreen::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsManageUsersScreen::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsManageUsersScreen::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsManageUsersScreen::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsManageUsersScreen::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsManageUsersScreen::eMainMenue:
            break;
        }
    }

public :

	static void ShowManageUsersMenueScreen()
	{
        if (!CheckAccessRights(clsUsers::enPermissions::pManageUsers))
        {
            return;
        }

		_DrawScreenHeader("\t  Manage Users Screen.");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption(enManageUsersMenueOprion(_ReadManageUsersOption()));
	}
};

