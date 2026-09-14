/* palavras.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/palavras.h"

<<<<<<< HEAD
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
    
=======
#define ARQUIVO_PALAVRAS "./assets/palavras.txt"

int sortearPalavra(Palavra *p, const char dificuldadeEscolhida[])
{
    FILE *arquivo;
    int totalPalavras;
    int indiceSorteado;
    int contador;
    char linha[200];
    char linhaEscolhida[200];
    char *token;

    arquivo = fopen(ARQUIVO_PALAVRAS, "r");

    if (arquivo == NULL)
    {
        return 0;
    }

    totalPalavras = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        /* Remove o ENTER */
        linha[strcspn(linha, "\n")] = '\0';

        if (strlen(linha) > 2)
        {
          
            token = strtok(linha, ";");
            token = strtok(NULL, ";");
            token = strtok(NULL, ";");
            token = strtok(NULL, ";");

            if (token != NULL)
            {
                if (strcmp(token, dificuldadeEscolhida) == 0)
                {
                    totalPalavras++;
                }
            }
        }
    }

    if (totalPalavras == 0)
    {
        fclose(arquivo);
        return 0;
    }
    indiceSorteado = rand() % totalPalavras;
    rewind(arquivo);

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

            if (token != NULL)
            {
                if (strcmp(token, dificuldadeEscolhida) == 0)
                {
                    if (contador == indiceSorteado)
                    {
                        break;
                    }

                    contador++;
                }
            }
        }
    }

>>>>>>> d9386fc (atualizado)
    fclose(arquivo);

    /*
     * Agora 'linha' cont�m a palavra sorteada.
     *
     * Formato:
     * PALAVRA;CATEGORIA;DICA;DIFICULDADE
     */

    token = strtok(linha, ";");

    if (token != NULL)
    {
        strcpy(p->palavra, token);
    }

<<<<<<< HEAD
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
    
=======
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

>>>>>>> d9386fc (atualizado)
    if (token != NULL)
    {
        strcpy(p->dificuldade, token);
    }
<<<<<<< HEAD
    
=======

>>>>>>> d9386fc (atualizado)
    return 1;
}
