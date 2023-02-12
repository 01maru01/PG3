#include <stdio.h>
#include "MenberManager.h"
#include "TaskManager.h"

int main() {
	MenberManager* menMan = MenberManager::GetInstance();
	TaskManager* taskMan = TaskManager::GetInstance();
	
	menMan->Add("マルイチユウキ", "LE2A");
	menMan->Add("ヤマダタロウ", "LE2B");
	menMan->Add("ヤマダタロウ", "LE2A");
	menMan->Change(1, "ヤマダタロウ1", "LE2B");
	menMan->Change(2, "ヤマダタロウ2", "LE2A");
	menMan->Draw();

	printf("タスク内容\n\n");

	taskMan->Add(2, "企画", "企画決め", Task::p_High, time_t());
	taskMan->Add(3, "プロトタイプ", "Unityでプロトタイプの作成", Task::p_Low, time_t());
	taskMan->Draw();
	taskMan->Add(1, "α版", "自作エンジンでα版作成", Task::p_Medium, time_t());
	taskMan->Change(1, Task::p_High,"","Unityで遊びが確認できるレベルのプロトタイプ作成");
	taskMan->Draw();

	TaskManager::DeleteInstance();
	MenberManager::DeleteInstance();
	return 0;
}