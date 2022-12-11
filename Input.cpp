#include "Input.h"
#include "DxLib.h"

Input* Input::GetInstance()
{
	static Input instance;
	return &instance;
}

void Input::Destroy()
{
	delete Input::GetInstance();
}

void Input::Update()
{
	//	‘OƒtƒŒ[ƒ€‚Ìî•ñæ“¾
	for (size_t i = 0; i < sizeof(key); i++)
	{
		prev[i] = key[i];
	}

	GetHitKeyStateAll(key);
	prevMouse = mouse;
	mouse = GetMouseInput();
	GetMousePoint(&MouseX, &MouseY);
}

bool Input::GetKey(int _key)
{
	return key[_key];
}

bool Input::GetTrigger(int _key)
{
	return key[_key] && !prev[_key];
}

bool Input::ReleaseKey(int _key)
{
	return prev[_key] && !key[_key];
}
