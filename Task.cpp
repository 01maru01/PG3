#include "Task.h"

void Task::SetInfo(std::string name_, int id_, std::string detail_, EPriority priority_, Date deadLine_)
{
	SetTaskName(name_);

	SetMenberID(id_);

	SetDetail(detail_);

	SetPriority(priority_);

	SetDeadLine(deadLine_);
}
