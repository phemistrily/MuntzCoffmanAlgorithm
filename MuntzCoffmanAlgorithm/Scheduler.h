#pragma once
#include "Task.h"
class Scheduler
{
private:
	int time, cpuNumber, idleCpus;
	Task** TaskArray = new Task*[12];
public:
	Scheduler(int dependencyArray[12][12], double timesOfProcess[12], int cpus);
	~Scheduler();
};

