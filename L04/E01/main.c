#include <stdio.h>
void sottoSequenze(const int V[], int N);
int main() {
    int V[30],N=0;
    FILE *fp_input;
    //apro il file e salvo il contenuto della stringa nel vettore V e la sua lunghezza nella variabile N
    fp_input= fopen("../input.txt", "r");
    if(fp_input!=NULL) {
        while (!feof(fp_input)) {
            fscanf_s(fp_input, "%d", &V[N]);
            N++;
        }
    }
    sottoSequenze(V,N);
    fclose(fp_input);
    return 0;
}

void sottoSequenze(const int V[],int N){
    int i,j,m1=0,m2=0, sottostringa_V[30];
   //eseguo un ciclo su tutto il vettore per individuare la lunghezza massima della sottostringa e salvo il valore
   //nella variabile m2
    for (i=0; i<N; i++) {
        if (V[i] != 0) {
            m1++;
        }
        else {
            if (m1 > m2) {
                m2 = m1;
            }
            m1=0;
        }
    }
    m1=0;
    //eseguo nuovamente un ciclo su tutto il vettore per individuare le sottostringhe di lunghezza m2
    for (i=0; i<N; i++){
        if (V[i] != 0) {
            sottostringa_V[m1]=V[i];
            m1++;
            if (m1==m2){
                printf("[ ");
                for (j=0; j<m1; j++){
                    printf("%d ", sottostringa_V[j]);
                }
                printf("]");
            }
        }
        else{
            m1=0;
        }
    }
}
