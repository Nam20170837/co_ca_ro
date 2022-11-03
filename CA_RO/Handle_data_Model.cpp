#include "Handle_data_Model.h"
using namespace std;

//Check the player position enter
bool Handle_data_Model::check_input_position(int c_M1[3])
{
	if (this->M[c_M1[0] - 1][c_M1[1] - 1] != 'X' && this->M[c_M1[0] - 1][c_M1[1] - 1] != 'O')
	{
		this->M1[0] = c_M1[0] - 1;
		this->M1[1] = c_M1[1] - 1;
		this->M1[2] = c_M1[2];
		return true;
	}
	else
	{
		cout << "The position is occupied" << endl;
		return false;
	}
}

void Handle_data_Model::input_M()
{
	if (this->M1[2] == 0)
	{
		this->M[M1[0]][M1[1]] = 'X';
	}
	else
	{
		this->M[M1[0]][M1[1]] = 'O';
	}
	this->v1.push_back(M1[0]);
	this->v1.push_back(M1[1]);
}

void Handle_data_Model::read_file_ini_push_vector(string v)
{
	ifstream in;
	in.open(v);
	while (in.eof() == false)
	{
		string s;
		getline(in, s, ',');
		if (s != "")
		{
			this->v1.push_back(stoi(s));
		}
	}
	in.close();
}
int Handle_data_Model::check_win()
{
	int count_1 = -1;
	int count_2 = -1;
	int count_3 = -1;
	int count_4 = -1;
	int w_x = this->M1[0];
	int w_y = this->M1[1];
	if (this->check_dickens < 100)
	{
		this->check_dickens++;
		if (this->M1[2] == 0)
		{
			for (int i = this->M1[0]; this->M[i][this->M1[1]] == 'X' && i >= 0; i--)
			{
				count_1++;
			}
			for (int i = this->M1[0]; this->M[i][this->M1[1]] == 'X' && i < 10; i++)
			{
				count_1++;
			}
			for (int i = this->M1[1]; this->M[this->M1[0]][i] == 'X' && i >= 0; i--)
			{
				count_2++;
			}
			for (int i = this->M1[1]; this->M[this->M1[0]][i] == 'X' && i < 10; i++)
			{
				count_2++;
			}
			while (M[w_x][w_y] == 'X' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_3++;
				w_x++;
				w_y++;

			}
			w_x = this->M1[0];
			w_y = this->M1[1];
			while (M[w_x][w_y] == 'X' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_3++;
				w_x--;
				w_y--;
			}
			w_x = this->M1[0];
			w_y = this->M1[1];
			while (M[w_x][w_y] == 'X' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_4++;
				w_x++;
				w_y--;

			}
			w_x = this->M1[0];
			w_y = this->M1[1];
			while (M[w_x][w_y] == 'X' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_4++;
				w_x--;
				w_y++;
			}

			if (count_1 > 3 || count_2 > 3 || count_3 > 3 || count_4 > 3)
			{
				return 1;
			}
		}
		else
		{
			for (int i = this->M1[0]; this->M[i][this->M1[1]] == 'O' && i >= 0; i--)
			{
				count_1++;
			}
			for (int i = this->M1[0]; this->M[i][this->M1[1]] == 'O' && i < 10; i++)
			{
				count_1++;
			}
			for (int i = this->M1[1]; this->M[this->M1[0]][i] == 'O' && i >= 0; i--)
			{
				count_2++;
			}
			for (int i = this->M1[1]; this->M[this->M1[0]][i] == 'O' && i < 10; i++)
			{
				count_2++;
			}
			while (M[w_x][w_y] == 'O' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_3++;
				w_x++;
				w_y++;

			}
			w_x = this->M1[0];
			w_y = this->M1[1];
			while (M[w_x][w_y] == 'O' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_3++;
				w_x--;
				w_y--;
			}
			w_x = this->M1[0];
			w_y = this->M1[1];
			while (M[w_x][w_y] == 'O' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_4++;
				w_x++;
				w_y--;

			}
			w_x = this->M1[0];
			w_y = this->M1[1];
			while (M[w_x][w_y] == 'O' && 0 <= w_x && w_x < 10 && 0 <= w_y && w_y < 10)
			{
				count_4++;
				w_x--;
				w_y++;
			}
			if (count_1 > 3 || count_2 > 3 || count_3 > 3 || count_4 > 3)
			{
				return 2;
			}

		}
		return 0;
	}
	else
	{
		return 3;
	}
}
