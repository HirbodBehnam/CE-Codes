#ifndef QUERA_Q72632_H
#define QUERA_Q72632_H

#endif //QUERA_Q72632_H

#include <stdio.h>

int main(){
    int ricks; // number of sub-questions
    scanf("%d", &ricks);
    for(; ricks > 0; ricks--){
        // number of teleporters and morty's position
        int teleporters, morty;
        scanf("%d %d", &teleporters, &morty);
        int range_max = 0; // max distance we can go
        for(; teleporters > 0; teleporters--){
            int beginning_position, end_position;
            scanf("%d %d", &beginning_position, &end_position);
            // check if the beginning of teleporter is in range (this means that we can travel to it somehow),
            // if so, check if the end_position of teleporter is more than max reachable range, if so update it
            if(beginning_position <= range_max && end_position > range_max)
                range_max = end_position;
        }
        // of morty is in reachable range, print YES
        printf(morty <= range_max ? "YES\n" : "NO\n");
    }
    return 0;
}