#include "pch.h"
#include "TJobStream.h"
#include <iostream>
using namespace std;


TJobStream::TJobStream(int Intåns)
{
	JobIntåns = Intåns;
}


int TJobStream::GetNewJob()
{
	if (rand() % 100< JobIntåns)
	{
		return 1;
	}
	return 0;
}