#include <stdio.h>

int binarySearchRecurvise(int[],int,int,int);
void insertValueToArray(int[], int);

int main(int count, const char *args[])
{
    int f = 455;
    int length = 500;
    int array[500];
    insertValueToArray(array, length);
    printf("so %d can tim o vi tri %d trong mang\n", f, binarySearchRecurvise(array, f, 0, length-1));
    return 0;
}

void insertValueToArray(int array[],int length){
    int i;
    for(i = 0; i < length; i++){
        array[i] = i + 1;
    }
}

int binarySearchRecurvise(int a[], int find, int low, int high){
    if(a[low] == find){
        return low;
    }
    if(a[high] == find){
        return high;
    }
    int mid = (low + high) / 2;

    if(a[mid] == find){
        return mid;
    }
    else if(a[mid] > find){
        return binarySearchRecurvise(a, find, low, mid - 1);
    }
    else{
        return binarySearchRecurvise(a, find , mid + 1, high);
    }
}