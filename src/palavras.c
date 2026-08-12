/* palavras.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/palavras.h"

#define ARQUIVO_PALAVRAS "../assets/palavras.txt"

int sortearPalavra(Palavra *p)
{
    /* Declaração de todas as variáveis no início da função */
    FILE *arquivo;
    int totalPalavras;
    char linha[200];
    int indiceSorteado;
    int i;
    char *token;

    /* Início das instruções executáveis */
    arquivo = fopen(ARQUIVO_PALAVRAS, "r");
    
    if (arquivo == NULL)
    {
        return 0;
    }

    totalPalavras = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (strlen(linha) > 2) 
        {
            totalPalavras++;
        }
    }

    if (totalPalavras == 0)
    {
        fclose(arquivo);
        return 0;
    }

    srand(time(NULL));
    indiceSorteado = rand() % totalPalavras;
    rewind(arquivo);

    for (i = 0; i <= indiceSorteado; i++)
    {
        fgets(linha, sizeof(linha), arquivo);
    }
    
    fclose(arquivo);

    linha[strcspn(linha, "\n")] = 0;

    token = strtok(linha, ";");
    
    if (token != NULL) 
    {
        strcpy(p->palavra, token);
    }
    
    token = strtok(NULL, ";");
    
    if (token != NULL) 
    {
        strcpy(p->categoria, token);
    }
    
    token = strtok(NULL, ";");
    
    if (token != NULL) 
    {
        strcpy(p->dica, token);
    }
    
    token = strtok(NULL, ";");
    
    if (token != NULL)
    {
        strcpy(p->dificuldade, token);
    }
    
    return 1;
}
