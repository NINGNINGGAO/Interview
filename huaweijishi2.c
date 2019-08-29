#include <stdio.h>
#define absd(a,b) (((a) - (b) >= 0) ? ((a) - (b)) :((b) - (a)))

int main() {
    int a[6];
    int ret;
    while (scanf("%d %d %d %d %d %d", &(a[0]), &(a[1]), &(a[2]), &(a[3]), &(a[4]), &(a[5])) != EOF) {
        ret = member(a);
        printf("%d\n", ret);
    }
    return 0;
}

int member(int* a) {
    int ret = 1;
    int temp[6], mid[6];
    for (int i = 0; i < 6; i++) {
        temp[i] = a[i] % 10;
        mid[i] = a[i] / 10;
    }
    for (int i = 0; i < 6; i++) {
        if (temp[i] < 0 || temp[i] > 5 || mid[i] < 0 || mid[i] > 5) {
            return 0;
        }
    }
    int flag[6] = {0};
    for (int i = 0; i < 6; i++) {
        search(temp, mid, flag, i);  
    }
    for (int j = 0; j < 6; j++) {
        if (flag[j] == 0) {
            ret = 0;
        }
    }
    return ret;
}
void search(int* temp, int* mid, int* flag, int i) {
    for (int j = 0; j < 6; j++) {
        if ((absd(temp[j], temp[i]) == 1 && absd(mid[j], mid[i]) == 0) || ((absd(temp[j], temp[i]) == 0) && (absd(mid[j], mid[i]) == 1))) {
            flag[i] = 1;
            break;
        }
    }
}