#pragma once
#include<iostream>
using namespace std;

//纯虚类，不需要任何实现，所以不需要创建cpp去做实现
class Worker
{
public:

	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string GetDeptName() = 0;

public:
	//职工编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门编号
	int m_DeptId;

private:

};