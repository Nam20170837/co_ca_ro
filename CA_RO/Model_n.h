#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<fstream>
using namespace std;
class Model_n
{
public:
	vector<string> v;
	char M[10][10];
	char M1[3];
	int check_dickens = 0;
	struct nguoichoi
	{
		string name;
		string thang;
		string thua;
		string hoa;
	};
	nguoichoi player;
	bool input_M1(int c_M1[3]);
	void input_M();
	int check_win();
	void read_file(ifstream &in_read);
	void inport_infor(ifstream &in1, string player1, string player2,int x);
	void outport_infor(ofstream& out);
	
};