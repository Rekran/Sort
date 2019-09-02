#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


void selection_sort(long int *vector,int size){
    for (int i = 0; i < size; i++)
    {
        int indexMin = i;
        for (int j = i; j < size; j++)
        {
            if(vector[j] < vector[indexMin])
                indexMin = j;
        }
        if(indexMin != i){
            long int aux = vector[i];
            vector[i] = vector[indexMin];
            vector[indexMin] = aux;
        }
    }
    

}

void insertion_sort(long int* vector,int size){
    for (int i = 1; i < size; i++)
    {
        int j = i;
        int indexMax;
        while ((j > 0) && (vector[j - 1] > vector[j]))
        {
            long int aux = vector[j];
            vector[j] = vector[j-1];
            vector[j-1] = aux;           
            j--;
        }
        
    }
    
}

int main(){
    ifstream file;
    int size;
    long int* vector;

    file.open("../instancias-num/num.1000.4.in"); 
    file>>size;
    vector = (long int*)malloc(sizeof(long int) * size);
    
    for(int i = 0 ; i < size; i++) 
        file>>vector[i];
    
    insertion_sort(vector,size);

    for(int i = 0 ; i < size; i++)
        cout<<vector[i]<<endl;


free(vector);
    
return 0;
}
