#ifndef QUERA_Q602_H
#define QUERA_Q602_H

#endif //QUERA_Q602_H

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/**
 * |a|
 * @param x
 * @return
 */
double dabs(double x){
    return x > 0 ? x : -x;
}

/**
 * y = x - floor(x)
 * @param x
 * @param y
 * @return
 */
double f1(double x, double y){
    return dabs(y - (x - floor(x)));
}

/**
 * y = x^2 + x
 * @param x
 * @param y
 * @return
 */
double f2(double x, double y){
    return dabs(y -(x * x + x));
}

/**
 * y = ∣−x^3 + 1∣ + x^3
 * @param x
 * @param y
 * @return
 */
double f3(double x, double y){
    return dabs(y - (dabs(-x*x*x + 1) + x*x*x));
}

// look; I know this stuff are fucked up. But the question is bullshit too :|
int main(){
    int n;
    bool ok[] = {true, true, true};
    scanf("%d", &n);
    for(; n > 0; n--){
        double x, y;
        scanf("%lf %lf", &x, &y);
        if(f1(x, y) > 0.2)
            ok[0] = false;
        if(f2(x, y) > 0.2)
            ok[1] = false;
        if(f3(x, y) > 0.2)
            ok[2] = false;
    }
    for(int i = 0; i < 3; i ++)
        if(ok[i])
            printf("%d\n", i + 1);
    if(!ok[0] && !ok[1] && !ok[2])
        printf("No ones");
    return 0;
}