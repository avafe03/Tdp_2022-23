#include <stdio.h>
#include <ctype.h>
#define filein "../input.txt"
int main(){
    FILE *fp_read, *fp_write;
    char c0,c1;
    int char_max, char_originali=0;
    fp_read= fopen(filein, "r");
    fp_write= fopen("../output.txt", "w");


    if (fp_read==NULL && fp_write==NULL) {
        printf("Errore nell'apertura dei file");
    }

    else {
        fscanf(fp_read, "%c%c", &c0,&c1);
        while(!feof(fp_read)){
            char_max=25;
            while (char_max>0){
                if (isdigit(c0)) { //se c0 è un numero stampo al suo posto un '*'
                    fprintf(fp_write, "*");
                    char_max--;
                    c0 = c1;
                    fscanf(fp_read, "%c", &c1);
                    char_originali++;
                }
                //se c0 è un segno di punteggiatura e non è seguito da '\n' o da ' '
                else if ((c0=='.' || c0=='(' || c0=='\'' || c0==',' || c0=='!' || c0=='?' || c0==';' || c0==':') && (c1!=' ' && c1!='\n')) {
                    fprintf(fp_write, "%c", c0); //scrivo c0 sul file in output
                    char_max--;
                    if (c0 == '.' || c0 == '?' || c0 == '!') { //se c0 è '.' o '?' o'!' rendo c1 maiuscolo
                        c1 = toupper(c1);
                    }
                    //se c0 non corrisponde al 25esimo carattere della riga del nuovo file posso aggiungere
                    // lo spazio che separa c0 da c1 sulla stessa riga
                    if (char_max > 0) {
                        fprintf(fp_write, " ");
                        char_max--;
                        c0 = c1;
                        fscanf(fp_read, "%c", &c1);
                        char_originali++;
                    } else { //altrimenti lo metterò nella riga successiva
                        c0 = ' ';

                    }
                }
                //se c0 è '.' o '?' o '!' ed è seguito da '\n' o da ' ' rendo il carattere successivo maiuscolo
                else if ((c0=='.' || c0=='!' || c0=='?') && (c1==' ' || c1=='\n')){
                    fprintf(fp_write,"%c",c0);
                    char_max--;
                    c0 = c1;
                    fscanf(fp_read, "%c", &c1);
                    c1 = toupper(c1);
                    char_originali++;

                }
                else if (c0=='\n') {
                    while (char_max>0) {
                        fprintf(fp_write, " ");
                        char_max = char_max - 1;
                    }
                    c0= c1;
                    fscanf(fp_read, "%c", &c1);
                    char_originali++;
                }
                //in tutti gli altri casi procedo così
                else{
                    fprintf(fp_write,"%c",c0);
                    char_max--;
                    c0= c1;
                    fscanf(fp_read, "%c", &c1);
                    char_originali++;

                }}

                fprintf(fp_write,"| c:%d\n",char_originali);
                char_originali=0; //azzero la variabile perchè è inisiziata una nuova riga
        }
    }
    fclose(fp_read);
    fclose(fp_write);
    return 0;
}
