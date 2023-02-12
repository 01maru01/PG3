#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
private:
	std::list<Task> task;
	int id = 0;
public:
	void Add(int menberID, std::string name_, std::string detail_, Task::EPriority priority, time_t deadLine_);
	void Delete(int id_);
	void SetStatus(int id_, bool isDone);
	void Change(int id_, Task::EPriority priority = Task::p_Error, std::string name_ = "", std::string detail_ = "", time_t deadLine_ = time_t());
	void Draw();
};

