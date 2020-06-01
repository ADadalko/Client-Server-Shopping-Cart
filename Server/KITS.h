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
		recv(newConnection, (char*)&Nike, sizeof(Nike), 0);
		recv(newConnection, (char*)&Adidas, sizeof(Adidas), 0);
		recv(newConnection, (char*)&Givova, sizeof(Givova), 0);
		recv(newConnection, (char*)&Masita, sizeof(Masita), 0);
	}
	void showKITS() {
	}
	void inputfileKITS() {
		fout.open("FOOTBALL_SHOP.txt", ios::out | ios::app);
		fout << "\nФутбольная форма:\n";
		fout << "Nike: " << Nike << "\n";
		fout << "Adidas: " << Adidas << "\n";
		fout << "Givova: " << Givova << "\n";
		fout << "Masita: " << Masita << "\n";
		fout.close();
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
			recv(newConnection, (char*)&choice5, sizeof(choice5), 0);
			switch (choice5) {
			case 1:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevNike = Nike;
				Nike = Nike - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Формы " << brandNike << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 2:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Формы " << brandAdidas << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 3:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevGivova = Givova;
				Givova = Givova - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Формы " << brandGivova << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 4:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevMasita = Masita;
				Masita = Masita - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Формы " << brandMasita << " - " << number << " (шт)\n";
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
		if (prevNike == 0 && prevAdidas == 0 && prevGivova == 0 && prevMasita == 0) {	}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryGivova = prevGivova - Givova;
			summaryMasita = prevMasita - Masita;
			biggest = summaryNike;
			brand = 1;
			if (biggest < summaryAdidas) {
				biggest = summaryAdidas;
				brand = 2;
			}
			if (biggest < summaryGivova) {
				biggest = summaryGivova;
				brand = 3;
			}
			if (biggest < summaryMasita) {
				biggest = summaryMasita;
				brand = 4;
			}
			send(newConnection, (char*)&brand, sizeof(brand), 0);
		}
	}
	~KITS() {};
};
