#include "OperationService.h"
#include"ICardPayment.h"
#include"Visa.h"
#include"MasterCard.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void OperationService::SentMoney(string type, CardModel* yourcard, CardModel* friendcard, string frombank, string tobank, string tocard) {
	ICardPayment* yourcart = NULL;
	if (type == "visa card") yourcart = new Visa;
	else yourcart = new MasterCard;
	yourcart->send_money(yourcard, friendcard, frombank, tobank, tocard);
}
void OperationService::CollectMoney(string type, CardModel* to, string tobank) {
	ICardPayment* yourcart = NULL;
	if (type == "visa card") yourcart = new Visa;
	else yourcart = new MasterCard;
	yourcart->collect_money(to, tobank);
}
void OperationService::transaction_history(CardModel* card)
{
	ifstream file1;
	file1.open("transaction history.txt", ios::in);
	vector<string>v;
	while (file1.is_open())
	{
		string line;
		while (getline(file1, line))
		{
			v.push_back(line);
		}
		file1.close();
	}
	for (int i = 0; i < v.size(); i += 3)
	{
		if (v[i + 1] == card->CardNumber)
		{
			cout << v[i] << " sent to u " << v[i + 2] << endl;
		}
	}
}
CardModel* OperationService::cincard() {
	CardModel* yourcard = new CardModel;
	string yourcardtype;
	int banknumber;
	int cardnumber;
	cout << "choise your card type" << endl;
	cout << "1- visa card" << endl;
	cout << "2- master card" << endl;
	cin >> cardnumber;
	cout << "choise your bank" << endl;
	cout << "1-Banquemisr" << endl;
	cout << "2-National Bank of Egypt" << endl;
	cout << "3-The United Bank of Egypt" << endl;
	cin >> banknumber;
	if (banknumber == 1)
	{
		cinbank = "Banquemisr";
	}
	else if (banknumber == 2)
	{
		cinbank = "National Bank of Egypt";
	}
	else
	{
		cinbank = "The United Bank of Egypt";
	}
	if (cardnumber == 1)
	{
		cincardtype = "visa card";
	}
	else
	{
		cincardtype = "master card";
	}
	string cardholderName;
	string phoneNumber;
	string cardNumber;
	string zipCode;
	string cVV;
	cout << "enter card holder Name : the name appear on the Visa card." << endl;
	cin >> cardholderName;
	cout << "enter card Number : A 16-digit number unique to your card." << endl;
	cin >> cardNumber;
	while (cardNumber.size() != 16)
	{
		cout << "enter valid card Number : A 16-digit number unique to your card." << endl;
		cin >> cardNumber;
	}
	cout << "enter CVV (Card Verification Value) : A three-digit security code on the back of the card" << endl;
	cin >> cVV;
	while (cVV.size() != 3)
	{
		cout << "enter valid CVV (Card Verification Value) : A three-digit security code on the back of the card" << endl;
		cin >> cVV;
	}
	cout << "Zip Code : The postal code of the cardholder's billing address." << endl;
	cin >> zipCode;
	cout << "enter the phone number that you link with your card" << endl;
	cin >> phoneNumber;
	yourcard->CardholderName = cardholderName;
	yourcard->PhoneNumber = phoneNumber;
	yourcard->CardNumber = cardNumber;
	yourcard->ZipCode = zipCode;
	yourcard->CVV = cVV;
	return yourcard;
}
