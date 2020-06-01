#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "SOCKET.h"

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
		recv(newConnection, (char*)&Nike, sizeof(Nike), 0);
		recv(newConnection, (char*)&Adidas, sizeof(Adidas), 0);
		recv(newConnection, (char*)&Puma, sizeof(Puma), 0);
		recv(newConnection, (char*)&Joma, sizeof(Joma), 0);
	}
	void showBOOTS() {
	}
	void inputfileBOOTS() {
		fout.open("FOOTBALL_SHOP.txt", ios::out | ios::app);
		fout << "\nБутсы:\n";
		fout << "Nike: " << Nike << "\n";
		fout << "Adidas: " << Adidas << "\n";
		fout << "Puma: " << Puma << "\n";
		fout << "Joma: " << Joma << "\n";
		fout.close();
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
			recv(newConnection, (char*)&choice5, sizeof(choice5), 0);
			switch (choice5) {
			case 1:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevNike = Nike;
				Nike = Nike - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Бутсы " << brandNike << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 2:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Бутсы " << brandAdidas << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 3:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevPuma = Puma;
				Puma = Puma - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Бутсы " << brandPuma << " - " << number << " (шт)\n";
				fout.close();
				break;
			case 4:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevJoma = Joma;
				Joma = Joma - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Бутсы " << brandJoma << " - " << number << " (шт)\n";
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
		if (prevNike == 0 && prevAdidas == 0 && prevPuma == 0 && prevJoma == 0) {		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryPuma = prevPuma - Puma;
			summaryJoma = prevJoma - Joma;
			biggest = summaryNike;
			brand = 1;
			if (biggest < summaryAdidas) {
				biggest = summaryAdidas;
				brand = 2;
			}
			if (biggest < summaryPuma) {
				biggest = summaryPuma;
				brand = 3;
			}
			if (biggest < summaryJoma) {
				biggest = summaryJoma;
				brand = 4;
			}
			send(newConnection, (char*)&brand, sizeof(brand), 0);
		}
	}
	~BOOTS() {};
};
