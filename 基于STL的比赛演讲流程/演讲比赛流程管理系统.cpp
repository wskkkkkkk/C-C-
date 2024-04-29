#include<iostream>
#include<string>
#include"speechManager.h"
#include<ctime>
using namespace std;
int main() {
	srand((unsigned int)time(NULL));
	speechManager sm;
	int choice;
	
	while (1) {
		sm.menu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			sm.start();
			break;
		}
		case 2: {
			sm.showRecord();
			break;
		}
		case 3: {
			sm.clearRecord();
			break;
		}
		case 0: {
			sm.exitSystem();
			break;
		}
		default:
			system("clas");
			break;
		}
	
	}
	return 0;
}