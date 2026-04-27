/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Bismar Alwi Khadavi (13224016)
 *   Nama File           : soal1.c
 *   Deskripsi           : Dari data yang diinput, disimpan di array dinamis, disorting, lalu dicari median
 * 
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr, int initialCapacity){
    arr->capacity = initialCapacity;
    arr->size = 0;
    arr->data = (int *)malloc(arr->capacity * sizeof(int));
}

void addData(DynamicArray *arr, int data){
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;  
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    
    arr->data[arr->size] = data;
    arr->size++;
}

void bubbleSort(DynamicArray *arr, int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
} 

void printData(DynamicArray *arr, int n) {
    if(n>=1){
        for (int i = 0; i < (arr->size - 1); i++) {
            printf("%d ", arr->data[i]);
        }
    }
}

int median(DynamicArray *arr, int n){
    int cekGanjil;
    int medi;
    if(n%2 == 1){
        cekGanjil = 1;
    } else{cekGanjil = 0;}

    if(cekGanjil ==1){
        medi = arr->data[n/2];
    }
    else{
        medi = (arr->data[n/2]+ arr->data[(n/2)-1]) / 2;
    }

    return medi;
}

void freeArray(DynamicArray *arr){
    free(arr->data);
    arr->size = 0;
    arr->capacity = 0;
}

int main(){
    DynamicArray data;
    initArray(&data, 2);
    int count=0;
    int input;
    int med;

    do{
        scanf("%d", &input);
        if(input != -1){
            addData(&data, input);
            count++;
        }
    }
    while (input != -1);

    if(count>1){
        bubbleSort(&data, count);
        med = median(&data, count);
    }

    printf("COUNT %d ", count);
    printf("SORTED ");
    printData(&data, count);
    printf("MEDIAN %d", med);

    freeArray(&data);
    return 0;
}
 
