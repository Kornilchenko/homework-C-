#pragma once
#include <cstring>
#pragma warning (disable:4996)
#include <iostream>

class Human
{
private:
	char* m_surname_name; // фамилия имя
	int m_age; //Возраст
public:
	/*конструктор с параметрами*/
	Human(const char* surname, int age); 

	Human() : Human{ "", 0 } {}//конструктор по умолчанию
	
	/*конструктор копирования*/
	Human(Human& human); 

	/*установка параметров человека*/
	void set_parametr_Human();
	
	/*Информация о проживающем*/ 
	void printHuman();
	
	~Human() { delete[] m_surname_name; }
	
};

