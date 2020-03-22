#include "WorkerManager.h"


//������Ĺ��캯����ʵ��
WorkerManager::WorkerManager()
{
	//��ʼ��
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ�������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����ڣ���������Ϊ��
	char ch;
	ifs >> ch;//����һλ
	if (ifs.eof())//�ж��Ƿ񵽴��ļ�ĩβ
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ�������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ�����
	int num = this->GetEmpNum();
	//cout << "����ְ��:"<<num << endl;
	this->m_EmpNum = num;


	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ��뵽������
	this->InitNum();

	//ѭ����ӡ���-����ʱʹ��
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ�����:  " << this->m_EmpArray[i]->m_Id
			 << "\tְ�������� " << this->m_EmpArray[i]->m_Name
			 << "\tְ�����ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/


	////��¼���е�����
	//m_EmpNum = 0;

	////��¼����Worker�����ָ��
	//m_EmpArray = NULL;
}

//ͳ���ļ��е�����
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
		//ͳ������
		num++;
	}
	return num;
}

//��ʾְ��
void WorkerManager::ShowEmp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ���ʾ��Ϣ
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//�����������������
	system("pause");
	system("cls");
}

//����Ա����Ϣ
void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲����ڣ���ȷ��" << endl;
	}
	else
	{
		int select = 0;
		cout << "������������ͣ�" << endl;
		cout << "0 - ����Ų���" << endl;
		cout << "1 - ����������" << endl;
		cin >> select;
		if (select == 0)//����Ų���
		{
			cout << "��������Ҫ���ҵ�ְ���ı�ţ�" << endl;
			int id = 0;
			cin >> id;
			if (this->IsExit(id) != -1)
			{
				cout << "���ҵ����Ϊ ��" << id << "�� ��ְ����Ϣ����:" << endl;
				this->m_EmpArray[this->IsExit(id)]->ShowInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 1)//����������
		{
			cout << "��������Ҫ���ҵ�ְ����������" << endl;
			string name = "";
			cin >> name;
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "���ҵ�����Ϊ ��" << name << "�� ��ְ����Ϣ����:" << endl;
					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (!flag)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}


	}
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//չʾ�˵�����
void WorkerManager::ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "**************��ӭʹ��ְ������ϵͳ************" << endl;
	cout << "**************   0���˳�����ϵͳ   ***********" << endl;
	cout << "**************   1������ְ����Ϣ   ***********" << endl;
	cout << "**************   2����ʾְ����Ϣ   ***********" << endl;
	cout << "**************   3��ɾ����ְְ��   ***********" << endl;
	cout << "**************   4���޸�ְ����Ϣ   ***********" << endl;
	cout << "**************   5������ְ����Ϣ   ***********" << endl;
	cout << "**************   6�����ձ������   ***********" << endl;
	cout << "**************   7����������ĵ�   ***********" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);//ֱ���˳�ϵͳ
}

//���ְ����Ϣ
void WorkerManager::AddEmp()
{
	cout << "���������ְ������:" << endl;
	int addNum = 0;
	//�����û��������ְ������
	cin >> addNum;
	if (addNum > 0)
	{
		//��ʼ���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//���¿����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����µ�����
		int id;//ְ�����
		string name;//ְ������
		int dSelect;//����
		for (int i = 0; i < addNum; i++)
		{
			cout << "�������" << i + 1 << "����Ա���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����Ա����������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			//���ݲ�̫�ķ�֧������ͬ���������
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
			//��������ְ����Ϣ�����浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//�������ļ��ı��
		this->m_FileIsEmpty = false;

		//��ʾһ����ӳɹ�
		cout << "��ӳɹ���" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
		Save();

		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������" << endl;
	}
}

//��ʼ������ȡ�ļ��е�����
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
		if (dId == 0)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//ɾ��ְ��
void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		int id = 0;
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		cin >> id;
		int index = this->IsExit(id);

		if (index != -1)//ְ�����ڲ���Ҫɾ����indexλ���ϵ�ְ��
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//ͬ�����µ��ļ���
			this->Save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���ڣ����ڷ���λ�������������ڷ���-1
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

//�޸�ְ����Ϣ
void WorkerManager::MdyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��!" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int rec = this->IsExit(id);
		if (rec != -1)
		{
			//�ͷ�ԭ��������
			delete this->m_EmpArray[rec];
			int newId = 0;
			string newName = "";
			int newDId = 0;

			cout << "���ҵ���" << id << "��ְ����������ְ���±�ţ�" << endl;;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������¸�λ��" << endl;
			cout << "1 ��ͨԱ��" << endl;
			cout << "2 ����" << endl;
			cout << "3 �ϰ�" << endl;
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
			cout << "�޸ĳɹ�!" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//ְ����Ϣ����
void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲�����!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1������Ž�����������" << endl;
		cout << "2������Ž��н�������" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//�������ֵ������Сֵ�±�
			for (int j = i; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
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
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->Save();
		this->ShowEmp();
	}
}

//����ļ�
void WorkerManager::CleanFile()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//ɾ��������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//�����������������ʵ��
WorkerManager::~WorkerManager()
{
	//�ͷŶ���������
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}