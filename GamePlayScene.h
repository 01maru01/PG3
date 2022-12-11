#pragma once
#include "IFScene.h"

class GamePlayScene :public IFScene
{
public:
	GamePlayScene();
	~GamePlayScene();
	void Initialize() override;

	void Update() override;
	void Draw(int sceneNo) override;
};

