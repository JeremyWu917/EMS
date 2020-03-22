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
	//w = new Employee(1, "张三", 1);
	//w->ShowInfo();
	//delete w;

	//w = new Manager(2, "李四", 2);
	//w->ShowInfo();
	//delete w;

	//w = new Boss(3, "王五", 3);
	//w->ShowInfo();
	//delete w;
	//w = NULL;
	//system("pause");


	//实例化（创建）一个管理类的对象
	WorkerManager wm;
	//声明一个变量记录用户的选择
	int choice = 0;

	//死循环，等待用户做出选择
	while (true)
	{
		//展示一下菜单
		wm.ShowMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出管理系统
			wm.ExitSystem();
			break;
		case 1://增加职工信息
			wm.AddEmp();
			break;
		case 2://显示职工信息
			wm.ShowEmp();
			break;
		case 3://删除离职职工
			wm.DelEmp();
			break;
		case 4://修改职工信息
			wm.MdyEmp();
			break;
		case 5://查找职工信息
			wm.FindEmp();
			break;
		case 6://按照编号排序
			wm.SortEmp();
			break;
		case 7://清空所有文档
			wm.CleanFile();
			break;
		default:
			system("cls");//清屏操作
			break;
		}
	}


	//等待用户按任意键继续
	system("pause");
	return 0;
}