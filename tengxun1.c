#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int n;
    scanf("%d\n", &n);
    int k;
    char temp;
    for (int i = 1; i <= n; i++) {
        int m;
        scanf("%d\n", &m);
        char nums[m];
        for (int j = 0; j < m; j++) {
            scanf("%c", &(nums[j]));
        }
        scanf("%c", &temp);
        if (m < 11) {
            printf("NO\n");
        } else {
            for (k = 0; k < m; k++) {
                if (nums[k] == '8') {
                    break;
                }
            }
            if (m - k >= 11) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}