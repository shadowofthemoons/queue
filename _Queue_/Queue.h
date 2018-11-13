#pragma once

class Queue
{
	int* pMem; // указатель на массив элементов
	int MaxSize; // размер пам€ти дл€ —ƒ
	int Hi; // индекс вершины стека
	int Ei; // индекс конца очереди 
	int Sizeel;//текущее кол эл 
	int GetNextIndex(int index);
public:
	Queue(int Size = 25);//конструктор
	~Queue(); //деструктор
	int IsEmpty(void) const; // контроль пустоты
	int IsFull(void) const; // контроль переполнени€
	void Put(const int &Val);// добавить значение
	int Get(void);
};
