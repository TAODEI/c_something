#include <iostream>

using namespace std;

class Person {
public:
    string name, idNumber;
    int sex;

public:
    Person(string name, string idNumber, int sex = 0) : name(name), idNumber(idNumber), sex(sex) {}
};

class Student : virtual protected Person {
private:
    string studentID;
    int grade;

public:
    Student(string name, string studentID, int grade, string idNumber, int sex = 0) : Person(name, idNumber, sex),
                                                                                      grade(grade),
                                                                                      studentID(studentID) {}
};

class Teacher : virtual protected Person {
private:
    string jobTitle;

public:
    Teacher(string name, string jobTitle, string idNumber, int sex = 0) : Person(name, idNumber, sex),
                                                                          jobTitle(jobTitle) {}
};

class StuTeah : public Student, public Teacher {
public:
    StuTeah(string name, string studentID, int grade, string jobTitle, string idNumber, int sex = 0)
            : Person(name, idNumber, sex),
              Student(name, studentID, grade, idNumber, sex),
              Teacher(name, jobTitle, idNumber, sex) {}

    string GetName() {
        return name;
    }
};

int main() {
    StuTeah s("cjh", "202021", 100, "部长", "510704", 0);
    cout << s.GetName();
}