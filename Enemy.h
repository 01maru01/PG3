#pragma once
class Enemy
{
private:
	int hp;
	bool isAlive;
	int posx;
	int posy;
	int r = 10;

	enum class State{
		MeleeS,
		ShootingS,
		WithDrawS,
	};
	State phase;
	int color;
public:
	Enemy();
	void Update();
	void Draw();

	//	‹ßÚËŒ‚—£’E
	void Melee();
	void Shooting();
	void WithDraw();
	static void (Enemy::* pFunc[])();

	bool IsDead() const { return !isAlive; }
};

