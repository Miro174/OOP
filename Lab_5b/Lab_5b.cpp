#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class A {
public:
	const string s;
	A() {
		cout << "Конструктор по умолчанию класса А" << endl;
	}

	A(const char* a) : s(a) {
		cout << "Пользовательский Конструктор класса A" << endl;
		cout << s << endl;
	}

	A(const A& obj) : s(obj.s) {}
	virtual A* clone() {
		return new A(*this);
	}
	virtual ~A() {
		cout << "Деструктор класса A" << endl;
		cout << typeid(*this).name() << endl;
	}
};

class B final : public A {
public:
	B() {
		cout << "Конструктор класса B" << endl;
	}
	B(const char* a) :A(a) {
	}
	B(const B& obj) : A(obj) {};
	B* clone() override {
		return new B(*this);
	}
	~B() {
	}
};

template<class T>
void del(const T& v) {
	for (auto& i : v)
		delete i;
}

int main() {
	setlocale(LC_ALL, "ru");
	list <A*> l;
	vector<A*> v;
	l.push_back(new A("first"));
	l.push_back(new B("second"));
	for (auto i : l) {
		v.push_back(i->clone());
	}

	{
		for (auto& i : l)
			cout << i << " ";
		cout << '\n';
		for (auto& i : v)
			cout << i << " ";
		cout << '\n';
	}

	del(v);
	del(l);

	l.clear();
	v.clear();
}