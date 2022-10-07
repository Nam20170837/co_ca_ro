#pragma once
#include"Model_n.h"
#include"View.h"
class Controller
{
public:
	
	Model_n M;
	View V;
	int i_m[3] = { 0,0,0 };
public:
	void C();
	bool check();
};

