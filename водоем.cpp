///*����������� ����� Reservoir (������). ����� ������ ����������� ����� ���� ���������. ����� ������ ���������:
//����������� �� ���������, ����������� � �����������, ��� ������������� ���������� ���������� � ����������� �����������.
//�������� ������ ���:
//1. ����������� ���������������� ������ (������*�����*������������ �������)
//2. ����������� ������� ������ �����������;
//3. ����� ��� �������� ��������� �� ������� � ������ ���� (����-����; �������-����);
//4. ��� ��������� ������� ������ ����������� �������� ������ ����;
//5. ��� ����������� ��������;
//6. ��������� ������ �� ���������� ������������ (������ set � get).
//�������� ��������� ��� ������ � �������. ����������� ������������ ������ �������� ������ � ������������
//����������, �������� �������� �� �������.*/
//#include <stdio.h>
//#include <iostream> //���������� ����� ������
//#include <cstring> //��� ������ �� �������� �-style
//#include <string.h>
//#pragma warning (disable:4996)
//using namespace std;
//
//
//class Reservior
//{
//public:
//    enum Type {
//        POOL, //������
//        LAKE, //�����
//        SEA, //����
//        NO_TYPE
//    };// ��� ����
//
//private:
//    char* m_names; //��������
//    Type m_type; //��� ��������
//    float f_length; //����� ��.
//    float f_width; //������ ��.
//    int f_deep; //������� �.
//public:
//    /*����������� � �����������*/
//    Reservior(const char* names, Type type, float length, float width, int deep) :
//        m_names{ new char[strlen(names) + 1] }, m_type{ type },
//        f_length{ length }, f_width{ width }, f_deep{ deep }
//    {
//        strcpy_s(m_names, strlen(names) + 1, names);
//    }
//    //����������� �� ���������
//    Reservior() :Reservior{ "no name", NO_TYPE, 0.0, 0.0, 0 } {}
//
//    //����������� �����������
//    Reservior(const Reservior& res) : m_names{ new char[strlen(res.m_names) + 1] },
//        m_type{ res.m_type }, f_length{ res.f_length }, f_width{ res.f_width }, f_deep{ res.f_deep }
//    {
//        strcpy_s(m_names, strlen(res.m_names) + 1, res.m_names);
//    }
//
//    //-----------------------������ � ������----------------------------
//    /*��������*/
//    void setNames(char* name)
//    {
//        if (m_names) //���� ��������� �� �������
//            delete[]m_names;
//        m_names = new char[strlen(name) + 1];
//        strcpy_s(m_names, strlen(name) + 1, name);
//    }
//    const char* getNames() { return m_names; }
//
//    /*���*/
//    void setType(Type type) { m_type = type; }
//    Reservior::Type getType_type() { return m_type; }
//    const char* getType()
//    {
//        switch (m_type)
//        {
//        case Reservior::POOL: return "������";
//        case Reservior::LAKE: return "�����";
//        case Reservior::SEA: return "����";
//        case Reservior::NO_TYPE: return "��� ����";
//        }
//    }
//
//    /*�����*/
//    void setLenght(float length) { f_length = length; }
//    float getLenght() { return f_length; }
//
//    /*������*/
//    void setWidth(float width) { f_width = width; }
//    float getWidth() { return f_width; }
//
//    /*�������*/
//    void setDeep(int deep) { f_deep = deep; }
//    int getDeep() { return f_deep; }
//
//    /*�������*/
//    friend double getArea(const Reservior& res);
//
//    /*�����*/
//    friend double getVolume(const Reservior& res);
//
//    /*����� ��� �������� ��������� �� ������� � ������ ���� */
//    bool metodType(Reservior& res)
//    {
//        return (m_type == res.getType_type()) ? true : false;
//    }
//
//    /*��������� 2 ��������*/
//    short compareReservoir(Reservior& res);
//
//    /*���������� ��������� ����������*/
//    Reservior& operator=(const Reservior& res);
//
//    /*����� ����� ������ � �������*/
//    void printReservior();
//
//    /*����������*/
//    ~Reservior() { delete[]m_names; }
//};
//
//double getArea(const Reservior& res) { return res.f_length * res.f_width; } //������� ������ ����� ��.��.
//double getVolume(const Reservior& res) { return getArea(res) * res.f_deep * 1000000; } //����� ������� ���.�.
//
// /*��������� 2 ��������*/
//short Reservior::compareReservoir(Reservior& res)
//{
//    if (!metodType(res)) //������ -2 (���� �������� �� �������������)
//        return -2;
//    else if (getArea(*this) < getArea(res)) //-1 (����� 2 ������)
//        return -1;
//    else if (getArea(*this) == getArea(res)) //0 (����� �� �������)
//        return 0;
//    else 1; //1 (����� 1 ������)
//}
///*���������� ��������� ����������*/
//Reservior& Reservior::operator=(const Reservior& res)
//{
//    if (&res != this)//�������� �� ��������������
//    {
//        if (m_names) //���� ��������� �� �������
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
///*����� ������ ������ � �������*/
//void Reservior::printReservior()
//{
//    cout << "\n������: " << m_names << "\n���: " << getType() << "\n�����: " << f_length << " ��."
//        << "\n������: " << f_width << " ��." << "\n����. �������: " << f_deep << " �."
//        << "\n�������: " << getArea(*this) << " ��.��." << "\n�����: " << getVolume(*this) << " ���.�\n";
//}
///*��������� ������� � ������*/
//void addReservior(Reservior* res, int& count)//�������� ��������� �� ������ � ���������� ���������
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
///*�������� ������� �� �������*/
//void deleteReservior(Reservior* res, int& count)
//{
//    short index;
//    cout << "\n�������� ����� ��� ��������:\n";
//    for (short i{ 0 }; i < count; ++i)
//        cout << i + 1 << ". " << res[i].getNames() << "\n";
//    cin >> index;
//    //if (index != count)//���� ��� �� ��������� ������� � �������
//    //    res[index-1] = res[count-1]; //��������� ������� �������� ���������
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
///*������� � ������� ���� ������ ��������*/
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
//    /*������� �������*/
//    Reservior pool { "������ ������", Reservior::POOL, 0.1, 0.02, 2 }; 
//    Reservior lake{ "������ �����", Reservior::LAKE, 0.3, 0.2, 5 };
//    Reservior lake1{ "������� �����", Reservior::LAKE, 0.3, 0.3, 2 };
//    Reservior sea{ "������� ����", Reservior::SEA, 67, 18, 250 };
//    /*�������������� ������ � ���������*/
//    Reservior* reservior = new Reservior[count]{pool, lake, lake1, sea };
//    while (menu != 5) //���� � �����
//    {
//        cout << "\n1. ������� ���������� �� ��������\n2. �������� ������\n3. ������� ������\n"
//            << "4. �������� �������\n5. �����\n";
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
//            cout << "���� ���������\n";
//        else
//            cout << "���� �� ���������\n";*/
//    }
//    return 0;
//}