#include <iostream>
#include <vector>

using namespace std;

class Employee
{
	protected:
		int age;
		int drivingEx; //досвід водіння у роках
	
	public:
		string lastname;
		Employee(string l, int a, int d) //конструктор для ініціалізації об'єкта Employee
		{
			lastname=l;
			age=a;
			drivingEx=d;
		}
		
		void updateInform_Employee(string newLastname, int newAge, int newDrivingex) //метод оновлення інформації про працівника
		{
			lastname=newLastname;
			age=newAge;
			drivingEx=newDrivingex;
		}
		
		void input_Employee()  //метод для введення даних працівника з клавіатури
		{
			cout<<"Last name: "; 				
			cin>>lastname;
			cout<<"Age: "; 						
			cin>>age;
			cout<<"Driving experience: "; 		
			cin>>drivingEx;
			cout<<endl;
		}
		
		void print_Employee()
		{
			cout<<"Last name: "<<lastname<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Driving experience: "<<drivingEx<<endl;
			cout<<endl;
		}
		
		int yearDriving_Employee(int current_year)  //обчислення року початку водіння
		{
			return current_year - drivingEx;
		}

};

class Car
{
	private:
		int mileage;   //пробіг автомобіля
	protected:
		int yearRelease;   //рік випуску автомобіля
	public:
		string registrationNum;  //реєстраційний номер
		string brand;   //марка автомобіля
		Car() //конструктор за замовчуванням
		{
			registrationNum="AK9265AK";
			brand="Audi";
			yearRelease=2009;
			mileage=12;
		}
		
		Car(string r, string b, int y, int m)   //конструктор для ініціалізації об'єкта Car
		{
			registrationNum=r;
			brand=b;
			yearRelease=y;
			mileage=m;
		}
		
		void updateInform_Car(string newRegistrationNum, string newBrand, int newYearRelease, int newMileage) //метод оновлення інформації про автомобіль
		{
			registrationNum = newRegistrationNum;
			brand = newBrand;
			yearRelease = newYearRelease;
			mileage = newMileage;
		}
		
		void input_Car()
		{
			cout<<"Registration number: "; 		
			cin>>registrationNum;
			cout<<"Brand: "; 					
			cin>>brand;
			cout<<"Year release: "; 			
			cin>>yearRelease;
			cout<<"Mileage: "; 					
			cin>>mileage;
			cout<<endl;
		}
		
		void print_Car()
		{
			cout<<"Registration number: "<<registrationNum<<endl;
			cout<<"Brand: "<<brand<<endl;
			cout<<"Year release: "<<yearRelease<<endl;
			cout<<"Mileage: "<<mileage<<endl;
			cout<<endl;
		}
		
		float averageMileage_Car(int current_year)
		{
			return mileage / (current_year - yearRelease);
		}
		
};

class Driver : public Employee, public Car
{
	public:
		int yearStartDriving;  //рік початку водіння
		bool fines;  //наявність штрафів
		vector<string> err;  //список помилок
		Driver()  //конструктор за замовчуванням
		: Employee("", 0, 0), Car("", "", 0, 0) 
		{
   			yearStartDriving = 0;
    		fines = false;
		}
		Driver(string l, int a, int d, string r, string b, int y, int m, int ys, bool f)  //конструктор для ініціалізації об'єкта Driver
		: Employee(l, a, d), Car(r, b, y, m)
		{
			yearStartDriving = ys;
			fines = f;
		}
		
		void updateInform_Driver(string newLastname, int newAge, int newDrivingex, string newRegistrationNum, string newBrand, int newYearRelease, int newMileage, int newYearSD, bool newFines)  //метод оновлення інформації про водія (метод для зміни даних всіх полів об’єкта класу)
		{
			err.clear();   //очищуємо список помилок
			if(newAge < 18 )  
			{
				err.push_back("Age less than 18");
			}
			if(newDrivingex < 0)
			{
				err.push_back("Driving experience less than 0");
			}
			if(newYearRelease < 0)
			{
				err.push_back("Year release less than 0");
			}
			if(newMileage < 0)
			{
				err.push_back("Mileage less than 0");
			}
			if(newYearSD < 0)
			{
				err.push_back("Year start driving less than 0");
			}
			if(!err.empty())
			{
				throw err;  //викидаємо помилки
			}
			updateInform_Employee(newLastname, newAge, newDrivingex);   //оновлення даних
			updateInform_Car(newRegistrationNum, newBrand, newYearRelease, newMileage);
			yearStartDriving = newYearSD;
			fines = newFines;
		}
		void input_Driver()  //метод для введення даних водія з клавіатури
		{
			input_Employee();
			input_Car();
			cout<<"Year started driving: "; cin>>yearStartDriving;
			cout<<"Fines (1 for yes, 0 for no): ";
			int finesInput;
			cin>>finesInput;
			fines = finesInput == 1;
			
		}
		void print_Driver()  //метод для виведення інформації про об’єкт класу
		{
			print_Employee();
			print_Car();
			cout<<"Year started driving: "<<yearStartDriving<<endl;
			if(fines)
			{
				cout<<"Fines: yes"<<endl;
			} else
			{
				cout<<"Fines: no"<<endl;
			}
			cout<<endl;
		}
		void whatMore_Driver(int current_year)    //метод порівняння віку автомобіля з досвідом водія
		{
			if((current_year - yearRelease) > drivingEx)
			{
				cout<<"The car is older than the driver's experience."<<endl;
			} else
			{
				cout<<"The driver's experience is longer than the car's age."<<endl;
			}
		}
	
};
int main()
{
    int n;
    cout << "Enter the number of drivers: ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "Number of drivers must be greater than 0." << endl;
        return 1;
    }
    Driver* drivers = new Driver[n];
    if (n > 0) 
        drivers[0] = Driver("Peter", 32, 8, "AM2310CC", "Toyota", 2015, 100, 2008, false);
    if (n > 1) 
        drivers[1] = Driver("Lina", 40, 15, "AI0000CC", "Honda", 2018, 150, 2003, true);

    try
    {
        if (n > 2) 
        {
            drivers[2] = Driver("Agata", 35, 12, "CC3333DD", "BMW", 2017, 120, 2005, false);
            drivers[2].updateInform_Driver("newAgata", 38, -10, "newDD4444EE", "newMercedes", 2021, 200, 2007, true);
        }
    }
    catch (vector<string> err)
    {
        cout << "Errors in updating third driver: " << endl;
        for (string it : err)
            cout << it << endl;
    }
    for (int i = 3; i < n; i++)
    {
        cout << "Enter details for driver " << i + 1 << ":" << endl;
        drivers[i].input_Driver();
    }
    cout << endl << "Driver List: " << endl;
    for (int i = 0; i < n; i++)
    {
        drivers[i].print_Driver();
        cout << "------------" << endl;
    }
    int current_year;
    cout << "Write the current year: ";
    cin >> current_year;
    cout << endl << "What more: ";
    for (int i = 0; i < n; i++)
    {
        drivers[i].whatMore_Driver(current_year);
    }
    delete[] drivers;

    return 0;
}