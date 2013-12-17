#pragma once

#include <iostream>
#include <conio.h>
#include <vector>

#include "PlayerData.h"

using namespace std;
extern deque<PlayerData> p1Q;
extern deque<PlayerData> p2Q;
extern deque<PlayerData> playerPos;
class Game
{
private:
	vector<vector<char>> gameField;
	PlayerData dummyData;

public:

	Game()
	{
		vector<char> gameRow;
		gameRow.push_back(char(218));
		for(int i = 0; i < 10; i++)
		{
			gameRow.push_back(char(196));
			gameRow.push_back(char(194));
		}
		gameRow.pop_back();
		gameRow.push_back(char(191));
		gameField.push_back(gameRow);
		gameRow.clear();
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				gameRow.push_back(char(179));
				gameRow.push_back(' ');
			}
			gameRow.push_back(char(179));
			gameField.push_back(gameRow);
			gameRow.clear();
			gameRow.push_back(char(195));
			for(int j = 0; j < 10; j++)
			{
				gameRow.push_back(char(196));
				gameRow.push_back(char(197));
			}
			gameRow.pop_back();
			gameRow.push_back(char(180));
			gameField.push_back(gameRow);
			gameRow.clear();
		}
		gameField.pop_back();
		gameRow.push_back(char(192));
		for(int i = 0; i < 10; i++)
		{
			gameRow.push_back(char(196));
			gameRow.push_back(char(193));
		}
		gameRow.pop_back();
		gameRow.push_back(char(217));
		gameField.push_back(gameRow);
		gameField[9][19] = '2';
		gameField[9][1] = '1';
		this->printGameField();
	}		

	~Game(void)
	{
	}

	void printGameField()
	{
		for(int i = 0; i < gameField.size(); i++)
		{
			for(int j = 0; j < gameField[i].size(); j++)
			{
				cout << gameField[i][j];
			}
			cout << endl;
		}
	}

	void operator () ()
	{
		chrono::milliseconds dura(2000);
		this_thread::sleep_for(dura);
		while(1){
			
			if(_kbhit())
			{
				dummyData.moveKey = this->getPlayerMoveKey();
				dummyData.playerID = this->checkPlayer(dummyData.moveKey);
				if(dummyData.playerID == 1)
					::p1Q.push_back(dummyData);
				else if(dummyData.playerID == 2)
					::p2Q.push_back(dummyData);
			}
			if(::playerPos.size() > 0)
			{
				PlayerData PMD = ::playerPos.front();
				this->setPlayer(PMD);
				::playerPos.pop_front();
				system("CLS");
				this->printGameField();
			}
		}
	}

	char getPlayerMoveKey()
	{
		return _getch();
	}

	int checkPlayer(char moveKey)
	{
		if(moveKey == 'w' || moveKey == 'a' || moveKey == 's' || moveKey == 'd')
			return 1;
		else if(moveKey == 'i' || moveKey == 'k' || moveKey == 'l' || moveKey == 'j')
			return 2;
		else
			return 0;
	}

	void setPlayer(PlayerData pd)
	{
		if(pd.playerID == 1)
		{
			if(gameField[pd.yPos][pd.xPos] != '2')
			{
				gameField[pd.yPrev][pd.xPrev] = ' ';
				gameField[pd.yPos][pd.xPos] = '1';
			}
			else
				gameField[pd.yPos][pd.xPos] = 'X';
		}
		else if(pd.playerID == 2)
		{
			if(gameField[pd.yPos][pd.xPos] != '1')
			{
				gameField[pd.yPrev][pd.xPrev] = ' ';
				gameField[pd.yPos][pd.xPos] = '2';
			}
			else
				gameField[pd.yPos][pd.xPos] = 'X';
		}
	}
};

