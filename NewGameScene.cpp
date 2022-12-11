#include "NewGameScene.h"
#include "DxLib.h"

NewGameScene::NewGameScene()
{
}

NewGameScene::~NewGameScene()
{
}

void NewGameScene::Initialize()
{
	SetBackgroundColor(0x00, 0x00, 0x88);
}

void NewGameScene::Update()
{
}

void NewGameScene::Draw(int sceneNo)
{
	DrawFormatString(50, 50, 0xFFFFFF, "SceneNo: %d\nPress Space to Scene Change", sceneNo);
}
