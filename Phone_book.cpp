#include <iostream>
#include <cstring>
#include "Phone_book.h"

/*дл€ указателей на строки выдел€ем необходимую пам€ть в соответствии с размером строк инициализации*/
Phone_book::Phone_book(const char* surname, const char* name, long int home_phone, long int work_phone, long int mobil_phone, const char* info):
	m_surname { new char [strlen(surname)+1] }, m_name { new char[strlen(name) + 1] },
	m_home_phone{ home_phone }, m_work_phone{ work_phone }, m_mobil_phone{ mobil_phone },
	m_info{ new char[strlen(info) + 1] }
{
	strcpy_s(m_surname, strlen(surname) + 1, surname);// копируем строки
	strcpy_s(m_name, strlen(name) + 1, name);
	strcpy_s(m_info, strlen(info) + 1, info);
}

void Phone_book::set_surname(const char* surname) 
{
	if (m_surname != nullptr) //если указатель не нулевой
		delete[] m_surname; //освобождаем пам€ть
	m_surname = new char[strlen(surname) + 1]; //выдел€ем новый кусок пам€ти
	strcpy_s(m_surname, strlen(surname) + 1, surname); //копируем новую фамилию
}

void Phone_book::set_name(const char* name)
{
	if (m_name != nullptr) //если указатель не нулевой
		delete[] m_name; //освобождаем пам€ть
	m_name = new char[strlen(name) + 1]; //выдел€ем новый кусок пам€ти
	strcpy_s(m_name, strlen(name) + 1, name); //копируем новую фамилию
}

void Phone_book::set_info(const char* info)
{
	if (m_info != nullptr) //если указатель не нулевой
		delete[] m_info; //освобождаем пам€ть
	m_info = new char[strlen(info) + 1]; //выдел€ем новый кусок пам€ти
	strcpy_s(m_info, strlen(info) + 1, info); //копируем новую фамилию
}

void Phone_book::set_home_phone(long int home_phone)
{
	m_home_phone = home_phone;
}

void Phone_book::set_work_phone(long int work_phone)
{
	m_work_phone = work_phone;
}

void Phone_book::set_mobil_phone(long int mobil_phone)
{
	m_mobil_phone = mobil_phone;
}

void Phone_book::print_book()
{
	std::cout << "‘амили€: \t" << m_surname << '\n' << "»м€:\t\t" << m_name << '\n'
		<< "ƒом. тел.:\t" << m_home_phone << '\n' << "–аб. тел.:\t" << m_work_phone <<
		'\n' << "ћоб. тел.:\t" << m_mobil_phone << '\n' << "ƒоп. инфо: \t" << m_info << '\n';
}

/*перегрузка оператора присвоени€*/
Phone_book& Phone_book::operator=(const Phone_book& book)
{
	delete [] m_surname;
	delete [] m_name;
	delete [] m_info;
	m_surname = new char[strlen(book.m_surname) + 1];
	m_name = new char[strlen(book.m_name) + 1] ;
	m_home_phone = book.m_home_phone;
	m_work_phone = book.m_work_phone;
	m_mobil_phone = book.m_mobil_phone;
	m_info = new char[strlen(book.m_info) + 1];
	strcpy_s(m_surname, strlen(book.m_surname) + 1, book.m_surname);// копируем строки
	strcpy_s(m_name, strlen(book.m_name) + 1, book.m_name);
	strcpy_s(m_info, strlen(book.m_info) + 1, book.m_info);
	return *this; 
}