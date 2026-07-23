#ifndef PALAVRAS_H
#define PALAVRAS_H

typedef struct {
    char palavra[50];
    char categoria[50];
    char dica[100];
} Palavra;

int sortearPalavra(Palavra *p);

#endif