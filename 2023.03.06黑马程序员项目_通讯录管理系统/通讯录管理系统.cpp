#include "Function.h"

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	//����ͨѶ¼�ṹ�����.
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while(true)
	{
		showMenu();//�˵�.
		cin >> select;
		switch (select)
		{
		case 0: // 0.�˳�ͨѶ¼.
			cout << "�˳�ϵͳ�ɹ�!" << endl;
			cout << "��ӭ�´�ʹ��!" << endl;
			return 0;
		case 1: // 1.�����ϵ��.
			addPerson(&abs);
			break;
		case 2: // 2.��ʾ��ϵ��.
			showPerson(&abs);
			break;
		case 3: // 3.ɾ����ϵ��.
			deletePerson(&abs);
			break;
		case 4: // 4.������ϵ��.
		{
			cout << "�����������ϵ�˵�����:" << endl;
			string name;
			cin >> name;
			int id = findPerson(&abs, name);
			if (!id)
			{
				cout << "���޴���!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				for (int i = 0; i < id; ++i)
				{
					cout << "\t����: " << abs.personArray[abs.v[i]].m_Name << '\t';
					cout << "\t�Ա�: " << abs.personArray[abs.v[i]].m_Sex << '\t';
					cout << "\t����: " << abs.personArray[abs.v[i]].m_Age << '\t';
					cout << "\t�绰: " << abs.personArray[abs.v[i]].m_Phone << '\t';
					cout << "\t��ַ: " << abs.personArray[abs.v[i]].m_Addr << endl;
				}
				cout << "�������!" << endl;
				cout<<"����" << id << "������Ϊ" << name << "����ϵ��!" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 5: // 5.�޸���ϵ��.
			cout << "��������޸���ϵ�˵�����:" << endl;
			changePerson(&abs);
			break;
		case 6: // 6.�����ϵ��.
			cout << "�Ƿ�ȷ�������ϵ��?" << endl;
			cout << "ȷ��������1:" << endl;
			deleteallPerson(&abs);
			break;
		default:
			cout << "�Ƿ�����������!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return 0;
}