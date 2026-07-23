#include <stdio.h>
#include "../include/interface.h"
#include "../include/conio_v3.2.4.h"

void limparTela() {
    clrscr();
}

void desenharLogo() {
    limparTela();
    textcolor(LIGHTCYAN);
    gotoxy(5, 2); printf("========================================================");
    gotoxy(5, 3); printf("   _   _   _   _   _   _   _     _   _   _   _   _  ");
    gotoxy(5, 4); printf("  / \\ / \\ / \\ / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ ");
    gotoxy(5, 5); printf(" ( J | O | G | O |   | D | A ) ( F | O | R | C | A )");
    gotoxy(5, 6); printf("  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ ");
    gotoxy(5, 7); printf("========================================================");
    textcolor(WHITE);
}