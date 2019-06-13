#include "Scheduler.h"
#include "Task.h"
#include <iostream>
using namespace std;


Scheduler::Scheduler(int dependencyArray[12][12],double timesOfProcess[12],int cpus)
{
	this->idleCpus = cpus;
	this->cpuNumber = cpus;

	for (int i = 0; i < 12; i++) {
		this->TaskArray[i] = new Task(i, timesOfProcess[i]);
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			//cout << dependencyArray[i][j];
			if (dependencyArray[i][j] > 0) {
				this->TaskArray[i]->addChildren(j);
			}
		}
		//cout << endl;
	}
	
	for (int i = 0; i < 12; i++)
	{
		this->TaskArray[i]->getAllChildrens();
	}
	cout << "Zaczynamy obliczanie poziomow dla zadan:" << endl;
	for (int i = 0; i < 12; i++) {
		this->calculateLevels(i);
	}

	for (int i = 0; i < 12; i++) {
		this->getTaskLevel(i);
	}
}

void Scheduler::calculateLevels(int taskId) {
	//cout << "Zaczynamy obliczanie poziomu:" << endl;
	int childrensSize = this->TaskArray[taskId]->childrens.size();
	if (childrensSize > 0) {
		for (int i : this->TaskArray[taskId]->childrens) {
			this->calculateLevels(i);
		}
		int maxChildrenLevel = this->findMaxLevelOfChildrens(taskId);
		this->TaskArray[taskId]->taskLevel = this->TaskArray[taskId]->processTime + maxChildrenLevel;
	}
	else {
		this->TaskArray[taskId]->taskLevel = this->TaskArray[taskId]->processTime;
	}
}

int Scheduler::findMaxLevelOfChildrens(int taskId) {
	int maxLevel = 0;
	for (int i : this->TaskArray[taskId]->childrens) {
		if (maxLevel < this->TaskArray[i]->taskLevel)
		{
			maxLevel = this->TaskArray[i]->taskLevel;
		}
	}
	//cout << "maxLevel: " << maxLevel << endl;
	return maxLevel;
}

void Scheduler::getTaskLevel(int taskId) {
	cout << "Poziom zadania " << taskId << " wynosi: ";
	cout << this->TaskArray[taskId]->taskLevel << endl;
}

Scheduler::~Scheduler()
{
	for (int i = 0; i < 12; ++i)
	{
		delete[] TaskArray[i];
	}
	delete[] TaskArray;
	cout << "closed" << endl;
}
