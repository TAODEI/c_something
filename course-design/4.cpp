#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
    string id;
    string name;
    int grade;

public:
    Student(string id, string name, int grade) : id(id), name(name), grade(grade) {}

    Student() {}

    void In(string fileName) {
        fstream file;
        file.open(fileName, ios::out | ios::in);
        file << id << " " << name << " " << grade << endl;
        file.close();
    }

    void Out(string fileName, int index) {
        fstream file;
        file.open(fileName, ios::out | ios::in);

        for (int i = 0; ; i++) {
            string _id, _name;
            int _grade;
            file >> _id >> _name >> _grade;
            if (_id == "" || _name == "") {
                cout << "index out" << endl;
                cout << _grade;
                break;
            }
            if (i == index) {
                id = _id;
                name = _name;
                grade = _grade;
                break;
            }
        }

        file.close();
    }

    void Print() {
        cout << id << " " << name << " " << grade << endl;
    }
};

int main() {
    Student s1 = Student("2020213675", "TAODEI", 100);
//    s1.In("student.dat");
//    s1.In("student.dat");

    Student s2;
    s2.Out("student.dat", 0);

    s2.Print();
}