#include "GameObject.h"




D3DXVECTOR3 GameObject::GetVelocity()
{
	return D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}



GameObject::GameObject()
{
	sprite = NULL;
}

GameObject::~GameObject()
{
	if (sprite)
	{
		delete(sprite);
	}
}


bool GameObject::Initialize(LPDIRECT3DDEVICE9 _gDevice, LPCWSTR _file, float _x, float _y, int tag)
{
	id = 0;
	

	if (!sprite)
	{
		sprite = new Sprite(_x, _y);
		if (!sprite->Initialize(_gDevice, _file))
			return false;
	}
	
	SetSize(sprite->GetWidth(), sprite->GetHeight());
	SetPosition(sprite->GetPosition());

	return true;
}

bool GameObject::InitSprite(LPDIRECT3DDEVICE9 gDevice, LPCWSTR file, float x, float y)
{
	if (!sprite)
	{
		sprite = new Sprite(x, y);
		if (!sprite->Initialize(gDevice, file))
			return false;
	}
	return true;
}

void GameObject::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void GameObject::SetPosition(D3DXVECTOR3 position)
{
	this->position = position;
}

void GameObject::SetPosition(float x, float y)
{
	sprite->SetPosition(x, y);
}

void GameObject::Render()
{
		sprite->Render();
}

void GameObject::Update(float gameTime)
{

}