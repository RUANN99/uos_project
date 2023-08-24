//
//  main.cpp
//  ds_w3_hanoi
//
//  2018920065 luan li chi


#include <iostream>
#include <stdio.h>
#include <time.h>

//2018920065 루안리치 자료구조 과제1 : 하노이탑 순환적인 방법
void hanoi_tower(int n, char from, char tmp, char to){
    if(n==1) printf("원판 1을 %c 에서 %c 으로 옮긴다.\n",from,to);
    else{
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d을 %c 에서 %c 으로 옮긴다.\n",n,from,to);
        hanoi_tower(n-1, tmp, from, to);
    }
}

int main(void){
    clock_t start, stop;
    double duration;
    start=clock();
    hanoi_tower(10,'A','B','C');
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("time: %f sec\n",duration);
    return 0;
}
//2018920065 루안리치 자료구조 과제1 : 하노이탑 순환적인 방법
