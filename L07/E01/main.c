#include <stdio.h>
void base(int matrice[50][50],int nr,int nc);
void altezza( int matrice[50][50],int nr,int nc);
void area( int matrice[50][50],int nr,int nc);

int main() {
    FILE*fp_input;
    int nr,nc,i,j;
    int matrice[50][50];
    fp_input= fopen("../mappa.txt", "r");
    fscanf_s(fp_input,"%d", &nr);
    fscanf_s(fp_input,"%d", &nc);
    //salvo valori matrice
    for(i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            fscanf_s(fp_input,"%d", &matrice[i][j]);}}
    base(matrice,nr, nc);
    area(matrice,nr,nc);
    altezza(matrice,nr,nc);
    fclose(fp_input);
            return 0;
}
void base( int matrice[50][50],int nr,int nc){
    int i,j,l,h,b, b_best=0,estr;
    for(i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            b=0;
            while (matrice[i][j]==1){ //fino a quando la casella della riga è nera incremento b
                b=b+1;
                j++;
            }
            if (b>b_best){ //se la base è più lunga della precedente calcolo la misura dell'altezza
                b_best=b;
                l=i;
                h=0;
                estr=j-b;
                while(matrice[l][j-b+1]!=0){
                    h++;
                    l++;
                }}}}
    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", l-h, estr, b_best, h, h*b_best);
}

void altezza( int matrice[50][50],int nr,int nc){
    int i,j,l,h,b,h_best=0,estr;
    for(j=0;j<nc;j++){
        for(i=0;i<nr;i++){
            h=0;
            while (matrice[i][j]==1){ //fino a quando la casella della colonna è nera incremento h
                h=h+1;
                i++;
            }
            if (h>h_best){ //se l'altezza è più lunga della precedente calcolo la misura della base
                h_best=h;
                l=j;
                b=0;
                estr=i-h;
                while(matrice[i-h+1][l]!=0){
                    b++;
                    l++;
                }}}}
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d", estr, l-b, b, h_best, b*h_best);
}

void area( int matrice[50][50],int nr,int nc){
    int i,j,l,h,b,area,area_best=0,b_best, h_best,estr_1, estr_2;
    for(i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            b=0;
            while (matrice[i][j]==1){  //calcolo misura base
                b=b+1;
                j++;
            }
            l=i;
            h=0;
            while(matrice[l][j-b]!=0){ //calcolo misura altezza
                h++;
                l++;
            }
            area=b*h; //calcolo area
            if(area>area_best){ //se l'area è più grande della precedente salvo i valori della base, dell'altezza e delle coordinate
                area_best=area;
                b_best=b;
                h_best=h;
                estr_2=j-b;
                estr_1=l-h;
            }
        }}
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", estr_1, estr_2, b_best, h_best, area_best);
}

