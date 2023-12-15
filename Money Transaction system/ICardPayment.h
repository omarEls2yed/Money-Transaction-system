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
class ICardPayment
{
public:
	virtual void send_money(CardModel* from, string cardnumber, string frombank, string tobank, string tocardtype) = 0;
	virtual void collect_money(CardModel* to, string tobank) = 0;
};

