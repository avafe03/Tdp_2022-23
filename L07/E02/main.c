#include <stdio.h>
#define LUNGHEZZA 100


void insertion_sort(int sequenza1[], int len_sequenza);
void selection_sort(int sequenza2[], int len_sequenza);
void shell_sort(int sequenza3[], int len_sequenza);


int main() {
    int S,i,len_sequenza,j,sequenza1[LUNGHEZZA],sequenza2[LUNGHEZZA],sequenza3[LUNGHEZZA];
    FILE*fp_input;
    fp_input= fopen("../sort.txt", "r");
    if (fp_input!=NULL) {
        fscanf_s(fp_input, "%d", &S);
        for (i = 0; i < S; i++) {
            fscanf_s(fp_input, "%d", &len_sequenza);
            for (j = 0; j < len_sequenza; j++) {
                fscanf_s(fp_input, "%d", &sequenza1[j]);
                sequenza2[j]=sequenza1[j]; //effettuo copie per ogni tipo di ordinamento
                sequenza3[j]=sequenza1[j];
            }
            printf("RIGA %d\n",i+1);
            insertion_sort(sequenza1, len_sequenza);
            selection_sort(sequenza2, len_sequenza);
            shell_sort(sequenza3,len_sequenza);
            printf("\n");

        }

    }
    else{
        printf("Errore");
    }

    fclose(fp_input);
    return 0;
}

void insertion_sort(int sequenza1[], int len_sequenza){
    int i, j, l=0, r=len_sequenza-1, x;
    int numerodiscambi=0,numeroiterazionicicloesterno=0,iterazioniciclointerno,numerototaleiterazioni;
    for (i = l+1; i <= r; i++) {
        x = sequenza1[i];
        j = i - 1;
        while (j >= l && x < sequenza1[j]){ //se il numero a sx è > di quello a dx li scambio
            sequenza1[j+1] = sequenza1[j];
            j--;
            numerodiscambi++;
        }
        sequenza1[j+1] = x;
        numeroiterazionicicloesterno++;

    }
    iterazioniciclointerno=numerodiscambi;
    numerototaleiterazioni=numerodiscambi+numeroiterazionicicloesterno;
    printf("insertion sort\nn. iterazioni esterne %d\nn. iterazioni ciclo interno %d\nn. totale di scambi %d\n"
           "n. totale iterazioni %d\n",numeroiterazionicicloesterno,iterazioniciclointerno,numerodiscambi,
           numerototaleiterazioni);
}

void selection_sort(int sequenza2[], int len_sequenza){
    int i, j, l=0, r=len_sequenza-1, min,temp;
    int numerodiscambi=0,numeroiterazionicicloesterno=0,iterazioniciclointerno=0,numerototaleiterazioni;
    for (i = l; i < r; i++) {
        min = i;
        numeroiterazionicicloesterno++;
        for (j = i + 1; j <= r; j++){
            iterazioniciclointerno++;
            if (sequenza2[j] < sequenza2[min]){
                min = j;}}
        if (min != i) {
            numerodiscambi++;
            temp = sequenza2[i];
            sequenza2[i] = sequenza2[min];
            sequenza2[min] = temp; } }


    iterazioniciclointerno=numerodiscambi;
    numerototaleiterazioni=numerodiscambi+numeroiterazionicicloesterno;
    printf("selection sort\nn. iterazioni esterne %d\nn. iterazioni ciclo interno %d\nn. totale di scambi %d\n"
           "n. totale iterazioni %d\n",numeroiterazionicicloesterno,iterazioniciclointerno,numerodiscambi,
           numerototaleiterazioni);
}

void shell_sort(int sequenza3[], int len_sequenza){
    int i, j, x, l=0, r=len_sequenza-1, h=1;
    int numerodiscambi=0,numeroiterazionicicloesterno=0,iterazioniciclointerno,numerototaleiterazioni;
    while (h <= len_sequenza/3){
        h = 3*h+1;} //sequenza di knuth
    while(h >= 1) {
        for (i = l + h; i <= r; i++) {
            j = i;
            x = sequenza3[i];
            while(j >= l + h && x < sequenza3[j-h]) {
                sequenza3[j] = sequenza3[j-h];
                j=j-h;
                numerodiscambi++;
            }
            sequenza3[j] = x;
            numeroiterazionicicloesterno++;
        }
        h = h/3;
    }
    iterazioniciclointerno=numerodiscambi;
    numerototaleiterazioni=numerodiscambi+numeroiterazionicicloesterno;
    printf("shell sort\nn. iterazioni esterne %d\nn. iterazioni ciclo interno %d\nn. totale di scambi %d\n"
           "n. totale iterazioni %d\n",numeroiterazionicicloesterno,iterazioniciclointerno,numerodiscambi,
           numerototaleiterazioni);
}