#include <stdio.h>
void ruota( int V[], int N, int P, int dir);
int main() {
    int V[30], N,P,dir,i;
    //
    printf("Inserire dimensione vettore\n");
    scanf("%d",&N);
    while(N>30 || N<1){
        printf("Inserire dimensione vettore\n");
        scanf("%d",&N);
    }
    for(i=0;i<N;i++){
        printf("Inserire numero\n");
        scanf("%d",&V[i]);
    }

    printf("Inserire il numero di posizioni\n");
    scanf(" %d",&P);
    while (P>30 || P<0){
        printf("Inserire il numero di posizioni\n");
        scanf("%d",&P);}

    printf("Inserire la direzione\n-Destra (-1)\n-Sinistra (1)\n");
    scanf("%d",&dir);
    while (dir!=-1 && dir!=1){
        printf("Inserire la direzione\n-Destra (-1)\n-Sinistra (1)\n");
        scanf("%d",&dir);}
    ruota(V,N,P,dir);
    return 0;
}

void ruota( int V[], int N, int P, int dir) {
    int V_ruotato[N],i;

    while (P!=0){
        if (dir==-1){
            i=0;
            while (i<N){
                while(P<N){
                    V_ruotato[i]=V[P];
                    i++;
                    P++;
                }
                P=0;
                V_ruotato[i]=V[P];
                i++;
                P++;
            }}

        else{
            P=N-P;
            i=0;
            while (i<N){
                while(P<N){
                    V_ruotato[i]=V[P];
                    i++;
                    P++;
                }
                P=0;
                V_ruotato[i]=V[P];
                i++;
                P++;
            }}
        for (i=0;i<N;i++){
            printf("%d ", V_ruotato[i]);
            V[i]=V_ruotato[i];
        }
        printf("\n");
        printf("Inserire il numero di posizioni\n");
        scanf("%d",&P);
        while (P>30 || P<0){
            printf("Inserire il numero di posizioni\n");
            scanf("%d",&P);}
        if(P!=0){
            printf("Inserire la direzione\n-Destra (-1)\n-Sinistra (1)\n");
            scanf("%d",&dir);
            while (dir!=-1 && dir!=1){
                printf("Inserire la direzione\n-Destra (-1)\n-Sinistra (1)\n");
                scanf("%d",&dir);}

        }}}