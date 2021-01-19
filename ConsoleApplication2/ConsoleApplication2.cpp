#include <iostream>
#include <string>
using namespace std;

class mchns;
class mchns
{
public:
	mchns(); // констр-р по умолч-ю
	mchns(const mchns&); // копирующий констр-р
	mchns(char* name, char* color, int Rzm, int Un, int Wt); // конструктор с параметрами
	~mchns(); // деструктор
	void print() const; // селектор
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
mchns::mchns()
{
	name = new char[strlen("name") + 1];
	strcpy(name, "name");
	color = new char[strlen("color") + 1];
	strcpy(color, "color");
	Rzm = 0;
	Un = 0;
	Wt = 0;
}
mchns::mchns(char* n, char* clr, int r, int u, int w)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	color = new char[strlen(clr) + 1];
	strcpy(color, clr);
	Rzm = r;
	Un = u;
	Wt = w;
}
mchns::mchns(const mchns& object)
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
void mchns::prisv(const mchns& object)
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
void mchns::print()const
{
	cout << "Наименование: " << name << endl
		<< "Цвет машины: " << color << endl
		<< "Размер: " << Rzm << endl
		<< "Напряжение: " << Un << endl
		<< "Мощность (мВт): " << Wt << endl << endl;
}
mchns::~mchns()
{
	delete[] name;
	delete[] color;
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
struct Node // линейный список
{
	mchns data;
	Node* Next, * Prev;
};

class List
{
	Node* Head, * Tail;
public:
	List() : Head(NULL), Tail(NULL) {};
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
	mchns l1((char*)"С/Х машина", (char*)"жёлтый", 10, 40, 220);
	mchns l2((char*)"С/Х машина", (char*)"зеленый", 15, 50, 220);
	mchns l3(l1);
	mchns l4;

	l1.print();
	l2.print();
	l4.print();
	l2.print();
	cout << "Сравнение: " << endl << endl;
	l1.compare(l2);
	cout << "Присваивание: " << endl << endl;
	l2.prisv(l1);

	l1.print();
	l2.print();
	List list_mchns;
	list_mchns.Add(l3);
	list_mchns.Add(l4);
	system("pause");
	return 0;
}