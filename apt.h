#pragma once
#include "Human.h"

class Apt
{
private:
	int m_number_apt; //����� ��������
	int m_count_human; // ���������� �����������
	Human* m_human; //������ ����������� ����� 
	int m_rooms; //���������� ������
public:
	/*����������� � �����������*/
	Apt(int number, int count, Human* human, int room); 

	//����������� �� ���������
	Apt();

	/*����������� �����������*/
	Apt(const Apt& apt); 

	/*��������� ���������� �������*/
	void set_parametr_Apt();

	/*����������*/
	~Apt();
	
	/*����� ���������� �������*/
	void print_apt();
};

