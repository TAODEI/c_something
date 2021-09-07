#include <stdio.h>
#include <string.h>
typedef struct {
    int num;
    int zimu;
} a;
void main() {
    int i, j, n = 0;
    a s[26][2];
    char str[128];
    scanf("%s", str);
    for (i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
        if (str[i] == 0)
            break;
        if (s[n]->zimu == str[i]) {
            s[n]->num++;
        } else {
            n++;
            s[n]->zimu = str[i];
            s[n]->num = 1;
        }
    }
    for (i = 1; i <= n; i++)
        printf("%c%d", s[i]->zimu, s[i]->num);
    putchar('\n');
}
