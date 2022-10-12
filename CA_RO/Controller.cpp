#include "Controller.h"
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
 
void Controller::D(string s)
{
	//nguoichoi* nc = static_cast<nguoichoi*>(M.find_infor("caro.ini",s));
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
