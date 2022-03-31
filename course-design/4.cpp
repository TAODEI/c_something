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

    void Out(string fileName) {
        ofstream outFile;
        outFile.open(fileName, ios::app);
        outFile << id << " " << name << " " << grade << endl;
        outFile.close();
    }

    void In(string fileName, int index) {
        fstream file;
        file.open(fileName, ios::out | ios::in);

        for (int i = 0;; i++) {
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

    void insertMap(map<string, Student> &Map) {
        Map[id] = *this;
    }

    void Print() {
        cout << id << " " << name << " " << grade << endl;
    }
};