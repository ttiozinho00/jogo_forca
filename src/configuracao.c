/*configuracao.c*/
#include <stdio.h>
#include "../include/configuracao.h"
#include "../include/interface.h"
#include "../include/conio_v3.2.4.h"

static Dificuldade dificuldadeAtual = DIFICULDADE_MEDIO;

void ajustarDificuldade() {
    char opcao;
    limparTela();
    
    textcolor(WHITE);
    gotoxy(5, 3); printf("=== CONFIGURACAO DE DIFICULDADE ===");
    gotoxy(5, 5); printf(" Dificuldade Atual: ");
    textcolor(YELLOW); printf("%s", obterNomeDificuldade());
    
    textcolor(WHITE);
    gotoxy(5, 7);  printf("[1] Facil   (8 Vidas)");
    gotoxy(5, 8);  printf("[2] Medio   (6 Vidas)");
    gotoxy(5, 9);  printf("[3] Dificil (4 Vidas)");
    gotoxy(5, 11); printf("Escolha uma opcao clicando na tecla... ");

    opcao = getch();

    switch (opcao) {
        case '1': dificuldadeAtual = DIFICULDADE_FACIL; break;
        case '2': dificuldadeAtual = DIFICULDADE_MEDIO; break;
        case '3': dificuldadeAtual = DIFICULDADE_DIFICIL; break;
        default:
            gotoxy(5, 13); textcolor(LIGHTRED);
            printf("Opcao invalida! Mantendo configuracao anterior.");
            getch();
            return;
    }

    gotoxy(5, 13); textcolor(LIGHTGREEN);
    printf("Dificuldade alterada para '%s' com sucesso!", obterNomeDificuldade());
    gotoxy(5, 15); textcolor(WHITE);
    printf("Pressione qualquer tecla para voltar...");
    getch();
}

int obterMaxErros() {
    if (dificuldadeAtual == DIFICULDADE_FACIL){ 
		return 8;
	}	
	
    if (dificuldadeAtual == DIFICULDADE_DIFICIL) 
	{
		return 4;
	}
    return 6;
}

const char* obterNomeDificuldade() {
    if (dificuldadeAtual == DIFICULDADE_FACIL)
	{
		return "Facil";
	}
    if (dificuldadeAtual == DIFICULDADE_DIFICIL) 
	{
		return "Dificil";
	}
    return "Medio";
}