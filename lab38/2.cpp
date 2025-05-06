#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class Vector10 {
private:
    T data[10];   //масив для зберігання елементів вектора

public:
    Vector10() 
	{
        for (int i=0; i<10; ++i) 
		data[i]=0; 
    }
    Vector10(const T& value) 
	{
        for (int i=0; i<10; ++i) 
		data[i]=value; 
    }
    void inputFromKeyboard() //введення з клавіатури 
	{
        for (int i=0; i<10; ++i) 
		{
            cout<<"Enter element "<<i+1<<": "; 
            cin>>data[i];
        }
    }
    void fillRandom(T min=0, T max=100) //метод для заповнення випадковими числами
	{
        srand(time(0)); 
        for (int i=0; i<10; ++i) 
		{
            data[i]=min+rand()%(max-min+1);
        }
    }
    void display() const {   //метод для виведення елементів
        for (int i=0; i<10; ++i) 
		{
            cout<<data[i]<< " ";
        }
        cout<<endl;
    }
    void rearrange()    //перестановка елементів
	{
        T temp[10];
        int evenIndex=0, oddIndex=5;    //індекси для парних і непарних елементів
        for (int i=0; i<10; ++i) 
		{
            if (i%2==0) 
			{
                temp[evenIndex++]=data[i];     //парні елементи у першу половину
            } else {
                temp[oddIndex++]=data[i];      //непарні елементи у другу половину
            }
        }
        for (int i=0; i<10; ++i) 
		{
            data[i]=temp[i];     //оновлення масиву
        }
    }
    void removeElement(const T& value) {       //метод для видалення елементів з вказаним значенням
        int j=0;
        T temp[10];
        for (int i=0; i<10; ++i) 
		{
            if (data[i]!=value) 
			{
                temp[j++]=data[i];   //копіюємо всі елементи які не дорівнюють заданому значенню
            }
        }
        while (j<10) 
		temp[j++]=0;        //заповнюємо решту масиву нулями
        for (int i=0; i<10; ++i) 
		data[i]=temp[i];    //оновлення масиву
    }
    //перевантаження операції +
    Vector10 operator+(const Vector10& other) const {
        Vector10 result;
        for (int i=0; i<10; ++i) 
		{
            result.data[i]=data[i]+other.data[i]; //поелементне додавання
        }
        return result;
    }
    //перевантаження операції ++
    void operator++() 
	{
        for (int i=0; i<10; ++i) 
		{
            data[i]+=10;   //збільшуємо кожен елемент на 10
        }
    }
    //перевантаження операцій порівняння
    bool operator>(const Vector10& other) const {
        return sum()>other.sum(); //порівняння за сумою елементів
    }

    bool operator<(const Vector10& other) const {
        return sum()<other.sum(); 
    }

    bool operator==(const Vector10& other) const {
        return sum()==other.sum(); 
    }

private:
    //метод для обчислення суми елементів
    T sum() const {
        T total=0;
        for (int i=0; i<10; ++i) 
		{
            total+=data[i];    //обчислення суми всіх елементів
        }
        return total;
    }
};

int main() 
{
    Vector10<int> v1; 
    cout<<"Vector 1: ";
    v1.display(); 
    Vector10<int> v2(5); 
    cout<<"Vector 2: ";
    v2.display(); 
    Vector10<int> v3;
    cout<<"Enter elements for Vector 3 (input from keyboard):\n";
    v3.inputFromKeyboard();
    cout<<"Vector 3: ";
    v3.display(); 
    Vector10<int> v4;
    v4.fillRandom(1, 50); 
    cout << "Vector 4: ";
    v4.display();
    v4.rearrange(); //перестановка елементів вектора 4
    cout<<"Vector 4 after rearranging: ";
    v4.display();
    int valueToRemove;        //видалення елементів з вказаним значенням у векторі 4
    cout<<"Enter value to remove from Vector 4: ";
    cin>>valueToRemove;
    v4.removeElement(valueToRemove);
    cout<<"Vector 4 after removing value "<<valueToRemove<<": ";
    v4.display();       //виведення вектора після видалення
//перевантаження операцій для векторів 3 і 4
    Vector10<int> 
	v5=v3+v4;        
    cout<<"Sum of Vector 3 and Vector 4: ";
    v5.display();
    ++v3;            //операція ++ для вектора 3
    cout << "Vector 3 after ++: ";
    v3.display();
    if (v3 > v4)      //порівняння векторів 3 і 4
	{
        cout<<"Vector 3 is greater than Vector 4.\n";
    } else if (v3<v4) 
	{
        cout<<"Vector 3 is less than Vector 4.\n";
    } else 
	{
        cout<<"Vector 3 is equal to Vector 4.\n";
    }
    return 0;
}
