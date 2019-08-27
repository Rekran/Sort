#include <iostream>
#include <fstream>
#include "sort.h"

using namespace std;

int main(){

int size;
ifstream file;
int *vector;

file.open("instancias-num/num.100000.3.in");
file>>size;

vector = (int*)malloc(sizeof(int) * size);

for(int i = 0; i < size; i++)
    file>>vector[i];

radixSort(vector,size);

for(int i =0; i < size;i++)
    printf("[%d] %d\n",i,vector[i]);

free(vector);


return 0;
}