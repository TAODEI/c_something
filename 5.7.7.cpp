#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class String {
  public:
    int Len;
    char *str;
  
    String(const char *s) {
        str = new char[1000];
        strcpy(str, s);
        Len = strlen(s);
    }
    bool IsSubString(const char *s) {
        int len = strlen(s);
        for (int i = 0; i < Len - len + 1; i++) {
            for (int j = 0; ; j++) {
                if (str[i+j] != s[j]) {
                    break;
                }
                if (j == len - 1) {
                    return true;
                } 
            }
        }
        return false;
    }
    bool IsSubString(const String &s) {
        int len = s.Len;
        for (int i = 0; i < Len - len + 1; i++) {
            for (int j = 0; ; j++) {
                if (str[i+j] != s.str[j]) {
                    break;
                }
                if (j == len - 1) {
                    return true;
                } 
            }
        }
        return false;
    }
    int Atoi() {
        int sum = 0;
        for (int i = 0; i < Len; i++) {
            if ('0' > str[i] || '9' < str[i]) {
                printf("\nerror:  Atoi wrong!!!\n\n");
                return -1;
            }
            sum = sum * 10 + str[i] - '0';
        }
        return sum;
    }
    void ToUpper() {
        for (int i = 0; i < Len; i++) {
            if ('z' >= str[i] && str[i] >= 'a') {
                str[i] += 'A' - 'a';
            }
        }
    }
};

int main() {
    String s("lstao");
    String strSub("ao");
    cout << s.IsSubString("lst0") << endl;
    cout << s.IsSubString(strSub) << endl;
    
    s.ToUpper();
    cout << s.str << endl;

    String num("3716");
    cout << num.Atoi() << endl;
}