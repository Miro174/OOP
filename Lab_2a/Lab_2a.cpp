#include <iostream>
#include <vector>
#include <typeinfo>

class Class1
{
public:
	Class1() {}
	virtual ~Class1() {}
	virtual Class1* clone()
	{
		Class1* copyObj = new Class1(*this);
		return copyObj;
	}
};

class Class2 : public Class1
{
public:
	Class2() {}
	~Class2() {}
	Class1* clone()
	{
		Class1* copyObj = new Class2(*this);
		return copyObj;
	}
};

void my_copy(Class1* obj, std::vector<Class1*>& dB)
{
	Class1* copyObject = obj->clone();
	dB.push_back(copyObject);
}

int main()
{
	Class1* obj1 = new Class1();
	Class1* obj2 = new Class2();

	std::vector<Class1*> dataBase;
	my_copy(obj1, dataBase);
	my_copy(obj2, dataBase);


	for (int i = 0; i < dataBase.size(); ++i)
	{
		std::cout << typeid(*(dataBase[i])).name() << std::endl;
		delete dataBase[i];
	}

	delete obj1;
	delete obj2;

	return 0;
}