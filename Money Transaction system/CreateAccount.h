#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "AccountModel.h"
using namespace std;
string cinbank, cincardtype;
class CreateAccount
{
public:
	AccountModel* account = new AccountModel;
	CreateAccount(AccountModel* account2);
};

