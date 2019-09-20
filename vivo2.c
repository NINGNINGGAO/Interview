#include "stdio.h"
#include <stdlib.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
/*
* Welcome to vivo !
*/

int getCountOfApp(const char* input){
    if(NULL == input){
        return 0;
    }
    int cnt = 0;
    for(int i=0;input[i]!=0;++i){
        if(input[i] == ','){
            ++cnt;
        }
    }
    return cnt/2;
}

//id start from 0
int getPositionOfApp(const char* input, const int id){
    int cntOfComma = id*2 + 1;
    int i=0;
    for(;input[i]!=0&&cntOfComma!=0;++i){
        if(input[i] == ','){
            --cntOfComma;
        }
    }
    while(input[--i]!=' '&&input[i]!='#');
    return i+1;
}

#define APP_MAX 1000
#define DP_MAX 2048
int disks[APP_MAX];
int mems[APP_MAX];
int users[APP_MAX];
int dp[DP_MAX*DP_MAX];

int solution(int countOfApp, int disk, int mem){

    // TODO Write your code here
    for (int i = 1; i <= countOfApp; i++) {
        for (int j = 1; j <= disk; j++) {
            for (int k = 1; k <= mem; k++) {
                if (j < disks[i] && k < mems[i]) {
                    dp[i * disk * mem + j * mem + k] = dp[(i - 1) * disk * mem + j * mem + k]
                } else {
                    dp[i * disk * mem + j *mem + k] = Max(dp[(i - 1) * disk * mem + j * mem + k], dp[(i - 1) * disk * mem])
                }
            }
        }
    }


    return -1;
}

int main(int argc, char* args[])
{
    char input[10000];
    gets(input);
    const int countOfApp = getCountOfApp(input);
    if(0 == countOfApp){
        return 0;
    }

    int disk = 0;
    int mem = 0;

    sscanf(input, "%d %d", &disk, &mem);
    for(int i=0; i< countOfApp;++i){
        const int pos = getPositionOfApp(input, i);
        sscanf(input+pos, "%d,%d,%d", &disks[i], &mems[i], &users[i]);
    }
    int num = solution(countOfApp, disk, mem);
    printf("%d\n", num);
    return 0;
}