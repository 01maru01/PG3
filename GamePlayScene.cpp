#include "GamePlayScene.h"
#include "DxLib.h"

GamePlayScene::GamePlayScene()
{
}

GamePlayScene::~GamePlayScene()
{
}

void GamePlayScene::Initialize()
{
	SetBackgroundColor(0x00, 0x88, 0x00);
}

void GamePlayScene::Update()
{
}

void GamePlayScene::Draw(int sceneNo)
{
	DrawFormatString(50, 50, 0xFFFFFF, "SceneNo: %d\nPress Space to Scene Change", sceneNo);
}
