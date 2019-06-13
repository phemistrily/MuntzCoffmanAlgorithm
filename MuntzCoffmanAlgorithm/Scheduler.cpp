#include "Scheduler.h"
#include "Task.h"
#include <iostream>
using namespace std;


Scheduler::Scheduler(int dependencyArray[12][12],double timesOfProcess[12],int cpus)
{
	this->idleCpus = cpus;
	this->cpuNumber = cpus;

	for (int i = 0; i < 12; i++) {
		TaskArray[i] = new Task(i, timesOfProcess[i]);
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << dependencyArray[i][j];
			if (dependencyArray[i][j] > 0) {
				TaskArray[i]->addChildren(j);
			}
		}
		cout << endl;
	}
	
	for (int i = 0; i < 12; i++)
	{
		TaskArray[i]->getAllChildrens();
	}

	for (int i = 0; i < 12; i++) {
		TaskArray[i]->calculateLevels();
	}
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
