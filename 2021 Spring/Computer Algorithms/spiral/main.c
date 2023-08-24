//
//  main.c
//  spiral
//
//  Created by RUAN on 2021/03/11.
//

#include <stdio.h>
#include <stdlib.h>

#define ROW 8
#define COL 6

void spiral(int A[ROW][COL]) {
    int left=0, right=COL-1, top=0, bottom=ROW-1;
    int value=1;
    while(left<=right&&top<=bottom){
        for (int j=left;j<=right;j++){
            A[left][j]=value;
            value++;
        }
        for (int i=top+1;i<=bottom;i++){
            A[i][right]=value;
            value++;
        }
        for (int j=right-1;j>=left;j--){
            A[bottom][j]=value;
            value++;
        }
        for (int i=bottom-1;i>=top+1;i--){
            A[i][left]=value;
            value++;
        }
        left++;
        right--;
        top++;
        bottom--;
    }
}

void printArray(int A[][COL]){
    for (int i=0;i<ROW;i++){
        for (int j=0;j<COL;j++){
            printf(" %2d ",A[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int A[ROW][COL]={0};
    spiral(A);
    printArray(A);
}

