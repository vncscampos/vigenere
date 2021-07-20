#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "function.h"

char* encrypt(char* message, char* keyword, char** table) {
    int message_size = strlen(message);
    int keyword_size = strlen(keyword);


    for(int i = 0; i < message_size; i++) {
        message[i] = toupper(message[i]);
    }

    for(int i = 0; i < keyword_size; i++) {
        keyword[i] = toupper(keyword[i]);
    }

    char* cyphertext = (char*)malloc(message_size*sizeof(char));
    int count = 0;

    for(int i = 0; i < message_size; i++) {

        int line, column;

        if(count >= keyword_size) {
            count = 0;
        }

        char ch1 = message[i];
        
        if(ch1 != ' ') {
            for(int j = 1; j < 27; j++) {
                if(ch1 == table[0][j]) {
                    column = j;
                }
            }

            char ch2 = keyword[count];

            for(int j = 1; j < 27; j++) {
                if(ch2 == table[j][0]) {
                    line = j;
                }
            }
            cyphertext[i] = table[line][column];
            count++;
        } else {
            cyphertext[i] = ' ';
        }
    }

    return cyphertext;
}

char** load_table() {
    FILE *file;
    file = fopen("table.txt", "r");

    if(file == NULL) {

        printf("Failed to read file!");
        exit(1);

    } else {

        int line = 27;
        int column = 27;

        char** table = (char**)malloc(27 * sizeof(char*));
        char c;

        for(int i = 0; i < 27; i++) {
            table[i] = (char*)malloc(27 * sizeof(char));

            int j = 0;
            while((c = fgetc(file)) != EOF && c != '\n') {
                table[i][j] = c;
                j++;
            }
        }

        fclose(file);

        return table;
    }
}

void free_aloc(char* cyphertext, char** table) {
    free(cyphertext);
    free(table);
    cyphertext = NULL;
    table = NULL;
}