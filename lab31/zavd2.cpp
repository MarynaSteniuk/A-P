#include <iostream>
#include <vector>
using namespace std;
class People 
{
private:
    string surname;   //�������
    string country;   //����� ����������
    string gender;    //�����
    string education; //�����
    int birthYear;    //�� ����������
    int age;          //��
public:
    //����������� �� �������������
    People() //����������� �� �������������
	{
        surname = "Nevidomo";
        country = "Ukraine";
        gender = "men";
        education = "seredna";
        birthYear = 2006;
        age = 2025 - birthYear;
    }
    void input() //�������� �����
	{
        cout << "Surname: ";
        cin >> surname;
        cout << "Country: ";
        cin >> country;
        cout << "Gender: ";
        cin >> gender;
        cout << "Education: ";
        cin >> education;
        cout << "Birth Year: ";
        cin >> birthYear;
        age = 2025 - birthYear;
    }
    void output() //��������� �����
	{
        cout << "Surname: " << surname << ", Country: " << country << ", Gender: " << gender << ", Education: " << education << ", Bith Year: " << birthYear << ", Age: " << age << endl;
    }
    //������
    string getEducation() 
	{ 
	return education; 
	}
    int getAge() 
	{ 
	return age; 
	}
    string getGender() 
	{
	return gender; 
	}
};
void removeByGender(vector<People>& people, string targetGender) //������� ��� ��������� ����� ����� ����
{
    for (int i = 0; i < people.size(); i++) //���������� ������� � ������ ����� (������ people)
	{
        if (people[i].getGender() == targetGender) //���� ����� ������� ������ (people[i]) ������� � ��, �� �� ������ (targetGender)
		{
            people.erase(people.begin() + i); //��������� i-�� ������ � �������
            i--; // ���� ��������� �������� ������
        }
    }
}
int main() 
{
    int n=3; 
    vector<People> people(n);  //����� ��'���� �����
    for (int i = 0; i < n; i++) //�������� ����� 
	{
        cout << "People #" << i + 1 << endl;
        people[i].input();
    }
    cout << "\nOsoby z vushoy osvitoy ta vikom bilshe 18:\n";
    for (int i = 0; i < people.size(); i++) //����������� �� ������ ������� people
	{
        if (people[i].getEducation() == "vusha" && people[i].getAge() > 18)
            people[i].output(); //�������� �� ��� ��� �� ������
    }
    string genderToRemove; //��������� ��� ����� ����
    cout << "\n Vvedit stat dla vudalenna (men or woman): ";
    cin >> genderToRemove;
    removeByGender(people, genderToRemove);
    cout << "\n Spusok pisla vudalenna osb stati \"" << genderToRemove << "\":\n";
    for (int i = 0; i < people.size(); i++)
    people[i].output();
    if (!people.empty()) //��������� ��ﳿ ��'���� �� ������� �� �������
	{
        People copy = people[0]; //������� ������ ��'���
        people.insert(people.begin(), copy); //���������� ���� �� �������
    }
    cout << "\n Final spusok:\n";
    for (int i = 0; i < people.size(); i++)
    people[i].output();
    return 0;
}

