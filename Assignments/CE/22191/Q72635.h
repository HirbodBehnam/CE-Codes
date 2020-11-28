#ifndef QUERA_Q72635_H
#define QUERA_Q72635_H

#endif //QUERA_Q72635_H
#define UNKNOWN 0
#define UP_HILL 1
#define DOWN_HILL 2

#include <stdio.h>

// I used same thing as Q66865 from university questions

int main() {
    int t;
    scanf("%d", &t);
    for(; t > 0; t--) {
        int n, elevation, last_elevation, hill_status = UNKNOWN;
        char good = 1, reached_elevated_point = 0;
        scanf("%d", &n);
        scanf("%d", &elevation);
        n--; // we have already read 1 var
        for (; n > 0; n--) {
            last_elevation = elevation;
            scanf("%d", &elevation);
            if(good == 0)
                continue;
            // try to detect hill status. We can't get any info if the values are equal
            if (hill_status == UNKNOWN) {
                if (last_elevation > elevation)
                    hill_status = DOWN_HILL;
                else if (last_elevation < elevation)
                    hill_status = UP_HILL;
            }
            // if the elevated point is not reached the numbers can also be equal
            if (reached_elevated_point == 0) {
                if ((hill_status == UP_HILL && last_elevation > elevation) ||
                    (hill_status == DOWN_HILL && elevation > last_elevation))
                    reached_elevated_point = 1;
            } else { // numbers must not be equal. Also the elevation status must be switched here
                if ((hill_status == UP_HILL && elevation > last_elevation) ||
                    (hill_status == DOWN_HILL && last_elevation > elevation)) {
                    good = 0;
                }
            }
        }
        printf(good == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}