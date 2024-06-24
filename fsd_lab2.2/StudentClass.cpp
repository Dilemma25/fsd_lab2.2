#include "StudentClass.h"

Student::Student() {}


Student::Student(int lineNumber) {
	this->lineNumber = lineNumber;
};

void Student::parseData(std::string data)
{
	std::istringstream iss(data);

	try {
		iss >> this->passport.serial >> this->passport.number;
		iss >> this->fullname.name >> this->fullname.middleName >> this->fullname.lastName;
		iss >> this->adress.town >> this->adress.street >> this->adress.numberHouse;
		this->key = this->adress.numberHouse;
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
	}
};


std::string Student::getFullName() const
{
	return this->fullname.name + this->fullname.middleName + this->fullname.lastName;
}

std::string Student::getFullAdress() const
{
	return this->adress.town + this->adress.street + std::to_string(this->adress.numberHouse);
}

std::ostream& operator<<(std::ostream& os, Student& student)
{
	return os << student.passport.number << ' ' << student.passport.serial << ' ' << student.fullname.name << ' '
		<< student.fullname.middleName << ' ' << student.fullname.lastName << ' '
		<< student.adress.town << ' ' << student.adress.street << ' ' << student.adress.numberHouse << '\n';
}


