#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Boots.h"

using namespace std;

class BALLS {
	string brandNike = "Nike";
	string brandAdidas = "Adidas";
	string brandSelect = "Select";
	string brandKelme = "Kelme";
	int Nike = 0;
	int Adidas = 0;
	int Select = 0;
	int Kelme = 0;

	int summaryNike = 0;
	int summaryAdidas = 0;
	int summarySelect = 0;
	int summaryKelme = 0;

	int prevNike = 0;
	int prevAdidas = 0;
	int prevSelect = 0;
	int prevKelme = 0;

	int maxNike = 280;
	int maxAdidas = 250;
	int maxSelect = 410;
	int maxKelme = 300;
public:
	BALLS() {};
	void pereuchBALLS() {
		system("cls");
		cout << endl << "Введите количество товара в шутках" << endl;
		cout << "Футбольные мячи:" << endl;
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
		cout << brandSelect << ": ";
		while (true) {
			try {
				cin >> Select;
				if (Select > maxSelect || Select < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Select, sizeof(Select), 0);
		cout << brandKelme << ": ";
		while (true) {
			try {
				cin >> Kelme;
				if (Kelme > maxKelme || Kelme < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Kelme, sizeof(Kelme), 0);
	}
	void showBALLS() {
		cout << endl << "Футбольные мячи (шт):" << endl;
		cout << brandNike << ": " << Nike << endl;
		cout << brandAdidas << ": " << Adidas << endl;
		cout << brandSelect << ": " << Select << endl;
		cout << brandKelme << ": " << Kelme << endl;
	}
	void inputfileBALLS() {
	}
	void allBALLS() {
		system("cls");
		cout << endl << "Футбольные мячи" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandSelect << " - " << endl;
		cout << "4 - " << brandKelme << " - " << endl;
	}
	void purchaseBALLS() {
		int choice5;
		int number;
		do {
			system("cls");
			cout << endl << "Футбольные мячи (шт):" << endl;
			cout << "1 - " << brandNike << ": " << Nike << endl;
			cout << "2 - " << brandAdidas << ": " << Adidas << endl;
			cout << "3 - " << brandSelect << ": " << Select << endl;
			cout << "4 - " << brandKelme << ": " << Kelme << endl;
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
						if (number > Select || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevSelect = Select;
				Select = Select - number;
				break;
			case 4:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Kelme || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevKelme = Kelme;
				Kelme = Kelme - number;
				break;
			case 5:
				break;
			}
		} while (choice5 > 0 && choice5 < 5);
	}
	void summary() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevSelect == 0 && prevKelme == 0) {
			cout << "В данный момент вывести рекомендации по оптимизации закупок футбольных мячей невозможно" << endl;
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summarySelect = prevSelect - Select;
			summaryKelme = prevKelme - Kelme;
			biggest = summaryNike;
			recv(Connection, (char*)&brand, sizeof(brand), 0);
			if (brand == 1) {
				cout << "Также, в категории << Футбольные мячи >> можно увеличить размер закупки мячей бренда " << brandNike << endl;
			}
			if (brand == 2) {
				cout << "Также, в категории << Футбольные мячи >> можно увеличить размер закупки мячей бренда " << brandAdidas << endl;
			}
			if (brand == 3) {
				cout << "Также, в категории << Футбольные мячи >> можно увеличить размер закупки мячей бренда " << brandSelect << endl;
			}
			if (brand == 4) {
				cout << "Также, в категории << Футбольные мячи >> можно увеличить размер закупки мячей бренда " << brandKelme << endl;
			}
		}
	}
	~BALLS() {};
};
