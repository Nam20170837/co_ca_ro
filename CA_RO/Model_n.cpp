#include "Model_n.h"
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<mysql.h>

#define password "123456"
#define name_SQL "dtb_caro"

//#include<stdio.h>
using namespace std;
bool Model_n::check_input_position(int c_M1[3])
{
	if (0 < c_M1[0] && c_M1[0] < 11 && 0 < c_M1[1] && c_M1[1] < 11)
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
			cout << "The position is unoccupied" << endl;
			return false;
		}
	}
	else
	{
		cout << "The position is not suitable!!!" << endl;
		return false;
	}
	
}

void Model_n::input_M()
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

int Model_n:: check_win()
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

void Model_n::read_file_ini(ifstream &in_read)
{
	getline(in_read, this->player.name,',');
	getline(in_read, this->player.thang,',');
	getline(in_read, this->player.thua,',');
	getline(in_read, this->player.hoa,',');
	getline(in_read, this->player.name_thang, ',');
	getline(in_read, this->player.name_thua, ',');
	getline(in_read, this->player.name_hoa, ',');
	string temp;
	getline(in_read, temp);
}

void Model_n::read_file_ini_push_vector(string v)
{
	ifstream in;
	in.open(v);
	while (in.eof() == false)
	{
		string s;
		getline(in, s, ',');
		//int i = stoi(s);
		if (s != "")
		{
			this->v1.push_back(stoi(s));
		}
	}
	in.close();

}

void Model_n::inport_infor(string str, string player1, string player2,int x)
{
	ifstream in1;
	in1.open(str, ios_base::in);
	int dem = 0;
	string s;
	while (in1.eof() == false )
	{
		//cout << "nam" << endl;
		this->read_file_ini(in1);
		if (dem != 3 &&(this->player.name == player1 || this->player.name == player2))
		{
			//cout << "a" << endl;
			int v;
			if (this->player.name == player1)
			{
				dem++;
				switch (x)
				{
				case 1:
					v = (stoi(this->player.thang))+1;
					this->player.thang = to_string(v);
					if(this->player.name_thang == "")
						this->player.name_thang = player2;
					else
						this->player.name_thang = this->player.name_thang + "-" + player2;
					break;
				case 2:
					v = (stoi(this->player.thua)) + 1;
					this->player.thua = to_string(v);
					if (this->player.name_thua == "")
						this->player.name_thua = player2;
					else
						this->player.name_thua = this->player.name_thua + "-" + player2;
					break;
				case 3:
					v = (stoi(this->player.hoa)) + 1;
					this->player.hoa = to_string(v);
					if (this->player.name_hoa == "")
						this->player.name_hoa = player2;
					else
						this->player.name_hoa = this->player.name_hoa + "-" + player2;
					break;
				}
				s = this->player.name + "," + this->player.thang + "," + this->player.thua + "," + this->player.hoa + ","+this->player.name_thang + "," + this->player.name_thua + "," + this->player.name_hoa + "," +"\n";
				this->v.push_back(s);
			}
			else
			{
				dem = dem + 2;
				switch (x)
				{
				case 2:
					v = (stoi(this->player.thang)) + 1;
					this->player.thang = to_string(v);
					if(this->player.name_thang == "")
						this->player.name_thang = player1;
					else
						this->player.name_thang = this->player.name_thang + "-" + player1;
					
					break;
				case 1:
					v = (stoi(this->player.thua)) + 1;
					this->player.thua = to_string(v);
					if (this->player.name_thua == "")
						this->player.name_thua = player1;
					else
						this->player.name_thua = this->player.name_thua + "-" + player1;
					break;
				case 3:
					v = (stoi(this->player.hoa)) + 1;
					this->player.hoa = to_string(v);
					if (this->player.name_hoa == "")
						this->player.name_hoa = player1;
					else
						this->player.name_hoa = this->player.name_hoa + "-" + player1;
					break;
				}
				s = this->player.name + "," + this->player.thang + "," + this->player.thua + "," + this->player.hoa + "," + this->player.name_thang + "," + this->player.name_thua + "," + this->player.name_hoa + "," + "\n";
				this->v.push_back(s);
			}
		}
		else
		{
			s = this->player.name + "," + this->player.thang + "," + this->player.thua + "," + this->player.hoa + "," + this->player.name_thang + "," + this->player.name_thua + "," + this->player.name_hoa + "," + "\n";
			if (this->player.name != "")
			{
				this->v.push_back(s);
			}
		}
		//cout << "dem = " << dem << endl;
	}
	switch (dem)
	{
	case 0:
		switch (x)
		{
		case 1:
			s = player1 + ",1,0,0," + player2 + ",,,\n";
			this->v.push_back(s);
			s = player2 + ",0,1,0," + "," + player1 + ",,\n";
			this->v.push_back(s);
			break;
		case 2:
			s = player2 + ",1,0,0," + player1 + ",,,\n";
			this->v.push_back(s);
			s = player1 + ",0,1,0," + "," + player2 + ",,\n";
			this->v.push_back(s);
			break;
		case 3:
			s = player1 + ",0,0,1,,," + player2 + ",";
			this->v.push_back(s);
			s = player2 + ",0,0,1,,," + player1 + ",";
			this->v.push_back(s);
			break;
		}
		break;
	case 1:
		switch (x)
		{
		case 1:
			s = player2 + ",0,1,0," + "," + player1 + ",,\n";
			this->v.push_back(s);
			break;
		case 2:
			s = player2 + ",1,0,0," + player1 + ",,,\n";
			this->v.push_back(s);
			break;
		case 3:
			s = player2 + ",0,0,1,,," + player1 + ",";
			this->v.push_back(s);
			break;
		}
		break;
	case 2:
		switch (x)
		{
		case 1:
			s = player1 + ",1,0,0," + player2 + ",,,\n";
			this->v.push_back(s);
			break;
		case 2:
			s = player1 + ",0,1,0," + "," + player2 + ",,\n";
			this->v.push_back(s);
			break;
		case 3:
			s = player1 + ",0,0,1,,," + player2 + ",";
			this->v.push_back(s);
			break;
		}
		break;
	}
	in1.close();
}

