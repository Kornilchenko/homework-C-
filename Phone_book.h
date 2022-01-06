#pragma once
#include <iostream>
class Phone_book
{
private: 
	char* m_surname;//�������
	char* m_name;//���
	long int m_home_phone;
	long int m_work_phone;
	long int m_mobil_phone;
	char* m_info;// ����������
public:
	/*����������� �� ����� �����������*/
	Phone_book(const char* surname, const char* name, long int home_phone, long int work_phone, long int mobil_phone, const char* info);
	/*����������� �� ���������*/
	Phone_book() : Phone_book{ "" , "",  0, 0, 0, "" } {}
	
	void set_surname(const char* surname);
	void set_name(const char* surname);
	void set_info(const char* surname);
	void set_home_phone(long int home_phone);
	void set_work_phone(long int work_phone);
	void set_mobil_phone(long int mobil_phone);
	char* get_surname() { return m_surname; }
	char* get_name() { return m_name; }
	long int get_home_phone() { return m_home_phone; }
	long int get_work_phone() { return m_work_phone; }
	long int get_mobil_phone() { return m_mobil_phone; }
	/*���������� ��������� ����������*/
	Phone_book& operator=(const Phone_book& book);
	/*����� ���������� �� 1 ��������*/
	void print_book();
	
	~Phone_book() //����������
	{
		delete[] m_surname;
		delete[] m_name;
		delete[] m_info;
	}
};