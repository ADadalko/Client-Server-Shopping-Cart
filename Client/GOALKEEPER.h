#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "KITS.h"

using namespace std;

class GOALKEEPER {
	string brandNike = "Nike";
	string brandAdidas = "Adidas";
	string brandReusch = "Reusch";
	string brandUhlsport = "Uhlsport";
	int Nike = 0;
	int Adidas = 0;
	int Reusch = 0;
	int Uhlsport = 0;
	int summaryNike = 0;
	int summaryAdidas = 0;
	int summaryReusch = 0;
	int summaryUhlsport = 0;
	int prevNike = 0;
	int prevAdidas = 0;
	int prevReusch = 0;
	int prevUhlsport = 0;
	int maxNike = 40;
	int maxAdidas = 20;
	int maxReusch = 55;
	int maxUhlsport = 75;
public:
	GOALKEEPER() {};
	void pereuchGOALKEEPER() {
		system("cls");
		cout << endl << "Введите количество товара в шутках" << endl;
		cout << "Вратарские перчатки:" << endl;
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
		cout << brandReusch << ": ";
		while (true) {
			try {
				cin >> Reusch;
				if (Reusch > maxReusch || Reusch < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Reusch, sizeof(Reusch), 0);
		cout << brandUhlsport << ": ";
		while (true) {
			try {
				cin >> Uhlsport;
				if (Uhlsport > maxUhlsport || Uhlsport < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Uhlsport, sizeof(Uhlsport), 0);
	}
	void showGOALKEEPER() {
		cout << endl << "Вратарские перчатки (шт):" << endl;
		cout << brandNike << ": " << Nike << endl;
		cout << brandAdidas << ": " << Adidas << endl;
		cout << brandReusch << ": " << Reusch << endl;
		cout << brandUhlsport << ": " << Uhlsport << endl;
	}
	void inputfileGOALKEEPER() {
	}
	void allGOALKEEPER() {
		system("cls");
		cout << endl << "Вратарские перчатки" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandReusch << " - " << endl;
		cout << "4 - " << brandUhlsport << " - " << endl;
	}
	void purchaseGOALKEEPER() {
		int choice5;
		int number;
		do {
			system("cls");
			cout << endl << "Вратарские перчатки (шт):" << endl;
			cout << "1 - " << brandNike << ": " << Nike << endl;
			cout << "2 - " << brandAdidas << ": " << Adidas << endl;
			cout << "3 - " << brandReusch << ": " << Reusch << endl;
			cout << "4 - " << brandUhlsport << ": " << Uhlsport << endl;
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
						if (number > Reusch || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevReusch = Reusch;
				Reusch = Reusch - number;
				break;
			case 4:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Uhlsport || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevUhlsport = Uhlsport;
				Uhlsport = Uhlsport - number;
				break;
			case 5:
				break;
			}
		} while (choice5 > 0 && choice5 < 5);
	}

	void summary() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevReusch == 0 && prevUhlsport == 0) {
			cout << "В данный момент вывести рекомендации по оптимизации закупок вратарских перчаток невозможно" << endl;
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryReusch = prevReusch - Reusch;
			summaryUhlsport = prevUhlsport - Uhlsport;
			biggest = summaryNike;
			recv(Connection, (char*)&brand, sizeof(brand), 0);
			if (brand == 1) {
				cout << "Очень популярными оказались вратарские перчатки от производителя " << brandNike << endl;
			}
			if (brand == 2) {
				cout << "Очень популярными оказались вратарские перчатки от производителя " << brandAdidas << endl;
			}
			if (brand == 3) {
				cout << "Очень популярными оказались вратарские перчатки от производителя " << brandReusch << endl;
			}
			if (brand == 4) {
				cout << "Очень популярными оказались вратарские перчатки от производителя " << brandUhlsport << endl;
			}
		}
	}
	~GOALKEEPER() {};
};
