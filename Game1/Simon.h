#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Enemy.h"

#define INVINCIBLE_TIME 2

class Simon : public Enemy
{
private:

	int currentAnimID;
	float simonSpeed;
	int directionX = 0, directionY = 0;
public:
	Simon(int hp, int damage, int point);
	~Simon();

	bool Initialize(LPDIRECT3DDEVICE9 _gDevice, LPCWSTR _file, float _x, float _y, int tag);
	void Render();
	void CreateAnimation();
	void Update(float gameTime);

	void Move();
	void Jump();
	void Sit();
	

	D3DXVECTOR3 GetVelocity();
	void SetVelocity(D3DXVECTOR3 vel) { velocity = vel; }


	bool GetIsLeft() { return isLeft; }
	void SetIsLeft(bool status) { isLeft = status; }

	
	int GetAction() { return action; }
	void SetAction(int action) { this->action = action; }

	bool nextStage;
	
};

