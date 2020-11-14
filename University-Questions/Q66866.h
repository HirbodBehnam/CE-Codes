#ifndef QUERA_Q66866_H
#define QUERA_Q66866_H

#endif //QUERA_Q66866_H

#define MAX_A 100000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    unsigned long long edges_count = 0;
    // create an array to store the occurrences of the numbers. The length of the array must be the max A + 1
    int *occurrences = malloc((MAX_A + 1) * sizeof(int)); // no need to free this. We need it until the very end
    memset(occurrences, 0, (MAX_A + 1) * sizeof(int));
    // read the input and calculate the occurrences
    for (; n > 0; n--) {
        int a;
        scanf("%d", &a);
        occurrences[a]++;
    }
    /**
     * Count the number of edges in graph. How?
     * Think that we have three vertexes that have the number of 1 on them. Also we have two vertexes have have number 2 on them
     * We should connect each of these vertexes together; This can be done with 3 * 2 = 6 edges.
     * So we just multiply a number in array with it's next element and add that number of edges to edges_count
     * note that i use MAX_A not MAX_A + 1. Because I don't want to check the last element
     */
    for (int i = 1; i < MAX_A; i++)
        edges_count += occurrences[i] * occurrences[i + 1];
    printf("%llu", edges_count);
}