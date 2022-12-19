#pragma once
#include "IShape.h"
class Circle :public IShape
{
private:
	int r;
	float s_area;
public:
	Circle(int r);
	void size() override;
	void Draw() override;
};

