#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "AccountService.h"
using namespace std;
string cinbank, cincardtype;

	bool AccountService::cheak_card(CardModel * card, string bankname, string cardtype, string amount)
	{
		map<pair<int, vector<string>>, int>mp2;
		ifstream file;
		if (bankname == "Banquemisr" and cardtype == "visa card") {
			file.open("visaBanquemisr.txt", ios::in);
		}
		else if (bankname == "National Bank of Egypt" and cardtype == "visa card")
		{
			file.open("visaNational Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "The United Bank of Egypt" and cardtype == "visa card")
		{
			file.open("visaThe United Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "Banquemisr" and cardtype == "master card")
		{
			file.open("masterBanquemisr.txt", ios::in);
		}
		else if (bankname == "National Bank of Egypt" and cardtype == "master card")
		{
			file.open("masterNational Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "The United Bank of Egypt" and cardtype == "master card")
		{
			file.open("masterThe United Bank of Egypt.txt", ios::in);
		}
		else
		{
			cout << "bank not found" << endl;
		}
		while (file.is_open()) {
			string line;
			int counter = 0;
			int indx = 0;
			vector<string>cheak;
			while (getline(file, line))
			{
				if (line == "*") {
					counter = 0;
					indx++;
					cheak.clear();
				}
				if (counter >= 1 and counter <= 5)
				{
					cheak.push_back(line);
				}
				if (counter == 6)
				{
					int number1 = stoi(line);
					int number2 = stoi(amount);
					if (number1 >= number2)mp2[{indx, cheak}]++;
				}
				counter++;
			}
			file.close();
		}
		vector<string>cheak2;
		cheak2.push_back(card->CardholderName);
		cheak2.push_back(card->CardNumber);
		cheak2.push_back(card->CVV);
		cheak2.push_back(card->ZipCode);
		cheak2.push_back(card->PhoneNumber);
		for (int i = 1; i <= 8; i++)
		{
			if (mp2[{i, cheak2}])return true;
		}
		return false;
	}
	bool AccountService::cheak_card(CardModel * card, string bankname, string cardtype)
	{
		map<pair<int, vector<string>>, int>mp2;
		ifstream file;
		if (bankname == "Banquemisr" and cardtype == "visa card") {
			file.open("visaBanquemisr.txt", ios::in);
		}
		else if (bankname == "National Bank of Egypt" and cardtype == "visa card")
		{
			file.open("visaNational Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "The United Bank of Egypt" and cardtype == "visa card")
		{
			file.open("visaThe United Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "Banquemisr" and cardtype == "master card")
		{
			file.open("masterBanquemisr.txt", ios::in);
		}
		else if (bankname == "National Bank of Egypt" and cardtype == "master card")
		{
			file.open("masterNational Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "The United Bank of Egypt" and cardtype == "master card")
		{
			file.open("masterThe United Bank of Egypt.txt", ios::in);
		}
		else
		{
			cout << "bank not found" << endl;
		}
		while (file.is_open()) {
			string line;
			int counter = 0;
			int indx = 0;
			vector<string>cheak;
			while (getline(file, line))
			{
				if (line == "*") {
					counter = 0;
					indx++;
					cheak.clear();
				}
				if (counter >= 1 and counter <= 5)
				{
					cheak.push_back(line);
				}
				if (counter == 6)
				{
					mp2[{indx, cheak}]++;
				}
				counter++;
			}
			file.close();
		}
		vector<string>cheak2;
		cheak2.push_back(card->CardholderName);
		cheak2.push_back(card->CardNumber);
		cheak2.push_back(card->CVV);
		cheak2.push_back(card->ZipCode);
		cheak2.push_back(card->PhoneNumber);
		for (int i = 1; i <= 8; i++)
		{
			if (mp2[{i, cheak2}])return true;
		}
		return false;
	}
	void AccountService::add_card(CardModel * card)
	{
		ofstream file;
		file.open("cards.txt", ios::out);
		file << "*" << endl;
		file << card->CardholderName << endl;
		file << card->PhoneNumber << endl;
		file << card->CardNumber << endl;
		file << card->ZipCode << endl;
		file << card->CVV << endl;
		file << card->amountofmoney << endl;
		file.close();
	}
	bool AccountService::cheak_account(AccountModel * accountmodl)
	{
		map<pair<int, vector<string>>, int>mp;
		ifstream account;
		account.open("accounts.txt", ios::in);
		while (account.is_open())
		{
			string line;
			int counter = 0;
			int indx = 0;
			vector<string>cheak;
			while (getline(account, line))
			{
				if (line == "*") {
					counter = 0;
					indx++;
					cheak.clear();
				}
				if (counter >= 1 and counter <= 6)
				{
					cheak.push_back(line);
				}
				if (counter == 7)
				{
					cheak.push_back(line);
					mp[{indx, cheak}]++;
				}
				counter++;
			}
			account.close();
		}
		vector<string>cheak2;
		cheak2.push_back(accountmodl->Name);
		cheak2.push_back(accountmodl->Email);
		cheak2.push_back(accountmodl->City);
		cheak2.push_back(accountmodl->Gender);
		cheak2.push_back(accountmodl->Password);
		cheak2.push_back(accountmodl->BirthdayYear);
		cheak2.push_back(accountmodl->PhoneNumber);
		for (int i = 1; i <= 8; i++)
		{
			if (mp[{i, cheak2}])return false;
		}
		return true;
	}
	void AccountService::save_account(AccountModel * accountmodl)
	{
		fstream account;
		account.open("accounts.txt", ios::app);
		account << "*" << endl;
		account << accountmodl->Name << endl;
		account << accountmodl->Email << endl;
		account << accountmodl->City << endl;
		account << accountmodl->Gender << endl;
		account << accountmodl->Password << endl;
		account << accountmodl->BirthdayYear << endl;
		account << accountmodl->PhoneNumber << endl;
		account.close();
	}
	int AccountService::indx(CardModel * card, string bankname, string cardtype)
	{
		map<pair<int, vector<string>>, int>mp2;
		ifstream file;
		if (bankname == "Banquemisr" and cardtype == "visa card") {
			file.open("visaBanquemisr.txt", ios::in);
		}
		else if (bankname == "National Bank of Egypt" and cardtype == "visa card")
		{
			file.open("visaNational Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "The United Bank of Egypt" and cardtype == "visa card")
		{
			file.open("visaThe United Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "Banquemisr" and cardtype == "master card")
		{
			file.open("masterBanquemisr.txt", ios::in);
		}
		else if (bankname == "National Bank of Egypt" and cardtype == "master card")
		{
			file.open("masterNational Bank of Egypt.txt", ios::in);
		}
		else if (bankname == "The United Bank of Egypt" and cardtype == "master card")
		{
			file.open("masterThe United Bank of Egypt.txt", ios::in);
		}
		else
		{
			cout << "bank not found" << endl;
		}
		while (file.is_open())
		{
			string line;
			int counter = 0;
			int indx = 0;
			vector<string>cheak;
			while (getline(file, line))
			{
				if (line == "*")
				{
					counter = 0;
					indx++;
					cheak.clear();
				}
				if (counter >= 1 and counter <= 5)
				{
					cheak.push_back(line);
				}
				if (counter == 6)
				{
					mp2[{indx, cheak}]++;
				}
				counter++;
			}
			file.close();
		}
		vector<string>cheak2;
		cheak2.push_back(card->CardholderName);
		cheak2.push_back(card->CardNumber);
		cheak2.push_back(card->CVV);
		cheak2.push_back(card->ZipCode);
		cheak2.push_back(card->PhoneNumber);
		for (int i = 1; i <= 8; i++)
		{
			if (mp2[{i, cheak2}])return i;
		}
	}
	void AccountService::updatefile(string save, int place, string amountofmoney, char want) {
		ifstream file2;
		file2.open(save, ios::in);
		vector<string>vb;
		while (file2.is_open())
		{
			string line;
			while (getline(file2, line))
			{
				vb.push_back(line);
			}
			file2.close();
		}
		int cvp = 0;
		int wantplace = 0;
		for (int i = 0; i < vb.size(); i++)
		{
			if (vb[i] == "*")
				cvp++;
			wantplace++;
			if (cvp == place)
			{
				wantplace += 6;
				break;
			}
		}
		wantplace--;
		string haveofmoney = vb[wantplace];
		int number1 = stoi(haveofmoney);
		int number2 = stoi(amountofmoney);
		if (want == '-')
		{
			number1 -= number2;
		}
		else
		{
			number1 += number2;
		}
		string newnumber = to_string(number1);
		vb[wantplace] = newnumber;
		ofstream step;
		step.open(save, ios::trunc);
		for (int i = 0; i < vb.size(); i++)
		{
			step << vb[i] << endl;
		}
		step.close();
	}
