#pragma once
#include "GameState.h"
#include "Simon.h"

class GamePlayStateOne : public GameState
{
private:
	//Simon *simon;
	
	Sprite *sprite;

	LPDIRECT3DDEVICE9 gDevice;

public:
	GamePlayStateOne();
	~GamePlayStateOne();

	bool Initialize(Graphics *graphics);
	void Render();
	void Update(float gameTime);
	void DestroyAll();
	/*
	* Overload tu class cha
	* Set va get gia tri cua $changeState
	*/
	bool GetChangingState();
	void SetChangingState(bool status);
	bool CameraFollowHandle(float gameTime) { return true; }
};

