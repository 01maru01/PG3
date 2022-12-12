#pragma once
class Enemy
{
private:
	static bool isAlive;
	static const int maxHP;

	int hp;
	int posx;
	int posy;
	int r = 10;
public:
	Enemy();
	void Update();
	void Draw();

	bool IsDead() const { return !isAlive; }
};

