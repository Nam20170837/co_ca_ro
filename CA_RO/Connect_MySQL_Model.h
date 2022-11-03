#pragma once
#include<string>
using namespace std;
class Connect_MySQL_Model
{
public:

	//Extend infor player into MySQL
	void database_MYSQL(string player1, string player2, int x); 

	//Find infor player into MySQL
	void read_database_MYSQL(string s);
};

