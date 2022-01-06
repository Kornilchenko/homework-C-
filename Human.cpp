#include "Human.h"

/*конструктор с параметрами*/
Human::Human(const char* surname, int age) : m_surname_name{ new char[strlen(surname) + 1] }, m_age{ age }
{
	strcpy_s(m_surname_name, strlen(surname) + 1, surname);
}

/*конструктор копирования*/
Human::Human(Human& human) :m_surname_name{ new char[strlen(human.m_surname_name) + 1] }, m_age{ human.m_age }
{
	strcpy_s(m_surname_name, strlen(human.m_surname_name) + 1, human.m_surname_name);
}

/*установка параметров человека*/
void Human::set_parametr_Human()
{
	if (m_surname_name)
		delete[] m_surname_name;
	m_surname_name = new char[30];
	std::cout << "enter surname and name: ";
	std::cin.ignore();
	std::cin.getline(m_surname_name, 30);
	std::cout << "enter age: ";
	std::cin >> m_age;
}

/*Информация о проживающем*/
void Human::printHuman()
{
	std::cout << "Name and Surname: " << m_surname_name << "\tAge: " << m_age << '\n';
}