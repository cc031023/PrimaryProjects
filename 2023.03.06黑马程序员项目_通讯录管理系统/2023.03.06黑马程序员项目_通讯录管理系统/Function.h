#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
//�����ϵ�˽ṹ��.
struct Person
{
	//����.
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int m_Sex;
	//����
	string m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//���ͨѶ¼�ṹ��.
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������.
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���.
	int m_Size;

	//��¼ͨѶ¼��������.
	vector<int> v;//ÿ�β�ѯ������.
};
void showMenu();
void addPerson(Addressbooks* abs); // �����ϵ��.
void showPerson(Addressbooks* abs); // ��ʾ��ϵ��.
int findPerson(Addressbooks* abs,string name);//������ϵ��.
void deletePerson(Addressbooks* abs);//ɾ����ϵ��.
void change(Addressbooks* abs, int x);//ɾ����ʵ�ʲ���.
void changePerson(Addressbooks* abs);//�޸���ϵ��.
void deleteallPerson(Addressbooks* abs);//ɾ��������ϵ��.