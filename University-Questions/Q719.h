#ifndef QUERA_Q719_H
#define QUERA_Q719_H

#endif //QUERA_Q719_H

#include <stdio.h>
#include <stdlib.h>

// From https://cs.stackexchange.com/a/104309

struct Point {
    int x, y;
};

int main(){
    int n;
    scanf("%d", &n);
    /**
     * 1: max(x+y)
     * 2: max(x-y)
     * 3: min(x+y)
     * 4: min(x-y)
     */
    struct Point points[4];
    scanf("%d %d", &points[0].x, &points[0].y);
    points[3] = points[2] = points[1] = points[0];
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        // max(x+y)
        if(points[0].x + points[0].y < x + y)
        {
            points[0].x = x;
            points[0].y = y;
        }
        // max(x-y)
        if(points[1].x - points[1].y < x - y)
        {
            points[1].x = x;
            points[1].y = y;
        }
        // min(x+y)
        if(points[2].x + points[2].y > x + y)
        {
            points[2].x = x;
            points[2].y = y;
        }
        // min(x-y)
        if(points[3].x - points[3].y > x - y)
        {
            points[3].x = x;
            points[3].y = y;
        }
    }
    // find the biggest distance
    int max_distance = 0;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++) {
            int distance = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
            if (distance > max_distance)
                max_distance = distance;
        }
    printf("%d", max_distance);
    return 0;
}