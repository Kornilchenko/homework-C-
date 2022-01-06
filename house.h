#pragma once
#include "Apt.h"

class House
{
private:
	char* m_adres; //адрес дома
	short m_numbers_of_floors; //количество этажей
	short m_number_of_apartaments; // количество квартир на этаже
	Apt* m_apt;  //массив квартир

public:
	House(); //конструктор по умолчанию
	
	/*конструктор с параметрами*/
	House(char* adres, short numbers_of_floors, short number_of_apartaments, Apt* apt);

	/*конструктор копирования*/
	House(House& human);

	/*установка параметров */
	void set_parametr_House();
	
	/*деструктор*/
	~House();
	
	/*вывод информации о жильцах в консоль*/
	void showHouse();
};

