

#include "pch.h"
#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue st(5);
	cout << st.IsEmpty();
	int a;
	while (!st.IsFull())
	{
		cin >> a;
		st.Put(a);
	}
	cout << st.Get();
	if (!st.IsFull())
	{
		cin >> a;
		st.Put(a);
	}
	cout << st.Get();
}

