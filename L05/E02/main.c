#include <stdio.h>
#include <string.h>
#define S 30
#define MAXN 200

struct dizionario{
    char originale[MAXN];
    char ricodifica[MAXN];
};

void leggi_dizionario(struct dizionario dati[], int dim, FILE *fp_dizionario);
void verifica(struct dizionario dati[],char c[], int dim);
char *strreplace(char *c, const char *s1, const char *s2);

int main(){
    FILE *fp_sorgente,*fp_dizionario, *fp_ricodificato;
    int dim;
    char *token, buffer[MAXN],c[MAXN], *riga;
    struct dizionario dati[S];

    fp_sorgente=fopen("sorgente.txt","r");
    fp_dizionario=fopen("dizionario.txt","r");
    fp_ricodificato= fopen("ricodifica.txt", "w");

    fscanf_s(fp_dizionario,"%d",&dim);
    leggi_dizionario(dati, dim, fp_dizionario);

    if(fp_sorgente!=NULL){
        riga=fgets(buffer,200, fp_sorgente);
        while(riga!=NULL) {

            token = strtok(riga, " ");
            strcpy(c,token);
            verifica(dati,c,dim);
            fprintf(fp_ricodificato, "%s", c);
            token = strtok(NULL, " ");
            while ( token!=NULL){
                strcpy(c,token);
                verifica(dati,c,dim);
                fprintf(fp_ricodificato," %s",c);
                token = strtok(NULL, " ");
            }
            riga=fgets(buffer,200, fp_sorgente);



        }
    }
    fclose(fp_sorgente);
    fclose(fp_ricodificato);
    fclose(fp_dizionario);
    return 0;}

void leggi_dizionario(struct dizionario dati[], int dim, FILE *fp_dizionario){
    int i;
    if (dim<S && fp_dizionario!=NULL){
    for(i=0;i<dim;i++){
        fscanf(fp_dizionario,"%s %s",dati[i].ricodifica,dati[i].originale);
    }}
}

void verifica(struct dizionario dati[],char c[], int dim){
    int i;
    int flag_trovato=0;
    for(i=0;i<dim && flag_trovato==0;i++){
        if (strstr(c, dati[i].originale) != NULL) {
            flag_trovato=1;
            c=strreplace(c, dati[i].originale, dati[i].ricodifica);
        }
    }

}

char *strreplace(char *c, const char *s1, const char *s2) {
    char *p = strstr(c, s1); //nella variabile p è presenta il carattere c ma dal punto in cui inizia a presentarsi la sottostringa (ciao ia -> iao)
    if (p != NULL) {
        size_t len1 = strlen(s1);//dimensione sottostringa
        size_t len2 = strlen(s2);//dimensione di ciò che voglio sostituire
        memmove(p + len2, p + len1, strlen(p + len1) + 1);
        memcpy(p, s2, len2);
    }
    return c;
}