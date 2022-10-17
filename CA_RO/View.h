#pragma once
#include<string>
using namespace std;
class View
{
public:
	string player_1;
	string player_2;
	void show(char c[10][10]);
	void import_XY(int XY[3]);
	void import_XY_1(int XY[3]);
	void user();
	void user1();
	void print(string s);
};
//int View::a = 0;




