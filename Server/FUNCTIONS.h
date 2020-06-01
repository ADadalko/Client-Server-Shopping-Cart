#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <locale.h>
#include <iomanip>
#include <memory>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <string.h>
#include <time.h>
#include <locale>
#include <windows.h>
#include <string>
#include <sstream>
#include <iomanip>
#include "ACCESSORIES.h";

using namespace std;

BOOTS a;
BALLS b;
KITS c;
GOALKEEPER d;
PADS e;

int i = 0;
int numberofcurrentuser = 0;
int checks = 1;

string User[50];
string Password[50];
int Usernumber = 0;

void Firstmenu();
void Purchase();

void openfile() {
	const int MAX = 150;
	char buffer[MAX];
	int counter = 0;
	fstream file;
	file.open("FOOTBALL_SHOP.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			file.getline(buffer, MAX);
			string msg1;
			msg1 = buffer;
			int msg_size = msg1.size();
			send(newConnection, (char*)&msg_size, sizeof(int), NULL);
			send(newConnection, msg1.c_str(), msg_size, NULL);
			Sleep(10);
			counter++;
		}
	string msg1 = "End of file";
	int msg_size = msg1.size();
	send(newConnection, (char*)&msg_size, sizeof(int), NULL);
	send(newConnection, msg1.c_str(), msg_size, NULL);
	Sleep(10);
	}
	file.close();
}


void openfile1() {
	const int MAX = 150;
	char buffer[MAX];
	int counter = 0;
	fstream file;
	file.open("CHECKS.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			file.getline(buffer, MAX);
			string msg1;
			msg1 = buffer;
			int msg_size = msg1.size();
			send(newConnection, (char*)&msg_size, sizeof(int), NULL);
			send(newConnection, msg1.c_str(), msg_size, NULL);
			Sleep(10);
			counter++;
		}
		string msg1 = "End of file";
		int msg_size = msg1.size();
		send(newConnection, (char*)&msg_size, sizeof(int), NULL);
		send(newConnection, msg1.c_str(), msg_size, NULL);
		Sleep(10);
	}
	file.close();
}


void Usermenu() {
	int choice;
	ofstream fout;
	ifstream fin;
	fstream file;
	const int MAX = 150;
	char buffer[MAX];
	int sch = 0;
	do {
		recv(newConnection, (char*)&choice, sizeof(choice), 0);
		switch (choice)
		{
		case 1:
			if (i == 0) {
				Sleep(10);
			}
			else {
				a.showBOOTS();
				b.showBALLS();
				c.showKITS();
				d.showGOALKEEPER();
				e.showBAGS();
				e.showSOCKS();
				e.showPADS();
			}
			break;
		case 2:
			int choice1;
			if (i == 0) { }
			else {
				do {
					recv(newConnection, (char*)&choice1, sizeof(choice1), 0);
					switch (choice1)
					{
					case 1:
						a.showBOOTS();
						break;
					case 2:
						b.showBALLS();
						break;
					case 3:
						c.showKITS();
						break;
					case 4:
						d.showGOALKEEPER();
						break;
					case 5:
						e.showBAGS();
						break;
					case 6:
						e.showSOCKS();
						break;
					case 7:
						e.showPADS();
						break;
					case 8:
						break;
					}
				} while (choice1 > 0 && choice1 < 8);
			}
			break;
		case 3:
			openfile();
			break;
		case 4:
			Purchase();
			break;
		case 5:
			Firstmenu();
			break;
		}
	} while (choice > 0 && choice < 5);
}


void Adminmenu() {
	int choice;
	ofstream fout;
	ifstream fin;
	fstream file;
	const int MAX = 150;
	char buffer[MAX];
	int sch = 0;
	do {
		recv(newConnection, (char*)&choice, sizeof(choice), 0);
		switch (choice)
		{
		case 1:
			a.pereuchBOOTS();
			b.pereuchBALLS();
			c.pereuchKITS();
			d.pereuchGOALKEEPER();
			e.pereuchBAGS();
			e.pereuchSOCKS();
			e.pereuchPADS();
			i = 1;
			break;
		case 2:
			if (i == 0) {
			}
			else {
				a.showBOOTS();
				b.showBALLS();
				c.showKITS();
				d.showGOALKEEPER();
				e.showBAGS();
				e.showSOCKS();
				e.showPADS();
			}
			break;
		case 3:
			int choice2;
			if (i == 0) {
			}
			else {
				do {
					recv(newConnection, (char*)&choice2, sizeof(choice2), 0);
					switch (choice2)
					{
					case 1:
						a.pereuchBOOTS();
						break;
					case 2:
						b.pereuchBALLS();
						break;
					case 3:
						c.pereuchKITS();
						break;
					case 4:
						d.pereuchGOALKEEPER();
						break;
					case 5:
						e.pereuchBAGS();
						break;
					case 6:
						e.pereuchSOCKS();
						break;
					case 7:
						e.pereuchPADS();
						break;
					case 8:
						break;
					}
				} while (choice2 > 0 && choice2 < 8);
			}
			break;
		case 4:
			int choice1;
			do {
				recv(newConnection, (char*)&choice1, sizeof(choice1), 0);
				switch (choice1)
				{
				case 1:
					a.showBOOTS();
					break;
				case 2:
					b.showBALLS();
					break;
				case 3:
					c.showKITS();
					break;
				case 4:
					d.showGOALKEEPER();
					break;
				case 5:
					e.showBAGS();
					break;
				case 6:
					e.showSOCKS();
					break;
				case 7:
					e.showPADS();
					break;
				case 8:
					break;
				}
			} while (choice1 > 0 && choice1 < 8);
			break;
		case 5:
			if (i == 0) {
			}
			else {
				a.inputfileBOOTS();
				b.inputfileBALLS();
				c.inputfileKITS();
				d.inputfileGOALKEEPER();
				e.inputfileBAGS();
				e.inputfileSOCKS();
				e.inputfilePADS();
			}
			break;
		case 6:
			fout.open("FOOTBALL_SHOP.txt");
			fout.close();
			break;
		case 7:
			openfile();
			break;
		case 8:
			openfile1();
			break;
		case 9:
			break;
		case 10:
			a.summary();
			b.summary();
			c.summary();
			d.summary();
			e.summaryBAGS();
			e.summarySOCKS();
			e.summaryPADS();
			break;
		case 11:
			Firstmenu();
			break;
		}
	} while (choice > 0 && choice < 11);
}

