/*
 * @Author: AGOGIN
 * @Date: 2019-09-15 14:39:32
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-15 16:45:44
 */
#include <stdio.h>

int matching(int* A, int* B, int* C, int* flag, int M, int num) {
    int pflag;
    int temp1[5] = {A[num], B[num], C[num]}, temp2[5];
    int one1, one2, two1, two2;
    for (int i = 0; i < M; i++) {
        pflag = 0;
        if (i != num && flag[i] == 1) {
            temp2[0] = A[i];
            temp2[1] = B[i];
            temp2[2] = C[i];
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < 3; j++) {
                    if (temp1[k] == temp2[j]) {
                        if (pflag == 0) {
                            one1 = k;
                            two1 = j;
                        } else if (pflag == 1){
                            one2 = k;
                            two2 = j;
                        }
                        pflag++;
                        break;
                    }
                }
            }
            int mid;
            if (pflag == 2) {
                int tmp1 = one1 - one2, tmp2 = two1 - two2;
                if (tmp1 == tmp2) {
                    mid = temp1[one1];
                    temp1[one1] = temp1[one2];
                    temp1[one2] = mid;
                    A[num] = temp1[0];
                    B[num] = temp1[1];
                    C[num] = temp1[2];
                } else if ((tmp1 == -2 && tmp2 == 1) || (tmp1 == 2 && tmp2 == -1) || (tmp1 == 1 && tmp2 == -2) || (tmp1 == -1 && tmp2 == 2)) {
                    mid = temp1[one1];
                    temp1[one1] = temp1[one2];
                    temp1[one2] = mid;
                    A[num] = temp1[0];
                    B[num] = temp1[1];
                    C[num] = temp1[2];
                }
                return i;
            }
        }
    }
    return -1;
}

void Sort(int* A, int* B, int* C, int M) {
    int temp[6];
    int mid;
    for (int i = 0; i < M; i++) {
        temp[0] = A[i];
        temp[1] = B[i];
        temp[2] = C[i];
        mid = i;
        for (int j = 0; j < 3; j++) {
            if (temp[mid] > temp[j]) {
                mid = j;
            }
        }
        for (int k = 0; k < mid; k++) {
            temp[k + 3] = temp[k];
        }
        A[i] = temp[mid++];
        B[i] = temp[mid++];
        C[i] = temp[mid];
    }
}

void solution(int* A, int* B, int* C, int N, int M) {
    int flag[M];
    memset(flag, 0, sizeof(flag));
    flag[0] = 1;
    int num;
    int i = 1, mid = 1;
    while (1) {
        mid = 1;
        while (flag[i] == 1) {
            if (i != M - 1) {
                i++;
                mid++;
            } else {
                break;
            }
        }
        if (i > M - 1) {
            i = 1;
        }
        if (mid == M - 1) {
            break;
        }
        num = matching(A, B, C, flag, M, i);
        if (num != -1) {
            flag[i] = 1;
        }
        if (i < M - 1) {
            i++;
        } else {
            i = 1;
        }
    }
    Sort(A, B, C, M);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[M], B[M], C[M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &(A[i]), &(B[i]), &(C[i]));
    }
    solution(A, B, C, N, M);
    for (int i = 0; i < M; i++) {
        printf("%d %d %d\n", A[i], B[i], C[i]);
    }
    return 0;
}