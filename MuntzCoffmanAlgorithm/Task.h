#pragma once
class Task
{
private:
	int parent = 0, processTime = 0;
public:
	Task(int, int);
	~Task();
};

