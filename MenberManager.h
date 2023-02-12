#pragma once
#include "Menber.h"
#include <list>

class MenberManager
{
private:
	std::list<Menber> menber;
	int id = 0;

	MenberManager() {};
	~MenberManager() {};
public:
	static MenberManager* GetInstance();
	static void DeleteInstance();
	MenberManager(const MenberManager& obj) = delete;
	MenberManager& operator=(const MenberManager& obj) = delete;

	void Add(std::string name_, std::string className_);
	void Delete(int id_);
	void Change(int id_, std::string name_, std::string className_);
	void Draw();
	void Draw(int id_);
};

