#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <string.h>
#include<iomanip>
#include<fstream>
#pragma comment(lib, "ws2_32.lib")

using namespace std;
string player_1, player_2;
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
void split_string(string s)
{
	string s1 = "";
	string s2 = s;
	//cout << s2 << endl;
	string name, win, lose, draw, name_win, name_lose,name_drow;
	int dem = 0;
	cout << s2.length();
	for (int j = 0; j < s2.length(); j++)
	{
		if (s2[j] != ',')
		{
			s1 = s1 + s[j];
			//cout << s1;
		}
		else
		{
			switch (dem)
			{
			case 1:
				name = s1;
				dem++;
				s1 = "";
				break;
			case 2:
				win = s1;
				dem++;
				s1 = "";
				break;
			case 3:
				lose = s1;
				dem++;
				s1 = "";
				break;
			case 4:
				name_win = s1;
				dem++;
				s1 = "";
				break;
			case 5:
				name_lose = s1;
				dem++;
				s1 = "";
				break;
			case 7:
				name_drow = s1;
				dem++;
				s1 = "";
				break;
			default:
				break;
			}
		}
	}
	cout << "NAME:" << name << endl;
	cout << "Number of wins:" << win << "(" << name_win << ")" << endl;
	cout << "Number of loses:" << lose << "(" << name_lose << ")" << endl;
	cout << "Number of draws:" << draw << "(" << name_drow << ")" << endl;
}
void t2(int hhh)
{
	string bb = to_string(hhh);
	char ch_ar[10][10];
	string ipAddress = "127.0.0.1";			// IP Address of the server
	int port = 54000;						// Listening port # on the server
	int bytesReceived;
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
	getline(cin, userInput);
	player_2 = userInput;
	int sendResult = send(sock,bb.c_str(), bb.size() + 1, 0);
	if (bb == "1")
	{
		getline(cin, userInput);
		player_2 = userInput;
		bytesReceived = recv(sock, buf, 4096, 0);
		string a = string(buf, 0, bytesReceived);
		player_1 = a;
		sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
		do
		{
			int x, y;
			string z;
			// Prompt the user for some text
			bytesReceived = recv(sock, buf, 4096, 0);
			a = string(buf, 0, bytesReceived);
			check_1(a, z, x, y);
			if (z == "1")
			{
				cout << player_1 << " WIN" << endl;
				ch_ar[x][y] = 'X';
				show(ch_ar);
				break;
			}
			else if (z == "2")
			{
				cout << player_2 << " WIN" << endl;
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
			ch_ar[x - 1][y - 1] = 'O';
			show(ch_ar);
			userInput = to_string(x) + "," + to_string(y) + ",";
			sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);

		} while (userInput.size() > 0);
		// Gracefully close down everything
		closesocket(sock);
	}
	else
	{
		getline(cin, userInput);
		player_2 = userInput;
		sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
		bytesReceived = recv(sock, buf, 4096, 0);
		string a = string(buf, 0, bytesReceived);
		split_string(a);
		closesocket(sock);
	}
}
void main()
{
	int chosse;
	do
	{
		cout << "NHAP LUA CHON:" << endl;
		cout << "1: NEW PLAY" << endl;
		cout << "2: LOOK MY INFORMATION " << endl;
		cout << "3: BREAK" << endl;
		cin >> chosse;
		switch (chosse)
		{
		case 1:
			t2(1);
			break;
		case 2:
			t2(2);
			break;
		}
	} while (chosse != 3);
	/*string v;
	getline(cin, v);*/
}