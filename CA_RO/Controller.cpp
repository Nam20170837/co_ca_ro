#include "Controller.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

bool Controller::check()
{
	if (0 < this->i_m[0] && this->i_m[0] < 11 && 0 < this->i_m[1] && this->i_m[1] < 11)
	{
		return true;
	}
	else
	{
		cout << "The position is not suitable" << endl;
		return false;
	}
}

void Controller:: C()
{
	int start = 0;
	V.user();
	while (start == 0)
	{
		V.import_XY(this->i_m);
		bool test = false;
		bool test1 = false;
		while (test == false || test1 == false)
		{
			test = M.input_M1(this->i_m);
			test1 = this->check();
			if (test == false || test1 == false)
			{
				V.import_XY(this->i_m);
			}
		}
		M.input_M();
		V.show(M.M);
		start = M.check_win();
		if (start == 1)
		{
			V.print(V.player_1 + " chien thang:");
		}
		else if(start == 2)
		{
			V.print(V.player_2 + " chien thang:");
		}
		if (this->i_m[2] == 0)
		{
			this->i_m[2] = 1;
			//cout << 'a';
		}
		else
		{
			this->i_m[2] = 0;
		}
	}
	M.inport_infor("caro.ini", V.player_1, V.player_2, start);
	M.outport_infor("caro.ini");
	ofstream out_caro1;
	out_caro1.open("caro1.ini");
	out_caro1.clear();
	for (int i = 0; i < M.v1.size(); i++)
	{
		out_caro1 << M.v1[i];
		if (i != M.v1.size() - 1)
		{
			out_caro1 << ",";
		}

	}
}

void Controller::C1()
{
	
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Can't Initialize winsock! Quitting" << endl;
		return;
	}

	// Create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create a socket! Quitting" << endl;
		return;
	}

	// Bind the ip address and port to a socket
	sockaddr_in hint;
	//sin_family Thành ph?n này d? c?p d?n h? d?a ch? mà trong h?u h?t các tru?ng h?p du?c d?t thành “AF_INET”
	hint.sin_family = AF_INET;
	//sin_port: Nó d? c?p d?n s? c?ng 16 bit mà máy ch? s? l?ng nghe các yêu c?u k?t n?i c?a máy khách.
	hint.sin_port = htons(54000);
	//sin_addr: Nó d?i di?n cho m?t d?a ch? IP 32 - bit.
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // Could also use inet_pton .... 

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Tell Winsock the socket is for listening 
	listen(listening, SOMAXCONN);
	//cout << "nam" << endl;

	// Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);
	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];		// Client's remote name
	char service[NI_MAXSERV];	// Service (i.e. port) the client is connect on

	ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);
	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << host << " connected on port " << service << endl;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " <<
			ntohs(client.sin_port) << endl;
	}

	// Close listening socket
	closesocket(listening);

	// While loop: accept and echo message back to client
	char buf[4096];
	ZeroMemory(buf, 4096);
	int sendResult;
	int bytesReceived1 = recv(clientSocket, buf, 4096, 0);
	string a = string(buf, 0, bytesReceived1);
	cout << a;
	if (a == "1")
	{

		string b;
		string data;
		V.user1();
		int start = 0;
		sendResult = send(clientSocket, this->V.player_1.c_str(), this->V.player_1.size() + 1, 0);
		bytesReceived1 = recv(clientSocket, buf, 4096, 0);
		this->V.player_2 = string(buf,0, bytesReceived1);
		while (true)
		{
			V.import_XY_1(this->i_m);
			bool test = false;
			bool test1 = false;
			while (test == false || test1 == false)
			{
				test = M.input_M1(this->i_m);
				test1 = this->check();
				if (test == false || test1 == false)
				{
					V.import_XY_1(this->i_m);
				}
			}
			M.input_M();
			V.show(M.M);
			start = M.check_win();
			if (start == 0)
			{
				data = "0," + to_string(this->M.M1[0]) + "," + to_string(this->M.M1[1]) + ",";
				sendResult = send(clientSocket, data.c_str(), data.size() + 1, 0);
			}
			else if (start == 1)
			{
				data = "1," + to_string(this->M.M1[0]) + "," + to_string(this->M.M1[1]) + ",";
				sendResult = send(clientSocket, data.c_str(), data.size() + 1, 0);
				cout << "X WIN" << endl;
				break;
			}

			ZeroMemory(buf, 4096);
			int bytesReceived1 = recv(clientSocket, buf, 4096, 0);
			b = string(buf, 0, bytesReceived1);
			string gan;
			int xet = 0;
			for (int i = 0; i < b.size(); i++)
			{
				if (b[i] != ',')
				{
					gan += b[i];
				}
				else
				{
					if (xet == 0)
					{
						this->i_m[0] = stoi(gan);
						gan = "";
						xet++;
					}
					else if (xet == 1)
					{
						this->i_m[1] = stoi(gan);
						gan = "";
						this->i_m[2] = 1;
					}
				}

			}
			this->M.input_M1(this->i_m);
			this->M.input_M();
			V.show(this->M.M);
			start = this->M.check_win();
			if (start == 2)
			{
				data = "2,,,";
				send(clientSocket, data.c_str(), data.size() + 1, 0);
				cout << "O WIN" << endl;
				break;

			}

		}
		M.inport_infor("caro.ini", V.player_1, V.player_2, start);
		M.outport_infor("caro.ini");
		// Close the socket
		closesocket(clientSocket);
	}
	else
	{
		bytesReceived1 = recv(clientSocket, buf, 4096, 0);
		string c = string(buf, 0, bytesReceived1);
		cout << c;
		ifstream filein;
		filein.open("caro.ini", ios_base::in);

		while (filein.eof() == false)
		{
			this->M.read_file(filein);
			cout << this->M.player.name;
			if (this->M.player.name == c)
			{
				string d = this->M.player.name + "," + this->M.player.thang + "," + this->M.player.thua + "," + this->M.player.hoa + "," + this->M.player.name_thang + "," + this->M.player.name_thua + "," + this->M.player.name_hoa + ",";
				cout << d << endl;
				sendResult = send(clientSocket, d.c_str(), d.size() + 1, 0);
				break;
			}
		}

	}

	// Cleanup winsock
	WSACleanup();
}
 
void Controller::D(string s)
{
	nguoichoi* nc = M.find_infor("caro.ini", s);
	cout << "Information of player:"<<endl;
	cout << "Name:" << nc[0].name << endl;
	cout << "Win:" << nc[0].thang << endl;
	cout << "Loser:" << nc[0].thua << endl;
	cout << "Draw:" << nc[0].hoa << endl;
	cout << "Information of same player:" << endl;
	cout << "Name:" << nc[1].name << endl;
	cout << "Win:" << nc[1].thang << endl;
	cout << "Loser:" << nc[1].thua << endl;
	cout << "Draw:" << nc[1].hoa << endl;
}

void Controller::E()
{
	int i1 = 0;
	M.read_file1("caro1.ini");
	int i2 = M.v1.size();
	int a[3];
	for (int i = 0;i < i2; i = i+2)
	{
		a[0] = M.v1[i] + 1;
		a[1] = M.v1[i+1] + 1;
		if (i1 == 0)
		{
			a[2] = 0;
			i1 = 1;
		}
		else
		{
			a[2] = 1;
			i1 = 0;
		}
		M.input_M1(a);
		M.input_M();
		V.show(M.M);
		cout << endl;
		this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
	if (a[2] == 0)
	{
		cout << "X WIN:" << endl;
	}
	else
	{
		cout << "O WIN:" << endl;
	}
}
