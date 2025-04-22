#include <iostream>
#include <string>
using namespace std;

//��������� ���� Employee
class Employee {
private:
    string lastName; //�������
    string department; //����
    int yearOfEmployment; //�� ����������������
    float salary; //��������
    float bonus; //�����

public:
	Employee() //����������� �� �������������
	{
        lastName="�������";
        department="�������";
        yearOfEmployment=2000;
        salary=0.0;
        bonus=0.0;
    }
    Employee(string ln, string dep, int year, float sal) //����������� �� �����������
	{
        lastName=ln;
        department=dep;
        yearOfEmployment=year;
        salary=sal;
        bonus=0.0;
    }
    void input() //�������� �����
	{
        cout<<"Prizvuche: "; 
        cin>>lastName;
        cout<<"Viddil: ";
        cin>>department;
        cout<<"Pik pracevlashtyvana: ";
        cin>>yearOfEmployment;
        cout<<"Zarplata: ";
        cin>>salary;
    }
    void output() const //��������� �����
	{
        cout<<"Prizvuche: "<<lastName<<" Viddil: "<<department<<" Pik pracevlashtyvana: "<<yearOfEmployment<<" Zarplata: "<<salary<<" Premia: "<< bonus << endl;
    }

    //���������� ���쳿
    void calculateBonus(int currentYear) {
        int experience = currentYear - yearOfEmployment;
        if (experience < 10) {
            bonus = 0.1 * salary;
        } else if (experience <= 25) {
            bonus = 0.25 * salary;
        } else {
            bonus = 0.4 * salary;
        }
    }
//������ ��� ��������� �����
    int getYearOfEmployment() const { return yearOfEmployment; }
    float getSalary() const { return salary; }
    float getBonus() const { return bonus; }
};
//������� ��� ���������� ���������� ����� ������
float calculateAverageExperience(const Employee employees[], int size, int currentYear) {
    int totalExperience = 0;
    for (int i = 0; i < size; i++) {
        totalExperience += currentYear - employees[i].getYearOfEmployment();
    }
    return static_cast<float>(totalExperience) / size; //������������ totalExperience � int � float ��� �������� ��������� ������� ����������
}

int main() {
    const int N = 3; 
    Employee employees[N]; //����� ��'���� ����� Employee
    int currentYear=2025; //�������� ��
    Employee emp("Petrenko", "IT", 2010, 15000); // ��������� ��'���� � �����������
    cout << "\nDani pro pracivnuka, stworeno za dopomogoyu konstruktoru z parametramy:\n";
    emp.output(); // ���� ����� ���������� ��'����

    for (int i=0; i<N; i++) //�������� ����� ��� ����������� 
	{
        cout<<"Pracivnuk #"<<i+1<< endl;
        employees[i].input();
        employees[i].calculateBonus(currentYear);
    }
    cout << "\nDani pro pracivnukiv:\n";     // ��������� ����� ��� �����������
    for (int i=0; i<N; i++) 
	{
        employees[i].output();
    }
    float averageExperience=calculateAverageExperience(employees, N, currentYear);   //���������� ���������� ����� ������
    cout<<"\nSeredniu stag robotu: "<<averageExperience<<" rokiv"<<endl;
    //���������� ������ ����������� �� ������ ������ (�� ����������) 
    for (int i=0; i<N-1; i++) //��������� �� ��� ��������� ������ ��� ����������
	 {
        for (int j=0; j<N-i-1; j++) //������� ���� ������ ��������
		{
            if (employees[j].getYearOfEmployment() > employees[j + 1].getYearOfEmployment()) //���� �� ���������������� ����������� j ������ �� � ����������� j + 1  �� j �� ������ ����
			{
                swap(employees[j], employees[j + 1]);  //������ ����������� ��������� ������
            }
        }
    }
    cout << "\nVidsortovani pracivnuku za stagem robotu:\n";  //��������� ������������ �����������
    for (int i=0; i<N; i++) 
	{
        employees[i].output();
    }
    return 0;
}

