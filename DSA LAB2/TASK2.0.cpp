
#include<iostream>
using namespace std;



class Employee {
public:
    virtual double calculateSalary() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    double fixedSalary;
public:
    FullTimeEmployee(double s) : fixedSalary(s) {}
    double calculateSalary() override {
        return fixedSalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};


void runTask2() {
    FullTimeEmployee ali(5000);
    PartTimeEmployee shani(20, 80);
    cout << "ali Salary: " << ali.calculateSalary() << endl;
    cout << "shani Salary: " << shani.calculateSalary() << endl;
}