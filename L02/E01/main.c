#include <stdio.h>
//Scrivere un programma C che, acquisiti 2 numeri interi positivi ne calcoli il massimo comune divisore
//utilizzando la formula di Eulero.
//Formula di Eulero o metodo dei resti: si procede per divisioni successive del numero maggiore per
//quello minore, sostituendo ad ogni passo il valore maggiore con il minore ed il minore
//col resto della divisione. Il processo termina quando il resto è 0.
int main() {
    int n1, n2,n1_0, n2_0, resto;

    printf("Inserire 2 numeri interi positivi separati da uno spazio:\n");
    scanf_s("%d %d",&n1,&n2);
    while (n1<0 || n2<0) {
        printf("Errore, inserire 2 numeri interi POSITIVI separati da uno spazio:\n");
        scanf_s("%d %d",&n1,&n2);
    }
    n1_0=n1;
    n2_0=n2;
    if (n1>n2) {
        while (n2 != 0) {
            resto = n1 % n2;
            n1 = n2;
            n2 = resto;
        }
        printf("Il MCD tra %d e %d corrisponde a %d", n1_0, n2_0,n1);
    }
    else if (n2 > n1) {
        while (n1 != 0) {
            resto = n2 % n1;
            n2 = n1;
            n1 = resto;
        }
        printf("Il MCD tra %d e %d è %d", n1_0, n2_0,n2);}
    else {
        printf("errore");
    }
        return 0;
    }