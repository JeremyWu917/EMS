#include"Employee.h"

//���캯��
Employee::Employee(int id, string name, int dID)
{
	//��ʼ������̳л���������
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}

//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ����ɾ����ŵ�����" << endl;
}

//��ȡ��λ����
string Employee::GetDeptName()
{
	return string("Ա��");
}