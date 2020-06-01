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
		recv(newConnection, (char*)&Nike, sizeof(Nike), 0);
		recv(newConnection, (char*)&Adidas, sizeof(Adidas), 0);
		recv(newConnection, (char*)&Kempa, sizeof(Kempa), 0);
		recv(newConnection, (char*)&Joma, sizeof(Joma), 0);
	}
	void showBAGS() {
	}
	void inputfileBAGS() {
		fout.open("FOOTBALL_SHOP.txt", ios::out | ios::app);
		fout << "\nÑóìêè è ðþêçàêè:\n";
		fout << "Nike: " << Nike << "\n";
		fout << "Adidas: " << Adidas << "\n";
		fout << "Kempa: " << Kempa << "\n";
		fout << "Joma: " << Joma << "\n";
		fout.close();
	}
	void allBAGS() {
		system("cls");
		cout << endl << "Ñóìêè è ðþêçàêè" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandKempa << " - " << endl;
		cout << "4 - " << brandJoma << " - " << endl;
	}
	void purchaseBAGS() {
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
				fout << "Ðþêçàêè " << brandNike << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 2:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ðþêçàêè " << brandAdidas << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 3:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevKempa = Kempa;
				Kempa = Kempa - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ðþêçàêè " << brandKempa << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 4:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevJoma = Joma;
				Joma = Joma - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ðþêçàêè " << brandJoma << " - " << number << " (øò)\n";
				fout.close();
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
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryKempa = prevKempa - Kempa;
			summaryJoma = prevJoma - Joma;
			biggest = summaryNike;
			brand = 1;
			if (biggest < summaryAdidas) {
				biggest = summaryAdidas;
				brand = 2;
			}
			if (biggest < summaryKempa) {
				biggest = summaryKempa;
				brand = 3;
			}
			if (biggest < summaryJoma) {
				biggest = summaryJoma;
				brand = 4;
			}
			send(newConnection, (char*)&brand, sizeof(brand), 0);
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
		recv(newConnection, (char*)&Nike, sizeof(Nike), 0);
		recv(newConnection, (char*)&Adidas, sizeof(Adidas), 0);
		recv(newConnection, (char*)&Puma, sizeof(Puma), 0);
		recv(newConnection, (char*)&Joma, sizeof(Joma), 0);
	}
	void showSOCKS() {
	}
	void inputfileSOCKS() {
		fout.open("FOOTBALL_SHOP.txt", ios::out | ios::app);
		fout << "\nÃåòðû:\n";
		fout << "Nike: " << Nike << "\n";
		fout << "Adidas: " << Adidas << "\n";
		fout << "Puma: " << Puma << "\n";
		fout << "Joma: " << Joma << "\n";
		fout.close();
	}
	void allSOCKS() {
		system("cls");
		cout << endl << "Ãåòðû" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandPuma << " - " << endl;
		cout << "4 - " << brandJoma << " - " << endl;
	}
	void purchaseSOCKS() {
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
				fout << "Ãåòðû " << brandNike << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 2:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ãåòðû " << brandAdidas << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 3:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevPuma = Puma;
				Puma = Puma - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ãåòðû " << brandPuma << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 4:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevJoma = Joma;
				Joma = Joma - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ãåòðû " << brandJoma << " - " << number << " (øò)\n";
				fout.close();
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
		}
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
		recv(newConnection, (char*)&Nike, sizeof(Nike), 0);
		recv(newConnection, (char*)&Adidas, sizeof(Adidas), 0);
		recv(newConnection, (char*)&Demix, sizeof(Demix), 0);
		recv(newConnection, (char*)&Fora, sizeof(Fora), 0);
	}
	void showPADS() {
	}
	void inputfilePADS() {
		fout.open("FOOTBALL_SHOP.txt", ios::out | ios::app);
		fout << "\nÙèòêè:\n";
		fout << "Nike: " << Nike << "\n";
		fout << "Adidas: " << Adidas << "\n";
		fout << "Demix: " << Demix << "\n";
		fout << "Fora: " << Fora << "\n";
		fout.close();
	}
	void allPADS() {
		system("cls");
		cout << endl << "Ùèòêè" << endl;
		cout << "1 - " << brandNike << " - " << endl;
		cout << "2 - " << brandAdidas << " - " << endl;
		cout << "3 - " << brandDemix << " - " << endl;
		cout << "4 - " << brandFora << " - " << endl;
	}
	void purchasePADS() {
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
				fout << "Ùèòêè " << brandNike << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 2:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevAdidas = Adidas;
				Adidas = Adidas - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ùèòêè " << brandAdidas << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 3:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevDemix = Demix;
				Demix = Demix - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ùèòêè " << brandDemix << " - " << number << " (øò)\n";
				fout.close();
				break;
			case 4:
				recv(newConnection, (char*)&number, sizeof(number), 0);
				prevFora = Fora;
				Fora = Fora - number;
				fout.open("CHECKS.txt", ios::out | ios::app);
				fout << "Ùèòêè " << brandFora << " - " << number << " (øò)\n";
				fout.close();
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
		}
		else {
			summaryNike = prevNike - Nike;
			summaryAdidas = prevAdidas - Adidas;
			summaryDemix = prevDemix - Demix;
			summaryFora = prevFora - Fora;
			biggest = summaryNike;
			brand = 1;
			if (biggest < summaryAdidas) {
				biggest = summaryAdidas;
				brand = 2;
			}
			if (biggest < summaryDemix) {
				biggest = summaryDemix;
				brand = 3;
			}
			if (biggest < summaryFora) {
				biggest = summaryFora;
				brand = 4;
			}
			send(newConnection, (char*)&brand, sizeof(brand), 0);
		}
	}
	~PADS() {};
};

