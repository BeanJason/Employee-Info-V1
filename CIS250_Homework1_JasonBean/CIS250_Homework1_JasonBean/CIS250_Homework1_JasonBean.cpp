// 2/12/2019
//Jason Bean
//Homework01 reading files

#include "pch.h"
#include <iostream>
#include "string"
#include "vector"
#include "fstream"

using namespace std;

struct department {
	int departmentID;
	string departmentName;
	string buildingLetter;
	int buildingFloor;
	string departmentPhoneNumber;
};

struct Employee {
	string SS;
	string firstName;
	string lastName;
	string middleInitial;
	string city;
	string state;
	int age;
	string gender;

	department dept;
};



void readFile(vector<Employee>&);
void display();
void option1(vector<Employee>);
void option2(vector<Employee>);
void option3(vector<Employee>);
void option4(vector<Employee>);
void option5(vector<Employee>);
void option6(vector<Employee>);

int main()
{
	int selection;
	bool quit = false;
	vector<Employee> Employees;

	readFile(Employees);
	display();

	while (!quit) {
	
	cout << "Enter your selection (0 for menu, -999 to exit): ";

	cin >> selection;
	system("CLS");

		if (selection == 0) {
			display();
		}

		if (selection == 1) {
			option1(Employees);
		}

		if (selection == 2) {
			option2(Employees);
		}

		if (selection == 3) {
			option3(Employees);
		}

		if (selection == 4) {
			option4(Employees);
		}

		if (selection == 5) {
			option5(Employees);
		}

		if (selection == 6) {
			option6(Employees);
		}

		if (selection == -999) {
			cout << "Goodbye" << endl;
			quit = true;
		}
	}
	
	system("pause");
	return 0;
}

void display() {
	cout << "EMPLOYEE INFORMATION BEANS' BEANS COMPANY INC." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "1. Display all employees" << endl;
	cout << "2. Display name of oldest employee" << endl;
	cout << "3. Display the building letter and floor for Computer Science department" << endl;
	cout << "4. Display department names who are in building A" << endl;
	cout << "5. Find an employee and list their information" << endl;
	cout << "6. Average age of employees who live in Michigan" << endl;
	cout << "0. Return to menu" << endl;
	cout << "-999. Exit the program" << endl;
}

void readFile(vector<Employee> &Employees) {
	//vector<Employee> Employees;
	int EmployeesSize = Employees.size();
	ifstream inputFile;
	string fileName = "Employees.txt";
	string lineOfText;
	int empNum = 0;
	char delim = ',';
	int commaPos;

	inputFile.open(fileName);

	if (inputFile) {
		while (getline(inputFile, lineOfText)) {

			Employees.push_back(Employee());

			commaPos = lineOfText.find(delim);


			Employees.at(empNum).SS = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).firstName = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).lastName = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).middleInitial = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).city = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).state = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).age = stoi(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).gender = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).dept.departmentID = stoi(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).dept.departmentName = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).dept.buildingLetter = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).dept.buildingFloor = stoi(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			Employees.at(empNum).dept.departmentPhoneNumber = (lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			empNum++;

		}

	}
	else {
		cout << "File not read" << endl;
	}
}

void option1(vector<Employee> Employees) {

	int empNum = 0;

	
		for (int i = 0; i < Employees.size(); i++) {

			cout << "Employee " << empNum << endl;
			cout << "===========" << endl;
			cout << endl;

			cout << "SSN             :" << Employees[i].SS << endl;
			cout << "Firstname       :" << Employees[i].firstName << endl;
			cout << "Lastname        :" << Employees[i].lastName << endl;
			cout << "Middle Initial  :" << Employees[i].middleInitial << endl;
			cout << "City            :" << Employees[i].city << endl;
			cout << "State           :" << Employees[i].state << endl;
			cout << "Age             :" << Employees[i].age << endl;
			cout << "Gender          :" << Employees[i].gender << endl;
			cout << "Depart ID       :" << Employees[i].dept.departmentID << endl;
			cout << "Depart Name     :" << Employees[i].dept.departmentName << endl;
			cout << "Building Letter :" << Employees[i].dept.buildingLetter << endl;
			cout << "Building Floor  :" << Employees[i].dept.buildingFloor << endl;
			cout << "Phone Number    :" << Employees[i].dept.departmentPhoneNumber << endl;
			
			empNum++;
		}
	
}

