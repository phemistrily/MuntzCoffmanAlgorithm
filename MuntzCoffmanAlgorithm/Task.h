#pragma once
#include <vector>
class Task
{
private:
	
public:
	int parent = 0, taskId = 0;
	double timeLeft = 0, processTime = 0;
	double taskLevel = 0;
	std::vector <int> childrens;
	Task(int i, double processTime);
	~Task();
	void addChildren(int taskId);
	void getAllChildrens();
	void calculateLevels(int i);
};

