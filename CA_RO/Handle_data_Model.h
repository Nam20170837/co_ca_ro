#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
class Handle_data_Model
{
public:
	char M[10][10];
	char M1[3];
	int check_dickens = 0;
	vector <int> v1;

	void input_M();
	bool check_input_position(int c_M1[3]);
	int check_win();
	void read_file_ini_push_vector(string s);
};

