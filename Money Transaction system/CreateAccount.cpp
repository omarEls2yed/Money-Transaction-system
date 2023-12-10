#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "AccountModel.h"
#include "CreateAccount.h"
using namespace std;
string cinbank, cincardtype;
CreateAccount::CreateAccount(AccountModel* account2)
{
	account->Name = account2->Name;
	account->City = account2->City;
	account->BirthdayYear = account2->BirthdayYear;
	account->Email = account2->Email;
	account->Gender = account2->Gender;
	account->PhoneNumber = account2->PhoneNumber;
	account->Password = account2->Password;
}
