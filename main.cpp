#include <deque>
#include <thread>

#include "PlayerData.h"
#include "Game.h"
#include "Player.h"

using namespace std;
deque<PlayerData> playerPos;
deque<PlayerData> p1Q;
deque<PlayerData> p2Q;
int main(void)
{
	Game game;
	Player p1(1,9,1,&p1Q);
	Player p2(19,9,2,&p2Q);

	thread gameThread(game);
	thread player1Thread(p1);
	thread player2Thread(p2);
	
	gameThread.join();
	cin.get();
	return 0;
}