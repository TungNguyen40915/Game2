#include "Enemy.h"



Enemy::Enemy(int _hp, int _damage, int _point)
{
	isGravity = true;
	isGrounded = false;
	this->isLeft = false;
}


Enemy::~Enemy()
{
	if (anim)
	{
		delete(anim);
		anim = NULL;
	}
}



bool Enemy::Initialize(LPDIRECT3DDEVICE9 gDevice, LPCWSTR file, float x, float y, int tag)
{
	return GameObject::Initialize(gDevice, file, x, y, tag);
}





void Enemy::Render()
{
	anim->Render(sprite, isLeft);
}

void Enemy::Update(float gameTime)
{
	sprite->SetPosition(sprite->GetPosition().x + velocity.x * gameTime,
		sprite->GetPosition().y + velocity.y  * gameTime);

	anim->DoAnimation(action);
	anim->Update(gameTime);
}

void Enemy::GravityHandle(float gameTime)
{
	velocity.y += EARTH_ACCELERATION * gameTime;
}
