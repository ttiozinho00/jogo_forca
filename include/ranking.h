#ifndef RANKING_H
#define RANKING_H

typedef struct {
    char nome[30];
    int vitorias;
    int derrotas;
    int pontuacao;
} Jogador;

void definirJogadorAtual();
void atualizarEstatisticas(int venceu, int erros);
void exibirRanking();
const char* obterJogadorAtual();

#endif