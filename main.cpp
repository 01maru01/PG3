#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <vector>
#include <iostream>
#include "List.h"
using namespace std;

//typedef struct CELL{
//	int val;
//	struct CELL* prev;
//	struct CELL* next;
//}CELL;
//
//void Create(CELL* currentCell, int val);
//void Delete(CELL* currentCell);
//void Edit(CELL* currentCell, int val);
//void Index(CELL* endCell);
//void Index(CELL* endCell, int iterator);
//CELL* GetInsertListAddress(CELL* endCELL, int iterator);

int main() {
	int iterator;
	int inputValue;
	//CELL* insertCell;
	//int size = 0;
	//CELL head;
	//head.prev = nullptr;
	//head.next = nullptr;
	List<int> list;
	int mord = -1;

	while (mord != 0) {
		mord = -1;

		cout << "�����I�����Ă�������\n0:�I�� 1:�\�� 2:�}�� 3:�ҏW 4:�폜" << endl;
		//printf("�����I�����Ă�������\n0:�I�� 1:�\�� 2:�}�� 3:�ҏW 4:�폜\n");
		scanf_s("%d", &mord);

		switch (mord)
		{
		case 0:
			cout << "�I�����܂�" << endl;
			//printf("�I�����܂�\n");
			break;
		case 1:
			if (list.Head().next != nullptr) {
				while (true)
				{
					cout << "�\�����@��I�����Ă�������\n1:�ꗗ�\�� 2:���Ԏw�� 9:�߂�" << endl;
					//printf("�\�����@��I�����Ă�������\n1:�ꗗ�\�� 2:���Ԏw�� 9:�߂�\n");
					cin >> mord;
					//scanf_s("%d", &mord);

					switch (mord)
					{
					case 1:
						cout << "�v�f��: " << list.Size() << endl;
						//printf("�v�f��: %d\n", size);

						list.Index();
						break;
					case 2:
						cout << "���Ԗڂ̃Z����\�����܂���?" << endl;
						//printf("���Ԗڂ̃Z����\�����܂���?\n");
						cin >> iterator;
						//scanf_s("%d", &iterator);

						list.Index(iterator);
						break;
					case 9:
						cout << "�v�f����ɖ߂�" << endl;
						//printf("�v�f����ɖ߂�\n");
						break;
					default:
						cout << "���͂��Ԉ���Ă��܂�" << endl;
						//printf("���͂��Ԉ���Ă��܂�\n");
						continue;
						break;
					}

					if (mord == 9) break;

					cout << "1:�v�f�̕\���ɖ߂� 2:�v�f�̑���ɖ߂�" << endl;
					//printf("1:�v�f�̕\���ɖ߂� 2:�v�f�̑���ɖ߂�\n");
					cin >> mord;
					//scanf_s("%d", &mord);
					if (mord == 2) break;
				}
			}
			else {
				cout << "�\������v�f������܂���" << endl;
				//printf("�\������v�f������܂���\n");
			}			
			break;
		case 2:	
			cout << "�v�f��ǉ�����ꏊ���w�肵�Ă�������" << endl;
			//cin.unsetf(ios::skipws);
			cin >> iterator;
			//cin.setf(ios::skipws);
			//printf("�v�f��ǉ�����ꏊ���w�肵�Ă�������\n");
			//scanf_s("%d", &iterator);

			cout << "�ǉ�����v�f�̒l����͂��Ă�������" << endl;
			//printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
			cin >> inputValue;
			//scanf_s("%d", &inputValue);

			//insertCell = GetInsertListAddress(&head, iterator);
			//Create(insertCell, inputValue);
			//size++;
			list.Create(inputValue, iterator);

			if (iterator > list.Size()) iterator = list.Size();

			cout << "�v�f"<< inputValue <<"��"<< iterator <<"�Ԗڂɑ}������܂���" << endl;
			//printf("�v�f%d��%d�Ԗڂɑ}������܂���\n", inputValue, iterator);
			break;
		case 3:
			if (list.Head().next != nullptr) {
				cout << "�ҏW�������v�f�̔ԍ����w�肵�Ă�������" << endl;
				//printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
				cin >> iterator;
				//scanf_s("%d", &iterator);

				//insertCell = GetInsertListAddress(&head, iterator);

				if (!list.CheckCell(iterator)) {
					cout << iterator<< "�Ԗڂ̗v�f��������܂���ł���" << endl;
					//printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iterator);
				}
				else {
					cout << iterator << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������" << endl;
					//printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n", iterator);
					cin >> inputValue;
					//scanf_s("%d", &inputValue);

					list.Edit(inputValue);

					cout << iterator << "�Ԗڂ̗v�f�̒l��"<< inputValue <<"�ɕύX����܂����B" << endl;
					//printf("%d�Ԗڂ̗v�f�̒l��%d�ɕύX����܂����B\n", iterator, inputValue);
				}
			}
			else {
				cout << "�ҏW�ł���v�f������܂���" << endl;
				//printf("�ҏW�ł���v�f������܂���\n");
			}			
			break;
		case 4:
			if (list.Head().next != nullptr) {
				cout << "�폜�������v�f�̔ԍ����w�肵�Ă�������" << endl;
				//printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
				cin >> iterator;
				//scanf_s("%d", &iterator);

				//insertCell = GetInsertListAddress(&head, iterator);
				if (!list.CheckCell(iterator)) {
					cout << iterator << "�Ԗڂ̗v�f��������܂���ł���" << endl;
					//printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iterator);
				}
				else {
					inputValue = list.Val(iterator);

					list.Delete();

					cout << iterator<<"�Ԗڂ̗v�f"<< inputValue << "���폜���܂����B" << endl;
					//printf("%d�Ԗڂ̗v�f%d���폜���܂����B\n", iterator, inputValue);
				}
			}
			else {
				cout << "�폜�ł���v�f������܂���" << endl;
				//printf("�폜�ł���v�f������܂���\n");
			}
			break;
		default:
			cout << "���͂��Ԉ���Ă��܂�" << endl;
			//printf("���͂��Ԉ���Ă��܂�\n");
			break;
		}
	}

	system("pause");

	return 0;
}

