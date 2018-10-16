#pragma once
#include "Sprite.h"
#include "Graphics.h"

class GameObject
{
private:

	int id;
protected:
	Sprite* sprite;
	float width;
	float height;
	D3DXVECTOR3 position;

public:
	GameObject();
	~GameObject();

	virtual bool Initialize(LPDIRECT3DDEVICE9 gDevice, LPCWSTR file, float x, float y, int tag);
	virtual bool InitSprite(LPDIRECT3DDEVICE9 gDevice, LPCWSTR file, float x, float y);
	virtual void Render();
	virtual void Update(float gameTime);





	virtual D3DXVECTOR3 GetVelocity();



	float GetWidth() { return width; }
	float GetHeight() { return height; }
	D3DXVECTOR3 GetPosition() { return sprite->GetPosition(); }
	void SetSize(float width, float height);
	void SetPosition(D3DXVECTOR3 position);
	void SetPosition(float x, float y);

	void SetID(int id) { this->id = id; }
	int GetID() { return id; }


	void SetColor(D3DCOLOR color) { sprite->SetColor(color); }
};