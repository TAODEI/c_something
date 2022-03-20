#include<stdio.h>

void sum_rows(int ar[][4], int rows);//等价于 int(*ar)[4]
void sum_cols(int [][4], int);//函数声明时可省略形参名
int sum2d(int(*ar)[4], int rows);//另一种语法
int main() {
    int junk[3][4] = {
            {2,  4,  6, 8},
            {3,  5,  7, 9},
            {12, 10, 8, 6}
    };

    sum_rows(junk, 3);
    sum_cols(junk, 3);
    printf("Sum of all elements=%d\n", sum2d(junk, 3));

}

void sum_rows(int ar[][4], int rows) {
    int r;
    int c;
    int tot;

    for (r = 0; r < rows; r++) {
        tot = 0;
        for (c = 0; c < 4; c++)
            tot += ar[r][c];
        printf("row %d: sum=%d\n", r, tot);
    }
}

void sum_cols(int ar[][4], int rows) {
    int r;
    int c;
    int tot;

    for (r = 0; r < rows; r++) {
        tot = 0;
        for (c = 0; c < rows; r++)
            tot += ar[r][c];
        printf("col %d: sum=%d\n", c, tot);
    }
}

int sum2d(int ar[][4], int rows) {
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < 3; r++) {
        for (c = 0; c < 4; c++)
            tot += ar[r][c];
    }
    return tot;
}