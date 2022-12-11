#pragma once
#include "IFScene.h"

class SceneManager final
{
private:
	IFScene* scene;
	int sceneNum;

	SceneManager();
	~SceneManager();
public:
	enum Scene {
		Title,
		NewGame,
		GamePlay,
		GameClear,
	};
	SceneManager(const SceneManager& obj) = delete;
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	void Initialize();
	void Update();
	void Draw();
	void ChangeScene(int sceneNo);
	IFScene* GetScene();
};