//void Create(CELL* currentCell, int val) {
//	CELL* newCell;
//	newCell = (CELL*)malloc(sizeof(CELL));
//	newCell->val = val;
//	newCell->prev = currentCell;
//	newCell->next = currentCell->next;
//
//	if (currentCell->next) {
//		CELL* nextCell = currentCell->next;
//		nextCell->prev = newCell;
//	}
//
//	currentCell->next = newCell;
//}
//
//void Delete(CELL* currentCell) {
//	CELL* nextCell = currentCell->next;
//	CELL* prevCell = currentCell->prev;
//
//	prevCell->next = nextCell;
//	if (currentCell->next != nullptr) {
//		nextCell->prev = prevCell;
//	}
//}
//
//void Edit(CELL* currentCell, int val) {
//	currentCell->val = val;
//}
//
//void Index(CELL* endCell) {
//	int no = 1;
//
//	while (endCell->next != nullptr)
//	{
//		endCell = endCell->next;
//		cout << no << ":";
//		cout << endCell->prev;
//		cout << setw(5) << endCell->val;
//		cout << "(" << endCell << ")";
//		cout << endCell->next << endl;
//		
//		//printf("%d:", no);
//		//printf("%p", endCell->prev);
//		//printf("%5d", endCell->val);
//		//printf("(%p)", endCell);
//		//printf("%p\n", endCell->next);
//		no++;
//	}
//}
//
//void Index(CELL* endCell, int iterator) {
//	CELL* insertCell = GetInsertListAddress(endCell, iterator);
//
//	cout<< iterator << ":";
//	//printf("%d:", iterator);
//	cout << insertCell->prev;
//	//printf("%p", insertCell->prev);
//	cout << setw(5) << insertCell->val;
//	//printf("%5d", insertCell->val);
//	cout << "(" << insertCell << ")";
//	//printf("(%p)", insertCell);
//	cout << insertCell->next << endl;
//	//printf("%p\n", insertCell->next);	
//}
//
//CELL* GetInsertListAddress(CELL* endCELL, int iterator) {
//	for (int i = 0; i < iterator; i++) {
//		if (endCELL->next) {
//			endCELL = endCELL->next;
//		}
//		else {
//			break;
//		}
//	}
//	return endCELL;
//}
