#pragma once
#include <vector>
class Task
{
private:
	
public:
	int taskId = 0;
	double timeLeft = 0, processTime = 0;
	double taskLevel = 0;
	std::vector <int> childrens;
	std::vector <int> parents;
	Task(int i, double processTime);
	~Task();
	void addChildren(int taskId);
	void addParent(int taskId);
	void deleteParent(int taskId);
	void getAllChildrens();
	void calculateLevels(int i);
	bool isBlocked();
	bool isDone();
	void execute(double cpuTime);
	std::vector<int> getHisChildrens();
};

