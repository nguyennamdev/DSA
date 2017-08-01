#include <stdio.h>

int giaithua(int);

int main(int count, const char * args[]){
    int i = 3;
    printf("giai thua cua %d la : %d", i,giaithua(i));
}

int giaithua(int n){
    if(n == 1){
        return 1;
    }
    return n * giaithua(n -1);
}