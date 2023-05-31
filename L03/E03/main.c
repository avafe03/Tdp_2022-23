#include <stdio.h>
#define filein "../numeri.txt"

int main() {
    FILE *fp_read;
    int risultato,n1,n2,max,min,scarto=0;
    fp_read= fopen(filein, "r");
    if (fp_read==NULL){
        printf("Errore apertura file");
    }
    else{
        fscanf_s(fp_read,"%d%d%d",&n1,&n2,&risultato);

        //calcolo massimo tra i 3 numeri
        if (n1>=n2 && n1>=risultato) {
            max = n1;}
        else if(n2>=n1 && n2>=risultato){
            max=n2;}
        else {
            max = risultato;}

        //calcolo minimo tra i 3 numeri
        if (n1<=n2 && n1<=risultato) {
            min = n1;}
        else if(n2<=n1 && n2<=risultato){
            min=n2;}
        else {
            min = risultato;}


        while (!feof(fp_read)){
            if(n2!=0) { //se n2 diverso da zero faccio divisione
                //se nessuna condizione è rispettata incremento lo scarto e provvedo a saltare il numero
                if ((risultato - (n1 + n2)) != 0 && (risultato - (n1 - n2)) != 0
                    && (risultato - (n1 * n2)) != 0 && (risultato - (n1 / n2)) != 0) {
                    scarto++;
                    n1=n2;
                    fscanf_s(fp_read, "%d%d",&n2, &risultato);
                }
                else{ //se la condizione è rispettata valuto se il numero è il massimo o il minimo
                    if(risultato>max){
                        max=risultato;}
                    if(risultato<min){
                        min=risultato;}
                        n1=n2;
                        n2=risultato;
                        fscanf_s(fp_read, "%d", &risultato);

                }
            }
            else{//se n2 uguale a zero non faccio divisione e procedo come prima
                if (risultato-(n1+n2)!=0 && (risultato-(n1-n2))!=0
                && (risultato-(n1*n2))!=0) {
                    scarto++;
                    n1=n2;
                    fscanf_s(fp_read, "%d%d",&n2, &risultato);
                }
                else{
                    if(risultato>max){
                        max=risultato;}
                    if(risultato<min){
                        min=risultato;}
                    n1=n2;
                    n2=risultato;
                    fscanf_s(fp_read, "%d", &risultato);
                }
            }

        }
        printf("Numero massimo: %d\nNumero minimo: %d\nNumeri scartati: %d",max, min, scarto);
    }

    return 0;
}
