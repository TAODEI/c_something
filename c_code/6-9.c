#include <stdio.h>
int i, tem = 0, b;
void r(int v[], int n) {
    for (i = 0; i <= n / 2; i++) {
        tem = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = tem;
    }
}
void main() {
    printf("数组长度为：\n");
    scanf("%d", &b);
    int a[b];
    for (i = 0; i < b; i++) {
        printf("[%d]:", i);
        scanf("%d", &a[i]);
    }
    r(a, b);
    for (i = 0; i < b; i++) {
        printf("[%d]:%d\n", i, a[i]);
    }
}
