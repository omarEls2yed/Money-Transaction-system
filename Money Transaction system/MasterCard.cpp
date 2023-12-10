#include "MasterCard.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void MasterCard::send_money(CardModel* from, CardModel* to, string frombank, string tobank, string tocardtype)
{
	cout << "Enter the amount of money u want to sent" << endl;
	cin >> amountofmoney;
	if (S->cheak_card(from, frombank, cardtype, amountofmoney) and S->cheak_card(to, tobank, tocardtype))
	{
		fstream file;
		file.open("transaction.txt", ios::app);
		file << from->CardNumber << endl;
		file << to->CardNumber << endl;
		file << amountofmoney << endl;
		file.close();
		fstream file2;
		file2.open("transaction history.txt", ios::app);
		file2 << from->CardNumber << endl;
		file2 << to->CardNumber << endl;
		file2 << amountofmoney << endl;
		file2.close();
		AccountService* Service_Account = new AccountService;
		int place = Service_Account->indx(from, frombank, cardtype);
		string save;
		if (frombank == "Banquemisr")
		{
			save = "masterBanquemisr.txt";
		}
		else if (frombank == "National Bank of Egypt")
		{
			save = "masterNational Bank of Egypt.txt";
		}
		else if (frombank == "The United Bank of Egypt")
		{
			save = "masterThe United Bank of Egypt.txt";
		}
		Service_Account->updatefile(save, place, amountofmoney, '-');
	}
}
void MasterCard::collect_money(CardModel* to, string tobank)
{
	if (S->cheak_card(to, tobank, cardtype))
	{
		ifstream file1;
		file1.open("transaction.txt", ios::in);
		int idx = 0;
		vector <string>sv;
		while (file1.is_open())
		{
			string line;
			while (getline(file1, line))
			{
				sv.push_back(line);
			}
			file1.close();
		}
		for (int i = 0; i < sv.size(); i++)
		{
			if (sv[i] == to->CardNumber)
			{
				sv[i + 1] = "0";
				idx = i + 2;
				break;
			}
		}
		ofstream file2;
		file2.open("transaction.txt", ios::trunc);
		for (int i = 0; i < sv.size(); i++)
		{
			file2 << sv[i] << endl;
		}
		file2.close();
		AccountService* Service_Account = new AccountService;
		int place = Service_Account->indx(to, tobank, cardtype);
		string save;
		if (tobank == "Banquemisr")
		{
			save = "masterBanquemisr.txt";
		}
		else if (tobank == "National Bank of Egypt")
		{
			save = "masterNational Bank of Egypt.txt";
		}
		else if (tobank == "The United Bank of Egypt")
		{
			save = "masterThe United Bank of Egypt.txt";
		}
		Service_Account->updatefile(save, place, amountofmoney, '+');
	}
}