void Model_n::outport_infor(string str)
{
	ofstream in1;
	in1.open(str, ios_base::out);
	int a = this->v.size();
	//cout << this->v.size();
	for (int i = 0; i < a; i++)
	{
		in1 << this->v[i];
	}
	in1.close();
}

nguoichoi* Model_n::find_infor(string s, string s1)
{
	ifstream filein;
	filein.open(s, ios_base::in);
	nguoichoi* pl1 = new nguoichoi[2];
	//nguoichoi pl1[2];
	double d1, d2, d3;
	d3 = -1;
	d1 = -1;

		while (filein.eof() == false)
		{
			this->read_file_ini(filein);
			if (this->player.name == s1)
			{
				pl1[0].name = this->player.name;
				pl1[0].thang = this->player.thang;
				pl1[0].thua = this->player.thua;
				pl1[0].hoa = this->player.hoa;
				d1 = stoi(pl1[0].thang) / (stoi(pl1[0].thang) + stoi(pl1[0].thua) + stoi(pl1[0].hoa));
			}
		}
	filein.close();
	ifstream filein1;
	filein1.open(s,ios::in);
	if(d1 != -1)
	{
		while (filein1.eof() == false)
		{
			this->read_file_ini(filein1);
				d2 = stoi(this->player.thang) / (stoi(this->player.thang) + stoi(this->player.thua) + stoi(this->player.hoa));
				if ((abs(d2 - d1) < d3 || d3 == -1) && this->player.name != ""&& this->player.name != s1)
				{
					pl1[1].name = this->player.name;
						pl1[1].thang = this->player.thang;
						pl1[1].thua = this->player.thua;
						pl1[1].hoa = this->player.hoa;
						d3 = abs(d2 - d1);
				}
		}
	}
	else
	{
		cout << "KHONG TIM THAY" << endl;
	}
	filein1.close();
	return pl1;
}

int Model_n::read_file_caro1(string s)
{
	return 0;
}

