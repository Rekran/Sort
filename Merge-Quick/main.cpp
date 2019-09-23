#include "MergSort.h"
#include "QuickSort.h"

int main(void){

    ifstream file;
    int size;
    long int* vector;

    file.open("../instancias-num/num.1000.1.in"); 
    file>>size;
    vector = (long int*)malloc(sizeof(long int) * size);
    
    for(int i = 0 ; i < size; i++) 
        file>>vector[i];

    QuickSort(vector,0,size);
    
    for(int i = 0 ; i < size; i++) 
        printf("%ld\n",vector[i]);

free(vector);

    return 0;
}