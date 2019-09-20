#include <stdio.h>
#include <string.h>
#define Maxnum 10000
void strcat1(char *a, int num1, char *b, int num2);

int main() {
    char a[Maxnum], b[Maxnum];
    scanf("%s", a);
    scanf("%s", b);
    int num1 = strlen(a);
    int num2 = strlen(b);
    strcat1(a, num1, b, num2);
    printf("%s\n", a);
    return 0;
}

void strcat1(char *a, int num1, char *b, int num2) {
    for (int i = num1; i < num1 + num2; i++) {
        a[i] = b[i - num1];
    }
    a[num1 + num2] = 0;
}