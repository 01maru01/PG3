#include "Enemy.h"
#include "DxLib.h"
#include "main.h"
#include "Input.h"

void (Enemy::* Enemy::pFunc[])() = {
	&Enemy::Melee,
	&Enemy::Shooting,
	&Enemy::WithDraw,
};

Enemy::Enemy() :isAlive(true), hp(5)
{
	posx = WIN_WIDTH / 2.0f;
	posy = WIN_HEIGHT / 2.0f;
	phase = State::MeleeS;
	color = GetColor(255, 255, 255);
}

void Enemy::Melee()
{
	color = GetColor(200, 0, 0);
}

void Enemy::Shooting()
{
	color = GetColor(0, 0, 200);
}

void Enemy::WithDraw()
{
	color = GetColor(0, 200, 0);
}

void Enemy::Update()
{
	if (Input::GetInstance()->GetTrigger(KEY_INPUT_SPACE)) {
		switch (phase)
		{
		case Enemy::State::MeleeS:
			phase = Enemy::State::ShootingS;
			break;
		case Enemy::State::ShootingS:
			phase = Enemy::State::WithDrawS;
			break;
		case Enemy::State::WithDrawS:
			phase = Enemy::State::MeleeS;
			break;
		default:
			break;
		}
	}

	(this->*pFunc[static_cast<size_t>(phase)])();
}

void Enemy::Draw()
{
	DrawFormatString(50, 50, 0xFFFFFF, "Press Space\nnow state:%d", static_cast<size_t>(phase));
	if (isAlive) {
		DrawCircle(posx, posy, r, color);
	}
}
