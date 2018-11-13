#include "pch.h"
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int Size)
{
	pMem = new int[Size];
	if (pMem == nullptr)
	{
		cout << "eror mem";
		throw 1;
	}
	MaxSize = Size;
	Hi = 0;
	Ei = 0;
	Sizeel = 0;
}

int Queue:: GetNextIndex(int index)
{
	return ++index%MaxSize;
}

Queue::~Queue()
{
	delete[] pMem;
}

int Queue::IsEmpty(void) const
{
	return Sizeel <= 0;
}

int Queue::IsFull(void) const
{
	return Sizeel >= MaxSize;
}

void Queue::Put(const int &Val)
{
	pMem[GetNextIndex(Hi)] = Val;
	Hi = GetNextIndex(Hi);
	Sizeel++;
}

int Queue::Get(void)
{
	int n = Ei;
	Sizeel--;
	Ei = GetNextIndex(Hi);
	return pMem[n];
}
