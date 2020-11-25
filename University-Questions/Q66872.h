#ifndef QUERA_Q66872_H
#define QUERA_Q66872_H

#endif //QUERA_Q66872_H

#define MAX_MASHKOOK_LENGTH 1000
#define MAX_INPUT_LENGTH 10

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int count_substring(const char* input, const char *to_check){
    int input_length = strlen(input), to_check_len= strlen(to_check), counter = 0;
    for(int i = 0; i <= input_length - to_check_len; i++){
        bool ok = true;
        for(int j = 0; j < to_check_len; j++){
            if(input[i + j] != to_check[j])
            {
                ok = false;
                break;
            }
        }
        if(ok)
            counter++;
    }
    return counter;
}

int main(){
    int khobi = 0, commands = 0;
    char mashkook[MAX_MASHKOOK_LENGTH];
    memset(mashkook, 0, sizeof(mashkook));
    scanf("%s", mashkook);
    while (1){
        char input[MAX_INPUT_LENGTH];
        scanf("%s", input);
        if(strcmp(input, "copy") == 0){
            char key[MAX_MASHKOOK_LENGTH];
            int count;
            scanf("%s %d", key, &count);
            int counter = 0;
            for(; count > 0; count--){
                for(int i = 0; i < strlen(key); i++) {
                    mashkook[counter] = key[i];
                    counter++;
                }
            }
        }else if(strcmp(input, "compare") == 0){
            char mashkook2[MAX_MASHKOOK_LENGTH];
            scanf("%s", mashkook2);
            if(strcmp(mashkook2, mashkook) == 0)
                khobi++;
        }else if(strcmp(input, "substr") == 0){
            char key[MAX_MASHKOOK_LENGTH];
            int count;
            scanf("%s %d", key, &count);
            if(count_substring(mashkook, key) == count)
                khobi++;
        }else if(strcmp(input, "attach") == 0){
            char key[MAX_INPUT_LENGTH], str[MAX_INPUT_LENGTH];
            int count;
            scanf("%s %d %s", key, &count, str);
            strcat(key, str);
            if(count_substring(mashkook, key) == count)
                khobi++;
        }else if(strcmp(input, "length") == 0){
            int l;
            scanf("%d", &l);
            if(strlen(mashkook) == l)
                khobi++;
        }else if(strcmp(input, "Is") == 0){
            if(commands <= khobi * 2)
                printf("Eyval");
            else
                printf("HeifShod");
            return 0;
        }
        commands++;
    }
}