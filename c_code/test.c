#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void a() {
    
    printf("111\n");
}

typedef struct ss {
    int i;
    char s[];
} * node;

struct sdshdr {
    
    // buf 中已占用空间的长度
    int len;

    // buf 中剩余可用空间的长度
    int free;

    // 数据空间
    char buf[];
};

int main() {
    struct sdshdr *a;
    int n[5];
    n[1] = 1;
    n[0] = 0;
    int *p = n;
    printf("%d\n", *(++p));
    // auto b = 1;
    printf("%ld\n", sizeof(a));
    a = calloc(1, sizeof(struct sdshdr)+1);
    // struct sdshdr a;
    memcpy(a->buf, "", 5);
    a->buf[1] = '1';
    // auto b = 1;
    printf("%ld\n", sizeof(a));
    //     node s;
    //     if (!s) {

    //     }
    //     // int a[5] = {0};
    //     // int b = 0 [a];
    //     // printf("%d\n", b);
    //     int a, b;
    //     a ^= b ^= a ^= b;
}