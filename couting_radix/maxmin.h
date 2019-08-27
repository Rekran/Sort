int getMax(int* vector, int size){ 
    int max = vector[0];
    
    for(int i = 1; i < size;i++){
        if (max < vector[i])
            max = vector[i];
    }
    return max;
}

int getMin(int* vector, int size){ 
    int min = vector[0];
    
    for(int i = 1; i < size;i++){
        if (min > vector[i])
            min = vector[i];
    }
    return min;
}
