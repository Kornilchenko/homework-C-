#pragma once
#include "Apt.h"

class House
{
private:
	char* m_adres; //����� ����
	short m_numbers_of_floors; //���������� ������
	short m_number_of_apartaments; // ���������� ������� �� �����
	Apt* m_apt;  //������ �������

public:
	House(); //����������� �� ���������
	
	/*����������� � �����������*/
	House(char* adres, short numbers_of_floors, short number_of_apartaments, Apt* apt);

	/*����������� �����������*/
	House(House& human);

	/*��������� ���������� */
	void set_parametr_House();
	
	/*����������*/
	~House();
	
	/*����� ���������� � ������� � �������*/
	void showHouse();
};

