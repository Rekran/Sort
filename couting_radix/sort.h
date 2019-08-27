#include "maxmin.h"
void countingSort(int *vector , int size){

    
    int *aux_vector = (int*)malloc(sizeof(int) * size);
    int min = getMin(vector,size);
    

    if(min < 0)
        for (int i = 0; i < size; i++)
            vector[i] += abs(min);
    
    int max = getMax(vector,size);    
    int *couting = (int*)malloc(sizeof(int) * (max+1));


    for(int i = 0 ; i < size ; i++){
        couting[ vector[i] ]++;
    }
    
    for(int i = 1 ; i < (max+1);i++)
        couting[i] +=couting[i-1];

    for(int i = size; i >= 0; i--){

        aux_vector[couting[vector[i]]] = vector[i];
        couting[ vector[i] ]--;
    }
    if(min >= 0){
        for (int i = 0; i < size; i++)
            vector[i] = aux_vector [i];
    }
    else{
        for (int i = 0; i < size; i++)
            vector[i] = aux_vector [i] - abs(min);
    }
    

    free(couting);
    free(aux_vector);

}

void countingSort(int *vector , int size,int digit){

    int couting[10]= {0}; 
    int *aux_vector = (int*)malloc(sizeof(int) * size);
    int aux;
    
    for(int i = 0 ; i < size ; i++)    
        couting[(vector[i]/digit)%10]++;
    
    
    for(int i = 1 ; i < 10;i++)
        couting[i] += couting[i-1];

    for(int i = size-1; i >= 0; i--){
        aux_vector[ couting[ (vector[i]/digit)%10 ] - 1 ] = vector[i];
        couting[ (vector[i]/digit)%10 ]--;
    } 

    for (int i = 0; i < size; i++){
        vector[i] = aux_vector [i];
    }
    
    free(aux_vector);

}

void radixSort(int *vector,int size){
    int max = getMax(vector, size);
    int min = getMin(vector,size);
    min = abs(min);

    for(int i = 0 ; i < size; i++)
        vector[i] += min; 

    for(int i = 1 ; max/i > 0; i*=10)
        countingSort(vector,size,i);

    for(int i = 0 ; i < size; i++)
        vector[i] -= min; 

}