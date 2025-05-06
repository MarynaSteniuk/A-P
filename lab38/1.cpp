#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> //для визначення кількості елементів рівних першому
int dorivnuePershomy(T arr[], int size) 
{
    int count=0;
    for (int i=1; i<size; ++i) //починаємо з другого елемента
    {
        if (arr[i]==arr[0]) 
        {
            ++count;
        }
    }
    return count;
}

template <typename T>  //для обміну значеннями двох елементів
void swapElements(T arr[], int idx1, int idx2) 
{
    T temp=arr[idx1];
    arr[idx1]=arr[idx2];
    arr[idx2]=temp;
}

template <typename T>   //для вставки елемента у вказану позицію
void insertElement(T arr[], int& size, int p, T v) 
{
    for (int i=size; i>p; --i) 
    {
        arr[i]=arr[i-1]; //зсуваємо всі елементи вправо від заданої позиції
    }
    arr[p]=v;  //вставляємо новий елемент у задану позицію
    ++size;    //збільшуємо розмір масиву
}

template <typename T>   //для знаходження найдовшої ділянки однакових елементів
int longest(T arr[], int size) 
{
    int max=1, current=1;
    for (int i=1; i<size; ++i) 
    {
        if (arr[i]==arr[i-1]) //якщо поточний елемент дорівнює попередньому
        {
            ++current;
            if (current>max) 
            {
                max=current;
            }
        } 
        else 
        {
            current=1; //починаємо нову ділянку
        }
    }
    return max; //повертаємо максимальну довжину
}

template <typename T> //для сортування між мінімальним і максимальним елементами
void sortBetweenMinMax(T arr[], int size)
{
    int minIndex=0, maxIndex=0;
    for (int i=1; i<size; ++i)     //знаходимо індекси мінімального і максимального елементів
    {
        if (arr[i]<arr[minIndex]) 
            minIndex=i;
        if (arr[i]>arr[maxIndex]) 
            maxIndex=i;
    }
    if (minIndex > maxIndex)   //переставляємо індекси, якщо мінімальний правіше за максимальний
        swap(minIndex, maxIndex);
    for (int i=minIndex+1; i<maxIndex; ++i) //сортуємо підмасив між minIndex і maxIndex 
    {
        for (int j=i+1; j<maxIndex; ++j) 
        {
            if (arr[i]>arr[j])   //сортування за зростанням
            {
                T temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main() 
{
    srand(time(0));
    const int MAX_SIZE = 20; 
    int arr[MAX_SIZE], size = 10; 
    for (int i = 0; i < size; ++i) 
    {
        arr[i]=rand()%10; 
    }
    cout<<"Masuv: ";
    for (int i=0; i<size; ++i) 
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Kilkist elementiv rivnux perhomy: "<<dorivnuePershomy(arr, size)<<endl;
    int idx1, idx2;
    cout<<"Vvedit dva indeksy dlya obminu elementiv: ";
    cin>>idx1>>idx2;
    swapElements(arr, idx1, idx2);
    cout<<"Pislya obminu elementiv: ";
    for (int i=0; i<size; ++i) 
	cout<<arr[i]<< " ";
    cout<<endl;
    int pos, value;
    cout<<"Vvedit pozitsiyu ta znachennya dlya vstavky: ";
    cin>>pos>>value;
    insertElement(arr, size, pos, value);
    cout<<"Pislya vstavky elementa: ";
    for (int i=0; i<size; ++i) 
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Naidovsha dilanka odnakovykh elementiv: "<<longest(arr, size)<<endl;
    sortBetweenMinMax(arr, size);
    cout<<"Pislya sortuvannya elementiv mizh min ta max: ";
    for (int i=0; i<size; ++i) 
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
