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
        for (int i = 0; i < (arr->size); i++) {
            printf("%d ", arr->data[i]);
        }
    }
}

float median(DynamicArray *arr, int n){
    int cekGanjil;
    int mediGanjil;
    if(n%2 == 1){
        cekGanjil = 1;
    } else{cekGanjil = 0;}

    if(cekGanjil ==1){
        mediGanjil = arr->data[n/2];
        return mediGanjil;
    }
    else{
        float a = arr->data[(n/2)-1];
        float b = arr->data[(n/2)];
        float mediGenap = (a+b) / 2;
        return mediGenap;
    }
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
    float input;
    int medGanjil;
    float medGenap;

    do{
        scanf("%f", &input);
        if(input != -1){
            addData(&data, input);
            count++;
        }
    }
    while (input != -1);

    bubbleSort(&data, count);

    if(count % 2 == 1){medGanjil = median(&data, count);} 
    else{medGenap = median(&data, count);}

    printf("COUNT %d ", count);
    printf("SORTED ");
    printData(&data, count);
    if(count % 2 ==1){printf("MEDIAN %d", medGanjil);}
    else{printf("MEDIAN %.2f", medGenap);}
    
    freeArray(&data);
    return 0;
}
 
