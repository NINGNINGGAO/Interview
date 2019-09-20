#include <stdio.h>

main() {
    int a = 10;
    switch (a) {
        case 9:
            a++;
        case 10:
            a++;
        case 8:
            a++;
        case 7:
            a++;
        default:
            a++;
    }
    printf("%d\n", a);
}