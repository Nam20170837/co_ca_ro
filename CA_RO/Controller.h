#pragma once
//#include"Model_n.h"
#include"View.h"
#include"playerr.h"
#include <chrono>
#include <thread>
#include <WS2tcpip.h>
#include<string>
#include "Connect_ini_Model.h"
#include "Connect_MySQL_Model.h"
#include "Handle_data_Model.h"
#pragma comment (lib, "ws2_32.lib")
class Controller
{
public:
	
	//Model_n M;
	View V;
	Connect_ini_Model c_ini_modle;
	Connect_MySQL_Model c_SQL_model;
	Handle_data_Model h_data_model;
	int i_m[3] = { 0,0,0 };

	//Play on 1 PC
	void game_mode_on_1_computer();

	//Play on 2 PC
	void information_of_player(string s);

	//Check information of Player
	void replay_privious_match();

	//Repaly privious match
	void game_mode_on_2_computer();
};

