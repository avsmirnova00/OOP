#include <iostream>
#include <string>
using namespace std;

template <class T>
class mchns
{
public:
	mchns<T>(); // констр-р по умолч-ю
	mchns<T>(const mchns<T>&); // копирующий констр-р
	mchns<T>(char* name, char* color, int Rzm, int Un, int Wt, int price); // конструктор с параметрами
	~mchns<T>(); // деструктор
	void print() const; // селектор
	mchns<T>& operator = (const mchns<T>& object); // присваивание
	bool& operator == (mchns<T>& object); // сравнение
	friend std::ostream& operator<< (std::ostream& out, const mchns<T>& object);
		int Get_price()const;
private:
	// интерфейсная часть класса
	float Rzm; // размер
	float Un; // напряжение
	int Wt; // мощность (мВт)
	char* name; // наименование
	char* color; // цвет
	int price;

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
	price = 0;
}
template <class T>
mchns<T>::mchns(char* n, char* clr, int r, int u, int w, int p)
{
	name = new char[strlen(n) + 1];
	strcpy((char*)name, n);
	color = new char[strlen(clr) + 1];
	strcpy((char*)color, clr);
	Rzm = r;
	Un = u;
	Wt = w;
	price = p;
}
template <class T>
mchns <T>::mchns(const mchns<T>& object)
{
	/*delete[] name;
	delete[] color;*/
	name = new char[strlen(object.name) + 1];
	strcpy_s(name, object.name);
	color = new char[strlen(object.color) + 1];
	strcpy_s(color, object.color);
	Rzm = object.Rzm;
	Un = object.Un;
	Wt = object.Wt;
	price = object.price;

}
template <class T>
void mchns<T>::print()const
{
	cout << "Наименование: " << name << endl
		<< "Цвет машины: " << color << endl
		<< "Размер: " << Rzm << endl
		<< "Напряжение: " << Un << endl
		<< "Мощность (мВт): " << Wt << endl 
		<< "Цена: " << price << endl << endl;
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
		price = object.price;
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
	if (price == object.price) {
		cout << "Цена: " << endl << price << " совпадает " << object.price << endl; flag = true;
	}
	else {
		cout << "Цена: " << endl << price << " не совпадает " << object.price << endl << endl; flag = false;
	}
	return flag; 
}
std::ostream& operator<< (std::ostream& out, const mchns<class T>& object) {
	out << "Наименование:" << object.name << endl;
	out << "Цвет:" << object.color << endl;
	out << "Цена:" << object.price << endl;
	out << "Напряжение:" << object.Un << endl;
	out << "Мощность:" << object.Wt << endl;
	out << "Размер:" << object.Rzm << endl;
	out << endl;
	return out;
}
int mchns<class T>::Get_price()const {
	return price;
}
struct Node // линейный список
{
	mchns<T> data;
	Node* Next, * Prev;
};
template <class T>
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
	void Add(mchns<T> & data) {
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
		mchns<class T>* arr = new mchns<T>[size];
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
					mchns<T> tmp;
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
	mchns <float> l1((char*)"С/Х машина", (char*)"жёлтый", 10, 40, 100, 220);
	mchns <float> l2((char*)"С/Х машина", (char*)"зеленый", 15, 50, 100, 220);
	mchns <float> l3(l1);
	mchns <float> l4;

	mchns <int> l5((char*)"С/Х машина", (char*)"жёлтый", 10, 40, 100, 220);
	mchns <int> l6((char*)"С/Х машина", (char*)"зеленый", 15, 50, 100, 220);
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
	List <int> list_data;
	list_data.Add(l5);
	list_data.Add(l6);
	list_data.Show();
	list_data.sort();
	list_data.Show();
	system("pause");
	return 0;
}