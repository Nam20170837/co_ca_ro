#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include <WS2tcpip.h>
#include"View.h"
#include"Model_n.h"
#include"Controller.h"
#include<mysql.h>
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

	return 0;
}


//#include<iostream>
//#include<iomanip>
//#include<string>
//#include<fstream>
//#include <WS2tcpip.h>
//#include"View.h"
//#include"Model_n.h"
//#include"Controller.h"
//#include<mysql.h>
//using namespace std;
//int qstate;
//
//int main()
//{
//	MYSQL* conn;
//	MYSQL_ROW row;
//	MYSQL_RES* res;
//	conn = mysql_init(0);
//
//	conn = mysql_real_connect(conn, "localhost", "root", "123456", "testdb", 3306, NULL, 0);
//	//INSERT INTO test(id, name, score) VALUES(1, "Marianne", 89);
//	if (conn) {
//		puts("Successful connection to database!");
//
//		string query = "SELECT * FROM test";
//		const char* q = query.c_str();
//		qstate = mysql_query(conn, q);
//		if (!qstate)
//		{
//			res = mysql_store_result(conn);
//			while (row = mysql_fetch_row(res))
//			{
//				printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
//			}
//		}
//		else
//		{
//			cout << "Query failed: " << mysql_error(conn) << endl;
//		}
//	}
//	else {
//		puts("Connection to database has failed!");
//	}
//	string insert_query = "insert into userreservation_tb (u_name, u_phone, u_passportno, u_ticket, u_flightno, u_address) values ('" + userName + "','" + userPhone + "','" + userPassportNo + "','" + userTicket + "','" + userFlightNo + "','" + userAddress + "')";
//
//	return 0;
//}