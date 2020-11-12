#ifndef QUERA_Q66865_H
#define QUERA_Q66865_H

#endif //QUERA_Q66865_H

#define UNKNOWN 0
#define UP_HILL 1
#define DOWN_HILL 2

#include <stdio.h>
#include <stdbool.h>

int run()
{
    int n, elevation, last_elevation, hill_status = UNKNOWN;
    bool reached_elevated_point = false;
    scanf("%d", &n);
    scanf("%d", &elevation);
    n--; // we have already read 1 var
    for(;n > 0; n--){
        last_elevation = elevation;
        scanf("%d", &elevation);
        // try to detect hill status. We can't get any info if the values are equal
        if(hill_status == UNKNOWN){
            if(last_elevation > elevation)
                hill_status = DOWN_HILL;
            else if(last_elevation < elevation)
                hill_status = UP_HILL;
        }
        // if the elevated point is not reached the numbers can also be equal
        if(!reached_elevated_point){
            if((hill_status == UP_HILL && last_elevation > elevation) || (hill_status == DOWN_HILL && elevation > last_elevation))
                reached_elevated_point = true;
        }else{ // numbers must not be equal. Also the elevation status must be switched here
            if((hill_status == UP_HILL && elevation >= last_elevation) || (hill_status == DOWN_HILL && last_elevation >= elevation)){
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}