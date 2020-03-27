#include<iostream>
#include<string>
#include"Header.h"
using namespace std;

int main() {
	init();
	int action = 0;
	do{
		cout << "1.add new qiuz" << endl;
		cout << "2.show qius" << endl;
		cout << "3.exit" << endl;
		cin >> action;

		switch (action) {
		case 1:
			addquiz();
			break;
		case 2:
			showallquiz();
			pasquiz();
			break;
		case 3:
			return 0;
			break;

		}


	} while (action != 0);
		system("pause");
	return 0;
}