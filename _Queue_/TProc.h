#pragma once
class TProc 
{
private:
	double ProcRate; // ������������������ ����������
	int JobId; // Id ������������ �������
public:
	TProc(int Rate);
	int IsProcBusy(); // ��������� �����?
	void RunNewJob(int JI); // ���������� � ���������� ������ �������
};