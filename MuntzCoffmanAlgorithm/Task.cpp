#include "Task.h"

#include <vector>


Task::Task(int i, double processTime)
{
	this->processTime = processTime;
	this->timeLeft = processTime;
}


Task::~Task()
{
}
