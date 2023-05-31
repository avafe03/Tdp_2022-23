#include <stdio.h>
//Esercizio 5. Scrivere un programma “calcolatrice” che esegua le quattro operazioni aritmetiche di base
//(addizione, sottrazione, divisione e moltiplicazione) tra due valori op1 e op2.
//Realizzare un programma C che:
//a) Acquisisca da tastiera utilizzando getchar l’operazione da eseguire (‘+’, ‘-‘, ‘*’ e ‘/’)
//b) Acquisisca da tastiera utilizzando scanf i due operandi (float) (es. 21.0 2.0).
//c) Stampi a schermo il carattere dell’operazione seguita dal risultato (es. / 10.50).
//Approfondimento: Cosa succede quando op2 è uguale a 0?
//Quando op2 è uguale a 0 il risultato stampato a schermo corrisponde a inf. Poichè questo risultato nelle
//calcolatrici normali non è accettabile è necessario gestire il problema.


int main() {
    float op1, op2;
    char operatore;

    //assumi in input i dati
    printf("Digitare l'operando desiderato per svolgere l'operazione tra i seguenti:\n-'+'\n-'-'\n-'*'\n-'/'\n");
    operatore=getchar();
    printf("Inserire valore op1:");
    scanf_s("%f", &op1);
    printf("Inserire valore op2:");
    scanf_s("%f", &op2);


    //gestire i casi in cui vengano indicati operatori non disponibili
    while (operatore!='+' & operatore!='-' & operatore!='*' & operatore!='/') {
        printf("Errore, operatore inesistente tra quelli diponibili\n");
        printf("Digitare l'operando desiderato per svolgere l'operazione tra i seguenti:\n-'+'\n-'-'\n-'*'\n-'/'\n");
        operatore = getchar();
    }

    //gestire caso in cui il divisore sia uguale a zero
    while (operatore=='/' & op2==0) {
        printf("Errore, il divisore 'op2' deve essere diverso da zero");
        printf("Inserire valore op2:");
        scanf_s("%f", &op2);
    }


    switch (operatore) {
        case '+':
            printf("%.2f+%.2f=%.2f",op1,op2,(op1+op2));
            break;
        case '-':
            printf("%.2f-%.2f=%.2f",op1,op2,(op1-op2));
            break;
        case '*':
            printf("%.2f*%.2f=%.2f",op1,op2,(op1*op2));
            break;
        case '/':
            printf("%.2f/%.2f=%.2f",op1,op2,(op1/op2));
            break;
        default:
            printf("Errore, hai digitato male");
            return -1;
    }
    return 0;
}
