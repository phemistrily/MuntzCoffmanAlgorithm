#include "Scheduler.h"
#include "Task.h"
#include <iostream>
using namespace std;

void Scheduler::printTasks()
{

	for (int i = 0; i < 12; i++)
	{
		cout << endl << "Task: " << TaskArray[i]->taskId + 1 << endl;
		cout << "children: ";
		for (int j = 0; j < TaskArray[i]->childrens.size(); j++)
		{
			cout << TaskArray[i]->childrens[j] + 1 << " ";
		}

		cout << endl << "parents: ";

		for (int j = 0; j < TaskArray[i]->parents.size(); j++)
		{
			cout << TaskArray[i]->parents[j] + 1 << " ";
		}
	}

	/*
		for (int i = 0; i < 12; i++)
		{
			cout << endl << "Task: " << TaskArray[i]->taskId << " (" << TaskArray[i]->taskLevel << ")";
			if (TaskArray[i]->isDone())
			{
				cout << "*";
			}
			if (TaskArray[i]->isBlocked())
			{
				cout << "#";
			}
		}
		*/
}

Scheduler::Scheduler(int dependencyArray[12][12], double timesOfProcess[12], int cpus)
{
	this->idleCpus = cpus;
	this->cpuNumber = cpus;
	this->time = 0;

	for (int i = 0; i < 12; i++) {
		this->TaskArray.push_back(new Task(i, timesOfProcess[i]));
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

	printTasks();

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
	cout << "closed" << endl;
}

void Scheduler::sortTasks()
{
	int i, j;

	for (i = 11; i > 0; i--)
	{
		for (j = 11; j > 0 + 11 - i; j--)
		{
			double a = TaskArray[j]->taskLevel;
			double b = TaskArray[j - 1]->taskLevel;

			if (a > b)
			{
				Task temp = *TaskArray[j];
				*TaskArray[j] = *TaskArray[j - 1];
				*TaskArray[j - 1] = temp;
			}
		}
	}

	for (i = 0, j = 0; i < 12 && j < 12; i++, j++)
	{
		if (TaskArray[i]->isBlocked() || TaskArray[i]->isDone())
		{
			Task* temp = TaskArray[i];
			TaskArray.erase(TaskArray.begin() + i);
			TaskArray.push_back(temp);
			i--;
		}
	}
}


void Scheduler::next() {

	this->sortTasks();

	vector<Task*> current;
	current.clear();

	// TODO: Collect process with the highest priority
	current.push_back(TaskArray[0]);
	--idleCpus;
	int i = 1;
	while (i < 12 &&
		(TaskArray[i]->taskLevel == current[i - 1]->taskLevel || idleCpus > 0)) {
		current.push_back(TaskArray[i]); // add top priority task
		--idleCpus;
		++i;
	}

	//printTasks();

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
					for (int u = 0; u < 12; u++)
					{
						if (s == TaskArray[u]->taskId)
							TaskArray[u]->deleteParent(t->taskId);
					}

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

	//printTasks();

	idleCpus = cpuNumber;
	++time;
	cout << endl;
}