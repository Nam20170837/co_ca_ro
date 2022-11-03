#include "Controller.h"
#include <stdlib.h>
#include<iostream>
#define data_caro "caro.ini"
#define replay "caro1.ini"
using namespace std;

//Play on 1 PC
void Controller:: game_mode_on_1_computer()
{
	int start = 0;
	V.user();
	while (start == 0)
	{
		V.import_XY(this->i_m);
		bool test = false;
		while (test == false)
		{
			test = h_data_model.check_input_position(this->i_m);
			if (test == false )
			{
				V.import_XY(this->i_m);
			}
		}
		h_data_model.input_M();
		V.show(h_data_model.M);
		start = h_data_model.check_win();
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
		}
		else
		{
			this->i_m[2] = 0;
		}
	}
	c_ini_modle.inport_infor(data_caro, V.player_1, V.player_2, start);
	c_SQL_model.database_MYSQL(V.player_1, V.player_2, start);
	c_ini_modle.outport_infor(data_caro);
	ofstream out_caro1;
	out_caro1.open(replay);
	out_caro1.clear();
	for (int i = 0; i < h_data_model.v1.size(); i++)
	{
		out_caro1 << h_data_model.v1[i];
		if (i != h_data_model.v1.size() - 1)
		{
			out_caro1 << ",";
		}

	}
}

//Play on 2 PC
void Controller::game_mode_on_2_computer()
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
			while (test == false)
			{
				test = h_data_model.check_input_position(this->i_m);
				if (test == false )
				{
					V.import_XY_1(this->i_m);
				}
			}
			h_data_model.input_M();
			V.show(h_data_model.M);
			start = h_data_model.check_win();
			if (start == 0)
			{
				data = "0," + to_string(this->h_data_model.M1[0]) + "," + to_string(this->h_data_model.M1[1]) + ",";
				sendResult = send(clientSocket, data.c_str(), data.size() + 1, 0);
			}
			else if (start == 1)
			{
				data = "1," + to_string(this->h_data_model.M1[0]) + "," + to_string(this->h_data_model.M1[1]) + ",";
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
			this->h_data_model.check_input_position(this->i_m);
			this->h_data_model.input_M();
			V.show(this->h_data_model.M);
			start = this->h_data_model.check_win();
			if (start == 2)
			{
				data = "2,,,";
				send(clientSocket, data.c_str(), data.size() + 1, 0);
				cout << "O WIN" << endl;
				break;

			}

		}
		c_ini_modle.inport_infor(data_caro, V.player_1, V.player_2, start);
		c_SQL_model.database_MYSQL(V.player_1, V.player_2, start);
		c_ini_modle.outport_infor(data_caro);
		// Close the socket
		closesocket(clientSocket);
	}
	else
	{
		bytesReceived1 = recv(clientSocket, buf, 4096, 0);
		string c = string(buf, 0, bytesReceived1);
		cout << c;
		ifstream filein;
		filein.open(data_caro, ios_base::in);

		while (filein.eof() == false)
		{
			this->c_ini_modle.read_file_ini(filein);
			cout << this->c_ini_modle.player.name;
			if (this->c_ini_modle.player.name == c)
			{
				string d = this->c_ini_modle.player.name + "," + this->c_ini_modle.player.thang + "," + c_ini_modle.player.thua + "," + c_ini_modle.player.hoa + "," + c_ini_modle.player.name_thang + "," + c_ini_modle.player.name_thua + "," + c_ini_modle.player.name_hoa + ",";
				sendResult = send(clientSocket, d.c_str(), d.size() + 1, 0);
				break;
			}
		}

	}

	// Cleanup winsock
	WSACleanup();
}
 
//Check information of Player
void Controller::information_of_player(string s)
{
	/*nguoichoi* nc = M.find_infor("caro.ini", s);

	cout << "Information of player:"<<endl;
	cout << "Name:" << nc[0].name << endl;
	cout << "Win:" << nc[0].thang << endl;
	cout << "Loser:" << nc[0].thua << endl;
	cout << "Draw:" << nc[0].hoa << endl;
	cout << "Information of same player:" << endl;
	cout << "Name:" << nc[1].name << endl;
	cout << "Win:" << nc[1].thang << endl;
	cout << "Loser:" << nc[1].thua << endl;
	cout << "Draw:" << nc[1].hoa << endl;*/
	c_SQL_model.read_database_MYSQL(s);

}

//Repaly privious match
void Controller::replay_privious_match()
{
	int i1 = 0;
	h_data_model.read_file_ini_push_vector(replay);
	int i2 = this->h_data_model.v1.size();
	int a[3];
	for (int i = 0;i < i2; i = i+2)
	{
		a[0] = this->h_data_model.v1[i] + 1;
		a[1] = this->h_data_model.v1[i+1] + 1;
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
		h_data_model.check_input_position(a);
		h_data_model.input_M();
		V.show(h_data_model.M);
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
