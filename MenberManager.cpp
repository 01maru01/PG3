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
	//	ID�Z�b�g
	menber_.SetId(id);
	id++;
	//	menber�̓��e�ݒ�
	menber_.SetInfo(name_, className_);
	//	Add
	menber.push_back(menber_);
}

void MenberManager::Delete(int id_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	�v�f�̍폜
			menber.erase(itr);
			
			printf("�v�f���폜����܂���\n");
			return;
		}
	}

	printf("�v�f�̍폜�Ɏ��s���܂���\n");
}

void MenberManager::Change(int id_, std::string name_, std::string className_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	�v�f�̕ύX
			itr->SetInfo(name_, className_);

			printf("ID:%d�̗v�f���ύX����܂���\n", id_);
			return;
		}
	}

	printf("ID:%d�̗v�f�̕ύX�Ɏ��s���܂���\n", id_);
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
	printf("�S���҂Ȃ�\n");
}