void Model_n::database_MYSQL(string player1,string player2,int x)
{

	string id,name,win,lose,draw,name_win,name_lose,name_draw;
	int dem = 0;
	MYSQL* conn;
	MYSQL_ROW rows;
	MYSQL_RES* res;

	string sqlupdate1,sqlinsert,sqlupdate2, sqlupdate3, sqlupdate4;
	sqlupdate1 = "";
	sqlupdate2 = "";
	sqlupdate3 = "";
	sqlupdate4 = "";
	const char* n;

	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", password, name_SQL, 3306, NULL, 0);
	if (conn)
	{
		
		int qstate;
		string query = "SELECT * FROM test_dtb_caro";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (rows = mysql_fetch_row(res))
			{
				//id = rows[0];
				name = rows[0];
				win = rows[1];
				lose = rows[2];
				draw = rows[3];
				name_win = rows[4];
				name_lose = rows[5];
				name_draw = rows[6];
				if (dem != 3 && (name == player1 || name == player2))
				{
					if (name == player1)
					{
						dem++;
						switch (x)
						{
						case 1:
							win = to_string(stoi(win) + 1);
							sqlupdate1 = "UPDATE test_dtb_caro SET WIN= " + win + " WHERE NAME = '" + name+"'";
							n = sqlupdate1.c_str();
							mysql_query(conn, n);
							if (name_win == "")
							{
								name_win = player2;
							}
							else
							{
								name_win = name_win + "-" + player2;
							}
							sqlupdate1 = "UPDATE test_dtb_caro SET NAME_WIN = '" + name_win + "' WHERE NAME = '" + name + "'";
							n = sqlupdate1.c_str();
							mysql_query(conn, n);
							break;
						case 2:
							lose = to_string(stoi(lose) + 1);
							sqlupdate1 = "UPDATE test_dtb_caro SET WIN= " + lose + " WHERE NAME= '" + name + "'";
							n = sqlupdate1.c_str();
							mysql_query(conn, n);
							if (name_lose == "")
							{
								name_lose = player2;
							}
							else
							{
								name_lose += "-" + player2;
							}
							sqlupdate1 = "UPDATE test_dtb_caro SET NAME_WIN='" + name_lose + "' WHERE NAME ='" + name + "'";
							n = sqlupdate1.c_str();
							mysql_query(conn, n);
							break;
						case 3:
							draw = to_string(stoi(draw) + 1);
							sqlupdate1 = "UPDATE test_dtb_caro SET WIN=" + draw + " WHERE NAME= '" + name + "'";
							n = sqlupdate1.c_str();
							mysql_query(conn, n);
							if (name_draw == "")
							{
								name_draw = player2;
							}
							else
							{
								name_draw += "-" + player2;
							}
							sqlupdate1 = "UPDATE test_dtb_caro SET NAME_WIN='" + name_draw + "' WHERE NAME ='" + name + "'";
							n = sqlupdate1.c_str();
							mysql_query(conn, n);
							break;
						}

					}
					else
					{
						dem += 2;
						switch (x)
						{
						case 2:
							win = to_string(stoi(win) + 1);
							sqlupdate2 = "UPDATE test_dtb_caro SET WIN=" + win + " WHERE NAME = '" + name + "'";
							n = sqlupdate2.c_str();
							mysql_query(conn, n);
							if (name_win == "")
							{
								name_win = player1;
							}
							else
							{
								name_win = "-" + player1;
							}
							sqlupdate2 = "UPDATE test_dtb_caro SET NAME_WIN='" + name_win + "' WHERE NAME ='" + name + "'";
							n = sqlupdate2.c_str();
							mysql_query(conn, n);
							break;

						case 1:
							lose = to_string(stoi(lose) + 1);
							sqlupdate2 = "UPDATE test_dtb_caro SET WIN=" + lose + " WHERE NAME= '" + name + "'";
							n = sqlupdate2.c_str();
							mysql_query(conn, n);
							if (name_lose == "")
							{
								name_lose = player1;
							}
							else
							{
								name_lose += "-" + player1;
							}
							sqlupdate2 = "UPDATE test_dtb_caro SET NAME_WIN='" + name_lose + "' WHERE NAME ='" + name + "'";
							n = sqlupdate2.c_str();
							mysql_query(conn, n);
							break;
						case 3:
							draw = to_string(stoi(draw) + 1);
							sqlupdate2 = "UPDATE test_dtb_caro SET WIN=" + draw + " WHERE NAME= '" + name + "'";
							n = sqlupdate2.c_str();
							mysql_query(conn, n);
							if (name_draw == "")
							{
								name_draw = player1;
							}
							else
							{
								name_draw += "-" + player1;
							}
							sqlupdate2 = "UPDATE test_dtb_caro SET NAME_WIN='" + name_draw + "' WHERE NAME ='" + name + "'";
							n = sqlupdate2.c_str();
							mysql_query(conn, n);
							break;
						}
					}

				}
				

			}
			switch (dem)
			{
			case 0:
				switch (x)
				{
				case 1:
					cout << endl << "no no no" << endl;
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player1 + "', 1, 0, 0, '" + player2 + "', '', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player2 + "', 0, 1, 0, '', '" + player1 + "', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;

				case 2:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player2 + "', 1, 0, 0, '" + player1 + "', '', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player1 + "', 0, 1, 0, '', '" + player2 + "', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;

				case 3:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player2 + "', 0, 0, 1, '', '' , '" + player1 + "')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player1 + "', 0, 0, 1, '', '' , '" + player2 + "')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;
				}
				break;
			case 1:
				switch (x)
				{
				case 1:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player2 + "', 1, 0, 0, '', '" + player1 + "', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;

				case 2:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player2 + "', 0, 1, 0, '" + player1 + "', '', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;

				case 3:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player2 + "', 0, 0, 1, '', '', '" + player1 + "')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;
				}
				break;
			case 2:
				switch (x)
				{
				case 1:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player1 + "', 1, 0, 0, '" + player2 + "', '', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;
				case 2:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player1 + "', 0, 1, 0, '', '" + player2 + "', '')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;
				case 3:
					sqlinsert = "INSERT INTO test_dtb_caro(NAME, WIN, LOSE, DRAW, NAME_WIN, NAME_LOSE, NAME_DRAW) VALUES('" + player1 + "', 0, 0, 1, '', '', '" + player2 + "')";
					n = sqlinsert.c_str();
					mysql_query(conn, n);
					break;
				}
				break;
			}
			mysql_close(conn);
		}
		else
		{
			cout << "QUERY FAILDED" << endl;
		}
		
	}
	else
	{
		cout << "CONNECT TO DATABASE HAS FAILED" << endl;
	}

}

