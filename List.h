#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
namespace
{
	using namespace std;
}

template <typename T>
struct CELL {
	T val;
	struct CELL* prev;
	struct CELL* next;
};

template <typename T>
class List
{
private:
	//int iterator;
	CELL<T>* insertCell;
	int size = 0;
	CELL<T> head;
public:
	List();
	void Create(T val, int iterator);
	void Delete();
	void Edit(T val);
	void Index();
	bool CheckCell(int iterator);
	void Index(int iterator);
	CELL<T>* GetInsertListAddress(int iterator);
	bool Empty() { return insertCell->next == nullptr; }
	T Val(int iterator);
	CELL<T> Head() { return head; }
	int Size() { return size; }
};

template<typename T>
inline List<T>::List()
{
	head.prev = nullptr;
	head.next = nullptr;
}

template<typename T>
inline void List<T>::Create(T val, int iterator)
{
	insertCell = GetInsertListAddress(iterator);

	CELL<T>* newCell;
	newCell = (CELL<T>*)malloc(sizeof(CELL<T>));
	newCell->val = val;
	newCell->prev = insertCell;
	newCell->next = insertCell->next;

	if (insertCell->next) {
		CELL<T>* nextCell = insertCell->next;
		nextCell->prev = newCell;
	}

	insertCell->next = newCell;

	size++;
}

template<typename T>
inline void List<T>::Delete()
{
	CELL<T>* cell = insertCell;
	if (!Empty())
	{
		T ret = cell->val;
		cell->prev->next = cell->next;
		cell->next->prev = cell->prev;
		delete cell;
		cell = cell->prev;
		size--;
	}
	else {
		cout << "íœ‚Å‚«‚é—v‘f‚ª‚ ‚è‚Ü‚¹‚ñ" << endl;
	}
	
	//return ret;

	//CELL<T>* nextCell = insertCell->next;
	//CELL<T>* prevCell = insertCell->prev;

	//prevCell->next = nextCell;
	//if (insertCell->next != nullptr) {
	//	nextCell->prev = prevCell;
	//}

	//size--;
}

template<typename T>
inline void List<T>::Edit(T val)
{
	CELL<T>* cell = insertCell;
	cell->val = val;
}

template<typename T>
inline void List<T>::Index()
{
	int no = 1;
	CELL<T>* head_ = &head;

	while (head_->next != nullptr)
	{
		head_ = head_->next;
		cout << no << ":";
		cout << head_->prev;
		cout << setw(5) << head_->val;
		cout << "(" << head_ << ")";
		cout << head_->next << endl;
		no++;
	}
}

template<typename T>
inline bool List<T>::CheckCell(int iterator)
{
	insertCell = GetInsertListAddress(iterator);
	return size >= iterator;
}

template<typename T>
inline void List<T>::Index(int iterator)
{
	insertCell = GetInsertListAddress(iterator);

	cout << iterator << ":";
	cout << insertCell->prev;
	cout << setw(5) << insertCell->val;
	cout << "(" << insertCell << ")";
	cout << insertCell->next << endl;
}

template<typename T>
inline CELL<T>* List<T>::GetInsertListAddress(int iterator)
{
	CELL<T>* head_ = &head;
	for (int i = 0; i < iterator; i++) {
		if (head_->next) {
			head_ = insertCell->next;
		}
		else {
			break;
		}
	}
	return head_;
}

template<typename T>
inline T List<T>::Val(int iterator)
{
	insertCell = GetInsertListAddress(iterator);
	return insertCell->val;
}
