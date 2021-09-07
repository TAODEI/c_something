#include <stdio.h>
int main(void) {
    int a, b, max, min;
    int sum = 0;
    puts("请输入两个整数");
    scanf("%d%d", &a, &b);
    if (a >= b) {
        min = b;
        max = a + 1;
    } else {
        min = a;
        max = b + 1;
    }

    do {
        sum = sum + min;
        min++;
    } while (min != max);

    printf("之间所有整数和为%d\n", sum);
    return 0;
}
