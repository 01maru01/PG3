#include "TitleScene.h"
#include "DxLib.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	SetBackgroundColor(0x88, 0x00, 0x00);
}

void TitleScene::Update()
{
}

void TitleScene::Draw(int sceneNo)
{
	DrawFormatString(50, 50, 0xFFFFFF, "SceneNo: %d\nPress Space to Scene Change", sceneNo);
}
