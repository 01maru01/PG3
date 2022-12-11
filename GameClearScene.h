#pragma once
#include "IFScene.h"

class GameClearScene :public IFScene
{
public:
	GameClearScene();
	~GameClearScene();
	void Initialize() override;

	void Update() override;
	void Draw(int sceneNo) override;
};

