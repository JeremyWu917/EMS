#pragma once			//防止头文件重复包含
#include<iostream>		//包含输入输出流头文件
#include "Worker.h"
#include "Manager.h"
#include "Employee.h"
#include "Boss.h"
#include<fstream>
using namespace std;	//包含标准的命名空间
#define FILENAME "tmpFile.cfg"


//管理类
class WorkerManager
{
public://方法

	//构造函数
	WorkerManager();

	//展示菜单函数
	void ShowMenu();

	//保存文件
	void Save();
	
	//统计文件中的人数
	int GetEmpNum();

	//初始化，读取文件中的内容
	void InitNum();

	//显示职工
	void ShowEmp();

	//退出系统
	void ExitSystem();

	//添加职工信息
	void AddEmp();

	//删除职工
	void DelEmp();

	//判断职工是否存在，存在返回位置索引，不存在返回-1
	int IsExit(int id);

	//修改职工信息
	void MdyEmp();

	//查找员工信息
	void FindEmp();

	//职工信息排序
	void SortEmp();
	
	//清空文件
	void CleanFile();

public://属性

	//记录现有的人数
	int m_EmpNum;

	//记录父类Worker数组的指针
	Worker** m_EmpArray;

	//判断文件是否为空
	bool m_FileIsEmpty;

	//析构函数
	~WorkerManager();
};
