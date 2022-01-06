#include "House.h"

/*конструктор с параметрами*/
House::House(char* adres, short numbers_of_floors, short number_of_apartaments, Apt* apt) :
	m_adres{ new char[strlen(adres) + 1] },
	m_numbers_of_floors{ m_numbers_of_floors },
	m_number_of_apartaments{ number_of_apartaments },
	m_apt{ new Apt[numbers_of_floors * number_of_apartaments] }
{
	strcpy_s(m_adres, strlen(adres) + 1, adres);
	for (short i{ 0 }; i < numbers_of_floors * number_of_apartaments; ++i)
		m_apt[i] = apt[i];
}

//конструктор по умолчанию
House::House(): m_adres {nullptr}, m_numbers_of_floors{ 0 },
			m_number_of_apartaments{ 0 }, m_apt{ nullptr } {}

/*конструктор копирования*/
House::House(House& house):m_adres{ new char[strlen(house.m_adres) + 1] },
			m_numbers_of_floors{ house.m_numbers_of_floors },
			m_number_of_apartaments{ house.m_number_of_apartaments },
			m_apt{ new Apt[m_numbers_of_floors * m_number_of_apartaments] }
{
	strcpy_s(m_adres, strlen(house.m_adres) + 1, house.m_adres);
	for (short i{ 0 }; i < house.m_numbers_of_floors * house.m_number_of_apartaments; ++i)
		m_apt[i] = house.m_apt[i];
}

/*установка параметров */
void House::set_parametr_House()
{
	if (m_adres)
		delete[] m_adres;
	m_adres = new char[50];
	std::cout << "enter adres home: ";
	std::cin.getline(m_adres, 50);
	std::cout << "enter the data of the apartments of the house at:\n" << m_adres << '\n';
	std::cout << "enter numbers of floors: ";
	std::cin >> m_numbers_of_floors;
	std::cout << "enter numbers of apartaments: ";
	std::cin >> m_number_of_apartaments;
	m_apt = new Apt[m_numbers_of_floors * m_number_of_apartaments];
	for (short i{ 0 }; i < m_numbers_of_floors * m_number_of_apartaments; ++i)
		m_apt[i].set_parametr_Apt();
}

/*вывод информации о жильцах в консоль*/
void House::showHouse()
{
	std::cout << "\nhouse data at:\n" << m_adres << "\nnumbers of floors: " <<
		m_numbers_of_floors << "\nnumber of apartments per floor: " <<
		m_number_of_apartaments << "\ndata on apartments and residents of the house:\n";
	for (short i{ 0 }; i < m_numbers_of_floors * m_number_of_apartaments; ++i)
		m_apt[i].print_apt();
}

/*деструктор*/
House::~House()
{
	delete[] m_adres;
	delete[] m_apt;
}