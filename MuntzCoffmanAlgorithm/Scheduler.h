#pragma once
#include "Task.h"
#include <vector.>
class Scheduler
{
private:
	int time, cpuNumber, idleCpus;
	std::vector<Task*> TaskArray;
public:
	int doneTasks = 0;
	Scheduler(int dependencyArray[12][12], double timesOfProcess[12], int cpus);
	void calculateLevels(int taskId);
	int findMaxLevelOfChildrens(int taskId);
	void getTaskLevel(int taskId);
	void getNextTimeFromTimeline();
	~Scheduler();
	void sortTasks();
	void next();
	void printTasks();
};