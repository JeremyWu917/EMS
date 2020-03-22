#pragma once
#include "Worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker
{
public:

	//构造函数
	Employee(int id, string name, int dID);
	//显示个人信息
	virtual void ShowInfo();
	//获取岗位名称
	virtual string GetDeptName();

};
