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
		recv(newConnection, (char*)&Nike, sizeof(Nike), 0);
		recv(newConnection, (char*)&Adidas, sizeof(Adidas), 0);
		recv(newConnection, (char*)&Reusch, sizeof(Reusch), 0);
		recv(newConnection, (char*)&Uhlsport, sizeof(Uhlsport), 0);
	}
	void showGOALKEEPER() {
	}
	void inputfileGOALKEEPER() {
		fout.open("FOOTBALL_SHOP.txt", ios::out | ios::app);
		fout << "\nВратарские перчатки:\n";
		fout << "Nike: " << Nike << "\n";
		fout << "Adidas: " << Adidas << "\n";
		fout << "Reusch: " << Reusch << "\n";
		fout << "Uhlsport: " << Uhlsport << "\n";
		fout.close();
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
			recv(newConnection, (char*)&choice5, sizeof(choice5), 0);
			switch (choice5) {
			case 1:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevNike = Nike;
				Nike = Nike - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Перчатки " << brandNike << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 2:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Перчатки " << brandAdidas << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 3:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevReusch = Reusch;
				Reusch = Reusch - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Перчатки " << brandReusch << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 4:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevUhlsport = Uhlsport;
				Uhlsport = Uhlsport - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Перчатки " << brandUhlsport << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 5:
				break;
			}
		} while (choice5 > 0 && choice5 < 5);
	}

	void summary() {
		int biggest = 0;
		int brand = 0;
		if (prevNike == 0 && prevAdidas == 0 && prevReusch == 0 && prevUhlsport == 0) {		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryReusch = prevReusch - Reusch;
			summaryUhlsport = prevUhlsport - Uhlsport;
			biggest = summaryNike;
			brand = 1;
			if (biggest < summaryAdidas) {
				biggest = summaryAdidas;
				brand = 2;
			}
			if (biggest < summaryReusch) {
				biggest = summaryReusch;
				brand = 3;
			}
			if (biggest < summaryUhlsport) {
				biggest = summaryUhlsport;
				brand = 4;
			}
			send(newConnection, (char*)&brand, sizeof(brand), 0);
		}
	}
	~GOALKEEPER() {};
};
