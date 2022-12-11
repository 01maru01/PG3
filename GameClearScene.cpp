#include "GameClearScene.h"
#include "DxLib.h"

GameClearScene::GameClearScene()
{
}

GameClearScene::~GameClearScene()
{
}

void GameClearScene::Initialize()
{
	SetBackgroundColor(0x00, 0x88, 0x88);
}

void GameClearScene::Update()
{
}

void GameClearScene::Draw(int sceneNo)
{
	DrawFormatString(50, 50, 0xFFFFFF, "SceneNo: %d\nPress Space to Scene Change", sceneNo);
}
