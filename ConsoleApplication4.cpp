

#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
	string name;
	int age;
public:

	Person(string name, int age) {
		this->age = age;
		this->name = name;

	}

	void eat() {
		cout << "had ate";
	}

	

};


class Employee {
protected:
	double salary;
public:
	Employee(double salary) {
		this->salary = salary;

	}

	void work() {
		cout << "Has work";
	}

	
	
};

class Teacher : public Person, public  Employee {
protected:
	string group;
public:

	Teacher(string name, int age, double salary,string group) : Person(name, age), Employee(salary) {
		this->group = group;
	}
	void info() {
		
		cout <<endl<< "ЗП: " << salary;
		cout <<endl<< "NAME: " << name << endl;
		cout <<endl<< "AGE: " << age << endl;
		cout<<endl <<"Группа:"<<group;

	}

};


int main()
{
	setlocale(LC_ALL,"rus");


	cout << endl;
	Teacher teach("MESSSSSIII", 12, 200,"g6");
	cout << endl;
	teach.info();
	
	cout << endl;

	cout << endl;
	

}
