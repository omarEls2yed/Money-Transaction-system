#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h> 
#include "CardModel.h"
#include "AccountModel.h"
using namespace std;
class AccountService {
public:
	bool cheak_card(CardModel* card, string bankname, string cardtype, string amount);
	bool cheak_card(CardModel* card, string bankname, string cardtype);
	bool cheak_card(string cardnumber, string bankname, string cardtype);
	void add_card(CardModel* card);
	bool cheak_account(AccountModel* accountmodl);
	void save_account(AccountModel* accountmodl);
	int indx(CardModel* card, string bankname, string cardtype);
	void updatefile(string save, int place, string amountofmoney, char want);
};
