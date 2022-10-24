#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include <WS2tcpip.h>
#include"View.h"
#include"Model_n.h"
#include"Controller.h"
#pragma comment (lib, "ws2_32.lib")
using namespace std;
void creat1()
{
	Controller nam;
	nam.C();
}

void creat2()
{
	Controller nam;
	string name;
	cout << "Enter the name:";
	cin.ignore();
	getline(cin, name);
	nam.D(name);
}

void creat4()
{
	Controller nam;
	nam.E();
}
void creat5()
{
	Controller nam;
	nam.C1();
}

int main()
{ 
	int chosse = 0;
	do
	{
		cout << "NHAP LUA CHON" << endl;
		cout << "1: CHOI TIEP" << endl;
		cout << "2: XUAT THONG TIN" << endl;
		cout << "3: DUNG CHOI" << endl;
		cout << "4: IN TRAN DAU TRUOC"<<endl;
		cout << "5: CHOI HAI NGUOI" << endl;
		cin >> chosse;
		if (chosse == 1)
		{
			creat1();
		}
		else if (chosse == 2)
		{
			creat2();
		}
		else if (chosse == 4)
		{
			creat4();
		}
		else if (chosse == 3)
		{
			break;
		}
		else if (chosse == 5)
		{
			creat5();
			
		}
	} while (chosse != 3);

	//t1();
	return 0;
}