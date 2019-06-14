#include <iostream>
#include "Scheduler.h"
#include "main.h"

using namespace std;

int main() {
	int tasks = 12;
	int cpus = 2;
	int dependencyArray[12][12] = { 
		{0,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,0,0},
		{0,0,0,0,1,0,1,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0}
	};
	double timeOfTask[12] = { 3,6,7,2,3,7,2,3,11,9,7,4 };
	cout << "Zadania liczone sa od 0, w notacji amerykanskiej" << endl;
	Scheduler *sched = new Scheduler(dependencyArray, timeOfTask, cpus);

	sched->next();
	while (sched->doneTasks != 12) {
		sched->next();
	}
	cout << endl;
	system("PAUSE");
	return 0;
}