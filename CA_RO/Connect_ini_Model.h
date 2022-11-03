#pragma once
#include<fstream>
#include<string>
#include<vector>
#include"playerr.h"
using namespace std;
class Connect_ini_Model
{public:
	vector<string> v;
	//vector<int> v1;
	nguoichoi player;
	void input_M();

	//Read information of win,lose,draw of player
	void read_file_ini(ifstream& in_read);

	//void read_file_ini_push_vector(string s, vector<int> vec);
	void inport_infor(string s, string player1, string player2, int x);

	//Push information of win,lose,draw into ini
	void outport_infor(string s);

	//Find info player
	nguoichoi* find_infor(string s, string s1);
};

