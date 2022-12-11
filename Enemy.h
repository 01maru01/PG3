#pragma once
class Enemy
{
private:
	static bool allDead;
	static const int maxHP;

	int hp;
	bool isAlive;
	int posx;
	int posy;
	int r = 10;
public:
	Enemy();
	void Update();
	void Draw();

	bool IsDead() const { return !isAlive; }
};

