#pragma once
#include "IShape.h"
class Circle :public IShape
{
private:
	int posX;
	int posY;
	int r;
public:
	Circle();
	float size() override;
	void Draw() override;
};

