
#include <stdio.h>
#define MAXR 50
#define nero 1

void LeggiMatrice (FILE *fp_input, int M[][MAXR], int *nr, int *nc);
int RiconosciRegione (int M[][MAXR], int i, int j, int *b, int *h);

int main() {
    int M[MAXR][MAXR];
    int nr, nc, b, h;
    int i, j;
    FILE *fp_input;
    if ((fp_input=fopen("../mappa.txt", "r"))==NULL) {
        printf("Errore\n");
        return -1;
    }
    LeggiMatrice(fp_input, M, &nr, &nc);
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            if (RiconosciRegione(M, i, j, &b, &h)) {
                printf("Rettangolo con estremo in (%d,%d), base %d e altezza %d.\n", i, j, b, h);
            }
        }
    }
    return 0;
}

void LeggiMatrice (FILE *fp_input, int M[][MAXR], int *nr, int *nc) {
    int i, j;
    fscanf(fp_input,"%d %d", nr, nc);
    for (i=0; i<*nr; i++) {
        for (j=0; j<*nc; j++) {
            fscanf(fp_input, "%d", &M[i][j]);
        }
    }
}

int RiconosciRegione (int M[][MAXR], int i, int j, int *b, int *h) {
    int base, altezza;
    if (M[i][j]==nero && M[i-1][j]!=nero && M[i][j-1]!=nero) {
        base=1;
        altezza=1;
        while (M[i][j+base]==nero) {
            base++;
        }
        while (M[altezza+i][j]==nero) {
            altezza++;
        }
        *b=base;
        *h=altezza;
        return 1;
    }

    else{
        return 0;
}}