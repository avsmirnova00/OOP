#include <iostream>
using namespace std;

class mchns;
class mchns
{
public:
	void input(char* name, char* color, int a, int b, int c); // псевдоконструктор
	void del(); // псевдодеструктор
	void print()const; // функция вывода
	void prisv(const mchns& object); // присваивание
	void compare(mchns object); // сравнение
private:
	// интерфейсная часть класса
	int Rzm; // размер
	int Un; // напряжение
	int Wt; // мощность (мВт)
	char* name; // наименование
	char* color; // цвет
	
};
void mchns::input(char* n, char* clr, int a, int b, int c)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	color = new char[strlen(clr) + 1];
	strcpy(color, clr);
	Rzm = a;
	Un = b;
	Wt = c;
}
void mchns::prisv(const mchns& object)
{
	name = new char[strlen(object.name) + 1];
	strcpy(name, object.name);
	color = new char[strlen(object.color) + 1];
	strcpy(color, object.color);
	Rzm = object.Rzm;
	Un = object.Un;
	Wt = object.Wt;
}
void mchns::print()const
{
	cout << "Наименование: " << name << endl
		<< "Цвет машины: " << color << endl 
		<< "Размер: " << Rzm << endl 
		<< "Напряжение: " << Un << endl 
		<< "Мощность (мВт): " << Wt << endl << endl;
}
void mchns::del()
{
	delete[] name;
	delete[] color;
	Rzm = 0;
	Un = 0;
	Wt = 0;
}
void mchns::compare(mchns object)
{
	if (strcmp(name, object.name) == 0) { cout << "Наименование: " << endl << name << "   совпадает   " << object.name << endl; }
	else { cout << "Наименование: " << endl << name << "   не совпадает   " << object.name << endl; }

	if (strcmp(color, object.color) == 0) { cout << "Цвет: " << endl << color << "   совпадает   " << object.color << endl; }
	else { cout << "Цвет: " << endl << color << "   не совпадает   " << object.color << endl; }

	if (Rzm == object.Rzm) { cout << "Размер: " << endl << Rzm << "   совпадает   " << object.Rzm << endl; }
	else { cout << "Размер: " << endl << Rzm << "   не совпадает   " << object.Rzm << endl; }

	if (Un == object.Un) { cout << "Потребляемое напряжение: " << endl << Un << "   совпадает   " << object.Un << endl; }
	else { cout << "Потребляемое напряжение: " << endl << Un << "   не совпадает   " << object.Un << endl; }

	if (Wt == object.Wt) { cout << "Выходная мощность (мВт): " << endl << Wt << "   совпадает   " << object.Wt << endl; }
	else { cout << "Выходная мощность (мВт): " << endl << Wt << "   не совпадает   " << object.Wt << endl << endl; }
}
int main()
{
	setlocale(LC_ALL, "Rus");
	mchns l1;
	mchns l2;
	l1.input((char*)"С/Х машина", (char*)"жёлтый", 10, 40, 220);
	l1.print();
	l2.input((char*)"С/Х машина", (char*)"зеленый", 15, 50, 220);
	l2.print();
	cout << "Сравнение: " << endl << endl;
	l1.compare(l2);
	cout << "Присваивание: " << endl << endl;
	l2.prisv(l1);
	l1.print();
	l2.print();
	l1.del();
	l1.print();
	system("pause");
	return 0;
}
