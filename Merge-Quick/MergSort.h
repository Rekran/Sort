#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <fstream>
using namespace std;

int Merge(long int* v, int p, int q, int r) {

int i, j, k;

int n1 = q - p + 1;

int n2 = r - q;

long int* AuxLeft  = (long int*) malloc((n1 + 1) * sizeof(long int));
long int* AuxRight = (long int*) malloc((n2 + 1) * sizeof(long int));

    for (i=0; i<n1; i++)
        AuxLeft[i] = v[p + i];

    for (j=0; j<n2; j++)
        AuxRight[j] = v[q + 1 + j];
        
    AuxLeft[n1]  = LONG_MAX;

    AuxRight[n2] = LONG_MAX;

    i = 0; j = 0;

    for (k=p; k<=r; k++)
        if (AuxLeft[i] <= AuxRight[j]) {
            v[k] = AuxLeft[i];
            i += 1;
        }
        else {
            v[k] = AuxRight[j];
            j += 1;
        }

free(AuxLeft); 
free(AuxRight);

}
void mergeSort(long int *vetor, int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        Merge(vetor, comeco, meio, fim);
    }
}
