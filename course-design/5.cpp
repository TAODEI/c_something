//
// Created by TAODEI on 2022/3/24.
//

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void insertMap(map<string, int> &Map, string data) {
    map<string, int>::iterator it;;
    it = Map.find(data);
    if (it == Map.end()) {
        Map[data] = 1;
    } else {
        Map[data] += 1;
    }
}

int main() {
    fstream file;
    file.open("../course-design/student.dat", ios::out | ios::in);

    map<string, int> Map;
    int lineCount = 0;
    int wordCount = 0;
    for (string line; getline(file, line); lineCount++) {
        string data;
        for (string::iterator it = line.begin(); ; it++) {
            if (*it == ' ') {
                insertMap(Map, data);
                data = "";
                wordCount++;
                continue;
            }

            if (it == line.end()) {
                insertMap(Map, data);
                wordCount++;
                break;
            }
            data += *it;
        }
    }

    cout << "line: " << lineCount << endl;
    cout << "word: " << wordCount << endl;
    for (auto pair: Map) {
        cout << pair.first << " : " << pair.second << endl;
    }
}
