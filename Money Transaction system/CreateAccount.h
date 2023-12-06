#define _pragma
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <bitset>
#include "ICardPayment.h"
#include "MasterCard.h"
#include "OperationService.h"
#include "Visa.h"
using namespace std;
string cinbank, cincardtype;
class CreateAccount
{
public:
	AccountModel* account = new AccountModel;
	CreateAccount(AccountModel* account2)
	{
		account->Name = account2->Name;
		account->City = account2->City;
		account->BirthdayYear = account2->BirthdayYear;
		account->Email = account2->Email;
		account->Gender = account2->Gender;
		account->PhoneNumber = account2->PhoneNumber;
		account->Password = account2->Password;
	}
};

