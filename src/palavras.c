/*palavreas.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/palavras.h"

int sortearPalavra(Palavra *p) {
    FILE *arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) return 0;

    int totalPalavras = 0;
    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strlen(linha) > 2) totalPalavras++;
    }

    if (totalPalavras == 0) {
        fclose(arquivo);
        return 0;
    }

    srand(time(NULL));
    int indiceSorteado = rand() % totalPalavras;
    rewind(arquivo);

    for (int i = 0; i <= indiceSorteado; i++) {
        fgets(linha, sizeof(linha), arquivo);
    }
    fclose(arquivo);

    linha[strcspn(linha, "\n")] = 0;

    char *token = strtok(linha, ";");
    if (token != NULL) strcpy(p->palavra, token);
    
    token = strtok(NULL, ";");
    if (token != NULL) strcpy(p->categoria, token);
    
    token = strtok(NULL, ";");
    if (token != NULL) strcpy(p->dica, token);

    return 1;
}