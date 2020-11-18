#ifndef QUERA_Q292_H
#define QUERA_Q292_H

#endif //QUERA_Q292_H

#include <stdio.h>

int main(){
    float max, min, sum;
    int n;
    scanf("%d %f", &n, &sum); // get the first number here
    min = max = sum;
    for(int i = 1; i < n; i++){
        float temp;
        scanf("%f", &temp);
        if(max < temp)
            max = temp;
        if(min > temp)
            min = temp;
        sum += temp;
    }
    printf("Max: %.3f\nMin: %.3f\nAvg: %.3f", max, min, sum / n);
    return 0;
}