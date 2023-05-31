#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define stringa_max 30
#define max_righe 1000

struct informazioni_tratte {
    char codice_tratta[stringa_max];
    char partenza[stringa_max];
    char capolinea[stringa_max];
    char data[stringa_max];
    char ora_partenza[stringa_max];
    char ora_arrivo[stringa_max];
    int  ritardo;};

typedef enum comando {r_date, r_partenza, r_capolinea, r_ritardo,
                      r_ritardo_tot, r_fine} comando_e;

void menu_comando(struct informazioni_tratte righe[],int n_righe);
int leggi_comando(void);
void stringa_formattata(char comando[]);
void date(struct informazioni_tratte righe[],int n_righe);
void partenza(struct informazioni_tratte righe[], int n_righe);
void capolinea(struct informazioni_tratte righe[], int n_righe);
void ritardo(struct informazioni_tratte righe[], int n_righe);
void ritardo_tot(struct informazioni_tratte righe[], int n_righe);

int main() {
    FILE*fp_input= fopen("../log.txt", "r");
    int n_righe=0,i;
    struct informazioni_tratte righe[max_righe];
    if(fp_input!=NULL) { //leggo file e salvo tutto nello struct
        fscanf_s(fp_input, "%d", &n_righe);
        if (n_righe<=1000){
            for(i=0; i<n_righe;i++){
                fscanf(fp_input, "%s", righe[i].codice_tratta);
                fscanf(fp_input, "%s", righe[i].partenza);
                fscanf(fp_input, "%s", righe[i].capolinea);
                fscanf(fp_input, "%s", righe[i].data);
                fscanf(fp_input, "%s", righe[i].ora_partenza);
                fscanf(fp_input, "%s", righe[i].ora_arrivo);
                fscanf_s(fp_input, "%d", &righe[i].ritardo);
            }}} else{ printf("errore apertuta file");}
    menu_comando(righe,n_righe);
    fclose(fp_input);
    return 0;
}
void menu_comando(struct informazioni_tratte righe[],int n_righe){
    int comando, continua=1;
    while (continua!=0){
    comando=leggi_comando();
    switch (comando) {
        case r_date:
            date(righe, n_righe);
            break;
        case r_partenza:
            partenza(righe, n_righe);
            break;
        case r_capolinea:
            capolinea(righe, n_righe);
            break;
        case r_ritardo:
            ritardo(righe,n_righe);
            break;
        case r_ritardo_tot:
            ritardo_tot(righe,n_righe);
            break;
        case r_fine:
            continua=0;
            break;
        default:
            printf("\ncomando errato");
    }}}

int leggi_comando(void){
    int i;
    char comando[30], tabella[6][20]={"Date", "Partenza", "Capolinea",
                                      "Ritardo", "Ritardo_Tot", "Fine" };

    printf("Scegliere il comando:\n-Date\n-Partenza\n-Capolinea\n-Ritardo\n-Ritardo_Tot\n-Fine\n");
    scanf("%s", comando); //leggo in input il comando

    stringa_formattata(comando);

    i=r_date; //valuto nel ciclo se il comando corrisponde ad una delle opzioni del menu che ho salvato nella tabella
    while(i<=r_fine && strcmp(comando,tabella[i])!=0) {
        i++;}
    return (i); //restituisco l'int corrispondente al valore che ha il comando in enum
}
void stringa_formattata(char comando[]) {
    int i=0;
    comando[i]= toupper(comando[i]);//
    for (i=1;i<strlen(comando);i++){ //rendo minuscolo il resto comando preso in input, tranne le lettere dopo "_"
        if (comando[i-1]=='_'){
            comando[i]= toupper(comando[i]);
        } else{
        comando[i]= tolower(comando[i]);}}
}


void date(struct informazioni_tratte righe[], int n_righe){
    char d1[stringa_max],d2[stringa_max];
    int i;
    printf("\nInserire le due date in questo formato AAAA/GG/MM\n");
    scanf("%s %s",d1,d2);
    for (i=0;i<n_righe;i++){
        if((strcmp(d1,righe[i].data)<0) && (strcmp(d2,righe[i].data)>0)){
            printf("%s %s %s %s %s %s %d",righe[i].codice_tratta,righe[i].partenza,righe[i].capolinea,
                   righe[i].data,righe[i].ora_partenza,righe[i].ora_arrivo,righe[i].ritardo);
            printf("\n");
        }}            printf("\n");}

void partenza(struct informazioni_tratte righe[], int n_righe){
    int i;
    char partenza_s[stringa_max];
    printf("inserisci partenza\n");
    scanf("%s",partenza_s);
    stringa_formattata(partenza_s);
    for(i=0;i<n_righe;i++){
        if(strcmp(partenza_s,righe[i].partenza)==0){
            printf("%s %s %s %s %s %s %d",righe[i].codice_tratta,righe[i].partenza,righe[i].capolinea,
                   righe[i].data,righe[i].ora_partenza,righe[i].ora_arrivo,righe[i].ritardo);
            printf("\n");
        }}            printf("\n");}

void capolinea(struct informazioni_tratte righe[], int n_righe){
    int i;
    char capolinea_s[stringa_max];
    printf("inserisci capolinea\n");
    scanf("%s", capolinea_s);
    stringa_formattata(capolinea_s);
    for(i=0;i<n_righe;i++){
        if(strcmp(capolinea_s,righe[i].capolinea)==0){
            printf("%s %s %s %s %s %s %d",righe[i].codice_tratta,righe[i].partenza,righe[i].capolinea,
                   righe[i].data,righe[i].ora_partenza,righe[i].ora_arrivo,righe[i].ritardo);
            printf("\n");
        }}            printf("\n");}

void ritardo(struct informazioni_tratte righe[], int n_righe){
    int i;
    char d1[stringa_max];
    char d2[stringa_max];
    printf("inserisci date\n");
    scanf("%s %s",d1,d2);
    for(i=0;i<n_righe;i++){
        if((strcmp(d1,righe[i].data)<0) && (strcmp(d2,righe[i].data)>0)){
            if(righe[i].ritardo>0){
                printf("%s %s %s %s %s %s %d\n",righe[i].codice_tratta,righe[i].partenza,righe[i].capolinea,
                       righe[i].data,righe[i].ora_partenza,righe[i].ora_arrivo,righe[i].ritardo);
            }}}
}

void ritardo_tot(struct informazioni_tratte righe[], int n_righe){
    int i;
    int delay=0;
    char codicetratta_s[stringa_max];
    printf("inserisci codice tratta\n");
    scanf("%s",codicetratta_s);
    for(i=0;i<3;i++){
        codicetratta_s[i]= toupper(codicetratta_s[i]);
    }
    for(i=0;i<n_righe;i++){
        if((strcmp(codicetratta_s,righe[i].codice_tratta)==0)){
            delay=delay+righe[i].ritardo;
        }
    }
    printf("%s %d\n\n",codicetratta_s,delay);
}