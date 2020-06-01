
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "GOALKEEPER.h"

using namespace std;


class BAGS {
	string brandNike = "Nike";
	string brandAdidas = "Adidas";
	string brandKempa = "Kempa";
	string brandJoma = "Joma";
	int Nike = 0;
	int Adidas = 0;
	int Kempa = 0;
	int Joma = 0;

	int summaryNike = 0;
	int summaryAdidas = 0;
	int summaryKempa = 0;
	int summaryJoma = 0;
	int prevNike = 0;
	int prevAdidas = 0;
	int prevKempa = 0;
	int prevJoma = 0;

	int maxNike = 30;
	int maxAdidas = 30;
	int maxKempa = 15;
	int maxJoma = 20;
public:
	BAGS() {};
	void pereuchBAGS() {
		system("cls");
		cout << endl << "Введите количество товара в шутках" << endl;
		cout << "Сумки и рюкзаки:" << endl;
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
		cout << brandKempa << ": ";
		while (true) {
			try {
				cin >> Kempa;
				if (Kempa > maxKempa || Kempa < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Kempa, sizeof(Kempa), 0);
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
	void showBAGS() {
		cout << endl << "Сумки и рюкзаки (шт):" << endl;
		cout << brandNike << ": " << Nike << endl;
		cout << brandAdidas << ": " << Adidas << endl;
		cout << brandKempa << ": " << Kempa << endl;
		cout << brandJoma << ": " << Joma << endl;
	}
	void inputfileBAGS() {
	}
	void allBAGS() {
		system("cls");
		cout << endl << "Сумки и рюкзаки" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandKempa << " - " << endl;
		cout << "4 - " << brandJoma << " - " << endl;
	}
	void purchaseBAGS() {
		int choice5;
		int number;
		do {
			system("cls");
			cout << endl << "Рюкзаки и сумки (шт):" << endl;
			cout << "1 - " << brandNike << ": " << Nike << endl;
			cout << "2 - " << brandAdidas << ": " << Adidas << endl;
			cout << "3 - " << brandKempa << ": " << Kempa << endl;
			cout << "4 - " << brandJoma << ": " << Joma << endl;
			cout << "5 - утвердить заказ" << endl;
			cin >> choice5;
			while (choice5 < 1 || choice5 > 5)
			{
				cout << "Нет такого варианта!" << endl;
				cin >> choice5;
			}
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
						if (number > Kempa || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevKempa = Kempa;
				Kempa = Kempa - number;
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
	void summaryBAGS() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevKempa == 0 && prevJoma == 0) {
			cout << "В данный момент вывести рекомендации по оптимизации закупок футбольных щиктов невозможно" << endl;
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryKempa = prevKempa - Kempa;
			summaryJoma = prevJoma - Joma;
			biggest = summaryNike;
			recv(Connection, (char*)&brand, sizeof(brand), 0);
			if (brand == 1) {
				cout << "Самые востребованные рюкзаки и сумки - рюкзаки и сумки бренда " << brandNike << endl;
			}
			if (brand == 2) {
				cout << "Самые востребованные рюкзаки и сумки - рюкзаки и сумки бренда " << brandAdidas << endl;
			}
			if (brand == 3) {
				cout << "Самые востребованные рюкзаки и сумки - рюкзаки и сумки бренда " << brandKempa << endl;
			}
			if (brand == 4) {
				cout << "Самые востребованные рюкзаки и сумки - рюкзаки и сумки бренда " << brandJoma << endl;
			}
		}
	}
	~BAGS() {};
};


class SOCKS :public BAGS {

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

	int maxNike = 290;
	int maxAdidas = 160;
	int maxPuma = 210;
	int maxJoma = 200;
public:
	SOCKS() {};
	void pereuchSOCKS() {
		system("cls");
		cout << endl << "Введите количество товара в шутках" << endl;
		cout << "Футбольные гетры:" << endl;
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
	void showSOCKS() {
		cout << endl << "Футбольные гетры (шт):" << endl;
		cout << brandNike << ": " << Nike << endl;
		cout << brandAdidas << ": " << Adidas << endl;
		cout << brandPuma << ": " << Puma << endl;
		cout << brandJoma << ": " << Joma << endl;
	}
	void inputfileSOCKS() {
	}
	void allSOCKS() {
		system("cls");
		cout << endl << "Гетры" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandPuma << " - " << endl;
		cout << "4 - " << brandJoma << " - " << endl;
	}
	void purchaseSOCKS() {
		int choice5;
		int number;
		do {
			system("cls");
			cout << endl << "Гетры (шт):" << endl;
			cout << "1 - " << brandNike << ": " << Nike << endl;
			cout << "2 - " << brandAdidas << ": " << Adidas << endl;
			cout << "3 - " << brandPuma << ": " << Puma << endl;
			cout << "4 - " << brandJoma << ": " << Joma << endl;
			cout << "5 - утвердить заказ" << endl;
			cin >> choice5;
			send(Connection, (char*)&choice5, sizeof(choice5), 0);
			while (choice5 < 1 || choice5 > 5)
			{
				cout << "Нет такого варианта!" << endl;
				cin >> choice5;
			}
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
	void summarySOCKS() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevPuma == 0 && prevJoma == 0) {
			cout << "В данный момент вывести рекомендации по оптимизации закупок футбольных гетр невозможно" << endl;
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryPuma = prevPuma - Puma;
			summaryJoma = prevJoma - Joma;
			biggest = summaryNike;
			recv(Connection, (char*)&brand, sizeof(brand), 0);
			if (brand == 1) {
				cout << "Есть возможность увеличить прибыль магазина, если увеличить закупку футбольных гетр бренда " << brandNike << endl;
			}
			if (brand == 2) {
				cout << "Есть возможность увеличить прибыль магазина, если увеличить закупку футбольных гетр бренда " << brandAdidas << endl;
			}
			if (brand == 3) {
				cout << "Есть возможность увеличить прибыль магазина, если увеличить закупку футбольных гетр бренда " << brandPuma << endl;
			}
			if (brand == 4) {
				cout << "Есть возможность увеличить прибыль магазина, если увеличить закупку футбольных гетр бренда " << brandJoma << endl;
			}
		}
	}
	~SOCKS() {};
};


class PADS :public SOCKS {
	string brandNike = "Nike";
	string brandAdidas = "Adidas";
	string brandDemix = "Demix";
	string brandFora = "Fora";
	int Nike = 0;
	int Adidas = 0;
	int Demix = 0;
	int Fora = 0;

	int summaryNike = 0;
	int summaryAdidas = 0;
	int summaryDemix = 0;
	int summaryFora = 0;
	int prevNike = 0;
	int prevAdidas = 0;
	int prevDemix = 0;
	int prevFora = 0;

	int maxNike = 50;
	int maxAdidas = 35;
	int maxDemix = 10;
	int maxFora = 10;
public:
	PADS() {};
	void pereuchPADS() {
		system("cls");
		cout << endl << "Введите количество товара в шутках" << endl;
		cout << "Щитки:" << endl;
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
		cout << brandDemix << ": ";
		while (true) {
			try {
				cin >> Demix;
				if (Demix > maxDemix || Demix < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Demix, sizeof(Demix), 0);
		cout << brandFora << ": ";
		while (true) {
			try {
				cin >> Fora;
				if (Fora > maxFora || Fora < 0) throw 1;
				else break;
			}
			catch (int) {
				cout << "Ошибка ввода" << endl;
			}
		}
		send(Connection, (char*)&Fora, sizeof(Fora), 0);
	}
	void showPADS() {
		cout << endl << "Щитки (шт):" << endl;
		cout << brandNike << ": " << Nike << endl;
		cout << brandAdidas << ": " << Adidas << endl;
		cout << brandDemix << ": " << Demix << endl;
		cout << brandFora << ": " << Fora << endl;
	}
	void inputfilePADS() {
	}
	void allPADS() {
		system("cls");
		cout << endl << "Щитки" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandDemix << " - " << endl;
		cout << "4 - " << brandFora << " - " << endl;
	}
	void purchasePADS() {
		int choice5;
		int number;
		do {
			system("cls");
			cout << endl << "Щитки (шт):" << endl;
			cout << "1 - " << brandNike << ": " << Nike << endl;
			cout << "2 - " << brandAdidas << ": " << Adidas << endl;
			cout << "3 - " << brandDemix << ": " << Demix << endl;
			cout << "4 - " << brandFora << ": " << Fora << endl;
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
						if (number > Demix || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevDemix = Demix;
				Demix = Demix - number;
				break;
			case 4:
				cout << endl << "Введите количество приобретаемого товара:" << endl;
				while (true) {
					try {
						cin >> number;
						if (number > Fora || number < 1) throw 1;
						else break;
					}
					catch (int) {
						cout << "Ошибка ввода" << endl;
					}
				}
				send(Connection, (char*)&number, sizeof(number), 0);
				prevFora = Fora;
				Fora = Fora - number;
				break;
			case 5:
				break;
			}
		} while (choice5 > 0 && choice5 < 5);
	}

	void summaryPADS() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevDemix == 0 && prevFora == 0) {
			cout << "В данный момент вывести рекомендации по оптимизации закупок футбольных щиктов невозможно" << endl;
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryDemix = prevDemix - Demix;
			summaryFora = prevFora - Fora;
			biggest = summaryNike;
			recv(Connection, (char*)&brand, sizeof(brand), 0);
			if (brand == 1) {
				cout << "Среди самых востребованных товаров магазина оказались футбольные щитки от производителя " << brandNike << endl;
			}
			if (brand == 2) {
				cout << "Среди самых востребованных товаров магазина оказались футбольные щитки от производителя " << brandAdidas << endl;
			}
			if (brand == 3) {
				cout << "Среди самых востребованных товаров магазина оказались футбольные щитки от производителя " << brandDemix << endl;
			}
			if (brand == 4) {
				cout << "Среди самых востребованных товаров магазина оказались футбольные щитки от производителя " << brandFora << endl;
			}
		}
	}
	~PADS() {};
};

