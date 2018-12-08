#include "pch.h"
#include "TProc.h"
#include <iostream>
using namespace std;

TProc::TProc(int Rate)
{
	ProcRate = Rate;
	JobId = -1;
}

int TProc::IsProcBusy()
{
	if (rand() % 100 < ProcRate || JobId == -1)
	{
		return 0;
	}
	return 1;

}
void TProc::RunNewJob(int JI)
{
	JobId = JI;
}
