///*Разработать класс Reservoir (водоем). Класс должен обязательно иметь поле «название». Класс должен содержать:
//конструктор по умолчанию, конструктор с параметрами, при необходимости еализовать деструктор и конструктор копирования.
//Добавить методы для:
//1. Определения приблизительного объема (ширина*длина*максимальная глубина)
//2. Определения площади водной поверхности;
//3. Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
//4. Для сравнения площади водной поверхности водоемов одного типа;
//5. Для копирования объектов;
//6. Остальные методы на усмотрение разработчика (методы set и get).
//Написать интерфейс для работы с классом. Реализовать динамический массив объектов класса с возможностью
//добавления, удаления объектов из массива.*/
//#include <stdio.h>
//#include <iostream> //библиотека ввода вывода
//#include <cstring> //для работы со строками с-style
//#include <string.h>
//#pragma warning (disable:4996)
//using namespace std;
//
//
//class Reservior
//{
//public:
//    enum Type {
//        POOL, //басейн
//        LAKE, //озеро
//        SEA, //море
//        NO_TYPE
//    };// нет типа
//
//private:
//    char* m_names; //название
//    Type m_type; //тип вордоема
//    float f_length; //длина км.
//    float f_width; //ширина км.
//    int f_deep; //глубина м.
//public:
//    /*конструктор с параметрами*/
//    Reservior(const char* names, Type type, float length, float width, int deep) :
//        m_names{ new char[strlen(names) + 1] }, m_type{ type },
//        f_length{ length }, f_width{ width }, f_deep{ deep }
//    {
//        strcpy_s(m_names, strlen(names) + 1, names);
//    }
//    //конструктор по умолчанию
//    Reservior() :Reservior{ "no name", NO_TYPE, 0.0, 0.0, 0 } {}
//
//    //конструктор копирования
//    Reservior(const Reservior& res) : m_names{ new char[strlen(res.m_names) + 1] },
//        m_type{ res.m_type }, f_length{ res.f_length }, f_width{ res.f_width }, f_deep{ res.f_deep }
//    {
//        strcpy_s(m_names, strlen(res.m_names) + 1, res.m_names);
//    }
//
//    //-----------------------сетеры и гетеры----------------------------
//    /*название*/
//    void setNames(char* name)
//    {
//        if (m_names) //если указатель не нулевой
//            delete[]m_names;
//        m_names = new char[strlen(name) + 1];
//        strcpy_s(m_names, strlen(name) + 1, name);
//    }
//    const char* getNames() { return m_names; }
//
//    /*тип*/
//    void setType(Type type) { m_type = type; }
//    Reservior::Type getType_type() { return m_type; }
//    const char* getType()
//    {
//        switch (m_type)
//        {
//        case Reservior::POOL: return "басейн";
//        case Reservior::LAKE: return "озеро";
//        case Reservior::SEA: return "море";
//        case Reservior::NO_TYPE: return "нет типа";
//        }
//    }
//
//    /*длина*/
//    void setLenght(float length) { f_length = length; }
//    float getLenght() { return f_length; }
//
//    /*ширина*/
//    void setWidth(float width) { f_width = width; }
//    float getWidth() { return f_width; }
//
//    /*глубина*/
//    void setDeep(int deep) { f_deep = deep; }
//    int getDeep() { return f_deep; }
//
//    /*площадь*/
//    friend double getArea(const Reservior& res);
//
//    /*объем*/
//    friend double getVolume(const Reservior& res);
//
//    /*Метод для проверки относятся ли водоемы к одному типу */
//    bool metodType(Reservior& res)
//    {
//        return (m_type == res.getType_type()) ? true : false;
//    }
//
//    /*сравнение 2 водоемов*/
//    short compareReservoir(Reservior& res);
//
//    /*перезрузка оператора присвоения*/
//    Reservior& operator=(const Reservior& res);
//
//    /*вывод даных класса в консоль*/
//    void printReservior();
//
//    /*деструктор*/
//    ~Reservior() { delete[]m_names; }
//};
//
//double getArea(const Reservior& res) { return res.f_length * res.f_width; } //площадь водной глади кв.км.
//double getVolume(const Reservior& res) { return getArea(res) * res.f_deep * 1000000; } //объем водоема куб.м.
//
// /*сравнение 2 водоемов*/
//short Reservior::compareReservoir(Reservior& res)
//{
//    if (!metodType(res)) //вернет -2 (типы водоемов не соответствуют)
//        return -2;
//    else if (getArea(*this) < getArea(res)) //-1 (водоём 2 больше)
//        return -1;
//    else if (getArea(*this) == getArea(res)) //0 (равны по площади)
//        return 0;
//    else 1; //1 (водоём 1 больше)
//}
///*перегрузка оператора присвоения*/
//Reservior& Reservior::operator=(const Reservior& res)
//{
//    if (&res != this)//проверка на самоприсвоение
//    {
//        if (m_names) //если указатель не нулевой
//            delete[]m_names;
//        m_names = new char[strlen(res.m_names) + 1];
//        strcpy_s(m_names, strlen(res.m_names) + 1, res.m_names);
//        m_type = res.m_type;
//        f_length = res.f_length;
//        f_width = res.f_width;
//        f_deep = res.f_deep;
//    }
//    return *this;
//}
///*вывод дааных класса в консоль*/
//void Reservior::printReservior()
//{
//    cout << "\nВодоем: " << m_names << "\nТип: " << getType() << "\nДлина: " << f_length << " км."
//        << "\nШирина: " << f_width << " км." << "\nМакс. глубина: " << f_deep << " м."
//        << "\nПлощадь: " << getArea(*this) << " кв.км." << "\nОбъем: " << getVolume(*this) << " куб.м\n";
//}
///*добавляем элемент в массив*/
//void addReservior(Reservior* res, int& count)//передаем указатель на массив и количество элементов
//{
//    ++count;
//        Reservior* temp = new Reservior[count];
//    for (short i{ 0 }; i < count-1; ++i)
//        temp[i] = res[i];
//    delete[]res;
//    res = new Reservior[count];
//    for (short i{ 0 }; i < count; ++i)
//        res[i] = temp[i];
//    delete[]temp;
//}
//
///*удаление водоема из массива*/
//void deleteReservior(Reservior* res, int& count)
//{
//    short index;
//    cout << "\nВыберите водоём для удаления:\n";
//    for (short i{ 0 }; i < count; ++i)
//        cout << i + 1 << ". " << res[i].getNames() << "\n";
//    cin >> index;
//    //if (index != count)//если это не последний элемент в массиве
//    //    res[index-1] = res[count-1]; //удаляемый элемент заменяем последним
//    count--;
//    Reservior* temp = new Reservior[count];
//    for (short i{ 0 }; i < count; ++i)
//    {
//        if (i < index - 1)
//            temp[i] = res[i];
//        else 
//            temp[i] = res[i+1];
//    }
//    delete[]res;
//    res = new Reservior[count];
//    for (short i{ 0 }; i < count; ++i)
//        res[i] = temp[i];
//    delete[]temp;
//}
//
///*выводим в консоль весь массив водоемов*/
//void printArrayReservior(Reservior* arr, int count)
//{
//    for (short i{ 0 }; i < count; ++i)
//        arr[i].printReservior();
//}
//
//int main()
//{
//    setlocale(0, "Rus");
//    //setlocale(LC_ALL, "");
//    int count{ 4 }, menu{ 0 };
//    short result;
//    /*создаем водоемы*/
//    Reservior pool { "Басейн Нептун", Reservior::POOL, 0.1, 0.02, 2 }; 
//    Reservior lake{ "Лесное озеро", Reservior::LAKE, 0.3, 0.2, 5 };
//    Reservior lake1{ "Соленое озеро", Reservior::LAKE, 0.3, 0.3, 2 };
//    Reservior sea{ "Мертвое море", Reservior::SEA, 67, 18, 250 };
//    /*организовываем массив с водоемами*/
//    Reservior* reservior = new Reservior[count]{pool, lake, lake1, sea };
//    while (menu != 5) //меню в цикле
//    {
//        cout << "\n1. Вывести информацию по водоемам\n2. Добавить водоем\n3. Удалить водоем\n"
//            << "4. Сравнить водоемы\n5. Выход\n";
//        do {
//            cin >> menu;
//        } while (menu < 1 || menu>4);
//        switch (menu)
//        {
//        case 1: printArrayReservior(reservior, count); break;
//        case 2: addReservior(reservior, count); break;
//        case 3: deleteReservior(reservior, count); break;
//        case 4: break;
//        case 5: break;
//        }
//
//        /*if (lake.metodType(lake1))
//            cout << "типы совпадают\n";
//        else
//            cout << "типы не совпадают\n";*/
//    }
//    return 0;
//}