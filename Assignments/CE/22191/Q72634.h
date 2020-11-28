#ifndef QUERA_Q72634_H
#define QUERA_Q72634_H

#endif //QUERA_Q72634_H

#include <stdio.h>

int main(){
    int str_len, sub_str_len;
    scanf("%d %d", &str_len, &sub_str_len);
    /**
     * So how do we store these chars without array? By using Bitarray!
     * Well, not really "bit"array; Each 4bits represent a char which a is 0
     * The max char is i which will be converted to 8 which is 1000 in binary.
     * There is also no need for null terminators, because we know how long the string is (str_len)
     */
    unsigned long long string = 0, sub_string = 0;
    // Read main string
    for(unsigned int i = 0; i < str_len; i++){
        unsigned char c;
        scanf("%c", &c);
        if(c == '\n')
        {
            i--;
            continue;
        }
        string |= (unsigned long long)(c - 'a') << (unsigned long long)(i * 4);
    }
    // Read substring to check
    for(unsigned int i = 0; i < sub_str_len; i++){
        unsigned char c;
        scanf("%c", &c);
        if(c == '\n')
        {
            i--;
            continue;
        }
        sub_string |= (unsigned long long)(c - 'a') << (unsigned long long)(i * 4);
    }
    // Check until str_len - sub_str_len
    for(unsigned int i = 0; i <= str_len - sub_str_len;i++){
        char ok = 1; // 1 is true; I'm not using bool or #define in order to satisfy this question's requirements
        for(unsigned int j = 0; j < sub_str_len; j++){
            // Get the first 4 bits of both strings after bit shifting
            if(((string >> (unsigned long long)((i + j) * 4)) & 0xfULL) != ((sub_string >> (unsigned long long)(j * 4)) & 0xfULL)){
                ok = 0;
                break;
            }
        }
        if(ok){
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}