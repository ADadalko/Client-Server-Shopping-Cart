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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (newConnection == 0) {
			cout << "Error #2\n";
	}
	else {
		while (true) {
				cout << endl << "Client connected" << endl;
				string msg1 = "\nМагазин футбольной атрибутики\n";
				int msg_size = msg1.size();
				send(newConnection, (char*)&msg_size, sizeof(int), NULL);
				send(newConnection, msg1.c_str(), msg_size, NULL);
				Sleep(10);
				Firstmenu();
			}
	}
	return 0;
}