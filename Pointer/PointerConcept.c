#include <stdio.h>
#include <stdlib.h>

int main(int count, const char* args[])
{
    // int x;
    // int *px;

    // px = &x; // lay dia chi cua x

    // x = 69;

    // printf("vi tri cua bien x la %x\n", &x);
    // printf("vi tri cua bien px la %x\n", px);

    // // lay gia tri

    // printf("gia tri cua bien x la %d\n", x);
    // printf("gia tri cua bien px la %d\n", *px);

    int *p, *q;
    // cap phat bo nho bang ham malloc and calloc

    p = (int *)malloc(sizeof(int)); // (int *) ep kieu int
    q = (int *)calloc(1, sizeof(int));

    printf("Vi tri cua con tro p la : %x\n", (unsigned int)p);
    printf("Gia tri cua con tro p la : %d\n", *p);

    printf("Vi tri cua con tro q la : %x\n", (unsigned int)q);
    printf("Gia tri cua con tro q la : %d\n", *q);

    // giai toa vung nho su dung ham free
    free(px);

    // &a[i] <=> a + i
    
    return 0;
}