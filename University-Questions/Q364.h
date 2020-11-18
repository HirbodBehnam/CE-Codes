#ifndef QUERA_Q364_H
#define QUERA_Q364_H

#endif //QUERA_Q364_H

#define MAX_DEPTH 100

#include <stdio.h>
#include <string.h>

/**
 * Returns the max between a and b
 * @param a
 * @param b
 * @return The max between a and b
 */
int max(int a, int b) {
    return a > b ? a : b;
}

int run() {
    int t;
    scanf("%d", &t);
    for (; t > 0; t--) {
        int n;
        scanf("%d", &n);
        // read the tree
        int tree[MAX_DEPTH][MAX_DEPTH];
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                scanf("%d", &tree[i][j]);

        /**
         * From project euler thread 67:
         * It's easier to start from the bottom instead. For every pair, add the largest to the number above.
         * You'll get the largest sum at the top. :)
         *
         * What myself did in problem 67 was using graphs and dijkstra's algorithm to find the biggest path.
         * Code at https://gist.github.com/HirbodBehnam/2eade4ef6f15410d1186565f4719e0ec
         */

        for (int i = n - 1; i > 0; i--) // note that i must not be 0
            for (int j = 0; j < i; j++) // also j must not be i; because we cannot check column (i + 1)
                tree[i - 1][j] += max(tree[i][j], tree[i][j + 1]);

        // the first element is the max sum
        printf("%d\n", tree[0][0]);
    }
    return 0;
}
