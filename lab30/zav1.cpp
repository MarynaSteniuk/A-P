#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int *fillArray(int a[], int n) //функц≥€ вибору заповненн€ масива
{
	int i, choose;
	cout<<"Choose 1 if you want to enter it yourself, or 2 if you want to use a generator: ";
	cin>>choose;
	
	switch(choose){
		case 1:
		{
			cout<<"Input numbers: ";
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			} break;
		}
		case 2:
		{ 
			int min, max;
			cout<<"Enter min and max value: "; cin>>min>>max;
			for(i=0;i<n;i++)
			{
				a[i] = rand() % ((max - min) + 1) + min;
			} break;
		}
		default: cout<<"Error!"<<endl; break;
	}
	
	return a;		
}

void printArray(int a[], int n) // функц≥€ вивденн€ масиву (теж за вибором)
{
	int i, choose;
	cout<<"Choose 2 if you want to output in a column, or 1 if in a row: ";
	cin>>choose;
	
	switch(choose){
		case 1:
		{
			for(i=0;i<n;i++){
				cout<<a[i]<<" ";
			} break;
		}
		case 2:
		{ 
			for(i=0;i<n;i++){
				cout<<a[i]<<endl;
			} break;
		}
		default: cout<<"Error!";
	}
}

int *deleteSimilar(int a[], int &n) 
{
	int max, min, i;
	max=a[0];
	min=a[0];
	for (i=1; i<n; i++) //знаходимо м≥н≥мальне та максимальне значенн€
		if (a[i]>max)
			max=a[i];
	for (i=1; i<n; i++)
		if (a[i]<min)
			min=a[i];
	bool min_found=false;
    bool max_found=false;
	for (i=0; i<n; i++) 
    {
        if (a[i]==min)  //видал€Їмо €кщо число р≥вне м≥н≥мальному чи максимальному
        {
            if (min_found) 
            {
                for (int j=i; j<n; j++) 
                    a[j]=a[j+1];
                n--;
                i--;
            }
            else
				min_found=true;
        }
        else if (a[i]==max) 
        {
            if (max_found) 
            {
                for (int j=i; j<n; j++) 
					a[j]=a[j+1];
                n--;
                i--; 
            }
            else
				max_found=true;
        }
    }
	return a; //повертаЇмо а			
}

int *zsuv(int a[], int n)
{
	int i;
	int minI;
	int min=a[0];
    for (i=1; i<n; i++)
		if (a[i]<min)
		{
			min=a[i];
			minI=i;
		}
	
	//розбиваЇмо масив на дв≥ частини 	
    int *t1=new int[minI+1]; //вс≥ елементи перед м≥н≥мальним елементом. 
    int *t2=new int[(n-minI)+1]; // м≥н≥мальний елемент та вс≥ елементи п≥сл€ нього.
    int index1=0, index2=0, count1=0, count2=0;
    
    for (i=0;i<minI;i++)
    {
    	t1[index1++]=a[i];
    	count1++;
    }
    for (i=minI;i<n;i++)
    {
    	t2[index2++]=a[i];
    	count2++;
    }
    
    index1=0;
    index2=0;
    for (i=0; i<count2; i++)
    	a[i]=t2[index2++];
    index1=0;
    for (i=index2; i<n; i++)
    	a[i]=t1[index1++];
    	
	delete[] t1;
	delete[] t2;
    	
    return a;
}

int *deleteElements(int a[], int &n)
{
	int i;
	int min_index=0, max_index=0;
    for (i=1; i<n; i++) 
    {
        if (a[i]<a[min_index]) //знаходимо максимальний та м≥н≥мальний ≥ндекс
            min_index=i;
        if (a[i]>a[max_index])
            max_index=i;
    }
    int start, end; //створюЇмо зм≥нн≥ дл€ визначенн€ меж
    if (min_index<max_index) 
    {
        start=min_index;
        end=max_index;
    } 
    else 
    {
        start=max_index;
        end=min_index;
    }

    int newSize=0; 
    for (i=start; i<=end; i++) 
    {
        a[newSize]=a[i]; 
        newSize++;
    }
    n=newSize;

    return a;
}

int *createNewArray(int a[], int n, int &newSize)
{
	int odd_count=0, even_count=0;

    for (int i=0; i<n; i++) 
    {
        if (a[i]%2==0) //визначаЇмо €ка к≥льк≥сть елемент≥в б≥льша(парна чи Ќ≈ парна)
            even_count++;
        else 
            odd_count++;
    }

	if (odd_count>even_count) 
        newSize=odd_count; //€кщо к≥льк≥сть непарних елемент≥в б≥льша, то розм≥р нового масиву дор≥вню odd_count
	else 
        newSize=even_count; //тут в протилежному випадку

    int* new_array=new int[newSize];
    int index=0;

    if (odd_count>even_count) 
    {
        for (int i=0; i<n; i++) 
        {
            if (a[i]%2!=0) //якщо непарних елемент≥в б≥льше, цикл проходить по вих≥дному масиву ≥ додаЇ вс≥ непарн≥ елементи
                new_array[index++]=a[i];
        }
    } 
    else 
    {
        for (int i=0; i<n; i++) 
        {
            if (a[i]%2==0) 
                new_array[index++]=a[i]; //якщо парних елемент≥в б≥льше, додаЇ вс≥ парн≥ елементи
        }
    }
    return new_array;
}

int main()
{
	srand(time(NULL));
	int i, n;
	
	cout<<"Input n: "; cin>>n;
	int *array = new int[n];
	
	int *p1 = fillArray(array, n);
	printArray(p1, n);
	
	int *p2 = deleteSimilar(array, n);
	cout<<endl<<"Array where similar ones are removed Max and Min: ";
	for(i=0;i<n;i++){
		cout<<*p2<<" ";
		p2++;
	}
	
	int *p3 = zsuv(array, n);
	cout<<endl<<"Array after the landslide: ";
	for(i=0;i<n;i++){
		cout<<*p3<<" ";
		p3++;
	}
	
	int *p4 = deleteElements(array, n);
	cout<<endl<<"Array after delete max and min: ";
	for(i=0;i<n;i++){
		cout<<*p4<<" ";
		p4++;
	}
	int newSize;
	int *p5 = createNewArray(array, n, newSize);
	cout<<endl<<"New array: ";
	for(i=0;i<newSize;i++){
		cout<<*p5<<" ";
		p5++;
	}
	
	delete[] array;
	delete[] p5;
	
	return 0;
}
