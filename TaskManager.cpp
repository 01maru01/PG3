#include "TaskManager.h"
#include "MenberManager.h"

TaskManager* TaskManager::GetInstance()
{
	static TaskManager* instance = new TaskManager;
	return instance;
}

void TaskManager::DeleteInstance()
{
	delete TaskManager::GetInstance();
}

void TaskManager::Add(int menberID, std::string name_, std::string detail_, Task::EPriority priority, Date deadLine_)
{
	Task task_;

	//	IDセット
	task_.SetId(id);
	id++;
	//	taskの内容設定
	task_.SetInfo(name_, menberID, detail_, priority, deadLine_);
	//	Add
	task.push_back(task_);
}

void TaskManager::Delete(int id_)
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	要素の削除
			task.erase(itr);

			printf("要素が削除されました\n");
			return;
		}
	}

	printf("要素の削除に失敗しました\n");
}

void TaskManager::SetStatus(int id_, bool isDone)
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		if (itr->GetId() == id_) {
			itr->SetStatus(isDone);

			printf("ID:%dのStatusが%dに変更されました 0:未完了 1:完了\n", id_, isDone);
			return;
		}
	}
	printf("要素の変更に失敗しました\n");

}

void TaskManager::Change(int id_, Task::EPriority priority, std::string name_, std::string detail_, Date deadLine_)
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	要素の変更
			if (priority != Task::p_Error) itr->SetPriority(priority);
			if (name_ != "") itr->SetTaskName(name_);
			if (detail_ != "") itr->SetDetail(detail_);
			if (deadLine_.GetDay() != 0 &&
				deadLine_.GetMonth() != 0 &&
				deadLine_.GetYear() != 0 ) itr->SetDeadLine(deadLine_);

			printf("ID:%dの要素が変更されました\n", id_);
			return;
		}
	}

	printf("ID:%dの要素の変更に失敗しました\n", id_);
}

void TaskManager::Draw()
{
	for (auto itr = task.begin(); itr != task.end(); ++itr) {
		std::string priorityStr;
		switch (itr->GetPriority())
		{
		case Task::p_High:
			priorityStr = "高";
			break;
		case Task::p_Medium:
			priorityStr = "中";
			break;
		case Task::p_Low:
			priorityStr = "低";
			break;
		}

		printf("ID:%d Name:%s Detail:%s\n", itr->GetId(), itr->GetTaskName().c_str(), itr->GetDetail().c_str());
		MenberManager::GetInstance()->Draw(itr->GetMenberID());
		printf("     Priority:%s IsDone:%d\n", priorityStr.c_str(), itr->IsDone());
		printf("     締め切り:%d年%d月%d日\n", itr->GetDeadLine().GetYear(), itr->GetDeadLine().GetMonth(), itr->GetDeadLine().GetDay());
		//	締め切りまで
		int diffDay = itr->GetDeadLine().CalcDifDay();

		if (diffDay > 0) {
			printf("締め切りまであと%d日\n", diffDay);
		}
		else if (diffDay < 0) {
			printf("締め切りから%d日遅れ\n", -diffDay);
		}
		else {
			printf("締め切り当日です\n");
		}
	}

	printf("\n");
}