void Model_n::read_database_MYSQL(string s)
{
	string id, name, win, lose, draw, name_win, name_lose, name_draw;
	double d = -1;
	MYSQL* conn;
	MYSQL_ROW rows;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "123456", "dtb_caro", 3306, NULL, 0);
	if (conn)
	{
		int qstate;
		string query = "SELECT * FROM test_dtb_caro";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (rows = mysql_fetch_row(res))
			{
				//id = rows[0];
				name = rows[0];
				win = rows[1];
				lose = rows[2];
				draw = rows[3];
				name_win = rows[4];
				name_lose = rows[5];
				name_draw = rows[6];
				if (s == name)
				{
					cout << "Information of player:" << endl;
					cout << "Name:" << name << endl;
					cout << "Win:" << win << endl;
					cout << "Loser:" << lose << endl;
					cout << "Draw:" << draw << endl;
					cout << "Name_Win:" << name_win << endl;
					cout << "Name_Lose:" << name_lose << endl;
					cout << "Name_Draw:" << name_draw << endl;
					d = stoi(win) / (stoi(win) + stoi(lose) + stoi(draw));
					break;
				}
			}
			mysql_close(conn);
		}
		else
		{
			cout << "QUERY FAILDED" << endl;
		}
	}
	else
	{
		cout << "CONNECT TO DATABASE HAS FAILED" << endl;
	}

	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "123456", "dtb_caro", 3306, NULL, 0);
	if (conn)
	{
		int qstate;
		string query = "SELECT * FROM test_dtb_caro";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (rows = mysql_fetch_row(res))
			{
				//id = rows[0];
				if (d < (stoi(rows[1]) / (stoi(rows[1]) + stoi(rows[2]) + stoi(rows[3]))))
				{
					name = rows[0];
					win = rows[1];
					lose = rows[2];
					draw = rows[3];
					name_win = rows[4];
					name_lose = rows[5];
					name_draw = rows[6];
					break;
					
				}
			}
			cout << "Information of same player:" << endl;
			cout << "Name:" << name << endl;
			cout << "Win:" << win << endl;
			cout << "Loser:" << lose << endl;
			cout << "Draw:" << draw << endl;
			cout << "Name_Win:" << name_win << endl;
			cout << "Name_Lose:" << name_lose << endl;
			cout << "Name_Draw:" << name_draw << endl;
			mysql_close(conn);
		}
		else
		{
			cout << "QUERY FAILDED" << endl;
		}
	}
	else
	{
		cout << "CONNECT TO DATABASE HAS FAILED" << endl;
	}
}



