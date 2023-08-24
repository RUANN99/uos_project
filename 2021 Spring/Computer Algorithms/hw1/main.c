#include <stdio.h>
#include <stdlib.h>



void buildList(int S[], int n){
    for(int i=0;i<n;i++){
        S[i] = i+1;
    }
}

void removeCandle(int S[], int r, int size){
    for(int i=r;i<size;i++){
        S[i]=S[i+1];
    }
}

int runSimulation1(int S[], int n, int k){
    int r=0;
    while(n>1){
        r=(r+k)%n;
        removeCandle(S,r,n);
        n--;
    }
    /*for(int j=0;j<n;j++){
        printf("%d -> ",S[j]);}*/
    return S[0];
}

void main(){
    int size, k;
    printf("insert size , key\n");
    scanf("%d %d",&size,&k);
    int candle[size];
    
    buildList(candle, size);
    
    printf("candle no.%d\n",runSimulation1(candle, size, k));
    
}

