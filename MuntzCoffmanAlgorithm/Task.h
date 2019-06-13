#pragma once
#include <vector>
class Task
{
private:
	int parent = 0;
	double timeLeft = 0, processTime = 0;
	std::vector <int> childrens;
public:
	Task(int i, double processTime);
	~Task();
};

