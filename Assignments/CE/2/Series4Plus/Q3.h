#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#define MAX 20

#include <stdio.h>

int main() {
    int a[MAX], b[MAX], a_size = 0, b_size = 0, target;
    // read first coins
    do {
        scanf("%d", &a[a_size]);
        a_size++;
    } while (getchar() != '\n');
    // read second coins
    do {
        scanf("%d", &b[b_size]);
        b_size++;
    } while (getchar() != '\n');
    // read the target
    scanf("%d", &target);
    // bruteforce
    for(int i = 0; i < a_size; i++)
        for(int j = 0; j < b_size; j++)
            if(a[i] + b[j] == target){
                printf("Yes");
                return 0;
            }

    printf("No");
    return 0;
}