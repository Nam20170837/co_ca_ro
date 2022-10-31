#pragma once

#include<string>
#include<fstream>
#include<vector>
#include<fstream>
#include"playerr.h"
//#include<mysql.h>
using namespace std;
class Model_n
{
public:
	vector<string> v;
	char M[10][10];
	vector<int> v1;
	char M1[3];
	int check_dickens = 0;
	nguoichoi player;
	bool input_M1(int c_M1[3]);
	void input_M();
	int check_win();
	void read_file(ifstream &in_read);
	void read_file1(string s);
	void inport_infor(string s, string player1, string player2,int x);
	void outport_infor(string s);
	nguoichoi* find_infor(string s,string s1);
	int read_file_caro1(string s);
	void database_MYSQL(string player1, string player2, int x); \
	void read_database_MYSQL(string s);

};