#pragma once

#include<iostream>
#include<string>
using namespace std;

struct quaestion {
	string questiontext;
	string trueanswer;

};
struct quiz {
	string title;
	quaestion question[5];

};
void insertquiz (quiz quiz);
void addquiz();
void showallquiz();
void init();
void pasquiz();