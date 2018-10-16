#include "GamePlayStateOne.h"



GamePlayStateOne::GamePlayStateOne()
{
}


GamePlayStateOne::~GamePlayStateOne()
{
}

bool GamePlayStateOne::Initialize(Graphics *graphics)
{
	this->gDevice = graphics->GetDevice();
	sprite = new Sprite();	
//	if (!sprite->Initialize(gDevice, L"Resource\\sprites\\lv1.s"))
//		return false;

	simon->Initialize(gDevice, SIMON_SPRITE, 50.0f, 10.0f,TAG_SIMON);
	simon->SetPosition(100, 150);
	changeState = false;
	time = 0;

	return true;
}


void GamePlayStateOne::Update(float gameTime)
{
	time += gameTime;

	
	
	simon->Update(gameTime);
	

}

void GamePlayStateOne::Render()
{
	
	simon->Render();


}

bool GamePlayStateOne::GetChangingState()
{
	return GameState::GetChangingState();
}

void GamePlayStateOne::SetChangingState(bool status)
{
	GameState::SetChangingState(status);
}

void GamePlayStateOne::DestroyAll()
{
}