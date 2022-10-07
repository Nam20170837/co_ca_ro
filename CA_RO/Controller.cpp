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
	ifstream filein;
	filein.open("caro.ini", ios_base::in);
	M.inport_infor(filein,V.player_1,V.player_2, start);
	filein.close();
	ofstream fileout;
	fileout.open("caro.ini");
	M.outport_infor(fileout);
	filein.close();
}
