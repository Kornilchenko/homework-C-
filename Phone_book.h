#pragma once
#include <iostream>
class Phone_book
{
private: 
	char* m_surname;//фамилия
	char* m_name;//имя
	long int m_home_phone;
	long int m_work_phone;
	long int m_mobil_phone;
	char* m_info;// информация
public:
	/*конструктор со всеми параметрами*/
	Phone_book(const char* surname, const char* name, long int home_phone, long int work_phone, long int mobil_phone, const char* info);
	/*конструктор по умолчанию*/
	Phone_book() : Phone_book{ "" , "",  0, 0, 0, "" } {}
	
	void set_surname(const char* surname);
	void set_name(const char* surname);
	void set_info(const char* surname);
	void set_home_phone(long int home_phone);
	void set_work_phone(long int work_phone);
	void set_mobil_phone(long int mobil_phone);
	char* get_surname() { return m_surname; }
	char* get_name() { return m_name; }
	long int get_home_phone() { return m_home_phone; }
	long int get_work_phone() { return m_work_phone; }
	long int get_mobil_phone() { return m_mobil_phone; }
	/*перегрузка оператора присвоения*/
	Phone_book& operator=(const Phone_book& book);
	/*вывод информации об 1 абоненте*/
	void print_book();
	
	~Phone_book() //деструктор
	{
		delete[] m_surname;
		delete[] m_name;
		delete[] m_info;
	}
};