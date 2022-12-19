#include "Circle.h"
#include <stdio.h>
#include "main.h"

Circle::Circle(int r)
{
	this->r = r;
	s_area = 0.0f;
}

void Circle::size()
{
	s_area = r * r * 3.14;
}

void Circle::Draw()
{
	printf("Circle\nradius:%d\nsize:%f\n", r, s_area);
}
