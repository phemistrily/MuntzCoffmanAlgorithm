#include "Scheduler.h"
#include "Task.h"
#include <iostream>
using namespace std;


Scheduler::Scheduler(int dependencyArray[12][12],double timesOfProcess[12],int cpus)
{
	this->idleCpus = cpus;
	this->cpuNumber = cpus;
	this->time = 0;

	for (int i = 0; i < 12; i++) {
		this->TaskArray[i] = new Task(i, timesOfProcess[i]);
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			//cout << dependencyArray[i][j];
			if (dependencyArray[i][j] > 0) {
				this->TaskArray[i]->addChildren(j);
				this->TaskArray[j]->addParent(i);
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
	cout << this->TaskArray[taskId]->taskLevel;
	cout << " Zadanie bedzie wykonywane przez: ";
	cout << this->TaskArray[taskId]->processTime << endl;
}

void Scheduler::getNextTimeFromTimeline() {
	//
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

void Scheduler::sortTasks()
{
	int i, j;
	cout << " blah 1 ";
	for (i = 0; i < 12; i++)
	{
		cout << TaskArray[i]->taskLevel << " ";
	}
	cout << endl;

	for (i = 11; i > 0; i--)
	{
		for (j = 11; j > 0 + 11 - i; j--)
		{

			double a = TaskArray[j]->taskLevel;
			double b = TaskArray[j - 1]->taskLevel;

			if (a > b || TaskArray[j - 1]->isDone() || TaskArray[j - 1]->isBlocked())
			{
				Task temp = *TaskArray[j];
				*TaskArray[j] = *TaskArray[j - 1];
				*TaskArray[j - 1] = temp;
			}
		}
	}

	for (i = 0; i < 12; i++)
	{
		cout << TaskArray[i]->taskLevel << " ";
	}
	cout << endl;

}


void Scheduler::next() {

	this->sortTasks();

	vector<Task*> current;
	current.clear();

	// TODO: Collect process with the highest priority
	current.push_back(TaskArray[0]);
	--idleCpus;
	int i = 1;
	while (i < 12 && !TaskArray[i]->isDone() && (TaskArray[i]->taskLevel == current[i - 1]->taskLevel || idleCpus > 0)) {
		current.push_back(TaskArray[i]); // add top priority task
		--idleCpus;
		++i;
	}

	cout << time << ": ";

	double beta = ((double)cpuNumber) / current.size();
	for (Task* t : current) {
		if (!t->isDone())
		{
			cout << t->taskId;
			t->execute(beta);
			if (t->isDone()) {
				vector <int> hisChildrens = t->getHisChildrens();
				for (int s : hisChildrens) {
					Task temp = *TaskArray[s];
					temp.deleteParent(t->taskId);
				}
				this->doneTasks++;
				cout << "* ";
				continue;
			}
			else
			{
				cout << " ";
			}
		}
	}

	idleCpus = cpuNumber;
	++time;
	cout << endl;
}