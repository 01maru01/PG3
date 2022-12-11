#pragma once
class IFScene
{
public:
	virtual ~IFScene() {};
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw(int sceneNo) = 0;
};

