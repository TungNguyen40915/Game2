#pragma once
#include "GameObject.h"
#include "Animation.h"

#define E_INVINCIBLE_TIME 0.4

class Enemy : public GameObject
{
protected:
	Animation *anim;
	D3DXVECTOR3 velocity;

	float acceleration;

	int action;
	bool isLeft;



	bool isGravity;
	bool isGrounded;


public:

	Enemy() {}
	Enemy(int hp, int damage, int point);
	~Enemy();

	virtual bool Initialize(LPDIRECT3DDEVICE9 gDevice, LPCWSTR file, float x, float y, int tag);
	virtual void Render();
	virtual void Update(float gameTime);

	void GravityHandle(float gameTime);

	
};

