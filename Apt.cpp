#include "Apt.h"

/*конструктор с параметрами*/
Apt::Apt(int number, int count, Human* human, int room) :m_number_apt{ number },
		m_count_human{ count }, m_human{ new Human[count] }, m_rooms{ room }
{
	for (short i{ 0 }; i < count; ++i)//заполнчем массив людьми
		m_human[i];
}

//конструктор по умолчанию
Apt::Apt() : m_number_apt{ 0 }, m_count_human{ 0 }, m_human{ nullptr }, m_rooms{ 0 } {}

/*конструктор копирования*/
Apt::Apt(const Apt& apt) :m_number_apt{ apt.m_number_apt }, m_count_human{ apt.m_count_human }, m_human{ new Human[apt.m_count_human] }, m_rooms{ apt.m_rooms }
{
	for (short i{ 0 }; i < apt.m_count_human; ++i)//заполнчем массив людьми
		m_human = apt.m_human;
}

/*установка параметров квартир*/
void Apt::set_parametr_Apt()
{
	std::cout << "enter numer apt: ";
	std::cin >> m_number_apt;
	std::cout << "enter quantity rooms: ";
	std::cin >> m_rooms;
	std::cout << "enter count human: ";
	std::cin >> m_count_human;
	if (m_human)
		delete[]m_human;
	m_human = new Human[m_count_human];
	for (short i{ 0 }; i < m_count_human; ++i)
		m_human[i].set_parametr_Human();
}

/*вывод параметров квартир*/
void Apt::print_apt()
{
	std::cout << "\napartment number: " << m_number_apt << "\nnumber of rooms: "
		<< m_rooms << "\nnumber of residents: " << m_count_human << "\ndata of residents:\n";
	for (short i{ 0 }; i < m_count_human; ++i)
		m_human[i].printHuman();
}

/*деструктор*/
Apt::~Apt()
{
	delete[] m_human;
}