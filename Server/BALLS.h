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
		recv(newConnection, (char*)&Nike, sizeof(Nike), 0);
		recv(newConnection, (char*)&Adidas, sizeof(Adidas), 0);
		recv(newConnection, (char*)&Select, sizeof(Select), 0);
		recv(newConnection, (char*)&Kelme, sizeof(Kelme), 0);
	}
	void showBALLS() {
	}
	void inputfileBALLS() {
		fout.open("FOOTBALL_SHOP.txt", ios::out | ios::app);
		fout << "\nּÿקט:\n";
		fout << "Nike: " << Nike << "\n";
		fout << "Adidas: " << Adidas << "\n";
		fout << "Select: " << Select << "\n";
		fout << "Kelme: " << Kelme << "\n";
		fout.close();
	}
	void allBALLS() {
		system("cls");
		cout << endl << "װףעבמכüםûו לÿקט" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandSelect << " - " << endl;
		cout << "4 - " << brandKelme << " - " << endl;
	}
	void purchaseBALLS() {
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
				fout << "ּÿקט " << brandNike << " - " << number << " (רע)\n";
				fout.close();
				break;
			case 2:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "ּÿקט " << brandAdidas << " - " << number << " (רע)\n";
				fout.close();
				break;
			case 3:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevSelect = Select;
				Select = Select - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "ּÿקט " << brandSelect << " - " << number << " (רע)\n";
				fout.close();
				break;
			case 4:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevKelme = Kelme;
				Kelme = Kelme - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "ּÿקט " << brandKelme << " - " << number << " (רע)\n";
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
		if (prevNike == 0 && prevAdidas == 0 && prevSelect == 0 && prevKelme == 0) {
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summarySelect = prevSelect - Select;
			summaryKelme = prevKelme - Kelme;
			biggest = summaryNike;
			brand = 1;
			if (biggest < summaryAdidas) {
				biggest = summaryAdidas;
				brand = 2;
			}
			if (biggest < summarySelect) {
				biggest = summarySelect;
				brand = 3;
			}
			if (biggest < summaryKelme) {
				biggest = summaryKelme;
				brand = 4;
			}
			send(newConnection, (char*)&brand, sizeof(brand), 0);
		}
	}
	~BALLS() {};
};
