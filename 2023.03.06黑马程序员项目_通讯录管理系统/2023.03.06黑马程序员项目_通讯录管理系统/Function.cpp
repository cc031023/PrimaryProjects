#include "Function.h"

//�˵�����
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
	return;
}
//1.�����ϵ��.
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����,�޷����!" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��.
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "�������Ա�:" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex;
		cin >> sex;
		while (sex != 1 && sex != 2)
		{
			cout << "�Ƿ�����!������" << endl;
			cin >> sex;
		}
		abs->personArray[abs->m_Size].m_Sex = sex;
		cout << "����������:" << endl;
		string age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		cout << "������绰:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		cout << "�������ַ:" << endl;
		string add;
		cin >> add;
		abs->personArray[abs->m_Size].m_Addr = add;
		++abs->m_Size;
		cout << "��ӳɹ�!" << endl;
		system("pause");
		system("cls");
	}
	return;
}
//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < abs->m_Size; ++i)
	{
		cout << "����: " << abs->personArray[i].m_Name << '\t';
		cout << "�Ա�: " << abs->personArray[i].m_Sex << '\t';
		cout << "����: " << abs->personArray[i].m_Age << '\t';
		cout << "�绰: " << abs->personArray[i].m_Phone << '\t';
		cout << "��ַ: " << abs->personArray[i].m_Addr << endl;
	}
	cout << "��ѯ���!" << endl;
	system("pause");
	system("cls");
	return;
}
// 3/4.������ϵ��.
int findPerson(Addressbooks* abs, string name)
{
	abs->v.clear();//����һ��.
	for (int i = 0; i < abs->m_Size; ++i)
	{
		if (abs->personArray[i].m_Name == name)
		{
			abs->v.push_back(i);
		}
	}
	return abs->v.size();
}
//ʵ��ɾ������.
void change(Addressbooks* abs, int x)
{
	for (int i = x; i < abs->m_Size - 1; ++i)
	{
		abs->personArray[i] = abs->personArray[i + 1];
	}
	--abs->m_Size;
	return;
}
//ɾ����ϵ��.
void deletePerson(Addressbooks* abs)
{
	cout << "�������ɾ��������:" << endl;
	cout << "(tips: �˳�ɾ����ϵ��������exit)" << endl;
	string name;
	cin >> name;
	if (name == "exit")
	{
		int num = findPerson(abs, name);
		if (!num)
		{
			cout << "�˳��ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "��⵽ͨѶ¼������ϵ��������exitһ��!" << endl;
			cout << "��ѡ���˳����Ǽ���ɾ����ϵ�˲���!" << endl;
			cout << "1.����\t0.�˳�" << endl;
			int h;
			cin >> h;
			if (!h)
			{
				cout << "�˳��ɹ�!" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	int num = findPerson(abs, name);
	if (!num)
	{
		cout << "���޴���!" << endl;
		system("pause");
		system("cls");
	}
	else if (num == 1)
	{
		change(abs, abs->v[0]);
		cout << "ɾ���ɹ�!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��⵽�ж����������ϵ��,��ѡ���Ӧ��ž���ɾ����λ��ϵ��:" << endl;
		cout << "tips:����all��ɾ����ѯ��������������ϵ��!" << endl;
		set<int> s;
		for (int i = 0; i < abs->v.size(); ++i)
		{
			cout << "��� " << abs->v[i] << ":" << endl;
			s.insert(abs->v[i]);//���һ�¿���ɾ��������.
			cout << "\t����: " << abs->personArray[i].m_Name << '\t';
			cout << "\t�Ա�: " << abs->personArray[i].m_Sex << '\t';
			cout << "\t����: " << abs->personArray[i].m_Age << '\t';
			cout << "\t�绰: " << abs->personArray[i].m_Phone << '\t';
			cout << "\t��ַ: " << abs->personArray[i].m_Addr << endl;
		}
		string id;
		while (cin >> id)
		{
			if (id.size() > 1)
			{
				if (id == "all")
				{
					set<int>::iterator it;
					for (it = s.begin(); it != s.end(); it++)
					{
						change(abs, *it);
					}
					cout << "������ϵ����ɾ�����!" << endl;
					system("pause");
					system("cls");
					return;
				}
				else
				{
					cout << "�Ƿ�����!������!" << endl;
				}
			}
			else
			{
				int now = id[0] - '0';
				if (!s.count(now))
				{
					cout << "�Ƿ�����!������!" << endl;
				}
				else
				{
					change(abs, now);
					s.erase(now);
					cout << "ɾ���ɹ�!" << endl;
					if (!s.size())
					{
						cout << "������ϵ����ɾ�����!" << endl;
						system("pause");
						system("cls");
						return;
					}
					else
					{
						cout << "��ѡ�����ɾ����ϵ�˻��˳�ɾ����ϵ��:" << endl;
						cout << "1.����\t0.�˳�" << endl;
						int pd;
						cin >> pd;
						if (!pd)
						{
							cout << "�˳��ɹ�!" << endl;
							system("pause");
							system("cls");
							return;
						}
						else
						{
							system("cls");
							cout << "��⵽�ж����������ϵ��,��ѡ���Ӧ��ž���ɾ����λ��ϵ��:" << endl;
							cout << "(tips: ����all��ɾ����ѯ��������������ϵ��.)" << endl;
							set<int>::iterator it;
							for (it = s.begin(); it != s.end(); it++)
							{
								cout << "���: " << *it << endl;
								cout << "\t����: " << abs->personArray[*it].m_Name << '\t';
								cout << "\t�Ա�: " << abs->personArray[*it].m_Sex << '\t';
								cout << "\t����: " << abs->personArray[*it].m_Age << '\t';
								cout << "\t�绰: " << abs->personArray[*it].m_Phone << '\t';
								cout << "\t��ַ: " << abs->personArray[*it].m_Addr << endl;
							}
						}
					}
				}
			}
		}
	}
	return;
}
void changePerson(Addressbooks* abs)
{
	string name;
	cin >> name;
	int id = findPerson(abs, name);
	if(id)
	{
		cout << "��ѯ�������:" << endl;
		set<int> s;
		for (int i = 0; i < id; ++i)
		{
			cout << "��� " << abs->v[i] << ":" << endl;
			s.insert(abs->v[i]);
			cout << "\t����: " << abs->personArray[abs->v[i]].m_Name << '\t';
			cout << "\t�Ա�: " << abs->personArray[abs->v[i]].m_Sex << '\t';
			cout << "\t����: " << abs->personArray[abs->v[i]].m_Age << '\t';
			cout << "\t�绰: " << abs->personArray[abs->v[i]].m_Phone << '\t';
			cout << "\t��ַ: " << abs->personArray[abs->v[i]].m_Addr << endl;
		}
		cout << "��ѡ�����޸ĵ���ϵ�˵����:" << endl;
		while(true)
		{
			int now;
			cin >> now;
			if (s.count(now))
			{
				string name;
				cout << "����������:" << endl;
				cin >> name;
				abs->personArray[now].m_Name = name;
				cout << "�������Ա�:" << endl;
				cout << "1 --- ��" << endl;
				cout << "2 --- Ů" << endl;
				int sex;
				cin >> sex;
				while (sex != 1 && sex != 2)
				{
					cout << "�Ƿ�����!������" << endl;
					cin >> sex;
				}
				abs->personArray[now].m_Sex = sex;
				cout << "����������:" << endl;
				string age;
				cin >> age;
				abs->personArray[now].m_Age = age;
				cout << "������绰:" << endl;
				string phone;
				cin >> phone;
				abs->personArray[now].m_Phone = phone;
				cout << "�������ַ:" << endl;
				string add;
				cin >> add;
				abs->personArray[now].m_Addr = add;
				cout << "�޸ĳɹ�!" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "�Ƿ�����!������!" << endl;
			}
		}
	}
	else
	{
		cout << "���޴���!" << endl;
		system("pause");
		system("cls");
	}
	return;
}
void deleteallPerson(Addressbooks* abs)
{
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << "������!" << endl;
		system("pause");
		system("cls");
		abs->m_Size = 0;
	}
	else
	{
		cout << "ȡ����ղ���!" << endl;
		system("pause");
		system("cls");
	}
}