#pragma once
class TProc 
{
private:
	double ProcRate; // производительность процессора
	int JobId; // Id выполняемого задания
public:
	TProc(int Rate);
	int IsProcBusy(); // процессор занят?
	void RunNewJob(int JI); // приступить к выполнению нового задания
};