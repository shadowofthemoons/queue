#include "pch.h"
#include "TJobStream.h"
#include <iostream>
using namespace std;


TJobStream::TJobStream(int Int�ns)
{
	JobInt�ns = Int�ns;
}


int TJobStream::GetNewJob()
{
	if (rand() % 100< JobInt�ns)
	{
		return 1;
	}
	return 0;
}