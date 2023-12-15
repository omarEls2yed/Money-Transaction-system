#include "MasterCard.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void MasterCard::void send_money(CardModel* from, string cardnumber, string frombank, string tobank, string tocardtype)
{
	cout << "Enter the amount of money u want to sent" << endl;
	cin >> amountofmoney;
	if (S->cheak_card(from, frombank, cardtype, amountofmoney) and S->cheak_card(cardnumber, tobank, tocardtype))
	{
		fstream file;
		file.open("transaction.txt", ios::app);
		file << from->CardNumber << endl;
		file << cardnumber << endl;
		file << amountofmoney << endl;
		file.close();
		fstream file2;
		file2.open("transaction history.txt", ios::app);
		file2 << from->CardNumber << endl;
		file2 << cardnumber << endl;
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
	else {
	        cout << "you havent this amount of monye" << endl;
	}
}
	void MasterCard::collect_money(CardModel* to, string tobank)
	{
		if (S->cheak_card(to,tobank,cardtype))
		{
			ifstream file1;
			file1.open("transaction.txt", ios::in);
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
			vector<string>money;
			for (int i = 0; i < sv.size(); i++)
			{
				if (sv[i] == to->CardNumber)
				{
					if (sv[i + 1] != "0") {
						money.push_back(sv[i + 1]);
					}
					sv[i+1] = "0";
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
			for (int i = 0; i < money.size(); i++) {
				Service_Account->updatefile(save, place, money[i], '+');
			}
		}
         }
