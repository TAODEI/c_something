#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Person {
  public:
    string name, idNumber, date;
    int sex;

  public:
    Person(string name, string idNumber, string date, int sex = 0)
        : name(name), idNumber(idNumber), date(date), sex(sex) {}
};

class Student : virtual public Person {
  private:
    string studentID;
    int grade;

  public:
    Student(string name, string studentID, int grade, string idNumber,
            string date, int sex = 0)
        : Person(name, idNumber, date, sex), grade(grade), studentID(studentID) {}
};

class Teacher : virtual protected Person {
  private:
    string jobTitle;

  public:
    Teacher(string name, string jobTitle, string idNumber, string date, int sex = 0)
        : Person(name, idNumber, date, sex), jobTitle(jobTitle) {}

    string GetJobTitle() {
        return jobTitle;
    }
};

class StuTeah : public Student, public Teacher {
  public:
    StuTeah(string name, string studentID, int grade, string jobTitle,
            string idNumber, string date, int sex = 0)
        : Person(name, idNumber, date, sex),
          Student(name, studentID, grade, idNumber, date, sex),
          Teacher(name, jobTitle, idNumber, date, sex) {}
    string GetName() {
        return name;
    }
};

// 完善第8章的student 类模板P307，使之可以添加、删除、查询学生积累，对学生的成绩进行排序。
template <class T, class Tscore = int, int num = 10>
class student {
  private:
    int n;
    T StudentIDs[num];
    Tscore scores[num];
    int tags[num];
  public:
    student() {
        n = 0;
    }

    void Append(T ID, Tscore s) {
        StudentIDs[n] = ID;
        scores[n] = s;
        tags[n] = 1;
        n++;
    }

    void Delete(T ID) {
        for (int i = 0; i < n; i++) {
            if (ID == StudentIDs[i]) {
                tags[i] = 0;
            }
        }
    }

    int Select(T ID) {
        for (int i = 0; i < n; i++) {
            if (ID == StudentIDs[i]) {
                return scores[i];
            }
        }
        return 0;
    }

    void Sort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (scores[i] < scores[j]) {
                    scores[i] ^= scores[j] ^= scores[i] ^= scores[j];
                    T tmp = StudentIDs[i];
                    StudentIDs[i] = StudentIDs[j];
                    StudentIDs[j] = tmp;
                }
            }
        }
    }

    void Display() {
        for (int i = 0; i < n; i++) {
            if (tags[i] == 1) {
                cout << "id:" << StudentIDs[i] << " score" << scores[i] << endl;
            }
        }
    }
};


int main() {
    student <string>s;


    StuTeah s1("cjh", "2020211111", 100, "中央军事委员会主席", "510704823472834721", "2011.11.11", 0);
    StuTeah s2("lst", "2020216666", 60, "共和國主席", "51070474286289341", "1999.9.9");

    ofstream outfile;
    outfile.open("record.dat", ios::out | ios::trunc);
    outfile << s1.name << " " << s1.GetJobTitle() << " " << s1.idNumber << endl;
    outfile << s2.name << " " << s2.GetJobTitle() << " " << s2.idNumber;

    outfile.close();
    
    ifstream infile; 
    infile.open("record.dat");
    string name, jobTitle, idNumber;
 
    cout << "Reading from the file" << endl;

    while (!infile.eof()) {

        infile >> name >> jobTitle >> idNumber;
        cout << "data: " << name << " " << jobTitle << " " << idNumber << endl;
    }

    infile.close();
}