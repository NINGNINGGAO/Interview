#include <stdio.h>
#include <string.h>
#define Maxnum 1000005

int main() {
    int k;
    scanf("%d\n", &k);
    char a[Maxnum];
    memset(a, 0, sizeof(a));
    int num = 1;
    char temp;
    while (a[num - 1] != '\n') {
        scanf("%c",&(a[num++]));
    }
    int ret = 0;
    int i = 1;
    int sum1 = 0, sum01 = 0, sum02 = 0;
    int flag = 0;
    while (i < num - 1) {
        if (a[i] == '1') {
            if (flag = 1) {
                flag = 0;
                sum01 = sum02;
                sum02 = 0;
            }
            sum1++;
            i++;
            continue;
        }
        if (flag == 0 && a[i] == '0') {
            sum01++;
        }
        if (sum1 == k && a[i] != '0') {
            ret += sum01 + 1;
        } else if (sum1 == k && a[i] == '0') {
            flag = 1;
            while (i < num - 1 && a[i] == '0') {
                sum02++;
                i++;
            }
            ret += (sum01 + 1) * (sum02 + 1);
        } else if (sum1 > k) {
            while (i < num - 1 && a[i] == '0') {
                sum02++;
                i++;
            }
            ret += sum02 + 1;
        }
    }
    printf("%d\n", ret);
    return 0;
}

