#ifndef SPRITE_H
#define SPRITE_H

#include <d3dx9.h>
#include <string>
#include "definition.h"

class Sprite
{
private:
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE spriteHandle;

	D3DCOLOR color;
	D3DXVECTOR3 position;
	bool initialized;

	LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 device, LPCWSTR file);
	LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 device, LPCWSTR file, int width, int height);

	float width, height;

public:
	Sprite();
	Sprite(float x, float y);
	~Sprite();

	bool Initialize(LPDIRECT3DDEVICE9 device, LPCWSTR file);
	bool Initialize(LPDIRECT3DDEVICE9 device, LPCWSTR file, int width, int height);
	bool IsInitialized();

	void Render();
	void Render(D3DXVECTOR3 pos, RECT rect);
	void Render(RECT rect, bool isLeft, int width, int height);
	void Render(D3DXVECTOR3 position, D3DCOLOR color);
	void Render(D3DXVECTOR3 position);

	void setColor(D3DCOLOR color) { this->color = color; }

	void SetPosition(float x, float y);

	D3DXVECTOR3 GetPosition();

	void SetPosition(D3DXVECTOR3 _position);

	float GetWidth();
	float GetHeight();

	void SetColor(D3DCOLOR _color) { color = _color; }

};

#endif // !SPRITE_H