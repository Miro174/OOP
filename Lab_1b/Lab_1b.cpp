#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Car {
public:
	Car(const std::string& _company, const std::string& _model) :
		company(_company),
		model(_model) {}

	virtual ~Car() {
		std::cout << "Company = " << company << ",    " << "Model = " << model << "\n";
	}

private:
	const std::string company;
	const std::string model;
};

class Toyota :public Car {
public:
	Toyota(const std::string& model) :Car("Toyota", model) {}

	~Toyota() = default;
};

class Mitsubishi : public Car {
public:
	Mitsubishi(const std::string& model) : Car("Mitsubishi", model) {}

	~Mitsubishi() = default;
};

class Nissan : public Car {
public:
	Nissan(const std::string& model) :Car("Nissan", model) {}

	~Nissan() = default;
};

class Mazda : public Car {
public:
	Mazda(const std::string& model) :Car("Mazda", model) {}

	~Mazda() = default;
};

int main() {
	std::ifstream file("cars.txt");

	std::vector<Car*> base;
	std::string company, model;

	while (file >> company >> model) {
		if (company == "Toyota") {
			base.push_back(new Toyota(model));
		}
		else if (company == "Mitsubishi") {
			base.push_back(new Mitsubishi(model));
		}
		else if (company == "Nissan") {
			base.push_back(new Nissan(model));
		}
		else if (company == "Mazda") {
			base.push_back(new Mazda(model));
		}
	}

	for (const Car* car : base) {
		delete car;
	}
}