#include <stdio.h>
int Minimo(int righe,int colonne);

int main() {
    int colonne,righe,j,i,nr,nc,dim=0,somma,max_somma=0,max_nr,max_nc;
    int matrice[20][20];
    FILE *fp_input;
    char fname[20];
    printf("Inserire nome file scrivendo 'nomefile.txt'\n");
    scanf("%s", fname);
    fp_input= fopen(fname, "r");
    printf("Inserire dimensione sottomatrice\n");
    scanf_s("%d", &dim);
    //leggi matrice di date dimensioni
    if(fp_input!=NULL) {
        fscanf_s(fp_input, "%d", &righe);
        fscanf_s(fp_input, "%d", &colonne);
        i=0;
        while (i<righe){
            j=0;
            while (j<colonne) {
                fscanf_s(fp_input, "%d", &matrice[i][j]);
                printf("%d ",matrice[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }
        while (dim>0 && dim < Minimo(righe,colonne)){
            printf("\nLe sottomatrici quadrate di dimensione = %d sono:\n", dim);
            for (i=0;i<righe-dim+1;i++){
                for (j=0;j<colonne-dim+1;j++){
                    somma=0;
                    for (nr=i;nr<dim+i;nr++){
                        for (nc=j;nc<dim+j;nc++){
                            printf("%d ",matrice[nr][nc]);
                            somma=somma+matrice[nr][nc];
                        }
                        printf("\n");
                    }
                    printf("\n");
                    if (somma>max_somma){
                        max_somma=somma;
                        max_nc=nc-dim;
                        max_nr=nr-dim;
                    }
                }
            }
            printf("\nLa sottomatrice con somma degli elementi massima (%d) e':\n", max_somma);
            for (i=max_nr;i<max_nr+dim;i++){
                for (j=max_nc;j<dim+max_nc;j++){
                    printf("%d ",matrice[i][j]);
                }
                printf("\n");
            }
            printf("\nInserire dimensione sottomatrice\n");
            scanf_s("%d",&dim);
        }
    }

    else {
        printf("Errore nel file");
    }
    fclose(fp_input);
    return 0;
}
int Minimo(int righe, int colonne){
    int minimo;
    if (righe>colonne){
        minimo=colonne;
    }
    else{
        minimo=righe;
    }
    return minimo;
}
