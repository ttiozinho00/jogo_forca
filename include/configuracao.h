#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

typedef enum {
    DIFICULDADE_FACIL,
    DIFICULDADE_MEDIO,
    DIFICULDADE_DIFICIL
} Dificuldade;

void ajustarDificuldade();
int obterMaxErros();
const char* obterNomeDificuldade();

#endif