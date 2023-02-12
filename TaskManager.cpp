#include "TaskManager.h"
#include "MenberManager.h"

void TaskManager::Add(int menberID, std::string name_, std::string detail_, Task::EPriority priority, time_t deadLine_)
{
	Task task_;

	//	ID�Z�b�g
	task_.SetId(id);
	id++;
	//	task�̓��e�ݒ�
	task_.SetInfo(name_, menberID, detail_, priority, deadLine_);
	//	Add
	task.push_back(task_);
}

void TaskManager::Delete(int id_)
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	�v�f�̍폜
			task.erase(itr);

			printf("�v�f���폜����܂���\n");
			return;
		}
	}

	printf("�v�f�̍폜�Ɏ��s���܂���\n");
}

void TaskManager::SetStatus(int id_, bool isDone)
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		if (itr->GetId() == id_) {
			itr->SetStatus(isDone);

			printf("ID:%d��Status��%d�ɕύX����܂��� 0:������ 1:����\n", id_, isDone);
			return;
		}
	}
	printf("�v�f�̕ύX�Ɏ��s���܂���\n");

}

void TaskManager::Change(int id_, Task::EPriority priority, std::string name_, std::string detail_, time_t deadLine_)
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	�v�f�̕ύX
			if (priority != Task::p_Error) itr->SetPriority(priority);
			if (name_ != "") itr->SetTaskName(name_);
			if (detail_ != "") itr->SetDetail(detail_);
			if (deadLine_ != time_t()) itr->SetDeadLine(deadLine_);

			printf("ID:%d�̗v�f���ύX����܂���\n", id_);
			return;
		}
	}

	printf("ID:%d�̗v�f�̕ύX�Ɏ��s���܂���\n", id_);
}

void TaskManager::Draw()
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		std::string priorityStr;
		switch (itr->GetPriority())
		{
		case Task::p_High:
			priorityStr = "��";
			break;
		case Task::p_Medium:
			priorityStr = "��";
			break;
		case Task::p_Low:
			priorityStr = "��";
			break;
		}

		printf("ID:%d Name:%s Detail:%s\n", itr->GetId(), itr->GetTaskName().c_str(), itr->GetDetail().c_str());
		MenberManager::GetInstance()->Draw(itr->GetMenberID());
		printf("     Priority:%s IsDone:%d\n", priorityStr.c_str(), itr->IsDone());
		//	���ߐ؂�܂�
	}

	printf("\n");
}