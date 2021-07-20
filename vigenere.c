#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main() {
    char message[9999];
    printf("\nEnter a message to encrypt: ");
    gets(message);

    char keyword[100];
    printf("\nEnter a keyword: ");
    scanf("%s", keyword);

    char** table = load_table();

    char *cyphertext = encrypt(message, keyword, table);

    printf("\nThis encrypted message is: ");
    for(int i = 0; i < strlen(message); i++) {
        printf("%c", cyphertext[i]);
    }

    free_aloc(cyphertext, table);

    return 0;
}