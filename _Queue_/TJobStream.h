#pragma once
class TJobStream
{
private:
	double JobIntеns; // интенсивность потока задач
public:
	TJobStream(int Intеns);
	int GetNewJob(); // генерация нового задания
};