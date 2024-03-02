#include <iostream>
#include<string.h>
#include<format>
using namespace std;

//class Person
//{
//	string name;
//	unsigned age;
//public:
//	Person(string p_name, unsigned p_age) //:name{ p_name }, age{ p_age } {}
//	{
//		name = p_name;
//		age = p_age;
//	}
//	
//	Person(const Person& p)// конструктор копирования
//	{
//		name = p.name;
//		age = p.age+1;
//	}
//	void print()
//	{
//		cout<<this << "Name : " << name << " \t Age : " << age<<endl;
//	}
//
//	//~Person();
//};
//
//
//
//int main()
//{
//	Person tom{ "Tom",35 };
//	Person tomas{ tom };
//	tom.print();
//	tomas.print();
//}


class DynArray
{
	const int val;
	int* arr;
	int size;
public:
	DynArray(int size_p, int value) :val{value} // обычный конструктор с параметрами
	{
		arr= new int[size_p] {};
		size= size_p ;
		cout << " DynArray выполнение конструктора " << size << " с количеством елементов массива " << this << endl;
	}
	DynArray() :DynArray(5,5) {} // конструктор принимающий по умолчанию значение
	DynArray(const DynArray& obj) :arr { new int[obj.size] {} }, size{ obj.size },val{obj.val} // конструктор копирования
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
		cout << " DynArray выполнение конструктора копирования " << size << " с количеством елементов массива " << this << endl<<endl;
	}

	int getElemet(int index) { return arr[index]; }
	void setElement(int index, int value) { arr[index] = value; }

	void print()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void randomize()const
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = 5+ rand() % 15;
		}
	}
	~DynArray()
	{
		cout << "Очищение памяти " << arr;
		delete[]arr;
		cout << " деструктор удалил " << size << " елементов в массиве " << this << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	const DynArray ar1(10,5);
	ar1.randomize();
	cout << " МАССИВ < 1 > " << endl;
	ar1.print();
	DynArray ar2{ ar1 };
	cout << " МАССИВ < 2 > " << endl;
	ar2.print();
	
	cout << std::format("{}+{}={}", 2, 5, 7) << endl;
}