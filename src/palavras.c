/* palavras.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/palavras.h"

/* Verifica o caminho correto de acordo com a pasta onde o executável é gerado (build) */
#define ARQUIVO_PALAVRAS "../assets/palavras.txt"

int sortearPalavra(Palavra *p, const char dificuldadeEscolhida[])
{
    FILE *arquivo;
    int totalPalavras = 0;
    int indiceSorteado, contador;
    char linha[200];
    char linhaEscolhida[200];
    char *token;

    arquivo = fopen(ARQUIVO_PALAVRAS, "r");

    if (arquivo == NULL)
    {
        return 0;
    }

    /* Primeira passagem: Conta quantas palavras existem com a dificuldade escolhida */
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0'; /* Remove o ENTER */

        if (strlen(linha) > 2)
        {
            /* Usamos linhaEscolhida para preservar a string original */
            strcpy(linhaEscolhida, linha);
            token = strtok(linhaEscolhida, ";");
            token = strtok(NULL, ";");
            token = strtok(NULL, ";");
            token = strtok(NULL, ";"); /* 4º token é a Dificuldade */

            if (token != NULL && strcmp(token, dificuldadeEscolhida) == 0)
            {
                totalPalavras++;
            }
        }
    }

    if (totalPalavras == 0)
    {
        fclose(arquivo);
        return 0;
    }

    /* Sorteia o índice com base apenas nas palavras válidas */
    indiceSorteado = rand() % totalPalavras;
    rewind(arquivo);

    /* Segunda passagem: Percorre até encontrar a palavra sorteada */
    contador = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';

        if (strlen(linha) > 2)
        {
            strcpy(linhaEscolhida, linha);
            token = strtok(linhaEscolhida, ";");
            token = strtok(NULL, ";");
            token = strtok(NULL, ";");
            token = strtok(NULL, ";");

            if (token != NULL && strcmp(token, dificuldadeEscolhida) == 0)
            {
                if (contador == indiceSorteado)
                {
                    break; /* Encontramos a linha certa, ela fica guardada na variável 'linha' */
                }
                contador++;
            }
        }
    }

    fclose(arquivo);

    /*
     * Formato: PALAVRA;CATEGORIA;DICA;DIFICULDADE
     * Agora extraímos os dados finais da 'linha' intacta para a struct
     */
    token = strtok(linha, ";");
    if (token != NULL) strcpy(p->palavra, token);

    token = strtok(NULL, ";");
    if (token != NULL) strcpy(p->categoria, token);

    token = strtok(NULL, ";");
    if (token != NULL) strcpy(p->dica, token);

    token = strtok(NULL, ";");
    if (token != NULL) strcpy(p->dificuldade, token);

    return 1;
}
