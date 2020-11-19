#ifndef QUERA_Q294_H
#define QUERA_Q294_H

#endif //QUERA_Q294_H

#include <math.h>
#include <stdio.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a != 0){
        double delta = b * b - 4 * a * c;
        if(delta < 0){
            printf("IMPOSSIBLE");
        }else if (delta == 0){
            double res = (-b)/ (2 * a);
            if(res == 0) // in test 7 fix -0.000
                printf("0.000");
            else
                printf("%.3f", res);
        }else{
            delta = sqrt(delta);
            double a1 = (-b + delta)/ (2 * a), a2 = (-b - delta)/ (2 * a);
            printf("%.3f\n%.3f", a1 > a2 ? a2 : a1, a1 < a2 ? a2 : a1);
        }
    } else if(b != 0){
        printf("%.3f", -c / b);
    }else{
        printf("IMPOSSIBLE");
    }
}