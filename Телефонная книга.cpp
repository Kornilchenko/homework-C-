///*�������� ���������� ����������� �����. ���������� ������� ������ �� �������� (���, �������� �������, 
//������� �������, ��������� �������, �������������� ���������� � ��������) ������ ���������������� ������.
//��������� ����� �����������-�������, ���������-�������, ��������������, inline-���������-�������, �����������
//��������������, ���������� ����������. ����������� ���������� �������� ����������� ������ ��� ���.
//������������ ������������ ����������� ��������� ����� ���������, ������� ���������, ������
//��������� �� ���, ���������� ���� ���������.*/
//#pragma warning (disable:4996)
//#include <iostream>
//#include <cstring>
////#include <windows.h> //��� ������� �������
//using namespace std;
//#include "Phone_book.h"
//
//void print_book(Phone_book* book, uint16_t count)
//{
//	cout << '\n';
//	for (short i{ 0 }; i < count; ++i)
//	{
//		book[i].print_book();
//		cout << '\n';
//	}
//}
//
//void main()
//{
//	setlocale(0, "Rus");
//	uint16_t menu{ 0 }, count{ 2 };
//	Phone_book* book{ new Phone_book[count]{ //�������� ������������ ������ ��� ���������
//		{ "Oreshkin", "Egor", 56895, 78945, 982565478, "Director" }, //������� 2 �������� � ���������� �����
//		{ "Ivanov", "Oleg", 34567, 78988, 985663568, "Bugalter" }} };  
//	char  str[20];
//	while(1) {
//		cout << "�������� ����� ���������� ����� \n0. ����� \n1. �������� ������ �������� \n"<<
//			"2. ������� �������� \n3. ����� �������� \n4. ������� ��� ���������� ����� \n";
//	cin >> menu;
//	//system("cls"); //������� �������
//		if (menu == 1)
//		{
//			long int temp;
//			count++; //����������� ������� ���������
//			/*�������� ������ ��� ��� ������ ��������*/
//			Phone_book* book_temp{ new Phone_book[count] };
//			/*�� �������� ������� �������� � ����� ������ ������������ ���������*/
//			for (short i{ 0 }; i < count - 1; ++i)
//				book_temp[i] = book[i];
//			delete[] book; //����������� ������ ������� book
//			cout << "���������� ������ ��������: \n�������: ";
//			cin.ignore();
//			cin.getline(str, 20);
//			if (strlen(str) > 2)//����������� ����� ���������� 2 �������
//				book_temp[count -1].set_surname(str);
//			else
//				book_temp[count - 1].set_surname("");
//			cout << "���: ";
//			cin.getline(str, 20);
//			if (strlen(str) > 2)//����������� ����� ���������� 2 �������
//				book_temp[count - 1].set_name(str);
//			else
//				book_temp[count - 1].set_name("");
//			cout << "�������� �������: ";
//			cin >> temp;
//			if (temp > 9999)//����������� ����� ������ 5 �������
//				book_temp[count - 1].set_home_phone(temp);
//			else
//				book_temp[count - 1].set_home_phone(0);
//			cout << "������� �������: ";
//			cin >> temp;
//			if (temp > 9999)//����������� ����� ������ 5 �������
//				book_temp[count - 1].set_work_phone(temp);
//			else
//				book_temp[count - 1].set_work_phone(0);
//			cout << "��������� �������: ";
//			cin >> temp;
//			if (temp > 999999)//����������� ����� ������ 7 �������
//				book_temp[count - 1].set_mobil_phone(temp);
//			else
//				book_temp[count - 1].set_mobil_phone(0);
//			cout << "�������������� ����������: ";
//			cin.ignore();
//			cin.getline(str, 20);
//			if (strlen(str) > 2)//����������� ����� ���������� 2 �������
//				book_temp[count - 1].set_info(str);
//			else
//				book_temp[count - 1].set_info("");
//			book = new Phone_book[count]; //����� ����������� ������ book
//			for (short i{ 0 }; i < count; ++i)
//				book[i] = book_temp[i]; //�������� ��������� � ���������� �������
//			delete[] book_temp; //����������� ������ ���������� ������� book_temp
//			//system("cls"); //������� �������
//			cout << "������� �������� \n\n";
//		}
//		else if (menu == 2)
//		{
//			cout << "�������� �������� ��� �������� � ���������� �����\n";
//			short temp{ 1 };
//			for (short i{ 0 }; i < count; ++i)//����� ������� � ���
//				cout << i + 1 << ". " << book[i].get_surname() <<" "<<book[i].get_name()<< '\n';
//			do { //�������� ������������ �����
//				cin >> temp;
//			} while (temp <= 0 || temp >= count);
//			/*���� ��� �������� ������� ������� �� ������ ������ �� ����� � ���� ���
//			�� ����� ����������� ��������� ������� ������� �� ����� ����������*/
//			if (temp != count - 1)
//				book[temp - 1] = book[count - 1];
//			count--; //��������� ������� ���������
//			/*��������  ��������� ������ ��� ����������� ���� �����������*/
//			Phone_book* book_temp{ new Phone_book[count] };
//			/*�� �������� ������� �������� � ����� ������ ���������*/
//			for (short i{ 0 }; i < count; ++i)
//				book_temp[i] = book[i];
//			delete[] book; //����������� ������ ������� book
//			book = new Phone_book[count]; //����� ������ book
//			for (short i{ 0 }; i < count; ++i)
//				book[i] = book_temp[i]; //�������� ��������� � ���������� �������
//			delete[] book_temp; //����������� ������ ���������� ������� book_temp
//			//system("cls"); //������� �������
//			cout << "�������� ��������� \n\n";
//		}
//		else if (menu == 3)
//		{
//			cout << "������� ��� ��� ������� ��������: ";
//			cin.ignore();
//			cin.getline(str, 20);
//			//system("cls"); //������� �������
//			short result{ -1 };
//			for (short i = 0; i < count; ++i)
//			{
//				if (!(strcmp(str, book[i].get_surname()) && strcmp(str, book[i].get_name())))
//					result = i;
//			}
//			if (result == -1)
//				cout << "����� ���������� �� ���\n";
//			else
//			{
//				cout << "������ �������\n";
//				book[result].print_book();
//			}
//		}
//		else if (menu == 4)
//			print_book(book, count);
//		else
//			cout << "�������� ������ �����\n";
//	}
//	delete[] book; //����������� ������
//}