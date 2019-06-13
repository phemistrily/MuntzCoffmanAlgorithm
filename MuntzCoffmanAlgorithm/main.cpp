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

	Scheduler *sched = new Scheduler(dependencyArray, timeOfTask, cpus);

	cout << endl;
	system("PAUSE");
	return 0;
}