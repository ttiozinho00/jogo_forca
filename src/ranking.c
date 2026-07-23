/*ranking.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ranking.h"
#include "../include/interface.h"
#include "../include/conio_v3.2.4.h"

#define ARQUIVO_RANKING "ranking.dat"

static char jogadorAtivo[30] = "Anonimo";

const char* obterJogadorAtual() {
    return jogadorAtivo;
}

void definirJogadorAtual() {
    limparTela();
    textcolor(LIGHTCYAN);
    gotoxy(5, 3); printf("=== IDENTIFICACAO DO JOGADOR ===");
    textcolor(WHITE);
    gotoxy(5, 5); printf("Digite o seu nickname (max 25 letras) e aperte ENTER: ");
    
    /*Scanf usado aqui apenas para capturar a string de texto completa do nome*/ 
    scanf(" %29s", jogadorAtivo);
    
    gotoxy(5, 7); textcolor(LIGHTGREEN);
    printf("Jogador '%s' configurado com sucesso!", jogadorAtivo);
    gotoxy(5, 9); textcolor(WHITE);
    printf("Pressione qualquer tecla para voltar ao menu...");
    getch();
}

void atualizarEstatisticas(int venceu, int erros) {
    FILE *arquivo = fopen(ARQUIVO_RANKING, "rb+");
    Jogador j;
    int encontrado = 0;
    int pontosDaRodada = venceu ? (100 - (erros * 15)) : 0;

    if (arquivo == NULL) 
	{
        arquivo = fopen(ARQUIVO_RANKING, "wb+");
        if (arquivo == NULL) return;
    }

    while (fread(&j, sizeof(Jogador), 1, arquivo)) 
	{
        if (strcmp(j.nome, jogadorAtivo) == 0) 
		{
            encontrado = 1;
            if (venceu) 
			{
                j.vitorias++;
                j.pontuacao += pontosDaRodada;
            }
			
			else 
			{
                j.derrotas++;
            }
            fseek(arquivo, -sizeof(Jogador), SEEK_CUR);
            fwrite(&j, sizeof(Jogador), 1, arquivo);
            break;
        }
    }

    if (!encontrado) 
	{
        strcpy(j.nome, jogadorAtivo);
        j.vitorias = venceu ? 1 : 0;
        j.derrotas = venceu ? 0 : 1;
        j.pontuacao = pontosDaRodada;
        fseek(arquivo, 0, SEEK_END);
        fwrite(&j, sizeof(Jogador), 1, arquivo);
    }
    fclose(arquivo);
}

void exibirRanking() 
{
	Jogador *lista = NULL;
    int total = 0,i,j;
    Jogador temp;
	
    limparTela();
    textcolor(LIGHTMAGENTA);
    gotoxy(5, 2); printf("====================================================");
    gotoxy(5, 3); printf("               RANKING GERAL DE JOGADORES           ");
    gotoxy(5, 4); printf("====================================================");

    FILE *arquivo = fopen(ARQUIVO_RANKING, "rb");
    if (arquivo == NULL) 
	{
        gotoxy(5, 6); textcolor(YELLOW);
        printf("Nenhum registo encontrado. Seja o primeiro a jogar!");
        gotoxy(5, 8); textcolor(WHITE);
        printf("Pressione qualquer tecla para voltar...");
        getch();
        return;
    }

    while (fread(&temp, sizeof(Jogador), 1, arquivo)) {
        total++;
        lista = realloc(lista, total * sizeof(Jogador));
        lista[total - 1] = temp;
    }
    fclose(arquivo);

    for ( i = 0; i < total - 1; i++) {
        for ( j = i + 1; j < total; j++) {
            if (lista[i].pontuacao < lista[j].pontuacao) {
                Jogador aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    gotoxy(5, 6); textcolor(WHITE);
    printf("%-4s %-20s %-10s %-10s %-10s", "Pos", "Jogador", "Pontos", "Vit.", "Der.");
    gotoxy(5, 7); printf("----------------------------------------------------");

    for ( i = 0; i < total; i++) {
        gotoxy(5, 8 + i);
        if (i == 0) textcolor(YELLOW);
        else if (i == 1) textcolor(WHITE);
        else if (i == 2) textcolor(LIGHTCYAN);
        else textcolor(LIGHTGRAY);
        
        printf("%-4d %-20s %-10d %-10d %-10d", i + 1, lista[i].nome, lista[i].pontuacao, lista[i].vitorias, lista[i].derrotas);
    }

    free(lista);
    gotoxy(5, 10 + total); textcolor(WHITE);
    printf("Pressione qualquer tecla para retornar...");
    getch();
}