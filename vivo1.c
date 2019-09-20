#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

/*
* Welcome to vivo !
*/

int solution(char* src) {
    int num = 0;

    // TODO Write your code here
    int i = 0;
    while (src[i] != '0') {
        if (src[i] == '(') {
            num++;
        } else if (src[i] == ')') {
            num--;
        }
        i++;
    }
    return num;
}

int main() {
    char src[MAX_SIZE] = {0};
    int num = 0;
    scanf("%s", src);
    num = solution(src);
    printf("%d\n", num);
    return 0;
}