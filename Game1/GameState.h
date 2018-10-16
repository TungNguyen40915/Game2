#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <fstream>
#include <vector>
#include "Simon.h"

static int score;

class GameState
{
	float simonDeadTime = 1.5;

protected:

	std::vector<GameObject*> *listObject;

	bool changeState;
	float time;
	D3DXVECTOR3 simonCheckpoint;
	D3DXVECTOR3 cameraCheckpoint;

	bool canUseKeyboard;
	static Simon* simon;

	float timeKillAll;
	bool choose;
	Graphics *graphics;
public:
	int state;

	GameState() {}
	~GameState() {}
	//virtual bool Initialize(LPDIRECT3DDEVICE9 gDevice) = 0;
	virtual bool Initialize(Graphics *graphics) = 0;
	virtual void Render() {};
	virtual void Update(float gameTime);
	virtual void DestroyAll() = 0;

	/*
	* 2 cai nay dung de chuyen scene
	*/
	virtual bool GetChangingState() { return changeState; };
	virtual void SetChangingState(bool status) { changeState = status; }

};

#endif __GAMESTATE_H__
