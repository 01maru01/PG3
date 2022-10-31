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

	StringTransVec(station, "Tokyo");
	lst.push_back(station);
	StringTransVec(station, "Yurakucho");
	lst.push_back(station);
	StringTransVec(station, "Shimbashi");
	lst.push_back(station);
	StringTransVec(station, "Hamamatsucho");
	lst.push_back(station);
	StringTransVec(station, "Tamachi");
	lst.push_back(station);
	//StringTransVec(station, "Takanawa Gateway");
	//lst.push_back(station);
	StringTransVec(station, "Shinagawa");
	lst.push_back(station);
	StringTransVec(station, "Osaki");
	lst.push_back(station);
	StringTransVec(station, "Gotanda");
	lst.push_back(station);
	StringTransVec(station, "Meguro");
	lst.push_back(station);
	StringTransVec(station, "Ebisu");
	lst.push_back(station);
	StringTransVec(station, "Shibuya");
	lst.push_back(station);
	StringTransVec(station, "Harajuku");
	lst.push_back(station);
	StringTransVec(station, "Yoyogi");
	lst.push_back(station);
	StringTransVec(station, "Shinjuku");
	lst.push_back(station);
	StringTransVec(station, "Shin-Okubo");
	lst.push_back(station);
	StringTransVec(station, "Takadanobaba");
	lst.push_back(station);
	StringTransVec(station, "Mejiro");
	lst.push_back(station);
	StringTransVec(station, "Ikebukuro");
	lst.push_back(station);
	StringTransVec(station, "Otsuka");
	lst.push_back(station);
	StringTransVec(station, "Sugamo");
	lst.push_back(station);
	StringTransVec(station, "Komagome");
	lst.push_back(station);
	StringTransVec(station, "Tabata");
	lst.push_back(station);
	//StringTransVec(station, "Nishi-Nippori");
	//lst.push_back(station);
	StringTransVec(station, "Nippori");
	lst.push_back(station);
	StringTransVec(station, "Uguisudani");
	lst.push_back(station);
	StringTransVec(station, "Ueno");
	lst.push_back(station);
	StringTransVec(station, "Okachimachi");
	lst.push_back(station);
	StringTransVec(station, "Akihabara");
	lst.push_back(station);
	StringTransVec(station, "Kanda");
	lst.push_back(station);

	PushNewStation(lst, "Tamachi", "Takanawa Gateway");

	//	•`‰æ
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