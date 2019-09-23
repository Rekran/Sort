int partition(long int* vector, int inicio, int fim){

long int pivo = vector [inicio];
long int aux;

int i = inicio - 1;
int j = fim + 1;

while(true){
    do{
        i++;
    }while(vector[i] <= pivo);
 
    do{
        j--;
    }while(vector[j] > pivo);
 
    if(i >= j)
        break;

    aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}

aux = vector[inicio];
vector[inicio] = vector[j];
vector[j] = aux ;

return j;

}

void QuickSort(long int* vector,int left , int right){


    if(left < right){

        int q = partition(vector , left, right);
        QuickSort(vector,left,q-1);
        QuickSort(vector,q+1,right);

    }
}