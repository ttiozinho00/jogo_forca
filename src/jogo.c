/*jogo.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/jogo.h"
#include "../include/interface.h"
#include "../include/palavras.h"
#include "../include/ranking.h"
#include "../include/configuracao.h"
#include "../include/conio_v3.2.4.h"
#include "../include/graphics_v1.1.h"

#define COR_ESTRUTURA RGB(139, 69, 19)
#define COR_CORPO RGB(255, 222, 173)
#define COR_CORDA RGB(218, 165, 32)

static Palavra palavraAtual;
static char chutes[MAX_CHUTES];
static int tentativas;
static int erros;
static int usouDica;

static int jaChutou(char letra) 
{
	int i;
	
    for (i = 0; i < tentativas; i++) 
	{
        if (chutes[i] == letra) return 1;
    }
    return 0;
}

static int letraExiste(char letra) 
{
    size_t i;
	for (i = 0; i < strlen(palavraAtual.palavra); i++)
	{
        if (palavraAtual.palavra[i] == letra) return 1;
    }
    return 0;
}

static int ganhou() 
{
    size_t i;
	for (i = 0; i < strlen(palavraAtual.palavra); i++) 
	{
        if (!jaChutou(palavraAtual.palavra[i])) return 0;
    }
    return 1;
}

static void renderizarForcaGrafica(int estagio) 
{
    int baseX = 520;
    int baseY = 280;

    linha(baseX, baseY, baseX + 100, baseY, COR_ESTRUTURA);
    linha(baseX + 30, baseY, baseX + 30, baseY - 180, COR_ESTRUTURA);
    linha(baseX + 30, baseY - 180, baseX + 80, baseY - 180, COR_ESTRUTURA);
    linha(baseX + 80, baseY - 180, baseX + 80, baseY - 160, COR_CORDA);

    if (estagio >= 1)
	{
		circulo(baseX + 80, baseY - 150, 10, COR_CORPO);
	}

	if (estagio >= 2)
	{
		linha(baseX + 80, baseY - 140, baseX + 80, baseY - 100, COR_CORPO);
	}

	if (estagio >= 3)
	{
		linha(baseX + 80, baseY - 130, baseX + 65, baseY - 115, COR_CORPO);
	}

	if (estagio >= 4)
	{
		linha(baseX + 80, baseY - 130, baseX + 95, baseY - 115, COR_CORPO);
	}

	if (estagio >= 5)
	{
		linha(baseX + 80, baseY - 100, baseX + 65, baseY - 70, COR_CORPO);
	}

	if (estagio >= 6)
	{
		linha(baseX + 80, baseY - 100, baseX + 95, baseY - 70, COR_CORPO);
	}
}

static void desenharForcaTela() 
{
    limparTela();
    int maxErrosPermitidos = obterMaxErros();
    
    textcolor(LIGHTCYAN);
    gotoxy(2, 2); printf("=== JOGO DA FORCA (%s) ===", obterNomeDificuldade());
    
    textcolor(WHITE);
    gotoxy(2, 4); printf("Categoria: ");
    textcolor(LIGHTMAGENTA); printf("%s", palavraAtual.categoria);
    
    textcolor(WHITE);
    gotoxy(2, 5); printf("Vidas restantes: ");
    textcolor(LIGHTRED); printf("%d", maxErrosPermitidos - erros);

    textcolor(YELLOW);
    gotoxy(2, 7); printf("Letras erradas: ");
    for (int i = 0; i < tentativas; i++) {
        if (!letraExiste(chutes[i])) 
		{
            printf("%c ", chutes[i]);
        }
    }

    gotoxy(2, 10);
    textcolor(WHITE);
	
    size_t i;
	for (i = 0; i < strlen(palavraAtual.palavra); i++) 
	{
        if (jaChutou(palavraAtual.palavra[i])) 
		{
            printf("%c ", palavraAtual.palavra[i]);
        } 
		
		else 
		{
            printf("_ ");
        }
    }
    
    if (usouDica) 
	{
        gotoxy(2, 13);
        textcolor(LIGHTBLUE);
        printf("Dica: %s", palavraAtual.dica);
    }

    int estagioForca = (erros * 6) / maxErrosPermitidos;
    if (estagioForca > 6) estagioForca = 6;
    
    renderizarForcaGrafica(estagioForca);
}

static void realizarChute() 
{
    gotoxy(2, 15);
    textcolor(WHITE);
    printf("Digite uma letra (ou [?] para Dica): ");
    
    char letra = getch(); 
    
    if (letra == '?') 
	{
        if (usouDica) 
		{
            gotoxy(2, 17); textcolor(YELLOW); printf("Voce ja usou a sua dica!");
            getch();
        } 
		
		else 
		{
            usouDica = 1;
        }
        return;
    }

    letra = toupper(letra);

    if (!isalpha(letra))
	{
		return;
	}

    if (jaChutou(letra)) 
	{
        gotoxy(2, 17); textcolor(YELLOW); printf("Letra '%c' ja testada!", letra);
        getch();
        return;
    }

    chutes[tentativas++] = letra;

    if (!letraExiste(letra)) 
	{
        erros++;
        printf("\a");
    }
}

void iniciarJogo() 
{
    tentativas = 0;
    erros = 0;
    usouDica = 0;
    memset(chutes, 0, sizeof(chutes));

    if (!sortearPalavra(&palavraAtual)) 
	{
        limparTela();
        textcolor(LIGHTRED);
        printf("Erro: Ficheiro 'palavras.txt' nao encontrado ou vazio!\n");
        getch();
        return;
    }

    time_t tempoInicio = time(NULL);
    int maxErrosPermitidos = obterMaxErros();

    while (erros < maxErrosPermitidos && !ganhou()) 
	{
        desenharForcaTela();
        realizarChute();
    }

    time_t tempoFim = time(NULL);
    int tempoTotal = (int)difftime(tempoFim, tempoInicio);

    desenharForcaTela();

    gotoxy(2, 17);
    if (ganhou()) 
	{
        printf("\a\a");
        textcolor(LIGHTGREEN);
        printf("PARABENS! VOCE VENCEU EM %d SEGUNDOS!", tempoTotal);
        atualizarEstatisticas(1, erros);
    } 
	
	else 
	{
        printf("\a");
        textcolor(LIGHTRED);
        printf("GAME OVER! A palavra era: ");
        textcolor(YELLOW); printf("%s", palavraAtual.palavra);
        atualizarEstatisticas(0, erros);
    }

    gotoxy(2, 19);
    textcolor(WHITE);
    printf("Pressione qualquer tecla para retornar ao menu...");
    getch();
}