#include <iostream>
using namespace std;

class Flat 
{
private:
    string address; //������ ��������
    int floor;      //������
    int rooms;      //������� �����
    float area;     //�����

public:
    Flat() //����������� �� �������������
	{
        address = "Nevidomo";
        floor = 1;
        rooms = 2;
        area = 55;
    }
    Flat(string a, int f) //���������������� ����������� (����� ������ � ������)
	{
        address = a;
        floor = f;
        rooms = 2;
        area = 55;
    }

    void input() //�������� �����
	{
        cout << "Adresa: ";
        cin >> address;
        cout << "Poverx: ";
        cin >> floor;
        cout << "Kilkist kimnat: ";
        cin >> rooms;
        cout << "Plosha: ";
        cin >> area;
    }
    void output()  //��������� ����� 
	 {
        cout << "Adresa: " << address << ", Poverx: " << floor<< ", Kimnat: " << rooms << ", Plosha: " << area << " m" << endl;
    }

    //������ �� ������ ��� ����������
    int getRooms()
	{ 
	return rooms;
	}
    float getArea()
	{ 
	return area; 
	}
    int getFloor()
	{ 
	return floor; 
	}
};

int main() {
    const int N = 3;         //������� �������
    Flat flats[N];           //����� ��'���� �����
    for (int i = 0; i < N; i++)  //�������� �����
	{
        cout << "Kvartura #" << i + 1 << endl;
        flats[i].input();
    }
    cout << "\n Kvartura z 2 kimnatamu:\n"; //��������� ������� � ������ ������� �����
    for (int i = 0; i < N; i++) 
	{
        if (flats[i].getRooms() == 2)
            flats[i].output();
    }
    cout << "\n Kvarturu z plosheu 40 m i poverxom 2-5:\n"; //��������� ������� � ������ �� 40 � �� ��������� �� 2 �� 5
    for (int i = 0; i < N; i++) 
	{
        if (flats[i].getArea() <= 40 && flats[i].getFloor() >= 2 && flats[i].getFloor() <= 5)
            flats[i].output();
    }
    return 0;
}

