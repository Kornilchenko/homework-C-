#pragma once
#include "Human.h"

class Apt
{
private:
	int m_number_apt; //номер квартиры
	int m_count_human; // количество проживающих
	Human* m_human; //данные проживающих людей 
	int m_rooms; //количество комнат
public:
	/*конструктор с параметрами*/
	Apt(int number, int count, Human* human, int room); 

	//конструктор по умолчанию
	Apt();

	/*конструктор копирования*/
	Apt(const Apt& apt); 

	/*установка параметров квартир*/
	void set_parametr_Apt();

	/*деструктор*/
	~Apt();
	
	/*вывод параметров квартир*/
	void print_apt();
};

