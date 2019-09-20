#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Num 10
void Sort(int a[Num]);


int main() {
    int a[Num];
    for (int i = 0; i < Num; i++) {
        scanf("%d", &(a[i]));
    }
    Sort(a);
    printf("%d", a[0]);
    for (int j = 1; j < Num; j++) {
        printf(" %d", a[j]);
    }
}

void Sort(int a[Num]) {
    int temp;
    int Max;
    for (int i = 0; i < Num - 1; i++) {
        Max = i;
        for (int j = i + 1; j < Num; j++) {
            if (a[j] > a[Max]) {
                Max = j;
            }
        }
        temp = a[i];
        a[i] = a[Max];
        a[Max] = temp;
    }
}