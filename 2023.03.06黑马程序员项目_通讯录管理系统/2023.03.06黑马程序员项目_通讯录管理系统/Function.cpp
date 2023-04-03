#include "Function.h"

//菜单界面
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
	return;
}
//1.添加联系人.
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满,无法添加!" << endl;
		return;
	}
	else
	{
		//添加具体联系人.
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "请输入性别:" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex;
		cin >> sex;
		while (sex != 1 && sex != 2)
		{
			cout << "非法输入!请重试" << endl;
			cin >> sex;
		}
		abs->personArray[abs->m_Size].m_Sex = sex;
		cout << "请输入年龄:" << endl;
		string age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		cout << "请输入电话:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		cout << "请输入地址:" << endl;
		string add;
		cin >> add;
		abs->personArray[abs->m_Size].m_Addr = add;
		++abs->m_Size;
		cout << "添加成功!" << endl;
		system("pause");
		system("cls");
	}
	return;
}
//2.显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < abs->m_Size; ++i)
	{
		cout << "姓名: " << abs->personArray[i].m_Name << '\t';
		cout << "性别: " << abs->personArray[i].m_Sex << '\t';
		cout << "年龄: " << abs->personArray[i].m_Age << '\t';
		cout << "电话: " << abs->personArray[i].m_Phone << '\t';
		cout << "地址: " << abs->personArray[i].m_Addr << endl;
	}
	cout << "查询完毕!" << endl;
	system("pause");
	system("cls");
	return;
}
// 3/4.查找联系人.
int findPerson(Addressbooks* abs, string name)
{
	abs->v.clear();//重置一下.
	for (int i = 0; i < abs->m_Size; ++i)
	{
		if (abs->personArray[i].m_Name == name)
		{
			abs->v.push_back(i);
		}
	}
	return abs->v.size();
}
//实操删除操作.
void change(Addressbooks* abs, int x)
{
	for (int i = x; i < abs->m_Size - 1; ++i)
	{
		abs->personArray[i] = abs->personArray[i + 1];
	}
	--abs->m_Size;
	return;
}
//删除联系人.
void deletePerson(Addressbooks* abs)
{
	cout << "请输入待删除人姓名:" << endl;
	cout << "(tips: 退出删除联系人请输入exit)" << endl;
	string name;
	cin >> name;
	if (name == "exit")
	{
		int num = findPerson(abs, name);
		if (!num)
		{
			cout << "退出成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "检测到通讯录中有联系人名字与exit一样!" << endl;
			cout << "请选择退出还是继续删除联系人操作!" << endl;
			cout << "1.继续\t0.退出" << endl;
			int h;
			cin >> h;
			if (!h)
			{
				cout << "退出成功!" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	int num = findPerson(abs, name);
	if (!num)
	{
		cout << "查无此人!" << endl;
		system("pause");
		system("cls");
	}
	else if (num == 1)
	{
		change(abs, abs->v[0]);
		cout << "删除成功!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "检测到有多个重名的联系人,请选择对应序号决定删除哪位联系人:" << endl;
		cout << "tips:输入all可删除查询到的所有重名联系人!" << endl;
		set<int> s;
		for (int i = 0; i < abs->v.size(); ++i)
		{
			cout << "序号 " << abs->v[i] << ":" << endl;
			s.insert(abs->v[i]);//存放一下可以删掉的坐标.
			cout << "\t姓名: " << abs->personArray[i].m_Name << '\t';
			cout << "\t性别: " << abs->personArray[i].m_Sex << '\t';
			cout << "\t年龄: " << abs->personArray[i].m_Age << '\t';
			cout << "\t电话: " << abs->personArray[i].m_Phone << '\t';
			cout << "\t地址: " << abs->personArray[i].m_Addr << endl;
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
					cout << "所有联系人已删除完毕!" << endl;
					system("pause");
					system("cls");
					return;
				}
				else
				{
					cout << "非法输入!请重试!" << endl;
				}
			}
			else
			{
				int now = id[0] - '0';
				if (!s.count(now))
				{
					cout << "非法输入!请重试!" << endl;
				}
				else
				{
					change(abs, now);
					s.erase(now);
					cout << "删除成功!" << endl;
					if (!s.size())
					{
						cout << "所有联系人已删除完毕!" << endl;
						system("pause");
						system("cls");
						return;
					}
					else
					{
						cout << "请选择继续删除联系人或退出删除联系人:" << endl;
						cout << "1.继续\t0.退出" << endl;
						int pd;
						cin >> pd;
						if (!pd)
						{
							cout << "退出成功!" << endl;
							system("pause");
							system("cls");
							return;
						}
						else
						{
							system("cls");
							cout << "检测到有多个重名的联系人,请选择对应序号决定删除哪位联系人:" << endl;
							cout << "(tips: 输入all可删除查询到的所有重名联系人.)" << endl;
							set<int>::iterator it;
							for (it = s.begin(); it != s.end(); it++)
							{
								cout << "序号: " << *it << endl;
								cout << "\t姓名: " << abs->personArray[*it].m_Name << '\t';
								cout << "\t性别: " << abs->personArray[*it].m_Sex << '\t';
								cout << "\t年龄: " << abs->personArray[*it].m_Age << '\t';
								cout << "\t电话: " << abs->personArray[*it].m_Phone << '\t';
								cout << "\t地址: " << abs->personArray[*it].m_Addr << endl;
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
		cout << "查询结果如下:" << endl;
		set<int> s;
		for (int i = 0; i < id; ++i)
		{
			cout << "序号 " << abs->v[i] << ":" << endl;
			s.insert(abs->v[i]);
			cout << "\t姓名: " << abs->personArray[abs->v[i]].m_Name << '\t';
			cout << "\t性别: " << abs->personArray[abs->v[i]].m_Sex << '\t';
			cout << "\t年龄: " << abs->personArray[abs->v[i]].m_Age << '\t';
			cout << "\t电话: " << abs->personArray[abs->v[i]].m_Phone << '\t';
			cout << "\t地址: " << abs->personArray[abs->v[i]].m_Addr << endl;
		}
		cout << "请选择想修改的联系人的序号:" << endl;
		while(true)
		{
			int now;
			cin >> now;
			if (s.count(now))
			{
				string name;
				cout << "请输入姓名:" << endl;
				cin >> name;
				abs->personArray[now].m_Name = name;
				cout << "请输入性别:" << endl;
				cout << "1 --- 男" << endl;
				cout << "2 --- 女" << endl;
				int sex;
				cin >> sex;
				while (sex != 1 && sex != 2)
				{
					cout << "非法输入!请重试" << endl;
					cin >> sex;
				}
				abs->personArray[now].m_Sex = sex;
				cout << "请输入年龄:" << endl;
				string age;
				cin >> age;
				abs->personArray[now].m_Age = age;
				cout << "请输入电话:" << endl;
				string phone;
				cin >> phone;
				abs->personArray[now].m_Phone = phone;
				cout << "请输入地址:" << endl;
				string add;
				cin >> add;
				abs->personArray[now].m_Addr = add;
				cout << "修改成功!" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "非法输入!请重试!" << endl;
			}
		}
	}
	else
	{
		cout << "查无此人!" << endl;
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
		cout << "清空完毕!" << endl;
		system("pause");
		system("cls");
		abs->m_Size = 0;
	}
	else
	{
		cout << "取消清空操作!" << endl;
		system("pause");
		system("cls");
	}
}