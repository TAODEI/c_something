#include <iostream>
using namespace std;

class Student {
    struct Class {
        string className;
        int score;
    };
    int StudentID;
    int ClassNum;
    string Name;
    Class *Classes;
    static int StudentNum;

  public:
    Student(string name, int id) {
        ClassNum = 0;
        Classes = new Class[100];
        Name = name;
        StudentID = id;
        StudentNum++;
    }
    
    void AddClass(string name, int score) {
        Class c;
        c.score = score;
        c.className = name;
        Classes[ClassNum] = c;
        ClassNum++;
    }

    float GetAverageScore() {
        float sum = 0;
        for (int i = 0; i < ClassNum; i++) {
            sum += Classes[i].score;
        }
        return (float)(sum / ClassNum);
    }
};

int Student::StudentNum = 0;

int main() {
    Student stu("cjh", 1);
    stu.AddClass("cpp", 100);
    stu.AddClass("English", 60);
    stu.AddClass("高数", 60);

    float average = stu.GetAverageScore();
    cout << average << endl;
}