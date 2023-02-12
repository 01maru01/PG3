#pragma once
#include <string>

class Menber
{
private:
	int id = -1;
	std::string name;
	std::string className;
public:
	void SetId(int id_) { id = id_; }
	void SetInfo(std::string name_ = nullptr, std::string className_ = nullptr);

	int GetId() { return id; }
	std::string GetName() { return name; }
	std::string GetClassName() { return className; }
};

