//
// Created by Daniel on 23/9/2020.
//

#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


char ** map( char** words, int size, char* (function)(char*,int)){
    char **map = malloc(size);

    for(int i = 0; i< size; i++){
        int wordSize = strlen(words[i]);
        map[i] = malloc(wordSize);
        map[i] = function(words[i],wordSize);

    }
    return map;
}

char* low(char* word,int size){
    char *newWord = malloc(size * sizeof(char));
    for(int i = 0; i < size;i++){
        newWord[i] = tolower(word[i]);
    }
    return newWord;
}


char* up(char* word,int size){
    char* newWord = (char*) malloc(size * sizeof(char));
    for(int i = 0; i < size;i++){
        char letter = word[i];
        newWord[i] =(char) toupper(letter);
    }
    return newWord;
}
