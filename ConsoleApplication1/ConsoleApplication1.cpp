#include <iostream>
#include <time.h>
#include <string>
using namespace std;

class mchns;
class mchns
{
private:
	// интерфейсная часть класса
	int Rzm; // размер
	int Un; // напряжение
	int Wt; // мощность (мВт)
	char* name = NULL; // наименование
	char* color = NULL; // цвет
	double price;
public:
	void input(char* n, char* clr, int r, int u, int w, double p) {
		name = new char[strlen(n) + 1];
		name = n;
		color = new char[strlen(clr) + 1];
		color = clr;
		Rzm = r;
		Un = u;
		Wt = w;
		price = p;	
	} // псевдоконструктор

	void input_data() {
		cout << "Наименование:" << endl;
		cin >> this->name;
		cout << "Цвет:" << endl;
		cin >> this->color;
		cout << "Размер:" << endl;
		cin >> this->Rzm;
		cout << "Напряжение:" << endl;
		cin >> this->Un;
		cout << "Мощность:" << endl;
		cin >> this->Wt;
		cout << "Цена:" << endl;
		cin >> this->price;
	}

	void print_data() {
		cout << "Наименование:" << this->name << endl;
		cout << "Цвет:" << this->color << endl;
		cout << "Размер:" << this->Rzm << endl;
		cout << "Напряжение:" << this->Un << endl;
		cout << "Мощность:" << this->Wt << endl;
		cout << "Цена:" << this->price << endl;
		cout << endl;
	}
	void del() {
		delete[] name;
		delete[] color;
		Rzm = 0;
		Un = 0;
		Wt = 0;
	} // псевдодеструктор
	void print()const {
		cout << "Наименование: " << name << endl
			<< "Цвет машины: " << color << endl
			<< "Размер: " << Rzm << endl
			<< "Напряжение: " << Un << endl
			<< "Мощность (мВт): " << Wt << endl
			<< "Мощность (мВт): " << price << endl << endl;
	}// функция вывода
	void prisv(const mchns& object) {
		delete[] name;
		delete[] color;
		name = new char[strlen(object.name) + 1];
		strcpy((char*)name, object.name);
		color = new char[strlen(object.color) + 1];
		strcpy((char*)color, object.color);
		Rzm = object.Rzm;
		Un = object.Un;
		Wt = object.Wt;
		price = object.price;
	}// присваивание
	void compare(mchns object) {
		if (strcmp(name, object.name) == 0) {
			cout << "Наименование: " << endl << name << " совпадает " << object.name << endl;
		}
		else {
			cout << "Наименование: " << endl << name << " не совпадает " << object.name << endl;
		}

		if (strcmp(color, object.color) == 0) {
			cout << "Цвет: " << endl << color << " совпадает " << object.color << endl;
		}
		else {
			cout << "Цвет: " << endl << color << "  не совпадает " << object.color << endl;
		}

		if (Rzm == object.Rzm) {
			cout << "Размер: " << endl << Rzm << " совпадает " << object.Rzm << endl;
		}
		else {
			cout << "Размер: " << endl << Rzm << " не совпадает " << object.Rzm << endl;
		}

		if (Un == object.Un) {
			cout << "Потребляемое напряжение: " << endl << Un << "   совпадает   " << object.Un << endl;
		}
		else {
			cout << "Потребляемое напряжение: " << endl << Un << "   не совпадает   " << object.Un << endl;
		}

		if (Wt == object.Wt) {
			cout << "Выходная мощность (мВт): " << endl << Wt << "   совпадает   " << object.Wt << endl;
		}
		else {
			cout << "Выходная мощность (мВт): " << endl << Wt << "   не совпадает   " << object.Wt << endl << endl;
		}
		if (price == object.price) {
			cout << "Цена: " << endl << price << " совпадает " << object.price << endl;
		}
		else {
			cout << "Цена: " << endl << price << " не совпадает " << object.price << endl;
		}
	} // сравнение
	double Get_price()const {
		return price;
	}
};

struct Node // линейный список
{
	mchns data;
	Node* Next, *Prev;
};

class List
{
	Node* Head, * Tail;
public:
	List(): Head(NULL), Tail(NULL) {};
	~List() {
		while (Head)
		{
			Tail = Head->Next;
			delete Head;
			Head = Tail;
		}
	}

	void Add(mchns& data) {
		Node* temp = new Node;
		temp->Next = NULL;
		temp->data = data;

		if (Head != NULL)
		{
			temp->Prev = Tail;
			Tail->Next = temp;
			Tail = temp;
		}
		else
		{
			temp->Prev = NULL;
			Head = Tail = temp;
		}
	}
	
	
};

int main()
{
	setlocale(LC_ALL, "Rus");
	mchns l1, l2, l3, l4, l5;

	l1.input((char*)"С/Х машина", (char*)"жёлтый", 10, 40, 220, 100);
	l1.print();
	l2.input((char*)"С/Х машина", (char*)"зеленый", 15, 50, 220, 100);
	l2.print();
	
	cout << "Сравнение: " << endl << endl;
	l1.compare(l2);

	List list_mchns;
	list_mchns.Add(l3);
	list_mchns.Add(l4);

	system("pause");
	return 0;
}
