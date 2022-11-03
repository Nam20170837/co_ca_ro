#include "Connect_MySQL_Model.h"
#include<mysql.h>
#include<iostream>

#define password "123456"
#define name_SQL "dtb_caro"

using namespace std;

//Extend infor player into MySQL
void Connect_MySQL_Model::database_MYSQL(string player1, string player2, int x)
{

	string id, name, win, lose, draw, name_win, name_lose, name_draw;
	int dem = 0;
	MYSQL* conn;
	MYSQL_ROW rows;
	MYSQL_RES* res;

	string sqlupdate1, sqlinsert, sqlupdate2, sqlupdate3, sqlupdate4;
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
							sqlupdate1 = "UPDATE test_dtb_caro SET WIN= " + win + " WHERE NAME = '" + name + "'";
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

//Find infor player into MySQL
void Connect_MySQL_Model::read_database_MYSQL(string s)
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
