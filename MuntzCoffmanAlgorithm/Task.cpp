#include "Task.h"

#include <iostream>
#include <vector>

using namespace std;

Task::Task(int i, double processTime)
{
	this->taskId = i;
	this->processTime = processTime;
	this->timeLeft = processTime;
}


Task::~Task()
{
}

void Task::addChildren(int taskId) {
	//cout << "taskId: " << taskId;
	childrens.push_back(taskId);
}

void Task::getAllChildrens() {
	int sizeOfVector = childrens.size();
	//cout << "childrens[" << this->taskId << "]:" << endl;
	/*for (int i = 0; i < sizeOfVector; i++) {
		cout << childrens[i] << ", ";
	}
	cout << endl;*/
}

void Task::calculateLevels(int i) {
	/*cout << "Zaczynamy obliczanie poziomu:" << endl;
	if (childrens.size() > 0) {
		for (int i : childrens) {
			calculateLevels(i);
		}
		int maxChildresn
		

	}
	else {
		this->taskLevel = this->processTime;
	}*/
}