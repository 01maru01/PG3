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

		cout << "操作を選択してください\n0:終了 1:表示 2:挿入 3:編集 4:削除" << endl;
		//printf("操作を選択してください\n0:終了 1:表示 2:挿入 3:編集 4:削除\n");
		scanf_s("%d", &mord);

		switch (mord)
		{
		case 0:
			cout << "終了します" << endl;
			//printf("終了します\n");
			break;
		case 1:
			if (list.Head().next != nullptr) {
				while (true)
				{
					cout << "表示方法を選択してください\n1:一覧表示 2:順番指定 9:戻る" << endl;
					//printf("表示方法を選択してください\n1:一覧表示 2:順番指定 9:戻る\n");
					cin >> mord;
					//scanf_s("%d", &mord);

					switch (mord)
					{
					case 1:
						cout << "要素数: " << list.Size() << endl;
						//printf("要素数: %d\n", size);

						list.Index();
						break;
					case 2:
						cout << "何番目のセルを表示しますか?" << endl;
						//printf("何番目のセルを表示しますか?\n");
						cin >> iterator;
						//scanf_s("%d", &iterator);

						list.Index(iterator);
						break;
					case 9:
						cout << "要素操作に戻る" << endl;
						//printf("要素操作に戻る\n");
						break;
					default:
						cout << "入力が間違っています" << endl;
						//printf("入力が間違っています\n");
						continue;
						break;
					}

					if (mord == 9) break;

					cout << "1:要素の表示に戻る 2:要素の操作に戻る" << endl;
					//printf("1:要素の表示に戻る 2:要素の操作に戻る\n");
					cin >> mord;
					//scanf_s("%d", &mord);
					if (mord == 2) break;
				}
			}
			else {
				cout << "表示する要素がありません" << endl;
				//printf("表示する要素がありません\n");
			}			
			break;
		case 2:	
			cout << "要素を追加する場所を指定してください" << endl;
			//cin.unsetf(ios::skipws);
			cin >> iterator;
			//cin.setf(ios::skipws);
			//printf("要素を追加する場所を指定してください\n");
			//scanf_s("%d", &iterator);

			cout << "追加する要素の値を入力してください" << endl;
			//printf("追加する要素の値を入力してください\n");
			cin >> inputValue;
			//scanf_s("%d", &inputValue);

			//insertCell = GetInsertListAddress(&head, iterator);
			//Create(insertCell, inputValue);
			//size++;
			list.Create(inputValue, iterator);

			if (iterator > list.Size()) iterator = list.Size();

			cout << "要素"<< inputValue <<"が"<< iterator <<"番目に挿入されました" << endl;
			//printf("要素%dが%d番目に挿入されました\n", inputValue, iterator);
			break;
		case 3:
			if (list.Head().next != nullptr) {
				cout << "編集したい要素の番号を指定してください" << endl;
				//printf("編集したい要素の番号を指定してください\n");
				cin >> iterator;
				//scanf_s("%d", &iterator);

				//insertCell = GetInsertListAddress(&head, iterator);

				if (!list.CheckCell(iterator)) {
					cout << iterator<< "番目の要素が見つかりませんでした" << endl;
					//printf("%d番目の要素が見つかりませんでした\n", iterator);
				}
				else {
					cout << iterator << "番目の要素の変更する値を入力してください" << endl;
					//printf("%d番目の要素の変更する値を入力してください\n", iterator);
					cin >> inputValue;
					//scanf_s("%d", &inputValue);

					list.Edit(inputValue);

					cout << iterator << "番目の要素の値が"<< inputValue <<"に変更されました。" << endl;
					//printf("%d番目の要素の値が%dに変更されました。\n", iterator, inputValue);
				}
			}
			else {
				cout << "編集できる要素がありません" << endl;
				//printf("編集できる要素がありません\n");
			}			
			break;
		case 4:
			if (list.Head().next != nullptr) {
				cout << "削除したい要素の番号を指定してください" << endl;
				//printf("削除したい要素の番号を指定してください\n");
				cin >> iterator;
				//scanf_s("%d", &iterator);

				//insertCell = GetInsertListAddress(&head, iterator);
				if (!list.CheckCell(iterator)) {
					cout << iterator << "番目の要素が見つかりませんでした" << endl;
					//printf("%d番目の要素が見つかりませんでした\n", iterator);
				}
				else {
					inputValue = list.Val(iterator);

					list.Delete();

					cout << iterator<<"番目の要素"<< inputValue << "を削除しました。" << endl;
					//printf("%d番目の要素%dを削除しました。\n", iterator, inputValue);
				}
			}
			else {
				cout << "削除できる要素がありません" << endl;
				//printf("削除できる要素がありません\n");
			}
			break;
		default:
			cout << "入力が間違っています" << endl;
			//printf("入力が間違っています\n");
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
