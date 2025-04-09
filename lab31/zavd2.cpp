#include <iostream>
#include <vector>
using namespace std;
class People 
{
private:
    string surname;   //прізвище
    string country;   //країна проживання
    string gender;    //стать
    string education; //освіта
    int birthYear;    //рік народження
    int age;          //вік
public:
    //конструктор за замовчуванням
    People() //конструктор за замовчуванням
	{
        surname = "Nevidomo";
        country = "Ukraine";
        gender = "men";
        education = "seredna";
        birthYear = 2006;
        age = 2025 - birthYear;
    }
    void input() //введення даних
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
    void output() //виведення даних
	{
        cout << "Surname: " << surname << ", Country: " << country << ", Gender: " << gender << ", Education: " << education << ", Bith Year: " << birthYear << ", Age: " << age << endl;
    }
    //гетери
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
void removeByGender(vector<People>& people, string targetGender) //функція для видалення людей певної статі
{
    for (int i = 0; i < people.size(); i++) //перебираємо кожного у списку людей (вектор people)
	{
        if (people[i].getGender() == targetGender) //якщо стать поточної людини (people[i]) співпадає з тією, що ми шукаємо (targetGender)
		{
            people.erase(people.begin() + i); //видаляємо i-ту людину з вектора
            i--; // після видалення зміщується індекс
        }
    }
}
int main() 
{
    int n=3; 
    vector<People> people(n);  //масив об'єктів класу
    for (int i = 0; i < n; i++) //введення даних 
	{
        cout << "People #" << i + 1 << endl;
        people[i].input();
    }
    cout << "\nOsoby z vushoy osvitoy ta vikom bilshe 18:\n";
    for (int i = 0; i < people.size(); i++) //проходимося по всьому вектору people
	{
        if (people[i].getEducation() == "vusha" && people[i].getAge() > 18)
            people[i].output(); //виводимо всі дані про цю людину
    }
    string genderToRemove; //видаляємо осіб певної статі
    cout << "\n Vvedit stat dla vudalenna (men or woman): ";
    cin >> genderToRemove;
    removeByGender(people, genderToRemove);
    cout << "\n Spusok pisla vudalenna osb stati \"" << genderToRemove << "\":\n";
    for (int i = 0; i < people.size(); i++)
    people[i].output();
    if (!people.empty()) //створення копії об'єкта та вставка на початок
	{
        People copy = people[0]; //копіюємо перший об'єкт
        people.insert(people.begin(), copy); //вставляємо копію на початок
    }
    cout << "\n Final spusok:\n";
    for (int i = 0; i < people.size(); i++)
    people[i].output();
    return 0;
}

