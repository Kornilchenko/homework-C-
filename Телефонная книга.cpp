///*Создайте приложение «Телефонная книга». Необходимо хранить данные об абоненте (ФИО, домашний телефон, 
//рабочий телефон, мобильный телефон, дополнительная информация о контакте) внутри соответствующего класса.
//Наполните класс переменными-членами, функциями-членами, конструкторами, inline-функциями-членами, используйте
//инициализаторы, реализуйте деструктор. Обязательно необходимо выделять динамически память под ФИО.
//Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов, искать
//абонентов по ФИО, показывать всех абонентов.*/
//#pragma warning (disable:4996)
//#include <iostream>
//#include <cstring>
////#include <windows.h> //для очистки консоли
//using namespace std;
//#include "Phone_book.h"
//
//void print_book(Phone_book* book, uint16_t count)
//{
//	cout << '\n';
//	for (short i{ 0 }; i < count; ++i)
//	{
//		book[i].print_book();
//		cout << '\n';
//	}
//}
//
//void main()
//{
//	setlocale(0, "Rus");
//	uint16_t menu{ 0 }, count{ 2 };
//	Phone_book* book{ new Phone_book[count]{ //выделяем динамический массив для абонетнов
//		{ "Oreshkin", "Egor", 56895, 78945, 982565478, "Director" }, //заносим 2 абонента в телефонную книгу
//		{ "Ivanov", "Oleg", 34567, 78988, 985663568, "Bugalter" }} };  
//	char  str[20];
//	while(1) {
//		cout << "Выбетите пункт телефонной книги \n0. Выход \n1. Добавить нового абонента \n"<<
//			"2. Удалить абонента \n3. Поиск абонента \n4. Покзать всю телефонную книгу \n";
//	cin >> menu;
//	//system("cls"); //очистка консоли
//		if (menu == 1)
//		{
//			long int temp;
//			count++; //увеличиваем счетчик абонентов
//			/*выделяем память под еще одного абонента*/
//			Phone_book* book_temp{ new Phone_book[count] };
//			/*со староого массива копируем в новый массив существующих абонентов*/
//			for (short i{ 0 }; i < count - 1; ++i)
//				book_temp[i] = book[i];
//			delete[] book; //освобождаем память массива book
//			cout << "Добавление нового абонента: \nФамилия: ";
//			cin.ignore();
//			cin.getline(str, 20);
//			if (strlen(str) > 2)//минимальная длина информации 2 символа
//				book_temp[count -1].set_surname(str);
//			else
//				book_temp[count - 1].set_surname("");
//			cout << "Имя: ";
//			cin.getline(str, 20);
//			if (strlen(str) > 2)//минимальная длина информации 2 символа
//				book_temp[count - 1].set_name(str);
//			else
//				book_temp[count - 1].set_name("");
//			cout << "Домашний телефон: ";
//			cin >> temp;
//			if (temp > 9999)//минимальная длина номера 5 символа
//				book_temp[count - 1].set_home_phone(temp);
//			else
//				book_temp[count - 1].set_home_phone(0);
//			cout << "Рабочий телефон: ";
//			cin >> temp;
//			if (temp > 9999)//минимальная длина номера 5 символа
//				book_temp[count - 1].set_work_phone(temp);
//			else
//				book_temp[count - 1].set_work_phone(0);
//			cout << "Мобильный телефон: ";
//			cin >> temp;
//			if (temp > 999999)//минимальная длина номера 7 символа
//				book_temp[count - 1].set_mobil_phone(temp);
//			else
//				book_temp[count - 1].set_mobil_phone(0);
//			cout << "Дополнительная информация: ";
//			cin.ignore();
//			cin.getline(str, 20);
//			if (strlen(str) > 2)//минимальная длина информации 2 символа
//				book_temp[count - 1].set_info(str);
//			else
//				book_temp[count - 1].set_info("");
//			book = new Phone_book[count]; //новый увеличенный массив book
//			for (short i{ 0 }; i < count; ++i)
//				book[i] = book_temp[i]; //копируем абонентов с временного массива
//			delete[] book_temp; //освобождаем память временного массива book_temp
//			//system("cls"); //очистка консоли
//			cout << "Абонент добавлен \n\n";
//		}
//		else if (menu == 2)
//		{
//			cout << "Выберите абонента для удаления с телефонной книги\n";
//			short temp{ 1 };
//			for (short i{ 0 }; i < count; ++i)//вывод фамилии и имя
//				cout << i + 1 << ". " << book[i].get_surname() <<" "<<book[i].get_name()<< '\n';
//			do { //проверка правильности ввода
//				cin >> temp;
//			} while (temp <= 0 || temp >= count);
//			/*если это послений элемент массива то ничего лелать не нужно а если нет
//			то нужно переместить последний элемент массива на место удаляемого*/
//			if (temp != count - 1)
//				book[temp - 1] = book[count - 1];
//			count--; //уменьшаем счетчик абонентов
//			/*выделяем  временную память под копирование туда справочника*/
//			Phone_book* book_temp{ new Phone_book[count] };
//			/*со староого массива копируем в новый массив абонентов*/
//			for (short i{ 0 }; i < count; ++i)
//				book_temp[i] = book[i];
//			delete[] book; //освобождаем память массива book
//			book = new Phone_book[count]; //новый массив book
//			for (short i{ 0 }; i < count; ++i)
//				book[i] = book_temp[i]; //копируем абонентов с временного массива
//			delete[] book_temp; //освобождаем память временного массива book_temp
//			//system("cls"); //очистка консоли
//			cout << "Удаление завершено \n\n";
//		}
//		else if (menu == 3)
//		{
//			cout << "Введите имя или фамилию абонента: ";
//			cin.ignore();
//			cin.getline(str, 20);
//			//system("cls"); //очистка консоли
//			short result{ -1 };
//			for (short i = 0; i < count; ++i)
//			{
//				if (!(strcmp(str, book[i].get_surname()) && strcmp(str, book[i].get_name())))
//					result = i;
//			}
//			if (result == -1)
//				cout << "Поиск результата не дал\n";
//			else
//			{
//				cout << "Найден абонент\n";
//				book[result].print_book();
//			}
//		}
//		else if (menu == 4)
//			print_book(book, count);
//		else
//			cout << "Сделайте другой выбор\n";
//	}
//	delete[] book; //освобождаем память
//}