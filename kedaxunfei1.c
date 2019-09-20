#include <stdio.h>
#define Maxnum 100000

int solution(char* arr, int num) {
    int ret = 0;
    int fast = 0, slow = 0;
    int temp, mid, flag = 0;
    while (fast < num) {
        temp = arr[fast] - '0';
        if (flag == 0 && temp <= 9 && temp >= 0) {
            fast++;
            continue;
        } else if (arr[fast] == ',') {
            if (flag == 0 && fast != slow) {
                mid = (arr[fast - 1] - '0');
                mid += (arr[slow] - '0');
                if (mid > 8) {
                    ret++;
                }
            }
            flag = 0;
            fast++;
            slow = fast;
            continue;
        } else {
            flag = 1;
            fast++;
        }
    }
    return ret;
}


int main() {
    char arr[Maxnum];
    int num = 0;
    do {
        scanf("%c", &(arr[num]));
        num++;
    } while (arr[num - 1] != '\n');
    int ret = solution(arr, num);
    printf("%d\n", ret);
    return 0;
}