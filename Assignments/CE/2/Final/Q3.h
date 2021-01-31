#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdio.h>
#include <stdlib.h>

/**
 * All years that have same mod 4 as this are leap years
 */
#define LEAP_YEAR_MOD (1399 % 4)

/**
 * Represents a date
 */
typedef struct d {
    int year;
    int month;
    int day;
} date;

/**
 * Returns 30 if the year is leap. Otherwise 29
 * @param year The year
 * @return 30 if the year is leap. Otherwise 29
 */
int esfand_is_leap(int year) {
    return year % 4 == LEAP_YEAR_MOD ? 30 : 29;
}

int main() {
    date start;
    int day_of_week, offset;
    scanf("%d-%d-%d", &start.year, &start.month, &start.day);
    scanf("%d", &day_of_week);
    scanf("%d", &offset);
    const int offset_backup = offset;
    // now for the hard part
    int days_in_months[] = {0, 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    date now = start;
    while (offset > 0) { // add to date
        offset--; // remove one from offset. we go one day forward
        // check leap year
        days_in_months[12] = esfand_is_leap(now.year);
        // add to day
        now.day++;
        // check month
        if (now.day > days_in_months[now.month]) {
            now.day = 1;
            now.month++;
        }
        // check year
        if (now.month > 12) {
            now.month = 1;
            now.year++;
        }
    }
    while (offset < 0) {
        offset++; // add one from offset. we go one day back
        // check leap year of year before
        days_in_months[12] = days_in_months[0] = esfand_is_leap(now.year - 1);
        // remove one day
        now.day--;
        // check end of month
        if (now.day == 0) {
            now.month--;
            now.day = days_in_months[now.month];
        }
        if (now.month == 0) {
            now.month = 12;
            now.year--;
        }
    }
    // print results
    printf("%d-%d-%d\n", now.year, now.month, now.day);
    printf("%d", (((offset_backup % 7 + 7) % 7) + day_of_week) % 7);
    return 0;
}