#pragma once
#include"Model_n.h"
#include"View.h"
#include"playerr.h"
#include <chrono>
#include <thread>
#include <WS2tcpip.h>
#include<string>
#pragma comment (lib, "ws2_32.lib")
class Controller
{
public:
	
	Model_n M;
	View V;
	int i_m[3] = { 0,0,0 };
public:
	void C();
	bool check();
	void D(string s);
	void E();
	void C1();
};

