#pragma once
class Scheduler
{
private:
	int time, cpuNumber, idleCpus;
	int tasks[12] = {};
public:
	Scheduler(int dependencyArray[12][12], double timesOfProcess[12], int cpus);
	~Scheduler();
};

