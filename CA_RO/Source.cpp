#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include <WS2tcpip.h>
#include"Controller.h"
#pragma comment (lib, "ws2_32.lib")
using namespace std;
void start()
{
	Controller nam;
	nam.game_mode_on_1_computer();
}

void pri_infor()
{
	Controller nam;
	string name;
	cout << "Enter the name:";
	cin.ignore();
	getline(cin, name);
	nam.information_of_player(name);
}

void review_of_before_game()
{
	Controller nam;
	nam.replay_privious_match();
}

void play_online()
{
	Controller nam;
	nam.game_mode_on_1_computer();
}

int main()
{ 
	int chosse = 0;
	do
	{
		cout << "ENTER YOUR SELCTION:" << endl;
		cout << "[1]: START" << endl;
		cout << "[2]: PRINT YOUR INFORMATION" << endl;
		cout << "[3]: STOP" << endl;
		cout << "[4]: REVIEW OF BEFORE GAME"<<endl;
		cout << "[5]: PLAY ONLINE" << endl;
		cin >> chosse;
		if (chosse == 1)
		{
			start();
		}
		else if (chosse == 2)
		{
			pri_infor();
		}
		else if (chosse == 4)
		{
			review_of_before_game();
		}
		else if (chosse == 3)
		{
			break;
		}
		else if (chosse == 5)
		{
			play_online();
			
		}
	} while (chosse != 3);

	return 0;
}
