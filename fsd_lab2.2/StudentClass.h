#pragma once

#include<iostream>
#include<sstream>

class Student {

	struct Passport {
		std::string number;
		std::string serial;
	};

	struct FullName {
		std::string name;
		std::string middleName;
		std::string lastName;
	};

	struct Adress {
		std::string town;
		std::string street;
		int numberHouse;
	};
public:
	Passport passport;
	FullName fullname;
	Adress adress;
	int lineNumber;
	int key;

public:
	Student();

	Student(int lineNumber);

	void parseData(std::string data);

	friend std::ostream& operator<<(std::ostream& os, Student& student);

	std::string getFullName() const;

	std::string getFullAdress() const;
};

