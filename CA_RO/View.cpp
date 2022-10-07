#include<iostream>
#include "View.h"
#include<iomanip>
#include<string>
using namespace std;

void View::print(string s)
{
	cout << s << endl;
}

void View::show(char c[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		cout << setw(2);
		for (int j = 0; j < 10; j++)
		{
			if (c[i][j] == 'X' || c[i][j] == 'O')
			{
				if (j < 9)
					cout << c[i][j] << setw(2) << "|" << setw(2);
				else
					cout << c[i][j] << setw(2);
			}
			else
			{
				if (j < 9)
					cout << ' ' << setw(2) << "|" << setw(2);
				else
					cout << ' ' << setw(2);
			}
		}
		cout << endl << "---------------------------------------";
		cout << endl;
	}
}


void View::import_XY(int XY[3])
{
	if (XY[2]==0)
	{
		cout << this->player_1 << " turn: " << endl;
		//XY[2] = 0;
		
	}
	else
	{
		cout << this->player_2 << " turn: " << endl;
		//XY[2] = 1;
	}
	cin >> XY[0];
	cin >> XY[1];
}

void View::user()
{
	cout << "Enter the name of Player_1:";
	getline(cin, this->player_1);
	cout << "Enter the name of Player_2:";
	getline(cin, this->player_2);
}




