#pragma once			//��ֹͷ�ļ��ظ�����
#include<iostream>		//�������������ͷ�ļ�
#include "Worker.h"
#include "Manager.h"
#include "Employee.h"
#include "Boss.h"
#include<fstream>
using namespace std;	//������׼�������ռ�
#define FILENAME "tmpFile.cfg"


//������
class WorkerManager
{
public://����

	//���캯��
	WorkerManager();

	//չʾ�˵�����
	void ShowMenu();

	//�����ļ�
	void Save();
	
	//ͳ���ļ��е�����
	int GetEmpNum();

	//��ʼ������ȡ�ļ��е�����
	void InitNum();

	//��ʾְ��
	void ShowEmp();

	//�˳�ϵͳ
	void ExitSystem();

	//���ְ����Ϣ
	void AddEmp();

	//ɾ��ְ��
	void DelEmp();

	//�ж�ְ���Ƿ���ڣ����ڷ���λ�������������ڷ���-1
	int IsExit(int id);

	//�޸�ְ����Ϣ
	void MdyEmp();

	//����Ա����Ϣ
	void FindEmp();

	//ְ����Ϣ����
	void SortEmp();
	
	//����ļ�
	void CleanFile();

public://����

	//��¼���е�����
	int m_EmpNum;

	//��¼����Worker�����ָ��
	Worker** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//��������
	~WorkerManager();
};
