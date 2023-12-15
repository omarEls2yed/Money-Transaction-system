#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include"ICardPayment.h"
#include"AccountService.h"
using namespace std;
string cinbank, cincardtype;
class Visa : public ICardPayment
{
public:
	AccountService* S = new AccountService;
	string cardtype = "visa card";
	string amountofmoney;
	void send_money(CardModel* from, string cardnumber , string frombank, string tobank, string tocardtype);
	void collect_money(CardModel* to, string tobank);
};

