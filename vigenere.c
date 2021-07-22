#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main() {
    int num;
    printf("Choose: \n1. Encrypt 2. Decrypt: ");
    scanf("%d", &num);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    char** table = load_table();

    char message[9999];
    char keyword[100];

    char* cyphertext = NULL;


    switch(num) {
        case 1:
            printf("\nEnter a message to encrypt: ");
            fgets(message, 9999, stdin);

            printf("\nEnter a keyword: ");
            scanf("%s", keyword);

            cyphertext = encrypt(message, keyword, table);

            printf("\nThis encrypted message is: ");
            printf("%s", cyphertext);

            free_aloc(cyphertext, table);
            break;

        case 2:
            printf("\nEnter a message to decrypt: ");
            fgets(message, 9999, stdin);

            printf("\nEnter a keyword: ");
            scanf("%s", keyword);

            cyphertext = decrypt(message, keyword, table);

            printf("\nThis encrypted message is: ");
            printf("%s", cyphertext);

            free_aloc(cyphertext, table);

            break;

        default:
            printf("Invalid number!");
            break;
    }
    
        
    return 0;
}