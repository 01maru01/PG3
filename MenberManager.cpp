#include "MenberManager.h"

MenberManager* MenberManager::GetInstance()
{
	static MenberManager* instance = new MenberManager;
	return instance;
}

void MenberManager::DeleteInstance()
{
	delete MenberManager::GetInstance();
}

void MenberManager::Add(std::string name_, std::string className_)
{
	Menber menber_;
	//	IDƒZƒbƒg
	menber_.SetId(id);
	id++;
	//	menber‚Ì“à—eÝ’è
	menber_.SetInfo(name_, className_);
	//	Add
	menber.push_back(menber_);
}

void MenberManager::Delete(int id_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	—v‘f‚Ìíœ
			menber.erase(itr);
			
			printf("—v‘f‚ªíœ‚³‚ê‚Ü‚µ‚½\n");
			return;
		}
	}

	printf("—v‘f‚Ìíœ‚ÉŽ¸”s‚µ‚Ü‚µ‚½\n");
}

void MenberManager::Change(int id_, std::string name_, std::string className_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	—v‘f‚Ì•ÏX
			itr->SetInfo(name_, className_);

			printf("ID:%d‚Ì—v‘f‚ª•ÏX‚³‚ê‚Ü‚µ‚½\n", id_);
			return;
		}
	}

	printf("ID:%d‚Ì—v‘f‚Ì•ÏX‚ÉŽ¸”s‚µ‚Ü‚µ‚½\n", id_);
}

void MenberManager::Draw()
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		printf("ID:%d Name:%s Class:%s\n", itr->GetId(), itr->GetName().c_str(), itr->GetClassName().c_str());
	}

	printf("\n");
}

void MenberManager::Draw(int id_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			printf("Name:%s Class:%s\n", itr->GetName().c_str(), itr->GetClassName().c_str());
			return;
		}
	}
	printf("’S“–ŽÒ‚È‚µ\n");
}
