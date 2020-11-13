#ifndef QUERA_Q66862_H
#define QUERA_Q66862_H

#endif //QUERA_Q66862_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts a part of string to long long
 * Returns -1 if the number begins with 0 and it's length is more than 1
 * @param str The string to convert
 * @param begin The beginning index
 * @param end The last index
 * @return
 */
int str_to_int(const char *str, int begin, int end){
    if(str[begin] == '0' && (begin + 1 != end))
        return -1;
    int result = 0;
    for(; begin < end; begin++){
        result *= 10;
        result += str[begin] - '0';
    }
    return result;
}

int run(){
    char ip_string[20];
    memset(ip_string, 0, sizeof(ip_string));
    scanf("%s", ip_string);
    int ip_len = strlen(ip_string);
    /*
     * Try to add 4 dot. I don't know if there is any better way to do this
     * The second condition in for loops checks that the string length is always less than 4.
     * This is done to prevent integer overflows on big numbers and also increasing speed of program
     */
    for(int a = 1; (a < ip_len - 2) && a < 4; a++)
        for (int b = a + 1; (b < ip_len - 1) && b - a < 4; b++)
            for (int c = b + 1; (c < ip_len) && c - b < 4; c++){
                if(ip_len - c > 3)
                    continue;
                // try to parse the number
                int ip[] = {
                        str_to_int(ip_string, 0, a),
                        str_to_int(ip_string, a, b),
                        str_to_int(ip_string, b, c),
                        str_to_int(ip_string, c, ip_len)
                };
                // check all numbers
                bool ok = true;
                for(int i = 0; i < 4; i++){
                    if(ip[i] == -1 || ip[i] > 255 || ip[i] < 0)
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
            }
    return 0;
}