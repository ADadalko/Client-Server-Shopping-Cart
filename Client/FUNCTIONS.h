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
	string end = "End of file";
	int msg_size = 0;
	char* msg = new char[msg_size + 1];	
	do {
	recv(Connection, (char*)&msg_size, sizeof(int), NULL);
	msg[msg_size] = '\0';
	recv(Connection, msg, msg_size, NULL);
	cout << msg << endl;
	} while (msg != end);
	system("PAUSE");
}


void openfile1() {
	string end = "End of file";
	int msg_size = 0;
	char* msg = new char[msg_size + 1];
	do {
		recv(Connection, (char*)&msg_size, sizeof(int), NULL);
		msg[msg_size] = '\0';
		recv(Connection, msg, msg_size, NULL);
		cout << msg << endl;
	} while (msg != end);
	system("PAUSE");
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
		system("cls");
		cout << endl << "�������:" << endl;
		cout << "1 - ��� ��������� ���������� � ������� ������" << endl;
		cout << "2 - ��� ������ ������������ �������� �� ����������" << endl;
		cout << "3 - ��� ��������� ���������� �� �����" << endl;
		cout << "4 - ��� ���������� ������� � ������ ����" << endl;
		cout << "5 - ��� ������" << endl;
		cin >> choice;
		while (choice < 1 || choice > 5)
		{
			cout << "��� ������ ��������!" << endl;
			cin >> choice;
		}
		send(Connection, (char*)&choice, sizeof(choice), 0);
		switch (choice)
		{
		case 1:
			system("cls");
			if (i == 0) {
				cout << endl << "���������� �� ������ ������ ����������" << endl << endl;
				system("PAUSE");
			}
			else {
				cout << endl << "����������� ��������: " << endl;
				a.showBOOTS();
				b.showBALLS();
				c.showKITS();
				d.showGOALKEEPER();
				e.showBAGS();
				e.showSOCKS();
				e.showPADS();
				cout << endl << endl;
				system("PAUSE");
			}
			break;
		case 2:
			int choice1;
			if (i == 0) {
				cout << endl << "���������� �� ������ ������ ����������" << endl << endl;
				system("PAUSE");
			}
			else {
				do {
					system("cls");
					cout << endl << "�������:" << endl;
					cout << "1 - ��� ������ ���� ��������� ����" << endl;
					cout << "2 - ��� ������ ���� ��������� ���������� �����" << endl;
					cout << "3 - ��� ������ ���� ��������� ���������� �����" << endl;
					cout << "4 - ��� ������ ���� ��������� ���������� ��������" << endl;
					cout << "5 - ��� ������ ���� ��������� �������� � �����" << endl;
					cout << "6 - ��� ������ ���� ��������� ��������� ����" << endl;
					cout << "7 - ��� ������ ���� ��������� ���������� ������" << endl;
					cout << "8 - ��� ������" << endl;
					cin >> choice1;
					while (choice1 < 1 || choice1 > 8)
					{
						cout << "��� ������ ��������!" << endl;
						cin >> choice1;
					}
					send(Connection, (char*)&choice1, sizeof(choice1), 0);
					switch (choice1)
					{
					case 1:
						a.showBOOTS();
						system("PAUSE");
						break;
					case 2:
						b.showBALLS();
						system("PAUSE");
						break;
					case 3:
						c.showKITS();
						system("PAUSE");
						break;
					case 4:
						d.showGOALKEEPER();
						system("PAUSE");
						break;
					case 5:
						e.showBAGS();
						system("PAUSE");
						break;
					case 6:
						e.showSOCKS();
						system("PAUSE");
						break;
					case 7:
						e.showPADS();
						system("PAUSE");
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
			system("cls");
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
		system("cls");
		cout << endl << "�������:" << endl;
		cout << "1 - ��� ���������� ���������" << endl;
		cout << "2 - ��� ��������� ���������� � ������� ������" << endl;
		cout << "3 - ��� �������������� ������� ������ �� ����������" << endl;
		cout << "4 - ��� ������ ������������ �������� �� ����������" << endl;
		cout << "5 - ��� ������ ���������� �� ������������ �������� � ����" << endl;
		cout << "6 - ��� ������� �����" << endl;
		cout << "7 - ��� ��������� ���������� �� �����" << endl;
		cout << "8 - ��� ��������� �����" << endl;
		cout << "9 - ��� ������� ����� � ������" << endl;
		cout << "10 - ��� ������ ������������ �� �����������" << endl;
		cout << "11 - ��� ������" << endl;
		cin >> choice;
		while (choice < 1 || choice > 11)
		{
			cout << "��� ������ ��������!" << endl;
			cin >> choice;
		}
		send(Connection, (char*)&choice, sizeof(choice), 0);
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "�������� �������" << endl;
			Sleep(1700);
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
			system("cls");
			if (i == 0) {
				cout << endl << "��� ������ ��������� �������� ������� ��������" << endl << endl;
				system("PAUSE");
			}
			else {
				cout << endl << "����������� ��������: " << endl;
				a.showBOOTS();
				b.showBALLS();
				c.showKITS();
				d.showGOALKEEPER();
				e.showBAGS();
				e.showSOCKS();
				e.showPADS();
				cout << endl << endl;
				system("PAUSE");
			}
			break;
		case 3:
			system("cls");
			int choice2;
			if (i == 0) {
				cout << endl << "��� ������ ��������� �������� ������� ��������" << endl << endl;
				system("PAUSE");
			}
			else {
				do {
					system("cls");
					cout << endl << "�������:" << endl;
					cout << "1 - ��� �������������� ���������� ����" << endl;
					cout << "2 - ��� �������������� ���������� ���������� �����" << endl;
					cout << "3 - ��� �������������� ���������� ���������� �����" << endl;
					cout << "4 - ��� �������������� ���������� ���������� ��������" << endl;
					cout << "5 - ��� �������������� ���������� �������� � �����" << endl;
					cout << "6 - ��� �������������� ���������� ���������� ����" << endl;
					cout << "7 - ��� �������������� ���������� ���������� ������" << endl;
					cout << "8 - ��� ������" << endl;
					cin >> choice2;
					while (choice2 < 1 || choice2 > 8)
					{
						cout << "��� ������ ��������!" << endl;
						cin >> choice2;
					}
					send(Connection, (char*)&choice2, sizeof(choice2), 0);
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
				system("cls");
				cout << endl << "�������:" << endl;
				cout << "1 - ��� ������ ���� ��������� ����" << endl;
				cout << "2 - ��� ������ ���� ��������� ���������� �����" << endl;
				cout << "3 - ��� ������ ���� ��������� ���������� �����" << endl;
				cout << "4 - ��� ������ ���� ��������� ���������� ��������" << endl;
				cout << "5 - ��� ������ ���� ��������� �������� � �����" << endl;
				cout << "6 - ��� ������ ���� ��������� ��������� ����" << endl;
				cout << "7 - ��� ������ ���� ��������� ���������� ������" << endl;
				cout << "8 - ��� ������" << endl;
				cin >> choice1;
				while (choice1 < 1 || choice1 > 8)
				{
					cout << "��� ������ ��������!" << endl;
					cin >> choice1;
				}	
				send(Connection, (char*)&choice1, sizeof(choice1), 0);
				switch (choice1)
				{
				case 1:
					a.showBOOTS();
					system("PAUSE");
					break;
				case 2:
					b.showBALLS();
					system("PAUSE");
					break;
				case 3:
					c.showKITS();
					system("PAUSE");
					break;
				case 4:
					d.showGOALKEEPER();
					system("PAUSE");
					break;
				case 5:
					e.showBAGS();
					system("PAUSE");
					break;
				case 6:
					e.showSOCKS();
					system("PAUSE");
					break;
				case 7:
					e.showPADS();
					system("PAUSE");
					break;
				case 8:
					break;
				}
			} while (choice1 > 0 && choice1 < 8);
			break;
		case 5:
			if (i == 0) {
				cout << endl << "��� ������ ��������� �������� ������� ��������" << endl << endl;
				system("PAUSE");
			}
			else {
				system("cls");
				a.inputfileBOOTS();
				b.inputfileBALLS();
				c.inputfileKITS();
				d.inputfileGOALKEEPER();
				e.inputfileBAGS();
				e.inputfileSOCKS();
				e.inputfilePADS();
				system("PAUSE");
			}
			break;
		case 6:
			system("cls");
			cout << endl << "���� ������" << endl << endl;
			system("PAUSE");
			system("cls");
			break;
		case 7:
			system("cls");
			openfile();
			break;
		case 8:
			system("cls");
			openfile1();
			break;
		case 9:
			system("cls");
			fout.open("C:\\Users\\mp167\\source\\repos\\SERVER_K\\SERVER_K\\CHECKS.txt");
			fout.close();
			cout << endl << "���� ������" << endl << endl;
			system("PAUSE");
			system("cls");
			break;
		case 10:
			system("cls");
			cout << endl << "------------------------------------------������������------------------------------------------" << endl;
			a.summary();
			b.summary();
			c.summary();
			d.summary();
			e.summaryBAGS();
			e.summarySOCKS();
			e.summaryPADS();
			system("PAUSE");
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
	while (1)      //��������� � �������, ��� ����� ������       
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
	system("cls");
	cout << endl << "������� ����� ������ ����������:" << endl;
	cin >> User[Usernumber];
	int msg_size = User[Usernumber].size();
	send(Connection, (char*)&msg_size, sizeof(int), NULL);
	send(Connection, User[Usernumber].c_str(), msg_size, NULL);
	Sleep(10);
	fout << User[Usernumber] << "\n";
	cout << endl << "������� ������ ������ ������������:" << endl;
	cin >> Password[Usernumber];
	msg_size = Password[Usernumber].size();
	send(Connection, (char*)&msg_size, sizeof(int), NULL);
	send(Connection, Password[Usernumber].c_str(), msg_size, NULL);
	Sleep(10);
	fout << Password[Usernumber] << "\n\n";
	Usernumber++;
	cout << endl << "����� ������������ ������" << endl;
	Sleep(1700);
	Firstmenu();
}


void Firstmenu() {
	int menuchoice;
	string loginadmin = "Admin";
	string passwordadmin = "Admin";
	string password;
	string loginuser;
	int decision = 0;
	int decision1 = 0;
	int msg_size = 0;
	while (1) {
		system("cls");
		cout << " ________________________________________" << endl;
		cout << "|           ����� ����������             |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|1 - ���� ��� ���������������            |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|2 - ���� ��� �������������              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|3 - �����������                         |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|4 - �����                               |" << endl;
		cout << "|________________________________________|" << endl;
		int menuchoice;
		cin >> menuchoice;
		if (menuchoice < 1 || menuchoice > 4) {
			cout << endl << "������ �����" << endl;
			cin >> menuchoice;
		}
		send(Connection, (char*)&menuchoice, sizeof(menuchoice), 0);
		switch (menuchoice)
		{
		case 1:
			system("cls");
			cout << endl << "������� ������:" << endl;
			password = stars();                                     
			msg_size = password.size();                            
			send(Connection, (char*)&msg_size, sizeof(int), NULL); 
			send(Connection, password.c_str(), msg_size, NULL);         
			Sleep(10);
			if (password == passwordadmin)
			{
				Adminmenu();
			}
			else {
				cout << endl << "�������� ������!" << endl;
				Sleep(1700);
			}
			break;
		case 2:
			system("cls");
			cout << endl << "�����:" << endl;
			cin >> loginuser;
			msg_size = loginuser.size();
			send(Connection, (char*)&msg_size, sizeof(int), NULL);
			send(Connection, loginuser.c_str(), msg_size, NULL);
			Sleep(10);

			for (int i = 0; i < Usernumber; i++) {
				if (loginuser == User[i])
				{
					decision = 1;
				}
			}
			if (decision == 0) {
				cout << endl << "������������ � ����� ������� ����������" << endl;
				Sleep(1700);
			}
			else {
				cout << endl << "������� ������:" << endl;
				password = stars();
				msg_size = password.size();
				send(Connection, (char*)&msg_size, sizeof(int), NULL);
				send(Connection, password.c_str(), msg_size, NULL);
				Sleep(10);
				for (int i = 0; i < Usernumber; i++) {
					if (password == Password[i])
					{
						numberofcurrentuser = i;
						Usermenu();
						decision1 = 1;
					}
				}
				if (decision1 == 0) {
					cout << endl << "�������� ������!" << endl;
					Sleep(1700);
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
	system("cls");
	if (i == 0) {
		cout << endl << "������� ���� ����������, ���������� �����" << endl << endl;
		system("PAUSE");
	}
	else {
		checks++;
		do {
			system("cls");
			cout << endl << "�������:" << endl;
			cout << "1 - ��� ������������ ����" << endl;
			cout << "2 - ��� ������������ �����" << endl;
			cout << "3 - ��� ������������ ���������� �����" << endl;
			cout << "4 - ��� ������������ ���������� ��������" << endl;
			cout << "5 - ��� ������������ �������� � �����" << endl;
			cout << "6 - ��� ������������ ���������� ����" << endl;
			cout << "7 - ��� ������������ ���������� ������" << endl;
			cout << "8 - ��� ������" << endl;
			cin >> choice1;
			while (choice1 < 1 || choice1 > 8)
			{
				cout << "��� ������ ��������!" << endl;
				cin >> choice1;
			}
			send(Connection, (char*)&choice1, sizeof(choice1), 0);
			switch (choice1)
			{
			case 1:
				a.purchaseBOOTS();
				system("PAUSE");
				break;
			case 2:
				b.purchaseBALLS();
				system("PAUSE");
				break;
			case 3:
				c.purchaseKITS();
				system("PAUSE");
				break;
			case 4:
				d.purchaseGOALKEEPER();
				system("PAUSE");
				break;
			case 5:
				e.purchaseBAGS();
				system("PAUSE");
				break;
			case 6:
				e.purchaseSOCKS();
				system("PAUSE");
				break;
			case 7:
				e.purchasePADS();
				system("PAUSE");
				break;
			case 8:
				break;
			}
		} while (choice1 > 0 && choice1 < 8);
	}
}