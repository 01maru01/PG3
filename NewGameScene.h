#pragma once
#include "IFScene.h"

class NewGameScene :public IFScene
{
public:
	NewGameScene();
	~NewGameScene();
	void Initialize() override;

	void Update() override;
	void Draw(int sceneNo) override;
};

