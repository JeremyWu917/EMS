#pragma once
#include<iostream>
using namespace std;

//�����࣬����Ҫ�κ�ʵ�֣����Բ���Ҫ����cppȥ��ʵ��
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;
	//��ȡ��λ����
	virtual string GetDeptName() = 0;

public:
	//ְ�����
	int m_Id;
	//ְ������
	string m_Name;
	//���ű��
	int m_DeptId;

private:

};