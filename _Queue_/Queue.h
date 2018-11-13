#pragma once

class Queue
{
	int* pMem; // ��������� �� ������ ���������
	int MaxSize; // ������ ������ ��� ��
	int Hi; // ������ ������� �����
	int Ei; // ������ ����� ������� 
	int Sizeel;//������� ��� �� 
	int GetNextIndex(int index);
public:
	Queue(int Size = 25);//�����������
	~Queue(); //����������
	int IsEmpty(void) const; // �������� �������
	int IsFull(void) const; // �������� ������������
	void Put(const int &Val);// �������� ��������
	int Get(void);
};
