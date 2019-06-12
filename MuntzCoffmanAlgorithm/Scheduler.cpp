#include "Scheduler.h"
#include <iostream>
using namespace std;


Scheduler::Scheduler(int dependencyArray[12][12],double timesOfProcess[12],int cpus)
{
	this->idleCpus = cpus;
	this->cpuNumber = cpus;

	for (int i = 0; i < 12; i++) {
		this->tasks[i] = new Task(i, timesOfProcess[i]);
	}
}


Scheduler::~Scheduler()
{
	cout << "closed" << endl;
}
