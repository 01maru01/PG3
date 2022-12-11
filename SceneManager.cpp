#include "SceneManager.h"
#include "TitleScene.h"
#include "NewGameScene.h"
#include "GamePlayScene.h"
#include "GameClearScene.h"
#include "Input.h"
#include "DxLib.h"

SceneManager::SceneManager()
{
	scene = new TitleScene();
	sceneNum = SceneManager::Title;
}

SceneManager::~SceneManager()
{
	delete scene;
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}

void SceneManager::Initialize()
{
	scene->Initialize();
}

void SceneManager::Update()
{
	if (Input::GetInstance()->GetTrigger(KEY_INPUT_SPACE)) {
		sceneNum++;
		if (sceneNum > SceneManager::GameClear) {
			sceneNum = SceneManager::Title;
		}
		ChangeScene(sceneNum);
	}
	scene->Update();
}

void SceneManager::Draw()
{
	scene->Draw(sceneNum);
}

void SceneManager::ChangeScene(int sceneNo)
{
	sceneNum = sceneNo;
	IFScene* nextScene = nullptr;

	switch (sceneNum)
	{
	case SceneManager::Title:
		nextScene = new TitleScene();
		break;
	case SceneManager::NewGame:
		nextScene = new NewGameScene();
		break;
	case SceneManager::GamePlay:
		nextScene = new GamePlayScene();
		break;
	case SceneManager::GameClear:
		nextScene = new GameClearScene();
		break;
	}

	if (nextScene != nullptr) {
		nextScene->Initialize();
		delete scene;
		scene = nextScene;
	}
}
