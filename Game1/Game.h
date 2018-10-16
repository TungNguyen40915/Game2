#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Input.h"
#include "Sprite.h"
#include "Simon.h"
#include "StateManager.h"
#include "GameTime.h"

class Game
{
private:
	Graphics* gDevice;
	DWORD timeStart;
	DWORD timeNow;

	//float gameTime;
	GameTime* gameTime;

	//void TimeHandle();

	StateManager* stateManager;
public:
	Game();
	~Game();

	// game function
	bool Initialize(HWND hWnd, int width, int height);
	void Run(); // will call update and draw
	void Update(float _gameTime);
	void Draw();

};

#endif // !GAME_H


