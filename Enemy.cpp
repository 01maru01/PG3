#include "Enemy.h"
#include "DxLib.h"
#include "main.h"
#include "Input.h"

bool Enemy::isAlive = true;
const int Enemy::maxHP = 5;

Enemy::Enemy() :hp(maxHP)
{
	posx = GetRand(WIN_WIDTH);
	posy = GetRand(WIN_HEIGHT);
}

void Enemy::Update()
{
	if ((Input::GetInstance()->GetMouse() & MOUSE_INPUT_LEFT) != 0&&
		(Input::GetInstance()->GetPrevMouse() & MOUSE_INPUT_LEFT) == 0) {
		int x = Input::GetInstance()->GetMouseX() - posx;
		int y = Input::GetInstance()->GetMouseY() - posy;

		if (x * x + y * y <= r * r) {
			hp--;
		}
	}

	if (hp <= 0) {
		isAlive = false;
	}
}

void Enemy::Draw()
{
	int color = hp / maxHP * 255;
	DrawCircle(posx, posy, r, GetColor(255, hp * 25, hp * 25));
}
