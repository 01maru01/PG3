#pragma once
#include <string>
#include "Date.h"

class Task
{
public:
	enum EPriority {
		p_Error,
		p_High,
		p_Medium,
		p_Low,
	};
private:
	int id = -1;
	std::string name;
	int menberId = -1;
	std::string detail;
	EPriority priority = p_Error;
	Date deadLine;
	bool isDone = false;
public:
	void SetInfo(std::string name_, int id_, std::string detail_, EPriority priority_, Date deadLine_);
	void SetTaskName(std::string name_) { name = name_; }
	void SetMenberID(int id_) { menberId = id_; }
	void SetDetail(std::string detail_) { detail = detail_; }
	void SetPriority(EPriority priority_) { priority = priority_; }
	void SetDeadLine(Date deadLine_) { deadLine = deadLine_; }
	void SetStatus(bool isDone_) { isDone = isDone_; }
	void SetId(int id_) { id = id_; }

	std::string GetTaskName() { return name; }
	std::string GetDetail() { return detail; }
	int GetMenberID() { return menberId; }
	EPriority GetPriority() { return priority; }
	Date GetDeadLine() { return deadLine; }
	bool IsDone() { return isDone; }
	int GetId() { return id; }
};

