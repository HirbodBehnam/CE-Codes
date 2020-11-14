#ifndef QUERA_Q596_H
#define QUERA_Q596_H

#endif //QUERA_Q596_H

#include <stdio.h>

int main(){
    // lookup tables because why not. Max input is 10^5
    const int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025};
    int n;
    scanf("%d", &n);
    // simple search
    while (n > 0) {
        for (int i = 0; ; i++){
            if(n < fib[i]){
                n -= fib[i - 1];
                printf("%d ", i);
                break;
            }
        }
    }

}