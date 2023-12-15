#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "CardModel.h"
using namespace std;
string cinbank, cincardtype;
class OperationService
{
public:
	void SentMoney(string type, CardModel* yourcard, string cardnumber, string frombank, string tobank, string tocard);
	void CollectMoney(string type, CardModel* to, string tobank);
	void transaction_history(CardModel* card);
	CardModel* cincard();
};


