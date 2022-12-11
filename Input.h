#pragma once

class Input
{
private:
	char key[256] = {};
	char prev[256] = {};

	int MouseX, MouseY;
	int mouse;
	int prevMouse;

	Input() {};
	~Input() {};
public:
	static Input* GetInstance();
	static void Destroy();
	Input(const Input& obj) = delete;
	Input& operator=(const Input& obj) = delete;

	void Update();

	bool GetKey(int _key);
	bool GetTrigger(int _key);
	bool ReleaseKey(int _key);
	int GetMouseX() const { return MouseX; }
	int GetMouseY() const { return MouseY; }
	int GetMouse() const { return mouse; }
	int GetPrevMouse() const { return prevMouse; }
};

