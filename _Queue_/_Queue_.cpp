

#include "pch.h"
#include <iostream>
#include "Queue.h"
#include "TProc.h"
#include "TJobStream.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int ProcRat, JobIntеns, ncycles;
	int ignor = 0,time=0, completed = -1, created = 0, downtime = 0,j=0,f=0;
	cout << "введите количество циклов ";
	cin >> ncycles;
	cout << "введите интенсивность потока задач ";
	cin >> JobIntеns;
	cout << "введите  производительность процессора ";
	cin >>  ProcRat;
	cout << endl;
	Queue q(3);
	TJobStream job(JobIntеns);
	TProc proc(ProcRat);
	if (ncycles <= 20) {
		for (int i = 0; i < ncycles; i++)
		{
			cout << "цикл номер";
			cout.width(3);
			cout << i;
			cout.width(19);
			if (job.GetNewJob())
			{
				created++;
				cout << "задача создана";
				cout.width(25);
				if (!q.IsFull())
				{
					q.Put(i);
					cout << "задача добавлена";
				}
				else
				{
					ignor++;
					cout << "задача проигнорированна";
				}
			}
			else
			{
				cout << "задача не создана";
				cout.width(25);
				cout << "задача не добавллена";
			}
			cout<<"  ";
			if (!proc.IsProcBusy())
			{
				if (f)
				{
					cout << "задча завершена, ";
				}
				if (!q.IsEmpty())
				{
					cout << "начинается выполнение новой задачи ";
					time++;
					completed++;
					proc.RunNewJob(q.Get());
					j = i;
					f++;
				}
				else
				{
					cout << "процессор простаивает";
					j = i;
					f=0;
					downtime++;
				    proc.RunNewJob(-1);
				}
			}
			else
			{
				f++;
				time++;
				cout << "процессор продолжает решение задачи";
			}
			cout << endl;
		}
		
	}
	else
	{
		for (int i = 0; i < ncycles; i++)
		{
			if (job.GetNewJob())
			{
				created++;
				if (!q.IsFull())
				{
					q.Put(i);
				}
				else
				{
					ignor++;
				}
				if (!proc.IsProcBusy())
				{
					if (!q.IsEmpty())
					{
						time++;
						completed++;
						proc.RunNewJob(q.Get());
						j = i;
						f++;
					}
					else
					{
						j = i;
						f = 0;
						downtime++;
						proc.RunNewJob(-1);
					}
				}
				else
				{
					f++;
					time++;
				}
			}
		}
	}
	time = time + j - ncycles;
	cout << "количество всего созданных задач " << created << " за " << ncycles << " циклов" << endl;
	cout << "процент проигнорированных задач " << double(ignor) / ncycles * 100 <<"%"<< endl;
	cout << "процент простоя процессора " << double(downtime) / ncycles * 100 << "%" << endl;
	cout << "среднее время выполнения задачи " << double(time)/ completed << " такта" << endl;
	return 0;
}



