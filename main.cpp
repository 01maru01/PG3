#include <stdio.h>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

void StringTransVec(vector<char>& vecstr, const char str[]) {
	int len = strlen(str);
	vecstr.resize(len);
	for (int i = 0; i < len; i++) {
		vecstr[i] = str[i];
	}
}

void PushBack(list<vector<char>>& lst, const char str[]) {
	vector<char> vecstr;

	StringTransVec(vecstr, str);
	lst.push_back(vecstr);
}

void PushNewStation(list<vector<char>>& lst, const char beforeStr[], const char newStr[]) {
	vector<char> vecstr;
	StringTransVec(vecstr, beforeStr);

	for (list<vector<char>>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == vecstr) {
			itr++;
			StringTransVec(vecstr, newStr);
			itr = lst.insert(itr, vecstr);
			break;
		}
	}
}

int main() {
	list<vector<char>> lst;
	vector<char> station;

	PushBack(lst, "Tokyo");
	PushBack(lst, "Yurakucho");
	PushBack(lst, "Shimbashi");
	PushBack(lst, "Hamamatsucho");
	PushBack(lst, "Tamachi");
	PushBack(lst, "Shinagawa");
	PushBack(lst, "Osaki");
	PushBack(lst, "Gotanda");
	PushBack(lst, "Meguro");
	PushBack(lst, "Ebisu");
	PushBack(lst, "Shibuya");
	PushBack(lst, "Harajuku");
	PushBack(lst, "Yoyogi");
	PushBack(lst, "Shinjuku");
	PushBack(lst, "Shin-Okubo");
	PushBack(lst, "Takadanobaba");
	PushBack(lst, "Mejiro");
	PushBack(lst, "Ikebukuro");
	PushBack(lst, "Otsuka");
	PushBack(lst, "Sugamo");
	PushBack(lst, "Komagome");
	PushBack(lst, "Tabata");
	PushBack(lst, "Nippori");
	PushBack(lst, "Uguisudani");
	PushBack(lst, "Ueno");
	PushBack(lst, "Okachimachi");
	PushBack(lst, "Akihabara");
	PushBack(lst, "Kanda");

	//	•`‰æ
	printf("1970”N\n");
	for (vector<char>& strlist : lst)
	{
		for (int i = 0; i < strlist.size(); i++)
		{
			printf("%c", strlist[i]);
		}
		printf("\n");
	}

	//	Push
	PushNewStation(lst, "Tabata", "Nishi-Nippori");
	//	•`‰æ
	printf("\n2019”N\n");
	for (vector<char>& strlist : lst)
	{
		for (int i = 0; i < strlist.size(); i++)
		{
			printf("%c", strlist[i]);
		}
		printf("\n");
	}

	//	Push
	PushNewStation(lst, "Tamachi", "Takanawa Gateway");
	//	•`‰æ
	printf("\n2022”N\n");
	for (vector<char>& strlist : lst)
	{
		for (int i = 0; i < strlist.size(); i++)
		{
			printf("%c", strlist[i]);
		}
		printf("\n");
	}

	return 0;
}