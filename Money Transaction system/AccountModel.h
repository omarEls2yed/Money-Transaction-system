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
#include "AccountService.h"
#include "CardModel.h"
#include "CreateAccount.h"
#include "ICardPayment.h"
#include "MasterCard.h"
#include "OperationService.h"
#include "Visa.h"
using namespace std;
class AccountModel
{
public:
	string Name;
	string Email;
	string City;
	string Gender;
	string Password;
	string BirthdayYear;
	string PhoneNumber;
};
