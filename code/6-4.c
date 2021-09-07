#include <stdio.h>
int sqr(int x) {
    return x * x;
}
int pow4(int y) {
    return sqr(y) * sqr(y);
}
void main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", pow4(a));
}
