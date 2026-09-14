#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

typedef enum {
    DIFICULDADE_FACIL,
    DIFICULDADE_MEDIO,
    DIFICULDADE_DIFICIL
} Dificuldade;

void ajustarDificuldade(void);
int obterMaxErros(void);
const char *obterNomeDificuldade(void);

#endif