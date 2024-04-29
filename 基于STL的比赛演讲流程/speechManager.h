#pragma once
#include<iostream>
#include<map>
#include"player.h"
#include<algorithm>
#include<ctime>	
#include<vector>
#include <random>
#include <numeric>
#include <fstream>
using namespace std;

class speechManager {
public:
	speechManager();
	void menu();
	void start();
	void saveRecord();
	void getRecord();
	void showRecord();
	void exitSystem();
	void clearRecord();
	bool fileIsEmpty;
	map<int, vector<string>>m_Record;
};
