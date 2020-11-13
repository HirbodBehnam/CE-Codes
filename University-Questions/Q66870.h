#ifndef QUERA_Q66870_H
#define QUERA_Q66870_H

#endif //QUERA_Q66870_H

#include <stdio.h>
#include <stdlib.h>

#define NO 0
#define YES 1

// We store each distance in here
struct locales_distance{
    // a is always smaller than b
    short a;
    short b;
    // b - a
    short distance;
};

// compares two locales_distance structs
int compare (const void * a, const void * b)
{
    short d = (*(struct locales_distance*)a).distance - (*(struct locales_distance*)b).distance;
    if(d == 0) // if distances of both locals is same, the one that has the smaller a must come first
        return (*(struct locales_distance*)a).a - (*(struct locales_distance*)b).a;
    return d; // if distances are not equal just return d
}

int run(){
    int n;
    scanf("%d", &n);
    // I think it's ok to store both of these variables in stack. Max size of them are 180 + 24030 bytes which is not a lot
    short distances[n]; // store all input
    struct locales_distance l[n * (n - 1) / 2]; // here we store all structs which have at last C(n,2) elements
    // read all distances
    int counter = 0; // this variable is here for duplicates
    for(int i = 0; i < n; i++){
        short distance;
        scanf("%hd", &distance);
        // shitty way to check if distance has been a duplicate
        char good = YES; // if this variable is YES it means that the number is not an duplicate
        for(int j = 0; j < counter; j++) // instead of i there is counter (because of duplicate variables)
            if(distances[j] == distance)
            {
                good = NO; // the variable is not unique
                break;
            }
        if(good == YES) { // only add the number if it is not duplicate
            distances[counter] = distance;
            counter++;
        }
    }
    n = counter; // not always there are n elements in array (because of duplicated ones)
    // fill locales_distance
    counter = 0; // it's SUPER easier to work with a simple counter rather than using formulas to get the index
    for(int i = 0; i < n; i++) // simple nested for loop because why not?
        for(int j = i + 1; j < n; j ++)
        {
            l[counter].a = distances[i] < distances[j] ? distances[i] : distances[j]; // the smaller distance
            l[counter].b = distances[i] > distances[j] ? distances[i] : distances[j]; // the larger distance
            l[counter].distance = l[counter].b - l[counter].a; // this one is always positive
            counter++;
        }
    // sort the data
    qsort(l, counter, sizeof(struct locales_distance), compare);
    // print the results
    for(int i = 0; i < counter; i++)
        printf("[%d, %d]\n", l[i].a, l[i].b);
    return 0;
}