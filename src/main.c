#include <stdio.h>
#include <stdlib.h>
#include "../include/interface.h"
#include "../include/jogo.h"
#include "../include/ranking.h"
#include "../include/configuracao.h"
#include "../include/conio_v3.2.4.h"

int main() {
    int rodando = 1;
    char escolha;

    while (rodando) {
        desenharLogo();
        
        gotoxy(5, 9);  printf("Jogador Atual: ");
        textcolor(YELLOW); printf("%s", obterJogadorAtual());
        textcolor(WHITE); printf(" | Dificuldade: ");
        textcolor(YELLOW); printf("%s", obterNomeDificuldade());
        
        textcolor(WHITE);
        gotoxy(5, 10); printf("--------------------------------------------------------");
        
        gotoxy(7, 12); printf("[1] "); textcolor(LIGHTGREEN);  printf("Iniciar Novo Jogo");
        textcolor(WHITE);
        gotoxy(7, 13); printf("[2] "); textcolor(LIGHTBLUE);   printf("Alterar Nickname do Jogador");
        textcolor(WHITE);
        gotoxy(7, 14); printf("[3] "); textcolor(LIGHTMAGENTA);printf("Visualizar Tabela de Ranking");
        textcolor(WHITE);
        gotoxy(7, 15); printf("[4] "); textcolor(WHITE);       printf("Configurar Nivel de Dificuldade");
        gotoxy(7, 16); printf("[0] "); textcolor(LIGHTRED);    printf("Sair do Jogo");
        
        textcolor(WHITE);
        gotoxy(5, 18); printf("Escolha uma opcao clicando na tecla correspondente... ");
        
        escolha = getch(); 

        switch (escolha) {
            case '1':
                iniciarJogo();
                break;
            case '2':
                definirJogadorAtual();
                break;
            case '3':
                exibirRanking();
                break;
            case '4':
                ajustarDificuldade();
                break;
            case '0':
                limparTela();
                textcolor(LIGHTRED);
                gotoxy(5, 5); printf("Saindo do jogo... Obrigado por jogar!\n\n");
                textcolor(WHITE);
                rodando = 0;
                break;
            default:
                gotoxy(5, 20); textcolor(LIGHTRED);
                printf("Opcao invalida! Escolha um numero de 0 a 4.");
                getch();
                break;
        }
    }

    return 0;
}