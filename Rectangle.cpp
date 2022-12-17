#include "Rectangle.h"
#include "DxLib.h"
#include "main.h"

RectAngle::RectAngle()
{
	posX = WIN_WIDTH / 2;
	posY = WIN_HEIGHT / 2;
	width = 100;
	height = 100;
}

float RectAngle::size()
{
	return width * height;
}

void RectAngle::Draw()
{
	int rbX = posX + width;
	int rbY = posY + height;
	DrawBox(posX, posY, rbX, rbY, 0xFFFFFF, true);
}
