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

		printf("操作を選択してください\n0:終了 1:表示 2:挿入 3:編集 4:削除\n");
		scanf_s("%d", &mord);

		switch (mord)
		{
		case 0:
			printf("終了します\n");
			break;
		case 1:
			if (head.next != nullptr) {
				while (true)
				{
					printf("表示方法を選択してください\n1:一覧表示 2:順番指定 9:戻る\n");
					scanf_s("%d", &mord);

					switch (mord)
					{
					case 1:
						printf("要素数: %d\n", num);

						Index(&head);
						break;
					case 2:
						printf("何番目のセルを表示しますか?\n");
						scanf_s("%d", &iterator);

						Index(&head, iterator);
						break;
					case 9:
						printf("要素操作に戻る\n");
						break;
					default:
						printf("入力が間違っています\n");
						continue;
						break;
					}

					if (mord == 9) break;

					printf("1:要素の表示に戻る 2:要素の操作に戻る\n");
					scanf_s("%d", &mord);
					if (mord == 2) break;
				}
			}
			else {
				printf("表示する要素がありません\n");
			}			
			break;
		case 2:
			printf("何番目のセルの後ろに挿入しますか?\n");
			scanf_s("%d", &iterator);

			printf("挿入する値を入力してください\n");
			scanf_s("%d", &inputValue);

			insertCell = GetInsertListAddress(&head, iterator);
			Create(insertCell, inputValue);
			num++;
			break;
		case 3:
			if (head.next != nullptr) {
				printf("編集したい要素の番号を指定してください\n");
				scanf_s("%d", &iterator);

				insertCell = GetInsertListAddress(&head, iterator);

				if (num < iterator) {
					printf("%d番目の要素が見つかりませんでした\n", iterator);
				}
				else {
					printf("%d番目の要素の変更する値を入力してください\n", iterator);
					scanf_s("%d", &inputValue);

					Edit(insertCell, inputValue);

					printf("%d番目の要素の値が%dに変更されました。\n", iterator, inputValue);
				}
			}
			else {
				printf("編集できる要素がありません\n");
			}			
			break;
		case 4:
			if (head.next != nullptr) {
				printf("削除したい要素の番号を指定してください\n");
				scanf_s("%d", &iterator);

				insertCell = GetInsertListAddress(&head, iterator);
				if (num < iterator) {
					printf("%d番目の要素が見つかりませんでした\n", iterator);
				}
				else {
					inputValue = insertCell->val;
					Delete(insertCell);
					num--;

					printf("%d番目の要素%dを削除しました。\n", iterator, inputValue);
				}
			}
			else {
				printf("削除できる要素がありません\n");
			}
			break;
		default:
			printf("入力が間違っています\n");
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
