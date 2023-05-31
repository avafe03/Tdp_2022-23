#include <stdio.h>
//Esercizio 6. Partendo dal codice dell’esercizio precedente, scrivere un programma C che legga da file
//una serie di operazione da eseguire e scriva su un altro file
// l’operazione eseguita ed il risultato dell’operazione con due cifre decimali.

int main() {
    //dichiaro variabili
    float op1, op2;
    char operatore;
    FILE *operations_r, *operations_w;
    //apro i file di lettura e scrittura
    operations_w=fopen("operations_w.txt", "w");
    operations_r=fopen("operations_r.txt.", "r");
    //verifico non ci siano errori nell' apertura dei file
    if (operations_r!=NULL && operations_w!=NULL) {
        //leggo il file fino alla fine
        while(!feof(operations_r)) {
            fscanf(operations_r, "%c %f %f ", &operatore, &op1, &op2);

            switch (operatore) {
                case '+':
                    fprintf(operations_w, "%.2f+%.2f=%.2f\n", op1, op2, (op1 + op2));
                    break;
                case '-':
                    fprintf(operations_w, "%.2f-%.2f=%.2f\n", op1, op2, (op1 - op2));
                    break;
                case '*':
                    fprintf(operations_w, "%.2f*%.2f=%.2f\n", op1, op2, (op1 * op2));
                    break;
                case '/':
                    if (op2!=0) {
                        fprintf(operations_w, "%.2f/%.2f=%.2f\n", op1, op2, (op1 / op2));
                        break;
                    }
                    else{
                        fprintf(operations_w,"impossibile eseguire operazione");
                        return -1;
                    }
                default:
                    printf("operatore non riconosciuto");
                    return -2;
            }
        }
    }
    else {printf("errore file");
    }
    fclose(operations_w);
    fclose(operations_r);
    return 0;
}