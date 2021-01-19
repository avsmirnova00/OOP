#include <iostream>
#include <string>
using namespace std;

template <class T>
class mchns
{
public:
	mchns<T>(); // констр-р по умолч-ю
	mchns<T>(const mchns<T>&); // копирующий констр-р
	mchns<T>(char* name, char* color, int Rzm, int Un, int Wt); // конструктор с параметрами
	~mchns<T>(); // деструктор
	void print() const; // селектор
	mchns<T>& operator = (const mchns<T>& object); // присваивание
	bool& operator == (mchns<T>& object); // сравнение
private:
	// интерфейсная часть класса
	T float Rzm; // размер
	T float Un; // напряжение
	int Wt; // мощность (мВт)
	char* name; // наименование
	char* color; // цвет

};
template <class T>
mchns<T>::mchns()
{
	name = new char[strlen("name") + 1];
	strcpy(name, "name");
	color = new char[strlen("color") + 1];
	strcpy(color, "color");
	Rzm = 0;
	Un = 0;
	Wt = 0;
}
template <class T>
mchns<T>::mchns(char* n, char* clr, int r, int u, int w)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	color = new char[strlen(clr) + 1];
	strcpy(color, clr);
	Rzm = r;
	Un = u;
	Wt = w;
}
template <class T>
mchns <T>::mchns(const mchns<T>& object)
{
	/*delete[] name;
	delete[] color;*/
	name = new char[strlen(object.name) + 1];
	strcpy(name, object.name);
	color = new char[strlen(object.color) + 1];
	strcpy(color, object.color);
	Rzm = object.Rzm;
	Un = object.Un;
	Wt = object.Wt;
}
template <class T>
void mchns<T>::print()const
{
	cout << "Наименование: " << name << endl
		<< "Цвет машины: " << color << endl
		<< "Размер: " << Rzm << endl
		<< "Напряжение: " << Un << endl
		<< "Мощность (мВт): " << Wt << endl << endl;
}
template <class T>
mchns<T>::~mchns()
{
	delete[] name;
	delete[] color;
}
template <class T>
mchns<T>& mchns<T>:: operator =(const mchns<T>& object)
{
	if (this != &object)
	{
		delete[] name;
		delete[] color;
		name = new char[strlen(object.name) + 1];
		strcpy(name, object.name);
		color = new char[strlen(object.color) + 1];
		strcpy(color, object.color);
		Rzm = object.Rzm;
		Un = object.Un;
		Wt = object.Wt;
	}
	return (*this);
}
template <class T>
bool& mchns<T>::operator == (mchns<T>& object)
{
	bool flag = true;

	if (strcmp(name, object.name) == 0) {
		cout << "Наименование: " << endl << name << " совпадает " << object.name << endl; flag = true;
	}
	else {
		cout << "Наименование: " << endl << name << " не совпадает " << object.name << endl; flag = false;
	}

	if (strcmp(color, object.color) == 0) {
		cout << "Цвет: " << endl << color << " совпадает " << object.color << endl; flag = true;
	}
	else {
		cout << "Цвет: " << endl << color << " не совпадает " << object.color << endl; flag = false;
	}

	if (Rzm == object.Rzm) {
		cout << "Размер: " << endl << Rzm << " совпадает " << object.Rzm << endl; flag = true;
	}
	else {
		cout << "Размер: " << endl << Rzm << " не совпадает " << object.Rzm << endl; flag = false;
	}

	if (Un == object.Un) {
		cout << "Потребляемое напряжение: " << endl << Un << " совпадает " << object.Un << endl; flag = true;
	}
	else {
		cout << "Потребляемое напряжение: " << endl << Un << " не совпадает " << object.Un << endl; flag = false;
	}

	if (Wt == object.Wt) {
		cout << "Выходная мощность (мВт): " << endl << Wt << " совпадает " << object.Wt << endl; flag = true;
	}
	else {
		cout << "Выходная мощность (мВт): " << endl << Wt << " не совпадает " << object.Wt << endl << endl; flag = false;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	mchns <float> l1((char*)"С/Х машина", (char*)"жёлтый", 10.5, 40.8, 220);
	mchns <float> l2((char*)"С/Х машина", (char*)"зеленый", 15, 50, 220);
	mchns <float> l3(l1);
	mchns <float> l4;

	mchns <int> l5((char*)"С/Х машина", (char*)"жёлтый", 10.5, 40.8, 220);
	mchns <int> l6((char*)"С/Х машина", (char*)"зеленый", 15, 50, 220);
	mchns <int> l7(l5);
	mchns <int> l8;

	l1.print();
	l2.print();
	l3.print();
	l4.print();
	l5.print();
	l6.print();
	l7.print();
	l8.print();
	cout << "Сравнение: " << endl << endl;
	if (l1 == l2)
		cout << "Объекты равны" << endl << endl;
	else
		cout << "Объекты неравны" << endl << endl;

	cout << "Присваивание: " << endl << endl;
	l5 = l6;

	l5.print();
	l6.print();
	system("pause");
	return 0;
}