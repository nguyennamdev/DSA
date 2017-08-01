#include <stdio.h>


int fibonacciRecursive(int);

int main(int count, const char* args[]){
    int i;
    for(i = 0; i < 30; i++){
        printf("%d | ",fibonacciRecursive(i));
    }
    return 0;
}

int fibonacciRecursive(int n){
    if (n == 0){
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}