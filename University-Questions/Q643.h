#ifndef QUERA_Q643_H
#define QUERA_Q643_H

#endif //QUERA_Q643_H

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

// kinda cheating :D
int main(){
    int* array = malloc(500 * 1000 * sizeof(int));
    int counter = 0;
    int temp;
    while (scanf("%d", &temp) != EOF){
        array[counter] = temp;
        counter++;
    }
    qsort(array, counter, sizeof(int), compare);
    for(int i = 0; i< counter;i++)
        printf("%d ", array[i]);
}