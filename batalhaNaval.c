#include <stdio.h>
#include <stdlib.h>
#define T 10
#define H 5

int main(){
    int tab[T][T]={0},cone[H][H],cruz[H][H],oct[H][H];

    tab[4][4]=3; tab[5][5]=3; tab[2][7]=3;

    for(int i=0;i<H;i++)for(int j=0;j<H;j++){
        cone[i][j]=(j>=H/2-i && j<=H/2+i);
        cruz[i][j]=(i==H/2 || j==H/2);
        oct[i][j]=(abs(i-H/2)+abs(j-H/2)<=H/2);
    }

    int ox[3]={2,5,7}, oy[3]={2,5,7};
    int*hab[3]={&cone[0][0],&cruz[0][0],&oct[0][0]};

    for(int h=0;h<3;h++)
        for(int i=0;i<H;i++)for(int j=0;j<H;j++)
            if(*(hab[h]+i*H+j)){
                int x=ox[h]+i-H/2,y=oy[h]+j-H/2;
                if(x>=0&&x<T&&y>=0&&y<T&&tab[x][y]==0) tab[x][y]=5;
            }

    for(int i=0;i<T;i++){for(int j=0;j<T;j++)
        printf(tab[i][j]==0?"~ ":tab[i][j]==3?"N ":"* ");
        printf("\n");}
}