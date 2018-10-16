#include "Simon.h"




Simon::Simon(int hp, int damage, int point) : Enemy(hp, damage, point)
{

}


Simon::~Simon()
{
	SAFE_DELETE(anim);
}

bool Simon::Initialize(LPDIRECT3DDEVICE9 _gDevice, LPCWSTR _file, float _x, float _y, int tag)
{
	if (!GameObject::Initialize(_gDevice, _file, _x, _y, tag))
		return false;
	isLeft = false;
	this->CreateAnimation();


	nextStage = false;


	return true;
}

void Simon::CreateAnimation()
{
	anim = new Animation();
	anim->Initialize(sprite, 60.0f, 66.0f, 0.15f);

	// Khoi tao animation dung yen
	std::vector<D3DXVECTOR2> standAnimation;
	standAnimation.push_back(D3DXVECTOR2(0, 0));

	//Khoi tao animation luc roi
	std::vector<D3DXVECTOR2> fallAnimation;
	fallAnimation.push_back(D3DXVECTOR2(0, 0));

	// Khoi tao animation luc di chuyen
	std::vector<D3DXVECTOR2> moveAnimation;
	moveAnimation.push_back(D3DXVECTOR2(0, 0));
	moveAnimation.push_back(D3DXVECTOR2(1, 0));
	moveAnimation.push_back(D3DXVECTOR2(2, 0));
	moveAnimation.push_back(D3DXVECTOR2(3, 0));

	//// Khoi tao animation luc ngoi
	std::vector<D3DXVECTOR2> sitAnimation;
	sitAnimation.push_back(D3DXVECTOR2(4, 0));

	//// Khoi tao animation luc nhay
	std::vector<D3DXVECTOR2> jumpAnimation;
	jumpAnimation.push_back(D3DXVECTOR2(4, 0));

	////Khoi tao animation luc danh roi khi dung
	std::vector<D3DXVECTOR2> hitStandAnimation;
	hitStandAnimation.push_back(D3DXVECTOR2(5, 0));
	hitStandAnimation.push_back(D3DXVECTOR2(6, 0));
	hitStandAnimation.push_back(D3DXVECTOR2(7, 0));

	std::vector<D3DXVECTOR2> throwSubWeapon;
	throwSubWeapon.push_back(D3DXVECTOR2(5, 0));
	throwSubWeapon.push_back(D3DXVECTOR2(6, 0));
	throwSubWeapon.push_back(D3DXVECTOR2(7, 0));

	////Khoi tao animation luc danh roi khi ngoi
	std::vector<D3DXVECTOR2> hitSitAnimation;
	hitSitAnimation.push_back(D3DXVECTOR2(7, 1));
	hitSitAnimation.push_back(D3DXVECTOR2(0, 2));
	hitSitAnimation.push_back(D3DXVECTOR2(1, 2));

	std::vector<D3DXVECTOR2> goUpStair;
	goUpStair.push_back(D3DXVECTOR2(4, 1));
	goUpStair.push_back(D3DXVECTOR2(5, 1));

	std::vector<D3DXVECTOR2> goDownStair;
	goDownStair.push_back(D3DXVECTOR2(2, 1));
	goDownStair.push_back(D3DXVECTOR2(3, 1));

	std::vector<D3DXVECTOR2> hitUpStair;
	hitUpStair.push_back(D3DXVECTOR2(5, 2));
	hitUpStair.push_back(D3DXVECTOR2(6, 2));
	hitUpStair.push_back(D3DXVECTOR2(7, 2));

	std::vector<D3DXVECTOR2> hitDownStair;
	hitDownStair.push_back(D3DXVECTOR2(2, 2));
	hitDownStair.push_back(D3DXVECTOR2(3, 2));
	hitDownStair.push_back(D3DXVECTOR2(4, 2));

	// Khoi tao animation nhay lui
	std::vector<D3DXVECTOR2> hurtedAnimation;
	hurtedAnimation.push_back(D3DXVECTOR2(0, 1));

	std::vector<D3DXVECTOR2> deadAnimation;
	deadAnimation.push_back(D3DXVECTOR2(4, 3));

	//Khoi tao animation dung yen khi dang len cau thang
	std::vector<D3DXVECTOR2> standingUpStairAnimation;
	standingUpStairAnimation.push_back(D3DXVECTOR2(4, 1));

	//Khoi tao animation dung yen khi di xuong cau thang
	std::vector<D3DXVECTOR2> standingDownStairAnimation;
	standingDownStairAnimation.push_back(D3DXVECTOR2(2, 1));

	std::vector<D3DXVECTOR2> invisibleAnimation;
	invisibleAnimation.push_back(D3DXVECTOR2(3, 4));

	std::vector<D3DXVECTOR2> eatItemAnimation;
	eatItemAnimation.push_back(D3DXVECTOR2(0, 3));
	eatItemAnimation.push_back(D3DXVECTOR2(1, 3));
	eatItemAnimation.push_back(D3DXVECTOR2(2, 3));

	std::vector<D3DXVECTOR2> standBack;
	standBack.push_back(D3DXVECTOR2(1, 1));

	// Them cac animation
	anim->AddAnimation(STAND, standAnimation);
	anim->AddAnimation(MOVE, moveAnimation);
	anim->AddAnimation(SIT, sitAnimation);
	anim->AddAnimation(JUMP, jumpAnimation);
	anim->AddAnimation(HIT_STAND, hitStandAnimation);
	anim->AddAnimation(HIT_SIT, hitSitAnimation);
	anim->AddAnimation(FALL_DOWN, fallAnimation);
	anim->AddAnimation(UP_STAIR, goUpStair);
	anim->AddAnimation(DOWN_STAIR, goDownStair);
	anim->AddAnimation(HURTED, hurtedAnimation);
	anim->AddAnimation(STANDING_UP, standingUpStairAnimation);
	anim->AddAnimation(STANDING_DOWN, standingDownStairAnimation);
	anim->AddAnimation(THROW_SUB_WEAPON, throwSubWeapon);
	anim->AddAnimation(HIT_UP_STAIR, hitUpStair);
	anim->AddAnimation(HIT_DOWN_STAIR, hitDownStair);
	anim->AddAnimation(DEAD, deadAnimation);
	anim->AddAnimation(INVISIBLE, invisibleAnimation);
	anim->AddAnimation(EAT_ITEM, eatItemAnimation);
	anim->AddAnimation(STAND_BACK, standBack);

	action = STAND;
}

void Simon::Update(float gameTime)
{

	GravityHandle(gameTime);

	sprite->SetPosition(sprite->GetPosition().x + velocity.x * gameTime,
		sprite->GetPosition().y + velocity.y  * gameTime);

	anim->DoAnimation(action);
	anim->Update(gameTime);


}

void Simon::Render()
{
	anim->Render(sprite, isLeft);
}

D3DXVECTOR3 Simon::GetVelocity()
{
	return velocity;
}

void Simon::Move()
{
	action = MOVE;
	velocity.x = ((isLeft) ? -1 : 1) * simonSpeed;
}

void Simon::Jump()
{
	velocity.y = JUMP_FORCE;
}

void Simon::Sit()
{
	velocity.x = 0;
	velocity.y = 0;
}
