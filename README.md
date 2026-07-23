# Jogo da Forca

Um jogo da forca desenvolvido em **C**, executado em ambiente de console. O objetivo é descobrir a palavra secreta antes que o número máximo de tentativas seja atingido.

---

## Funcionalidades

- Escolha aleatória de palavras.
- Controle de tentativas.
- Exibição das letras descobertas.
- Validação de letras repetidas.
- Sistema de ranking.
- Configurações do jogo.
- Interface em modo texto.

---

## Tecnologias Utilizadas

- Linguagem C
- GCC
- MinGW 4.7.2
- Biblioteca GDI32 (Windows)

---

## Requisitos

- **Sistema Operacional:** Windows
- **Compilador:** MinGW GCC 4.7.2
- **Codificação do Console:** OEM 850 (CP850)
- Biblioteca **GDI32**

> **Importante:** Para que os caracteres acentuados sejam exibidos corretamente no console do Windows, utilize a codificação **OEM 850 (CP850)**.

---

## Estrutura do Projeto

```text
jogo-forca/
├── include/
│   └── *.h
├── src/
│   ├── configuracao.c
│   ├── interface.c
│   ├── jogo.c
│   ├── main.c
│   ├── palavras.c
│   ├── ranking.c
│   ├── conio_v3.2.4.c
│   ├── console_v1.5.5.c
│   └── graphics_v1.1.c
└── README.md
```

---

## Compilação

Compile o projeto utilizando o comando abaixo:

```bash
gcc -Wall -pedantic -Wextra -Werror -I./include \
src/configuracao.c \
src/interface.c \
src/jogo.c \
src/main.c \
src/palavras.c \
src/ranking.c \
src/conio_v3.2.4.c \
src/console_v1.5.5.c \
src/graphics_v1.1.c \
-o main -lgdi32
```

---

## Execução

Após a compilação, execute:

```bash
main.exe
```

Caso o console não esteja utilizando a codificação OEM 850, execute antes:

```cmd
chcp 850
main.exe
```

---

## Como Jogar

1. Execute o programa.
2. Digite uma letra por vez para tentar descobrir a palavra secreta.
3. Cada erro reduz o número de tentativas disponíveis.
4. Vença descobrindo toda a palavra antes de esgotar as tentativas.

---

## Autor

Desenvolvido por **Douglas**.

---

## Licença

Este projeto foi desenvolvido para fins acadêmicos e de aprendizado.
