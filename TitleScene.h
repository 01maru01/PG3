#pragma once
#include "IFScene.h"

class TitleScene :public IFScene
{
public:
	TitleScene();
	~TitleScene();
	void Initialize() override;
	
	void Update() override;
	void Draw(int sceneNo) override;
};

