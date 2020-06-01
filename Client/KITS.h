#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "BALLS.h"

using namespace std;

class KITS {
	string brandNike = "Nike";
	string brandAdidas = "Adidas";
	string brandGivova = "Givova";
	string brandMasita = "Masita";
	int Nike = 0;
	int Adidas = 0;
	int Givova = 0;
	int Masita = 0;

	int summaryNike = 0;
	int summaryAdidas = 0;
	int summaryGivova = 0;
	int summaryMasita = 0;
	int prevNike = 0;
	int prevAdidas = 0;
	int prevGivova = 0;
	int prevMasita = 0;

	int maxNike = 100;
	int maxAdidas = 120;
	int maxGivova = 70;
	int maxMasita = 50;
public:
	KITS() {};
	void pereuchKITS() {
		system("cls");
		cout << endl << "Введите количество товара в шутках" << endl;
		cout << "Футбольная форма:" << endl;
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
		cout << brandGivova << ": ";
		while (true) {
			try {
				cin >> Givova;
				if (Givova > maxGivova || Givova < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Givova, sizeof(Givova), 0);
		cout << brandMasita << ": ";
		while (true) {
			try {
				cin >> Masita;
				if (Masita > maxMasita || Masita < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Masita, sizeof(Masita), 0);
	}
	void showKITS() {
		cout << endl << "Футбольная форма (шт):" << endl;
		cout << brandNike << ": " << Nike << endl;
		cout << brandAdidas << ": " << Adidas << endl;
		cout << brandGivova << ": " << Givova << endl;
		cout << brandMasita << ": " << Masita << endl;
	}
	void inputfileKITS() {
	}
	void allKITS() {
		system("cls");
		cout << endl << "Футбольная форма" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandGivova << " - " << endl;
		cout << "4 - " << brandMasita << " - " << endl;
	}
	void purchaseKITS() {
		int choice5;
		int number;
		do {
			system("cls");
			cout << endl << "Футбольные формы (шт):" << endl;
			cout << "1 - " << brandNike << ": " << Nike << endl;
			cout << "2 - " << brandAdidas << ": " << Adidas << endl;
			cout << "3 - " << brandGivova << ": " << Givova << endl;
			cout << "4 - " << brandMasita << ": " << Masita << endl;
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
						if (number > Givova || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevGivova = Givova;
				Givova = Givova - number;
				break;
			case 4:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Masita || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevMasita = Masita;
				Masita = Masita - number;
				break;
			case 5:
				break;
			}
		} while (choice5 > 0 && choice5 < 5);
	}
	void summary() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevGivova == 0 && prevMasita == 0) {
			cout << "В данный момент вывести рекомендации по оптимизации закупок футбольных форм невозможно" << endl;
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryGivova = prevGivova - Givova;
			summaryMasita = prevMasita - Masita;
			biggest = summaryNike;
			recv(Connection, (char*)&brand, sizeof(brand), 0);
			if (brand == 1) {
				cout << "Увеличьте размер закупки футбольных форм от производителя " << brandNike << endl;
			}
			if (brand == 2) {
				cout << "Увеличьте размер закупки футбольных форм от производителя " << brandAdidas << endl;
			}
			if (brand == 3) {
				cout << "Увеличьте размер закупки футбольных форм от производителя " << brandGivova << endl;
			}
			if (brand == 4) {
				cout << "Увеличьте размер закупки футбольных форм от производителя " << brandMasita << endl;
			}
		}
	}
	~KITS() {};
};
