#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "SOCKET.cpp"

using namespace std;


ofstream fout;
class BOOTS {
	string brandNike = "Nike";
	string brandAdidas = "Adidas";
	string brandPuma = "Puma";
	string brandJoma = "Joma";
	int Nike = 0;
	int Adidas = 0;
	int Puma = 0;
	int Joma = 0;
	int summaryNike = 0;
	int summaryAdidas = 0;
	int summaryPuma = 0;
	int summaryJoma = 0;
	int prevNike = 0;
	int prevAdidas = 0;
	int prevPuma = 0;
	int prevJoma = 0;
	int maxNike = 500;
	int maxAdidas = 400;
	int maxPuma = 250;
	int maxJoma = 120;
public:
	BOOTS() {};
	void pereuchBOOTS() {
		system("cls");
		cout << endl << "Введите количество товара в шутках" << endl;
		cout << "Футбольные бутсы:" << endl;
		cout << brandNike << ": ";
		while (true) {
			try {
				cin >> Nike;
				if (Nike > maxNike || Nike < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Nike, sizeof(Nike), 0);
		cout << brandAdidas << ": ";
		while (true) {
			try {
				cin >> Adidas;
				if (Adidas > maxAdidas || Adidas < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Adidas, sizeof(Adidas), 0);
		cout << brandPuma << ": ";
		while (true) {
			try {
				cin >> Puma;
				if (Puma > maxPuma || Puma < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Puma, sizeof(Puma), 0);
		cout << brandJoma << ": ";
		while (true) {
			try {
				cin >> Joma;
				if (Joma > maxJoma || Joma < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Joma, sizeof(Joma), 0);
	}
	void showBOOTS() {
		cout << endl << "Бутсы (шт):" << endl;
		cout << brandNike << ": " << Nike << endl;
		cout << brandAdidas << ": " << Adidas << endl;
		cout << brandPuma << ": " << Puma << endl;
		cout << brandJoma << ": " << Joma << endl;
	}
	void inputfileBOOTS() {
	}
	void allBOOTS() {
		system("cls");
		cout << endl << "Бутсы" << endl;
		cout << "1 - " << brandNike << endl;
		cout << "2 - " << brandAdidas << endl;
		cout << "3 - " << brandPuma << endl;
		cout << "4 - " << brandJoma << endl;
	}
	void purchaseBOOTS() {
		int choice5;
		int number;
		do {
			system("cls");
			cout << endl << "Бутсы (шт):" << endl;
			cout << "1 - " << brandNike << ": " << Nike << endl;
			cout << "2 - " << brandAdidas << ": " << Adidas << endl;
			cout << "3 - " << brandPuma << ": " << Puma << endl;
			cout << "4 - " << brandJoma << ": " << Joma << endl;
			cout << "5 - утвердить заказ" << endl;
			cin >> choice5;
			while (choice5 < 1 || choice5 > 5)
			{
				cout << "Нет такого варианта!" << endl;
				cin >> choice5;
			}
			send(Connection, (char*)&choice5, sizeof(choice5), 0);
			switch (choice5) {
			case 1:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Nike || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevNike = Nike;
				Nike = Nike - number;
				break;
			case 2:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Adidas || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				break;
			case 3:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Puma || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevPuma = Puma;
				Puma = Puma - number;
				break;
			case 4:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Joma || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevJoma = Joma;
				Joma = Joma - number;
				break;
			case 5:
				break;
			}
		} while (choice5 > 0 && choice5 < 5);
	}
	void summary() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevPuma == 0 && prevJoma == 0) {
			cout << "В данный момент вывести рекомендации по оптимизации закупок бутс невозможно" << endl;
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryPuma = prevPuma - Puma;
			summaryJoma = prevJoma - Joma;
			biggest = summaryNike;
			recv(Connection, (char*)&brand, sizeof(brand), 0);
			if (brand == 1) {
				cout << "Для повышения прибыли магазина необходимо увеличить величину последующей закупки футбольных бутс бренда " << brandNike << endl;
			}
			if (brand == 2) {
				cout << "Для повышения прибыли магазина необходимо увеличить величину последующей закупки футбольных бутс бренда " << brandAdidas << endl;
			}
			if (brand == 3) {
				cout << "Для повышения прибыли магазина необходимо увеличить величину последующей закупки футбольных бутс бренда " << brandPuma << endl;
			}
			if (brand == 4) {
				cout << "Для повышения прибыли магазина необходимо увеличить величину последующей закупки футбольных бутс бренда " << brandJoma << endl;
			}
		}
	}
	~BOOTS() {};
};
