#pragma once
#include <cstring>
#pragma warning (disable:4996)
#include <iostream>

class Human
{
private:
	char* m_surname_name; // ������� ���
	int m_age; //�������
public:
	/*����������� � �����������*/
	Human(const char* surname, int age); 

	Human() : Human{ "", 0 } {}//����������� �� ���������
	
	/*����������� �����������*/
	Human(Human& human); 

	/*��������� ���������� ��������*/
	void set_parametr_Human();
	
	/*���������� � �����������*/ 
	void printHuman();
	
	~Human() { delete[] m_surname_name; }
	
};

