//
// Created by TAODEI on 2022/3/24.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "4.cpp"

using namespace std;

int main() {
    map<string, Student> Map;

    fstream file1;
    file1.open("../course-design/student1.dat", ios::out | ios::in);
    string line;
    for (int i = 0; getline(file1, line); i++) {
        Student s;
        s.In("../course-design/student1.dat", i);
        s.insertMap(Map);
    }

    fstream file2;
    file2.open("../course-design/student2.dat", ios::out | ios::in);
    for (int i = 0; getline(file2, line); i++) {
        Student s;
        s.In("../course-design/student2.dat", i);
        s.insertMap(Map);
    }

    for (auto pair: Map) {
        pair.second.Out("../course-design/student3.dat");
        pair.second.Print();
    }
}


