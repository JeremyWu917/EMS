#include<iostream>
#include "WorkerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

int main()
{
	//Worker* w = NULL;
	//w = new Employee(1, "����", 1);
	//w->ShowInfo();
	//delete w;

	//w = new Manager(2, "����", 2);
	//w->ShowInfo();
	//delete w;

	//w = new Boss(3, "����", 3);
	//w->ShowInfo();
	//delete w;
	//w = NULL;
	//system("pause");


	//ʵ������������һ��������Ķ���
	WorkerManager wm;
	//����һ��������¼�û���ѡ��
	int choice = 0;

	//��ѭ�����ȴ��û�����ѡ��
	while (true)
	{
		//չʾһ�²˵�
		wm.ShowMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�����ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ����Ϣ
			wm.AddEmp();
			break;
		case 2://��ʾְ����Ϣ
			wm.ShowEmp();
			break;
		case 3://ɾ����ְְ��
			wm.DelEmp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.MdyEmp();
			break;
		case 5://����ְ����Ϣ
			wm.FindEmp();
			break;
		case 6://���ձ������
			wm.SortEmp();
			break;
		case 7://��������ĵ�
			wm.CleanFile();
			break;
		default:
			system("cls");//��������
			break;
		}
	}


	//�ȴ��û������������
	system("pause");
	return 0;
}