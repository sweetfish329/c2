#include <stdio.h>

#define N 16
void scorein(int *s);

int main(void){
    int ten[N], rank[N], bunpu[6], x;
    int i,j;
    for(i=0;i<6;i++){
        bunpu[i]=0;
    }
    // input score
    for(i=0;i<N;i++){
        printf("No.%dの点数(0-100)：",i+1);
        //if you don't use original func, change to scanf()
        scorein(&ten[i]);
    }
    // init rank
    for(i=0;i<N;i++)
        rank[i]=1;

    // judge score
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(ten[i]<ten[j]){
                rank[i]++;
            }
        }
        bunpu[ten[i]/20]++;
        
    }

    printf("\n\nNo.点数　順位\n");
    printf("-------------\n");
    // put score and rank

    for(i=0;i<N;i++){
        printf(" %2d %3d  %2d\n", i+1,ten[i],rank[i]);
    }
    printf("+---------+-----------------------------\n");
    printf("|得点     |分布\n");
    printf("+---------+----5----10----15----20----25----30-----\n");
    for(i=0;i<6;i++){
        x=5;
        if(i==5){
            printf("|     100 |");
        }else{
            printf("| %2d - %2d |",i*20,i*20+19);
        }for(j=1;j<=bunpu[i];j++){
            if(j==x){
                printf("*");
                x+=5;
            }else{
                printf(".");
            }
        }
        putchar('\n');
    }
    return 0;
    
}

void scorein(int *s){
    while(1){
    scanf("%d",s);
    if(*s>=0&&*s<=100){
        break;   
    }
    printf("ERROR INPUT AGAIN : ");
    }
    return;
}
