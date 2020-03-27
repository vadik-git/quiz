#include "Header.h"
#include<iostream>
#include<string>
#include<fstream>;


quiz* quizes;
int countquizes = 0;
const int countquestion = 5;

void insertquiz(quiz getquiz)
{
	quiz*temp = new quiz[countquizes + 1];
	for (int i = 0; i < countquizes; i++) {
		temp[i] = quizes[i];
	}
	temp[countquizes] = getquiz;
	countquizes++;
	quizes = new quiz[countquizes];
	for (int i = 0; i < countquizes; i++) {
		quizes[i] = temp[i];
	}
	delete[]temp;
}
void init()
{
	ifstream fin;
	fin.open("quiz.txt");
	bool isopen = fin.is_open();
	if (isopen == true) {
		cout << "open" << endl;
		while (!fin.eof()) {
			quiz getquiz;
			fin >> getquiz.title;
			for (int i = 0; i < countquestion; i++) {
				
				fin >> getquiz.question[i].questiontext;
				fin >> getquiz.question[i].trueanswer;
			}
			insertquiz(getquiz);
		}
	}
	else {
		cout << "eroor" << endl;
	}
}

void pasquiz()
{

	int selectquiz = 0;
	int score = 0;
	cout << "enter numb quiz" << endl;
	cin >> selectquiz;
	selectquiz--;
	cout << endl;
	cout << "you start quiz" <<quizes[selectquiz].title<< endl;
	for (int i = 0; i < countquestion; i++)
	{
		string tempanswer = "";

		cout << i + 1 << "-" << quizes[selectquiz].question[i].questiontext << endl;
		cout << "you answer" << endl;
		cin >> tempanswer;
		if (tempanswer == quizes[selectquiz].question->trueanswer) {
			score += 20;
			cout << "goood vidpovid" << endl;
		}
		else {
			cout << "falsee vidpovid" << endl;
		}
	}
	cout << "your result" << score << "/100" << endl;


}

void addquiz()
{
	ofstream fout;
	fout.open("quiz.txt",fstream::app );


	bool isopen = fout.is_open();
	if (isopen == true) {

		cout << "file open" << endl;
		quiz*temp = new quiz[countquizes + 1];
		for (int i = 0; i < countquizes; i++) {
			temp[i] = quizes[i];
		}
		cout << "enter title for quiz ->_";
		cin >> temp[countquizes].title;

		for (int i = 0; i < countquestion; i++) {
			cout << "enter " << i + 1 << "/" << countquestion << "question ->";
			cin >> temp[countquizes].question[i].questiontext;
			cout << "enter correct answer fot this question ->";
			cin >> temp[countquizes].question[i].trueanswer;




		}

		fout << temp[countquizes].title;
		for (int i = 0; i < countquestion; i++) {
			fout << temp[countquizes].question[i].questiontext;
			fout << temp[countquizes].question[i].trueanswer;
		}
		countquizes++;
		quizes = new quiz[countquizes];
		for (int i = 0; i < countquizes; i++) {
			quizes[i] = temp[i];
		}

		delete[]temp;
	}
	else {
		cout << "eroor" << endl;
	}
}

void showallquiz()
{
	if (countquizes != 0) {


		for (int i = 0; i < countquizes; i++) {
			cout << i + 1 << "." << quizes[i].title << endl;
		}
	}
	else {
		cout << "eroor" << endl;
	}
}


