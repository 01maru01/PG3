#include "Circle.h"
#include "DxLib.h"
#include "main.h"

Circle::Circle()
{
	posX = WIN_WIDTH / 2;
	posY = WIN_HEIGHT / 2;
	r = 50;
}

float Circle::size()
{
	return r * r * 3.14;
}

void Circle::Draw()
{
	DrawCircle(posX, posY, r, 0xFFFFFF);
}
