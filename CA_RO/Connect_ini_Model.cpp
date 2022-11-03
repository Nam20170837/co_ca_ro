#include "Connect_ini_Model.h"
#include<iostream>
using namespace std;

//Read information of win,lose,draw of player
void Connect_ini_Model::read_file_ini(ifstream& in_read)
{
	getline(in_read, this->player.name, ',');
	getline(in_read, this->player.thang, ',');
	getline(in_read, this->player.thua, ',');
	getline(in_read, this->player.hoa, ',');
	getline(in_read, this->player.name_thang, ',');
	getline(in_read, this->player.name_thua, ',');
	getline(in_read, this->player.name_hoa, ',');
	string temp;
	getline(in_read, temp);
}

//Push information of win,lose,draw into vector
void Connect_ini_Model::inport_infor(string str, string player1, string player2, int x)
{
	ifstream in1;
	in1.open(str, ios_base::in);
	int dem = 0;
	string s;
	while (in1.eof() == false)
	{
		this->read_file_ini(in1);
		if (dem != 3 && (this->player.name == player1 || this->player.name == player2))
		{
			int v;
			if (this->player.name == player1)
			{
				dem++;
				switch (x)
				{
				case 1:
					v = (stoi(this->player.thang)) + 1;
					this->player.thang = to_string(v);
					if (this->player.name_thang == "")
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
				s = this->player.name + "," + this->player.thang + "," + this->player.thua + "," + this->player.hoa + "," + this->player.name_thang + "," + this->player.name_thua + "," + this->player.name_hoa + "," + "\n";
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
					if (this->player.name_thang == "")
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

//Push information of win,lose,draw into ini
void Connect_ini_Model::outport_infor(string str)
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

//Find info player
nguoichoi* Connect_ini_Model::find_infor(string s, string s1)
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
	filein1.open(s, ios::in);
	if (d1 != -1)
	{
		while (filein1.eof() == false)
		{
			this->read_file_ini(filein1);
			d2 = stoi(this->player.thang) / (stoi(this->player.thang) + stoi(this->player.thua) + stoi(this->player.hoa));
			if ((abs(d2 - d1) < d3 || d3 == -1) && this->player.name != "" && this->player.name != s1)
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
		cout << "Can't find player info" << endl;
	}
	filein1.close();
	return pl1;
}
