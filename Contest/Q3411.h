#include <stdio.h>

int main()
{
    unsigned long long number = 1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int iCopy = i;
        while (iCopy % 10 == 0) {
            iCopy /= 10;
        }
        number *= iCopy;
        while (number % 10 == 0) {
            number /= 10;
        }
        number %= 1000000000ull;
    }
    printf("%llu", number % 10);

    return 0;
}
