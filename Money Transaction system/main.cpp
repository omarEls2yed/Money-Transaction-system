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
#include "AccountModel.h"
using namespace std;
string cinbank, cincardtype;
signed main()
{
	string name;
	string email;
	string city;
	string gender;
	string password;
	string birthdayyear;
	string phonenumber;
	AccountService service;
	bool cheakaccountt = 0;
	while (1) {
		cout << "choise one operation" << endl;
		int numofoperation;
		if (cheakaccountt == 0) {
			cout << "1 - log in " << endl;
		}
		cout << "2 - Send Money" << endl;
		cout << "3 - Collect Money" << endl;
		cout << "4 - Transaction History" << endl;
		cout << "5 - cheak you card" << endl;
		cout << "6 - log out " << endl;
		cout << "7 - end progam " << endl;
		cin >> numofoperation;
		while (numofoperation > 7 or numofoperation < 1) {
			cout << "Please Enter Valid Operation " << endl;
		}
		while (numofoperation > 1 and numofoperation <= 5 and cheakaccountt == 0) {
			cout << "you have to log in at first " << endl;
			cout << "choise operation again" << endl;
			cout << "1 - log in " << endl;
			cout << "2 - Send Money" << endl;
			cout << "3 - Collect Money" << endl;
			cout << "4 - Transaction History" << endl;
			cout << "5 - cheak you card" << endl;
			cout << "6 - log out " << endl;
			cin >> numofoperation;
		}
		if (numofoperation == 1) {
			AccountModel* new_account = new AccountModel;
			cout << "enter your name" << endl;
			cin >> name;
			new_account->Name = name;
			cout << "enter your email" << endl;
			cin >> email;
			new_account->Email = email;
			cout << "enter your city" << endl;
			cin >> city;
			new_account->City = city;
			cout << "enter your gender" << endl;
			cin >> gender;
			new_account->Gender = gender;
			while (gender != "male" and gender != "female")
			{
				cout << "please enter correct gender male or female" << endl;
				cin >> gender;
				new_account->Gender = gender;
			}
			cout << "enter your password" << endl;
			cin >> password;
			new_account->Password = password;
			cout << "enter your birthday year" << endl;
			cin >> birthdayyear;
			new_account->BirthdayYear = birthdayyear;
			cout << "enter your phone number" << endl;
			cin >> phonenumber;
			new_account->PhoneNumber = phonenumber;
			CreateAccount newaccount(new_account);
			if (service.cheak_account(new_account))
			{
				service.save_account(new_account);
			}
			else
			{
				cout << "welcome back " << " " << name << endl;
			}
			cheakaccountt = 1;
		}
		if (numofoperation == 2)
		{
			CardModel* friendcard = new CardModel;
			CardModel* yourcard = new CardModel;
			bool one = 0;
			bool two = 0;
			string tobank;
			string frombank;
			string tocard;
			string fromcard;
			cout << "to sent money you have to add your visa and visa you want to sent " << endl;
			while (true) {
				int banknumber;
				string bank;
				string cardtype;
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
					bank = "Banquemisr";
					frombank = "Banquemisr";
				}
				else if (banknumber == 2)
				{
					bank = "National Bank of Egypt";
					frombank = "National Bank of Egypt";
				}
				else
				{
					bank = "The United Bank of Egypt";
					frombank = "The United Bank of Egypt";
				}
				if (cardnumber == 1)
				{
					cardtype = "visa card";
					fromcard = "visa card";
				}
				else
				{
					cardtype = "master card";
					fromcard = "master card";
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
				if (service.cheak_card(yourcard, bank, cardtype))
				{
					cout << "Your card is valid" << endl;
					service.add_card(yourcard);
					one = 1;
					break;
				}
				else
				{
					cout << "Your card is not valid" << endl;
					cout << "if you want to try again enter (1)" << endl;
					int opo; cin >> opo;
					if (opo != 1)break;
				}
			}
			while (true) {
				int banknumber;
				string bank;
				string cardtype;
				int cardnumber;
				cout << "choise the type of the card that you want to sent money" << endl;
				cout << "1- visa card" << endl;
				cout << "1- master card" << endl;
				cin >> cardnumber;
				cout << "choise the bank of the card that you want to sent money" << endl;
				cout << "1-Banquemisr" << endl;
				cout << "2-National Bank of Egypt" << endl;
				cout << "3-The United Bank of Egypt" << endl;
				cin >> banknumber;
				if (banknumber == 1)
				{
					bank = "Banquemisr";
					tobank = "Banquemisr";
				}
				else if (banknumber == 2)
				{
					bank = "National Bank of Egypt";
					tobank = "National Bank of Egypt";
				}
				else
				{
					bank = "The United Bank of Egypt";
					tobank = "The United Bank of Egypt";
				}
				if (cardnumber == 1)
				{
					cardtype = "visa card";
					tocard = "visa card";
				}
				else
				{
					cardtype = "master card";
					tocard = "master card";
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
				cout << "enter the phone number that link with the card" << endl;
				cin >> phoneNumber;
				friendcard->CardholderName = cardholderName;
				friendcard->PhoneNumber = phoneNumber;
				friendcard->CardNumber = cardNumber;
				friendcard->ZipCode = zipCode;
				friendcard->CVV = cVV;
				if (service.cheak_card(friendcard, bank, cardtype))
				{
					cout << "card you want to sent money to it is valid" << endl;
					service.add_card(friendcard);
					two = 1;
					break;
				}
				else
				{
					cout << "card you want to sent money to it is not valid" << endl;
					cout << "if you want to try again enter (1)" << endl;
					int opo; cin >> opo;
					if (opo != 1)break;
				}
			}
			if (one == 1 and two == 1)
			{
				OperationService* Operation_Service = new OperationService;
				Operation_Service->SentMoney(fromcard, yourcard, friendcard, frombank, tobank, tocard);
				cout << "Money has sent succisfully" << endl;
			}
			else {
				cout << "Sorry money has't sent" << endl;
			}
		}
		if (numofoperation == 3) {
			cout << "to collect money you have to verifay your card " << endl;
			while (true) {
				OperationService* Operation_Service = new OperationService;
				CardModel* Card_model = new CardModel;
				Card_model = Operation_Service->cincard();
				if (service.cheak_card(Card_model, cinbank, cincardtype))
				{
					cout << "Your card is valid" << endl;
					Operation_Service->CollectMoney(cincardtype, Card_model, cinbank);
					cout << "Money has collect succisfully" << endl;
					break;
				}
				else
				{
					cout << "Your card is not valid" << endl;
				}
				cout << "if you want to use this future again enter (1)" << endl;
				int one_zero; cin >> one_zero;
				if (one_zero != 1)break;
			}
		}
		if (numofoperation == 4) {

			cout << "to see your transaction " << endl;
			while (true) {
				OperationService* Operation_Service = new OperationService;
				CardModel* Card_model = new CardModel;
				Card_model = Operation_Service->cincard();
				if (service.cheak_card(Card_model, cinbank, cincardtype))
				{
					cout << "this is you transaction " << endl;
					Operation_Service->transaction_history(Card_model);
				}
				else
				{
					cout << "Your card is not valid" << endl;
				}
				cout << "if you want to use this future again enter (1)" << endl;
				int one_zero; cin >> one_zero;
				if (one_zero != 1)break;
			}
		}
		if (numofoperation == 5) {
			cout << "cin your card to cheak it" << endl;
			while (true) {
				OperationService* Operation_Service = new OperationService;
				CardModel* Card_model = new CardModel;
				Card_model = Operation_Service->cincard();
				if (service.cheak_card(Card_model, cinbank, cincardtype))
				{
					cout << "you card is valid " << endl;
				}
				else
				{
					cout << "Your card is not valid" << endl;
				}
				cout << "if you want to use this future again enter (1)" << endl;
				int one_zero; cin >> one_zero;
				if (one_zero != 1)break;
			}
		}
		if (numofoperation == 6) {
			cheakaccountt = 0;
		}
		if (numofoperation == 7) {
			cout << "program end" << endl;
			break;
		}
	}
}
