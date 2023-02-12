#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
private:
	std::list<Task> task;
	int id = 0;

	TaskManager() {};
	~TaskManager() {};
public:
	static TaskManager* GetInstance();
	static void DeleteInstance();
	TaskManager(const TaskManager& obj) = delete;
	TaskManager& operator=(const TaskManager& obj) = delete;

	void Add(int menberID, std::string name_, std::string detail_, Task::EPriority priority, Date deadLine_);
	void Delete(int id_);
	void SetStatus(int id_, bool isDone);
	void Change(int id_, Task::EPriority priority = Task::p_Error, std::string name_ = "", std::string detail_ = "", Date deadLine_ = Date(0, 0, 0));
	void Draw();
};