string stars()
{
	char str[100];
	int k = 0;
	while (1)      //звездочки в консоли, при вводе пароля       
	{
		str[k] = _getch();
		if (str[k] == '\r') break;
		if (str[k] == '\b')
		{
			printf("\b \b");
			k--;
		}
		else
		{
			printf("*");
			k++;
		}
	}
	str[k] = '\0';
	string password = string(str);
	return password;
}

void Registration() {
	fout.open("USERS.txt", ios::out | ios::app);
	int msg_size;
	recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
	char* msg = new char[msg_size + 1];
	msg[msg_size] = '\0';
	recv(newConnection, msg, msg_size, NULL);
	User[Usernumber] = msg;
	fout << User[Usernumber] << "\n";
	recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
	msg[msg_size] = '\0';
	recv(newConnection, msg, msg_size, NULL);
	Password[Usernumber] = msg;
	fout << Password[Usernumber] << "\n\n";
	fout.close();
	Usernumber++;
	Firstmenu();
}


void Firstmenu() {
	int menuchoice;
	string loginadmin = "Admin";
	string passwordadmin = "Admin";
	string password;
	string loginuser;
	int msg_size = 0;
	char* msg = new char[msg_size + 1];
	int decision = 0;
	int decision1 = 0;
	while (1) {
		recv(newConnection, (char*)&menuchoice, sizeof(menuchoice), 0);
		switch (menuchoice)
		{
		case 1:                                      
			recv(newConnection, (char*)&msg_size, sizeof(int), NULL);                  
			msg[msg_size] = '\0';
			recv(newConnection, msg, msg_size, NULL);

			password = msg;
			if (password == passwordadmin)
			{
				Adminmenu();
			}
			break;
		case 2:
			recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
			msg[msg_size] = '\0';
			recv(newConnection, msg, msg_size, NULL);
			loginuser = msg;
			for (int i = 0; i < Usernumber; i++) {
				if (loginuser == User[i])
				{
					decision = 1;
				}
			}
			if (decision == 0) {
				Sleep(10);
			}
			else {
				recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
				msg[msg_size] = '\0';
				recv(newConnection, msg, msg_size, NULL);
				password = msg;
				for (int i = 0; i < Usernumber; i++) {
					if (password == Password[i])
					{
						numberofcurrentuser = i;
						Usermenu();
						decision1 = 1;
					}
				}
				if (decision1 == 0) {
					Sleep(10);
				}
			}
			break;
		case 3:
			Registration();
			break;
		case 4:
			exit(1);
			break;
		}
	}
}

void Purchase() {
	int choice1;
	if (i == 0) {
		Sleep(10);
	}
	else {
		fout.open("CHECKS.txt", ios::out | ios::app);
		fout << "\n---------------Чек номер " << checks << "---------------\n";
		checks++;
		fout.close();
		do {
			recv(newConnection, (char*)&choice1, sizeof(choice1), 0);
			switch (choice1)
			{
			case 1:
				a.purchaseBOOTS();
				break;
			case 2:
				b.purchaseBALLS();
				break;
			case 3:
				c.purchaseKITS();
				break;
			case 4:
				d.purchaseGOALKEEPER();
				break;
			case 5:
				e.purchaseBAGS();
				break;
			case 6:
				e.purchaseSOCKS();
				break;
			case 7:
				e.purchasePADS();
				break;
			case 8:
				break;
			}
		} while (choice1 > 0 && choice1 < 8);
		fout.open("CHECKS.txt", ios::out | ios::app);
		fout << "\n-----------------------------------------\n";
		fout.close();
	}
}
