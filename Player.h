#pragma once

#include <iostream>

#include "PlayerData.h"

using namespace std;
extern deque<PlayerData> playerPos;
class Player
{
private:
	PlayerData pd;
	PlayerData dummyData;
	deque<PlayerData> *pQ;
public:

	Player(int xPos, int yPos, int id, deque<PlayerData> *pQ)
	{
		this->pQ = pQ;
		this->pd.xPos = this->pd.xPrev = xPos;
		this->pd.yPos = this->pd.yPrev = yPos;
		this->pd.playerID = id;
	}

	~Player(void)
	{
	}

	void operator () ()
	{
		chrono::milliseconds dura(2000);
		this_thread::sleep_for(dura);
		while(1)
		{
			this->pd.xPrev = this->pd.xPos;
			this->pd.yPrev = this->pd.yPos;
			if((*pQ).size() > 0)
			{
				dummyData = (*pQ).front();
				this->setPos();
				(*pQ).pop_front();
				::playerPos.push_back(pd);
			}
		}
	}

	void setPos()
	{
		if(dummyData.moveKey == 'w' || dummyData.moveKey == 'i')
			if((pd.yPos - 2) > 0)
				pd.yPos -= 2;
		if(dummyData.moveKey == 's' || dummyData.moveKey == 'k')
			if((pd.yPos + 2) < 20)
				pd.yPos += 2;
		if(dummyData.moveKey == 'd' || dummyData.moveKey == 'l')
			if((pd.xPos + 2) < 20)
				pd.xPos += 2;
		if(dummyData.moveKey == 'a' || dummyData.moveKey == 'j')
			if((pd.xPos - 2) > 0)
				pd.xPos -= 2;
	}
};

