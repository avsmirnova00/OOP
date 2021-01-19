#include <iostream>
#include <string>
using namespace std;

class mchns;
class mchns
{
public:
	mchns(); // констр-р по умолч-ю
	mchns(const mchns&); // копирующий констр-р
	mchns(char* name, char* color, int Rzm, int Un, int Wt, int price); // конструктор с параметрами
	~mchns(); // деструктор
	void print() const; // селектор
	mchns & operator = (const mchns& object); // присваивание
	bool &operator == (mchns & object); // сравнение
	friend std::ostream& operator<< (std::ostream& out, const mchns& object);
	int Get_price()const;
private:
	// интерфейсная часть класса
	int Rzm; // размер
	int Un; // напряжение
	int Wt; // мощность (мВт)
	char* name; // наименование
	char* color; // цвет
	int price;

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
	price = 0;
}
mchns::mchns(char* n, char* clr, int r, int u, int w, int p)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	color = new char[strlen(clr) + 1];
	strcpy(color, clr);
	Rzm = r;
	Un = u;
	Wt = w;
	price = p;
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
	price = object.price;
}
mchns & mchns::operator = (const mchns& object)
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
		price = object.price;

	}
	return (*this);
}
void mchns::print()const
{
	cout << "Наименование: " << name << endl
		<< "Цвет машины: " << color << endl
		<< "Размер: " << Rzm << endl
		<< "Напряжение: " << Un << endl
		<< "Мощность (мВт): " << Wt << endl 
	    << "Цена: " << price << endl << endl;
}
mchns::~mchns()
{
	if (name != NULL) delete[] name;
	if (color != NULL) delete[] color;
}

bool & mchns::operator == (mchns & object)
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
	if (price == object.price) {
		cout << "Цена: " << endl << price << " совпадает " << object.price << endl; flag = true;
	}
	else {
		cout << "Цена: " << endl << price << " не совпадает " << object.price << endl << endl; flag = false;
	}
	return flag;
}
std::ostream& operator<< (std::ostream& out, const mchns& object) {
	out << "Наименование:" << object.name << endl;
	out << "Цвет:" << object.color << endl;
	out << "Цена:" << object.price << endl;
	out << "Напряжение:" << object.Un << endl;
	out << "Мощность:" << object.Wt << endl;
	out << "Размер:" << object.Rzm << endl;
	out << endl;
	return out;
}
int mchns::Get_price()const {
	return price;
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
	void Show() {
		Node* temp = Head;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->Next;
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
	void sort() {
		Node* tmp = Head;
		int size = 0;
		while (tmp != NULL) {
			size++;
			tmp = tmp->Next;
		}
		mchns* arr = new mchns[size];
		int a = 0;
		tmp = Head;
		while (tmp != NULL) {
			arr[a] = tmp->data;
			tmp = tmp->Next;
			a++;
		}
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (arr[i].Get_price() < arr[j].Get_price()) {
					mchns tmp;
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
		tmp = Head;
		while (tmp != NULL) {
			Head = Head->Next;
			delete(tmp);
			tmp = Head;
		}
		for (int i = 0; i < size; i++) {
			Add(arr[i]);
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	mchns l1((char*)"С/Х машина", (char*)"жёлтый", 10, 40, 220, 100);
	mchns l2((char*)"С/Х машина", (char*)"зеленый", 15, 50, 100, 220);
	mchns l3(l1);
	mchns l4;

	l1.print();
	l2.print();
	l3.print();
	l4.print();

	cout << "Сравнение: " << endl << endl;
	if (l1 == l2)
			cout << "Объекты равны" << endl << endl;
		else
			cout << "Объекты неравны" << endl << endl;

		cout << "Присваивание: " << endl << endl;
		l2 = l1;

		l1.print();
		l2.print();
		List list_mchns;
		list_mchns.Add(l3);
		list_mchns.Add(l4);
		list_mchns.Show();
		list_mchns.sort();
		list_mchns.Show();
		system("pause");
		return 0;
	}