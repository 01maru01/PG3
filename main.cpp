#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

typedef struct CELL{
	int val;
	struct CELL* prev;
	struct CELL* next;
}CELL;

void Create(CELL* currentCell, int val);
void Delete(CELL* currentCell);
void Edit(CELL* currentCell, int val);
void Index(CELL* endCell);
void Index(CELL* endCell, int iterator);
CELL* GetInsertListAddress(CELL* endCELL, int iterator);

int main() {
	int iterator;
	int inputValue;
	CELL* insertCell;
	int num = 0;
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	int mord = -1;

	while (mord != 0) {
		mord = -1;

		printf("�����I�����Ă�������\n0:�I�� 1:�\�� 2:�}�� 3:�ҏW 4:�폜\n");
		scanf_s("%d", &mord);

		switch (mord)
		{
		case 0:
			printf("�I�����܂�\n");
			break;
		case 1:
			if (head.next != nullptr) {
				while (true)
				{
					printf("�\�����@��I�����Ă�������\n1:�ꗗ�\�� 2:���Ԏw�� 9:�߂�\n");
					scanf_s("%d", &mord);

					switch (mord)
					{
					case 1:
						printf("�v�f��: %d\n", num);

						Index(&head);
						break;
					case 2:
						printf("���Ԗڂ̃Z����\�����܂���?\n");
						scanf_s("%d", &iterator);

						Index(&head, iterator);
						break;
					case 9:
						printf("�v�f����ɖ߂�\n");
						break;
					default:
						printf("���͂��Ԉ���Ă��܂�\n");
						continue;
						break;
					}

					if (mord == 9) break;

					printf("1:�v�f�̕\���ɖ߂� 2:�v�f�̑���ɖ߂�\n");
					scanf_s("%d", &mord);
					if (mord == 2) break;
				}
			}
			else {
				printf("�\������v�f������܂���\n");
			}			
			break;
		case 2:
			printf("���Ԗڂ̃Z���̌��ɑ}�����܂���?\n");
			scanf_s("%d", &iterator);

			printf("�}������l����͂��Ă�������\n");
			scanf_s("%d", &inputValue);

			insertCell = GetInsertListAddress(&head, iterator);
			Create(insertCell, inputValue);
			num++;
			break;
		case 3:
			if (head.next != nullptr) {
				printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
				scanf_s("%d", &iterator);

				insertCell = GetInsertListAddress(&head, iterator);

				if (num < iterator) {
					printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iterator);
				}
				else {
					printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n", iterator);
					scanf_s("%d", &inputValue);

					Edit(insertCell, inputValue);

					printf("%d�Ԗڂ̗v�f�̒l��%d�ɕύX����܂����B\n", iterator, inputValue);
				}
			}
			else {
				printf("�ҏW�ł���v�f������܂���\n");
			}			
			break;
		case 4:
			if (head.next != nullptr) {
				printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
				scanf_s("%d", &iterator);

				insertCell = GetInsertListAddress(&head, iterator);
				if (num < iterator) {
					printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iterator);
				}
				else {
					inputValue = insertCell->val;
					Delete(insertCell);
					num--;

					printf("%d�Ԗڂ̗v�f%d���폜���܂����B\n", iterator, inputValue);
				}
			}
			else {
				printf("�폜�ł���v�f������܂���\n");
			}
			break;
		default:
			printf("���͂��Ԉ���Ă��܂�\n");
			break;
		}
	}

	system("pause");

	return 0;
}

void Create(CELL* currentCell, int val) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void Delete(CELL* currentCell) {
	CELL* nextCell = currentCell->next;
	CELL* prevCell = currentCell->prev;

	prevCell->next = nextCell;
	if (currentCell->next != nullptr) {
		nextCell->prev = prevCell;
	}
}

void Edit(CELL* currentCell, int val) {
	currentCell->val = val;
}

void Index(CELL* endCell) {
	int no = 1;

	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d:", no);
		printf("%p", endCell->prev);
		printf("%5d", endCell->val);
		printf("(%p)", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}

void Index(CELL* endCell, int iterator) {
	CELL* insertCell = GetInsertListAddress(endCell, iterator);

	printf("%d:", iterator);
	printf("%p", insertCell->prev);
	printf("%5d", insertCell->val);
	printf("(%p)", insertCell);
	printf("%p\n", insertCell->next);	
}

CELL* GetInsertListAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			break;
		}
	}
	return endCELL;
}
