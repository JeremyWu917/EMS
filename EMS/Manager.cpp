#include"Manager.h"

//���캯��
Manager::Manager(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}
//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ������ϰ尲�ŵ����񣬲����·��������ͨ��Ա����" << endl;
}
//��ȡ��λ����
string Manager::GetDeptName()
{
	return string("����");
}
