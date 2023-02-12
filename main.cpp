#include <stdio.h>
#include "MenberManager.h"
#include "TaskManager.h"
#include "Date.h"

int main() {
	MenberManager* menMan = MenberManager::GetInstance();
	TaskManager* taskMan = TaskManager::GetInstance();
	
	menMan->Add("�}���C�`���E�L", "LE2A");
	menMan->Add("���}�_�^���E", "LE2B");
	menMan->Add("���}�_�^���E", "LE2A");
	menMan->Change(1, "���}�_�^���E1", "LE2B");
	menMan->Change(2, "���}�_�^���E2", "LE2A");
	menMan->Draw();

	printf("�^�X�N���e\n\n");

	taskMan->Add(2, "���", "��挈��", Task::p_High, Date{ 2023,2,9 });
	taskMan->Add(3, "�v���g�^�C�v", "Unity�Ńv���g�^�C�v�̍쐬", Task::p_Low, Date{ 2023,2,21 });
	taskMan->Draw();
	taskMan->Add(1, "����", "����G���W���Ń��ō쐬", Task::p_Medium, Date{ 2023,3,1 });
	taskMan->Change(1, Task::p_High,"","Unity�ŗV�т��m�F�ł��郌�x���̃v���g�^�C�v�쐬");
	taskMan->Draw();

	TaskManager::DeleteInstance();
	MenberManager::DeleteInstance();
	return 0;
}