#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

char* encrypt(char* message, char* keyword, char** table);
char* decrypt(char* message, char* keyword, char** table);
char** load_table();
void free_aloc(char* cyphertext, char** table);

#endif