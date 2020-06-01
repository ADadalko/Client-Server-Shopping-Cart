#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <locale.h>
#include <iomanip>
#include <memory>
#include "FUNCTIONS.h";

#pragma warning(disable: 4996)

using namespace std;



int main(int argc, char* argv[]) {
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		cout << "Error" << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		cout << "Error: failed connect to server.\n";
		return 1;
	}
	else {
		cout << "Connected!\n";
		Sleep(1700);
		while (true) {
			system("cls");
			int msg_size;                                            
			recv(Connection, (char*)&msg_size, sizeof(int), NULL); 
			char* msg = new char[msg_size + 1];                      
			msg[msg_size] = '\0';
			recv(Connection, msg, msg_size, NULL);
			cout << msg << endl;
			Firstmenu();
		}
	}
	return 0;
}