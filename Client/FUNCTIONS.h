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
		cout << endl << "Введите:" << endl;
		cout << "1 - для просмотра информации о наличии товара" << endl;
		cout << "2 - для вывода ассортимента магазина по категориям" << endl;
		cout << "3 - для просмотра информации из файла" << endl;
		cout << "4 - для оформления покупки и записи чека" << endl;
		cout << "5 - для выхода" << endl;
		cin >> choice;
		while (choice < 1 || choice > 5)
		{
			cout << "Нет такого варианта!" << endl;
			cin >> choice;
		}
		send(Connection, (char*)&choice, sizeof(choice), 0);
		switch (choice)
		{
		case 1:
			system("cls");
			if (i == 0) {
				cout << endl << "Информация на данный момент недоступна" << endl << endl;
				system("PAUSE");
			}
			else {
				cout << endl << "Ассортимент магазина: " << endl;
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
				cout << endl << "Информация на данный момент недоступна" << endl << endl;
				system("PAUSE");
			}
			else {
				do {
					system("cls");
					cout << endl << "Введите:" << endl;
					cout << "1 - для вывода всех доступных бутс" << endl;
					cout << "2 - для вывода всех доступных футбольных мячей" << endl;
					cout << "3 - для вывода всей доступной футбольной формы" << endl;
					cout << "4 - для вывода всех доступных вратарских перчаток" << endl;
					cout << "5 - для вывода всех доступных рюкзаков и сумок" << endl;
					cout << "6 - для вывода всех доступных футбольнх гетр" << endl;
					cout << "7 - для вывода всех доступных футбольных щитков" << endl;
					cout << "8 - для выхода" << endl;
					cin >> choice1;
					while (choice1 < 1 || choice1 > 8)
					{
						cout << "Нет такого варианта!" << endl;
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
		cout << endl << "Введите:" << endl;
		cout << "1 - для проведения переучета" << endl;
		cout << "2 - для просмотра информации о наличии товара" << endl;
		cout << "3 - для редактирования наличия товара по категориям" << endl;
		cout << "4 - для вывода ассортимента магазина по категориям" << endl;
		cout << "5 - для записи информации об ассортименте магазина в файл" << endl;
		cout << "6 - для очистки файла" << endl;
		cout << "7 - для просмотра информации из файла" << endl;
		cout << "8 - для просмотра чеков" << endl;
		cout << "9 - для очистки файла с чеками" << endl;
		cout << "10 - для вывода рекомендаций по оптимизации" << endl;
		cout << "11 - для выхода" << endl;
		cin >> choice;
		while (choice < 1 || choice > 11)
		{
			cout << "Нет такого варианта!" << endl;
			cin >> choice;
		}
		send(Connection, (char*)&choice, sizeof(choice), 0);
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Переучет товаров" << endl;
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
				cout << endl << "Для начала проведите переучет товаров магазина" << endl << endl;
				system("PAUSE");
			}
			else {
				cout << endl << "Ассортимент магазина: " << endl;
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
				cout << endl << "Для начала проведите переучет товаров магазина" << endl << endl;
				system("PAUSE");
			}
			else {
				do {
					system("cls");
					cout << endl << "Введите:" << endl;
					cout << "1 - для редактирования количества бутс" << endl;
					cout << "2 - для редактирования количества футбольных мячей" << endl;
					cout << "3 - для редактирования количества футбольной формы" << endl;
					cout << "4 - для редактирования количества вратарских перчаток" << endl;
					cout << "5 - для редактирования количества рюкзаков и сумок" << endl;
					cout << "6 - для редактирования количества футбольных гетр" << endl;
					cout << "7 - для редактирования количества футбольных щитков" << endl;
					cout << "8 - для выхода" << endl;
					cin >> choice2;
					while (choice2 < 1 || choice2 > 8)
					{
						cout << "Нет такого варианта!" << endl;
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
				cout << endl << "Введите:" << endl;
				cout << "1 - для вывода всех доступных бутс" << endl;
				cout << "2 - для вывода всех доступных футбольных мячей" << endl;
				cout << "3 - для вывода всей доступной футбольной формы" << endl;
				cout << "4 - для вывода всех доступных вратарских перчаток" << endl;
				cout << "5 - для вывода всех доступных рюкзаков и сумок" << endl;
				cout << "6 - для вывода всех доступных футбольнх гетр" << endl;
				cout << "7 - для вывода всех доступных футбольных щитков" << endl;
				cout << "8 - для выхода" << endl;
				cin >> choice1;
				while (choice1 < 1 || choice1 > 8)
				{
					cout << "Нет такого варианта!" << endl;
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
				cout << endl << "Для начала проведите переучет товаров магазина" << endl << endl;
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
			cout << endl << "Файл очищен" << endl << endl;
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
			cout << endl << "Файл очищен" << endl << endl;
			system("PAUSE");
			system("cls");
			break;
		case 10:
			system("cls");
			cout << endl << "------------------------------------------Рекомендации------------------------------------------" << endl;
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
	system("cls");
	cout << endl << "Введите логин нового пользателя:" << endl;
	cin >> User[Usernumber];
	int msg_size = User[Usernumber].size();
	send(Connection, (char*)&msg_size, sizeof(int), NULL);
	send(Connection, User[Usernumber].c_str(), msg_size, NULL);
	Sleep(10);
	fout << User[Usernumber] << "\n";
	cout << endl << "Введите пароль нового пользователя:" << endl;
	cin >> Password[Usernumber];
	msg_size = Password[Usernumber].size();
	send(Connection, (char*)&msg_size, sizeof(int), NULL);
	send(Connection, Password[Usernumber].c_str(), msg_size, NULL);
	Sleep(10);
	fout << Password[Usernumber] << "\n\n";
	Usernumber++;
	cout << endl << "Новый пользователь введен" << endl;
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
		cout << "|           ДОБРО ПОЖАЛОВАТЬ             |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|1 - Вход под администратором            |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|2 - Вход под пользователем              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|3 - Регистрация                         |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|4 - Выход                               |" << endl;
		cout << "|________________________________________|" << endl;
		int menuchoice;
		cin >> menuchoice;
		if (menuchoice < 1 || menuchoice > 4) {
			cout << endl << "Ошибка ввода" << endl;
			cin >> menuchoice;
		}
		send(Connection, (char*)&menuchoice, sizeof(menuchoice), 0);
		switch (menuchoice)
		{
		case 1:
			system("cls");
			cout << endl << "Введите пароль:" << endl;
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
				cout << endl << "Неверный пароль!" << endl;
				Sleep(1700);
			}
			break;
		case 2:
			system("cls");
			cout << endl << "Логин:" << endl;
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
				cout << endl << "Пользователь с таким логином отсутсвует" << endl;
				Sleep(1700);
			}
			else {
				cout << endl << "Введите пароль:" << endl;
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
					cout << endl << "Неверный пароль!" << endl;
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
		cout << endl << "Покупка пока недоступна, попробуйте позже" << endl << endl;
		system("PAUSE");
	}
	else {
		checks++;
		do {
			system("cls");
			cout << endl << "Введите:" << endl;
			cout << "1 - для приобретения бутс" << endl;
			cout << "2 - для приобретения мячей" << endl;
			cout << "3 - для приобретения футбольной формы" << endl;
			cout << "4 - для приобретения вратарских перчаток" << endl;
			cout << "5 - для приобретения рюкзаков и сумок" << endl;
			cout << "6 - для приобретения футбольных гетр" << endl;
			cout << "7 - для приобретения футбольных щитков" << endl;
			cout << "8 - для выхода" << endl;
			cin >> choice1;
			while (choice1 < 1 || choice1 > 8)
			{
				cout << "Нет такого варианта!" << endl;
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
