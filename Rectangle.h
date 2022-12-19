#pragma once
#include "IShape.h"

class RectAngle :public IShape
{
private:
	int width;
	int height;
	float s_area;
public:
	RectAngle(int width_,int height_);
	void size() override;
	void Draw() override;
};

