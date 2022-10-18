#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <string.h>
#include<thread>
#include<iomanip>
#pragma comment(lib, "ws2_32.lib")

using namespace std;
void show(char c[10][10])
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(2);
		for (int j = 0; j < 10; j++)
		{
			if (c[i][j] == 'X' || c[i][j] == 'O')
			{
				if (j < 9)
					cout << c[i][j] << setw(2) << "|" << setw(2);
				else
					cout << c[i][j] << setw(2);
			}
			else
			{
				if (j < 9)
					cout << ' ' << setw(2) << "|" << setw(2);
				else
					cout << ' ' << setw(2);
			}
		}
		cout << endl << "---------------------------------------";
		cout << endl;
	}
}
bool check( int x, int y)
{
	if (x > 0 && x < 11 && y>0 && y < 11)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool input_M1(char a[10][10], int x,int y)
{
	if (a[x][y]!='X'&&a[x][y]!='Y')
	{
		return false;
	}
	else
	{
		cout << "The position is occupied" << endl;
		return true;
	}
}
void check_1(string s,string &s1,int &x,int&y)
{
	int xet = 0;
	string gan;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ',')
		{
			gan += s[i];
		}
		else
		{
			if (xet == 0)
			{
				s1 = gan;
				xet++;
				gan = "";
			}
			else if (xet == 1 && s1!="2")
			{
				x = stoi(gan);
				xet++;
				gan = "";
			}
			else if (xet == 2 && s1 != "2")
			{
				y = stoi(gan);
				gan = "";
			}
		}

	}
}
void t2()
{
	char ch_ar[10][10];
	string ipAddress = "127.0.0.1";			// IP Address of the server
	int port = 54000;						// Listening port # on the server

	// Initialize WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Can't start Winsock, Err #" << wsResult << endl;
		return;
	}

	// Create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "Can't create socket, Err #" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}

	// Fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);
	// Connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "Can't connect to server, Err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

	// Do-while loop to send and receive data
	char buf[4096];
	string userInput;
	cout << "Enter the name Player:";
	getline(cin, userInput);
	int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
	do
	{
		int x, y;
		string z;
		// Prompt the user for some text
		int bytesReceived = recv(sock, buf, 4096, 0);
		string a = string(buf, 0, bytesReceived);
		check_1(a, z, x, y);
		if (z == "1")
		{
			cout << "X WIN" << endl;
			ch_ar[x][y] = 'X';
			show(ch_ar);
			break;
		}
		else if (z == "2")
		{
			cout << "Y WIN" << endl;
			show(ch_ar);
			break;
		}
		else
		{
			ch_ar[x][y] = 'X';
			show(ch_ar);
		}
		bool test = true;
		bool test1 = true;
		while (test == true && test1 == true)
		{
			cout << "Enter x:";
			cin >> x;
			cout << "Enter y:";
			cin >> y;
			test = input_M1(ch_ar, x, y);
			test1 = check(x, y);
		}
		ch_ar[x-1][y-1] = 'O';
		show(ch_ar);
		userInput = to_string(x) + "," + to_string(y) + ",";
		sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);

	} while (userInput.size() > 0);

	// Gracefully close down everything
	closesocket(sock);
}
void main()
{
	t2();
}