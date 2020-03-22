#include "WorkerManager.h"


//管理类的构造函数空实现
WorkerManager::WorkerManager()
{
	//初始化
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组的指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在，但是数据为空
	char ch;
	ifs >> ch;//右移一位
	if (ifs.eof())//判断是否到达文件末尾
	{
		//文件为空
		//cout << "文件为空" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组的指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在
	int num = this->GetEmpNum();
	//cout << "共有职工:"<<num << endl;
	this->m_EmpNum = num;


	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存入到数组中
	this->InitNum();

	//循环打印输出-测试时使用
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号:  " << this->m_EmpArray[i]->m_Id
			 << "\t职工姓名： " << this->m_EmpArray[i]->m_Name
			 << "\t职工部门： " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/


	////记录现有的人数
	//m_EmpNum = 0;

	////记录父类Worker数组的指针
	//m_EmpArray = NULL;
}

//统计文件中的人数
int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数
		num++;
	}
	return num;
}

//显示职工
void WorkerManager::ShowEmp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口显示信息
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//按任意键继续、清屏
	system("pause");
	system("cls");
}

//查找员工信息
void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者不存在，请确认" << endl;
	}
	else
	{
		int select = 0;
		cout << "请输入查找类型：" << endl;
		cout << "0 - 按编号查找" << endl;
		cout << "1 - 按姓名查找" << endl;
		cin >> select;
		if (select == 0)//按编号查找
		{
			cout << "请输入您要查找的职工的编号：" << endl;
			int id = 0;
			cin >> id;
			if (this->IsExit(id) != -1)
			{
				cout << "查找到编号为 【" << id << "】 的职工信息如下:" << endl;
				this->m_EmpArray[this->IsExit(id)]->ShowInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (select == 1)//按姓名查找
		{
			cout << "请输入您要查找的职工的姓名：" << endl;
			string name = "";
			cin >> name;
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "查找到姓名为 【" << name << "】 的职工信息如下:" << endl;
					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (!flag)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误！" << endl;
		}


	}
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

//展示菜单函数
void WorkerManager::ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "**************欢迎使用职工管理系统************" << endl;
	cout << "**************   0、退出管理系统   ***********" << endl;
	cout << "**************   1、增加职工信息   ***********" << endl;
	cout << "**************   2、显示职工信息   ***********" << endl;
	cout << "**************   3、删除离职职工   ***********" << endl;
	cout << "**************   4、修改职工信息   ***********" << endl;
	cout << "**************   5、查找职工信息   ***********" << endl;
	cout << "**************   6、按照编号排序   ***********" << endl;
	cout << "**************   7、清空所有文档   ***********" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);//直接退出系统
}

//添加职工信息
void WorkerManager::AddEmp()
{
	cout << "请输入添加职工数量:" << endl;
	int addNum = 0;
	//保存用户新输入的职工数量
	cin >> addNum;
	if (addNum > 0)
	{
		//开始添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;

		//重新开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新的数据
		int id;//职工编号
		string name;//职工姓名
		int dSelect;//部门
		for (int i = 0; i < addNum; i++)
		{
			cout << "请输入第" << i + 1 << "个新员工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新员工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			//根据不太的分支创建不同的子类对象
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工信息，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新下文件的标记
		this->m_FileIsEmpty = false;

		//提示一下添加成功
		cout << "添加成功了" << addNum << "名新职工" << endl;

		//保存数据到文件中
		Save();

		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入有误" << endl;
	}
}

//初始化，读取文件中的内容
void WorkerManager::InitNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 0)//普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else//老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//删除职工
void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空!" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入您要删除的职工编号：" << endl;
		cin >> id;
		int index = this->IsExit(id);

		if (index != -1)//职工存在并且要删除掉index位置上的职工
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//同步更新到文件中
			this->Save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在，存在返回位置索引，不存在返回-1
int WorkerManager::IsExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//修改职工信息
void WorkerManager::MdyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空!" << endl;
	}
	else
	{
		cout << "请输入你要修改的职工编号：" << endl;
		int id;
		cin >> id;
		int rec = this->IsExit(id);
		if (rec != -1)
		{
			//释放原来的数据
			delete this->m_EmpArray[rec];
			int newId = 0;
			string newName = "";
			int newDId = 0;

			cout << "查找到：" << id << "号职工，请输入职工新编号：" << endl;;
			cin >> newId;
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入新岗位：" << endl;
			cout << "1 普通员工" << endl;
			cout << "2 经理" << endl;
			cout << "3 老板" << endl;
			cin >> newDId;

			Worker* worker = NULL;
			switch (newDId)
			{
			case 1:
				worker = new Employee(newId, newName, newDId);
				break;
			case 2:
				worker = new Manager(newId, newName, newDId);
				break;
			case 3:
				worker = new Boss(newId, newName, newDId);
				break;
			default:
				break;
			}
			this->m_EmpArray[rec] = worker;
			this->Save();
			cout << "修改成功!" << endl;
		}
		else
		{
			cout << "修改失败，查无此人!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//职工信息排序
void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者不存在!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按编号进行升序排列" << endl;
		cout << "2、按编号进行降序排列" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//声明最大值或者最小值下标
			for (int j = i; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = tmp;
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->Save();
		this->ShowEmp();
	}
}

//清空文件
void WorkerManager::CleanFile()
{
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、取消" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区的指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//管理类的析构函数空实现
WorkerManager::~WorkerManager()
{
	//释放堆区的数据
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}