void option2 (vector<Employee> Employees){

	int empAge = Employees.at(0).age;
	int emp = 0;

	for (int i = 0; i < Employees.size(); i++) {
		if (Employees.at(i).age > empAge) {
			empAge = Employees.at(i).age;
			emp = i;
		}
	}
		cout << "Oldest Employee Name" << endl;
		cout << "-------------------" << endl;
		cout << Employees.at(emp).lastName << ", " << Employees.at(emp).lastName << " " << Employees.at(emp).middleInitial << endl;
		cout << empAge;
}

void option3(vector<Employee> Employees) {
	cout << "Computer Science Employees" << endl;
	cout << "--------------------------" << endl;

	string letter;
	int floor;

	for (int i = 0; i < Employees.size(); i++) {
		if (Employees[i].dept.departmentName == "Computer Science") {
			letter = Employees[i].dept.buildingLetter;
			floor = Employees[i].dept.buildingFloor;
		}
		
	}
	cout << "Building: " << letter << " " << "Floor: " << floor << endl;
}

void option4(vector<Employee> Employees) {
	//4. Display department names who are in building A

	vector<string> deptNamesVector;
	vector<string> theOne;
	int vectorPos = 0;
	int count = 0;
	int index = 0;
	deptNamesVector.push_back(Employees.at(vectorPos).dept.departmentName);

	for (int i = 0; i < Employees.size(); i++) {
		if (Employees[i].dept.buildingLetter == "A") {

		
			deptNamesVector.push_back(Employees.at(vectorPos).dept.departmentName);
			cout << deptNamesVector.at(vectorPos) << endl;
			vectorPos++;

			//I know as soon as I see the solution to this im going to kick myself for it lol
			//for (int i = 0; i < deptNamesVector.size(); i++) {
			//	if (deptNamesVector.at(count) != deptNamesVector.at(i)) {
			//		theOne.push_back(deptNamesVector.at(count));
			//		//theOne.at(index) = deptNamesVector.at(count);
			//		index++;
			//		count++;

			//		for (int i = 0; i < deptNamesVector.size(); i++) {
			//			if (deptNamesVector.at(count) == deptNamesVector.at(i)) {
			//				theOne.push_back(deptNamesVector.at(count));
			//				//theOne.at(index) = deptNamesVector.at(count);
			//				index++;
			//				
			//			}
			//		}

			//	}
			//}


		}
	}
}

void option5(vector<Employee> Employees) {
	//5. Find an employee and list their information

	string ssn;
	int emp;
	bool found = false;
	cout << "Departmentsf on 1st floor of Building C" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Enter the ssn for the employee";
	cin >> ssn;
	
	

	for (int i = 0; i < Employees.size(); i++) {
		if (Employees[i].SS == ssn) {
			emp = i;
			found = true;
		}
		else {
			found = false;
		}
	}
		if (found = true) {
			cout << "SSN             :" << Employees[emp].SS << endl;
			cout << "Firstname       :" << Employees[emp].firstName << endl;
			cout << "Lastname        :" << Employees[emp].lastName << endl;
			cout << "Middle Initial  :" << Employees[emp].middleInitial << endl;
			cout << "City            :" << Employees[emp].city << endl;
			cout << "State           :" << Employees[emp].state << endl;
			cout << "Age             :" << Employees[emp].age << endl;
			cout << "Gender          :" << Employees[emp].gender << endl;
			cout << "Depart ID       :" << Employees[emp].dept.departmentID << endl;
			cout << "Depart Name     :" << Employees[emp].dept.departmentName << endl;
			cout << "Building Letter :" << Employees[emp].dept.buildingLetter << endl;
			cout << "Building Floor  :" << Employees[emp].dept.buildingFloor << endl;
			cout << "Phone Number    :" << Employees[emp].dept.departmentPhoneNumber << endl;
		}
		else {
			cout << "The emplyee with the ssn of " << ssn << " does not exist" << endl;
		}
}

void option6(vector<Employee> Employees) {
	//Average age of employees who live in Michigan
	cout << "Average age for the employees who live in MI" << endl;
	cout << "--------------------------------------------" << endl;

	int sum = 0;
	int numOfEmp = 0;

	for (int i = 0; i < Employees.size(); i++) {
		if (Employees[i].state == "MI") {
			sum = Employees[i].age + sum;
			numOfEmp++;
		}
	}
	if (numOfEmp != 0) {
		cout << sum / numOfEmp << endl;
	}
	else {
		cout << "No employees live in michigan" << endl;
	}

}