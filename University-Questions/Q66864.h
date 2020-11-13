#ifndef QUERA_Q66864_H
#define QUERA_Q66864_H

#endif //QUERA_Q66864_H

#include <stdio.h>

void run(){
    int k;
    scanf("%i", &k);
    if(k < 10) // one digit numbers
        ; // just return k
    else if(k < 190){ // two digit number
        k -= 10;
        if(k % 2 == 0) // request to get tenth of number
            k = (k / 20) + 1;
        else // request to get first of number
            k = ((k - 1) / 2) % 10;
    }else if(k < 2890){ // three digit numbers
        k -= 190;
        if(k % 3 == 0) // last digit
            k = (k / 300) + 1;
        else if(k % 3 == 1) // middle digit
            k = ((k - 1) / 30) % 10;
        else // first digit
            k = ((k - 2) / 3) % 10;
    }else{ // four digit; At this point got the pattern
        k -= 2890;
        if(k % 4 == 0)
            k = (k / 4000) + 1;
        else if(k % 4 == 1)
            k = ((k - 1) / 400) % 10;
        else if(k % 4 == 2)
            k = ((k - 2) / 40) % 10;
        else
            k = ((k - 3) / 4) % 10;
    }
    printf("%i", k);
}