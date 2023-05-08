#include "Function.h"

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	//创建通讯录结构体变量.
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while(true)
	{
		showMenu();//菜单.
		cin >> select;
		switch (select)
		{
		case 0: // 0.退出通讯录.
			cout << "退出系统成功!" << endl;
			cout << "欢迎下次使用!" << endl;
			return 0;
		case 1: // 1.添加联系人.
			addPerson(&abs);
			break;
		case 2: // 2.显示联系人.
			showPerson(&abs);
			break;
		case 3: // 3.删除联系人.
			deletePerson(&abs);
			break;
		case 4: // 4.查找联系人.
		{
			cout << "请输入查找联系人的姓名:" << endl;
			string name;
			cin >> name;
			int id = findPerson(&abs, name);
			if (!id)
			{
				cout << "查无此人!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				for (int i = 0; i < id; ++i)
				{
					cout << "\t姓名: " << abs.personArray[abs.v[i]].m_Name << '\t';
					cout << "\t性别: " << abs.personArray[abs.v[i]].m_Sex << '\t';
					cout << "\t年龄: " << abs.personArray[abs.v[i]].m_Age << '\t';
					cout << "\t电话: " << abs.personArray[abs.v[i]].m_Phone << '\t';
					cout << "\t地址: " << abs.personArray[abs.v[i]].m_Addr << endl;
				}
				cout << "查找完毕!" << endl;
				cout<<"共有" << id << "个姓名为" << name << "的联系人!" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 5: // 5.修改联系人.
			cout << "请输入待修改联系人的名字:" << endl;
			changePerson(&abs);
			break;
		case 6: // 6.清空联系人.
			cout << "是否确认清空联系人?" << endl;
			cout << "确认请输入1:" << endl;
			deleteallPerson(&abs);
			break;
		default:
			cout << "非法输入请重试!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return 0;
}