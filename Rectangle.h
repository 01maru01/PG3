#pragma once
#include "IShape.h"

class RectAngle :public IShape
{
private:
	int posX;
	int posY;
	int width;
	int height;
public:
	RectAngle();
	float size() override;
	void Draw() override;
};

