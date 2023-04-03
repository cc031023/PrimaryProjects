#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
//设计联系人结构体.
struct Person
{
	//姓名.
	string m_Name;
	//性别 1 男 2 女
	int m_Sex;
	//年龄
	string m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体.
struct Addressbooks
{
	//通讯录中保存的联系人数组.
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数.
	int m_Size;

	//记录通讯录重名人数.
	vector<int> v;//每次查询完就清空.
};
void showMenu();
void addPerson(Addressbooks* abs); // 添加联系人.
void showPerson(Addressbooks* abs); // 显示联系人.
int findPerson(Addressbooks* abs,string name);//查找联系人.
void deletePerson(Addressbooks* abs);//删除联系人.
void change(Addressbooks* abs, int x);//删除的实际操作.
void changePerson(Addressbooks* abs);//修改联系人.
void deleteallPerson(Addressbooks* abs);//删除所有联系人.