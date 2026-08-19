#include <iostream>
#include "clsLoginScreen.h"

using namespace std;

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			system("color 4F");
			break;
		}
	}

	system("pause>0");

	return 0;

}
