#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c) {
  if (c == '\0') {
    return 0;
  }
  if (c == ' ' || c == '\t') {
    return 1;
  }
  return 0;
}

int non_space_char(char c) {
  if (c == '\0') {
    return 0;
  }
  if (c == ' ' || c == '\t') {
    return 0;
  }
  return 1;
}


char *token_start(char *str) {
    int i = 0;
    while(space_char(str[i]) == 1) {
        i++;
    }
    if (str[i] == '\0') {
        return '\0';
    }
    
    return &str[i];
}

char *token_terminator(char *token) {
    int i = 0;
    if (token == "") {
        return token;
    }
    
    while(non_space_char(token[i])) {
        i++;
    }
    if (token[i] == NULL) {
        return '\0';
    } 
    return &token[i];
}


/* Counts the number of tokens in the string argument.*/
int count_tokens(char *str) {
    int i = 0;
    int n = 0;
    while(str[i] != NULL) {
        if (space_char(str[i])) {
            n++;
        }
        i++;
    }
    return n;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
    char* result = (char*)malloc(len+1); // allocates memory 

    for (short i = 0; i < len; i++) {
        result[i] = inStr[i];
    }

    result[len] = '\0'; // adds the null-terminator
    return result;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {
    int n = count_tokens(str);
    char **tokens = (char **)malloc((n+1) * sizeof(char*));
    int c = 0;
    int tokenIndex = 0;
    const char* oldStr = NULL; // old string pointer;

    while (*str != NULL) {
        if (non_space_char(*str)) {
            oldStr = str;
            while (non_space_char(*str)) {
                c++;
                str++;
            }
            tokens[tokenIndex++] = copy_str(oldStr, c);
            str--;
        }
        c = 0;
        str++;
    }
    tokens[tokenIndex] = NULL;

    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("tokens[%d] = \"%s\"\n", i, tokens[i]);
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
