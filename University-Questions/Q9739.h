#ifndef QUERA_Q9739_H
#define QUERA_Q9739_H

#endif //QUERA_Q9739_H

#include <stdlib.h>
#include <stdio.h>

/**
 * I don't understand this algorithm at all :|
 * Code from https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 */

int main(){
    int n;
    scanf("%d", &n);
    int *height = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &height[i]);

    int max = 0;
    int *stack = malloc(n * sizeof(int));;
    int stack_size = 0;

    int i = 0;
    while (i < n){
        if(stack_size == 0 || height[stack[stack_size - 1]] <= height[i]){
            stack[stack_size] = i;
            stack_size++;
            i++;
        }else{
            int top = height[stack[stack_size - 1]];
            stack_size--;
            top *= (stack_size == 0 ? i : i - stack[stack_size - 1] - 1);
            if(max < top)
                max = top;

        }
    }

    while (stack_size > 0){
        int top = height[stack[stack_size - 1]];
        stack_size--;
        top *= (stack_size == 0 ? i : i - stack[stack_size - 1] - 1);
        if(max < top)
            max = top;
    }

    printf("%d", max);
    return 0;
}