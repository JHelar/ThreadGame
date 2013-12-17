#pragma once

struct PlayerData
{
	char moveKey;
	int playerID;
	int xPos;
	int yPos;
	int xPrev;
	int yPrev;

	PlayerData()
	{
		playerID = 0;
	}
};

