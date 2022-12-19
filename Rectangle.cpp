#include "Rectangle.h"
#include <stdio.h>

RectAngle::RectAngle(int width_, int height_)
{
	width = width_;
	height = height_;
	s_area = 0.0f;
}

void RectAngle::size()
{
	s_area = width * height;
}

void RectAngle::Draw()
{
	printf("RectAngle\nWidth:%d Height:%d\nsize:%f\n", width, height, s_area);
}
