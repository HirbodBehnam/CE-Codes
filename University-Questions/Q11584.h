#ifndef QUERA_Q11584_H
#define QUERA_Q11584_H

#endif //QUERA_Q11584_H

#include <stdio.h>

int main() {
    int q, n;
    scanf("%d %d", &n, &q);
    // Surely I can just use n instead of n+1 but the code in 100 times simpler to read now. Also now I use a bit less computing power
    unsigned int input[n + 1];
    // read the input array
    for (int i = 0; i < n; i++)
        scanf("%u", &input[i + 1]);

    // pre-calculate; generate the lookup table
    unsigned long long answers[n + 1];
    for (unsigned int i = 1; i <= n; i++) {
        long long sum = 0;
        for (unsigned int j = 1; j <= i; j++)
            sum += input[j] ^ (i - j);
        answers[i] = sum;
    }
    // get questions
    for (; q > 0; q--) {
        int question;
        scanf("%d", &question);
        printf("%lld\n", answers[question]);
    }
    return 0;
}