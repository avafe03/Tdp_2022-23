#include <stdio.h>

void comprimi(FILE *fp_read, FILE *fp_write);
void decomprimi(FILE *fp_read, FILE *fp_write);

int main() {
    FILE *fp_read, *fp_write;
    char scelta;

    fp_read= fopen("../sorgente.txt", "r");
    fp_write=fopen("../compresso.txt", "w");

    if( fp_read==NULL && fp_write==NULL) {
        printf("Si e’ verificato un errore in apertura del file\n");
        return 1;
    }
    else {
        printf("Scegliere se:\n-Comprimere il file (C)\n-Decomprimere il file(D)\n");
        scanf_s("%c", &scelta);

        while (scelta != 'C' && scelta != 'D') {
            printf("ERRORE\nScegliere se:\n-Comprimere il file (C)\n-Decomprimere il file(D)\n");
            scanf_s(" %c", &scelta);
        }
        switch (scelta) {
            case 'C':
                comprimi(fp_read, fp_write);
                break;
            case 'D':
                decomprimi(fp_read, fp_write);
                break;
            default:
                return 2;
        }
    }

    fclose(fp_read);
    fclose(fp_write);
    return 0;
}

void comprimi(FILE *fp_read, FILE *fp_write){
    char c1,c2,c3,c4;
    int contatore=2; //Contatore di ripetizioni
    fscanf(fp_read,"%c%c",&c1,&c2);
    while(!feof(fp_read)) { // analisi file carattere per carattere fino alla fine
        fscanf(fp_read,"%c",&c3);
        fprintf(fp_write,"%c",c1);

        //se i tre caratteri presi in esame sono identici valuto attraverso l'utilizzo di un ciclo while
        //se ci sono più di 2 ripetizioni consecutive dello stesso carattere, le conto e le salvo nella variabile
        // contatore

        if(c1==c2 && c1==c3){
            fscanf(fp_read,"%c",&c4);
            while (c4==c3 && contatore<9){
                contatore=contatore+1;
                fscanf(fp_read,"%c",&c4);
            }
            fprintf(fp_write,"$%d",contatore);
            contatore=2;
            c1=c4;
            fscanf(fp_read,"%c",&c2);
        }
        //se i tre caratteri non sono identici proseguo con l'analisi cambiando prendendo i caratteri successiivi a
        // quelli già presi in esame

        else{
            c1=c2;
            c2=c3;
        }}}


void decomprimi(FILE *fp_read, FILE *fp_write){
    char c1,c2,c3;
    int contatore;

    fscanf(fp_read,"%c%c",&c1,&c2);
    while(!feof(fp_read)) {
        fprintf(fp_write, "%c", c1);
        fscanf(fp_read,"%c",&c3);
        if (c2=='$') {
            //se c2 è uguale a $ significa che ci sono delle ripetizioni del carattere c1 e che il carattere c3
            //indica il numero di ripetizioni. Tale dato per essere utilizzato necessita di essere convertito
            //da char a int.
            contatore=c3-'0';
            while (contatore!=0){
                fprintf(fp_write, "%c", c1);
                contatore=contatore-1;
            }
            fscanf(fp_read, "%c%c", &c1, &c2);

        }
        else {
            c1=c2;
            c2=c3;
        }
    }
}