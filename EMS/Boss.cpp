#include"Boss.h"

//���캯��
Boss::Boss(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}
//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ�𣺹���˾���е�����" << endl;
}
//��ȡ��λ����
string Boss::GetDeptName()
{
	return string("�ϰ�");
}