//
//  main.cpp
//  ds_w3_hanoi_iter
//
//  2018920065 luan li chi


#include <iostream>
#include <stdio.h>
#include <time.h>
#define pause getch()
#define is_stack_empty()  (top < 0)
#define MAX 100
 
//2018920065 루안리치 자료구조 과제1 : 하노이탑 반복적인 방법
int top;
int stack[MAX];
 
void init_stack()
{
    top = -1;
}
 
int push(int val)
{
    if(top >= MAX -1)  // Overflow
    {
       printf("\nOverflow.");
       return -1;
    }
    stack[++top] = val;
    return val;
}
 
int pop()
{
    if(top < 0)  // Underflow
    {
       printf("\nUnderflow.");
       return -1;
    }
    return stack[top--];
}
 
void move(int n, char a, char c)
{
    printf("원판 %d을 %c 에서 %c 으로 옮긴다\n", n, a, c);
}
 
void hanoi_iter(int n, char from, char tmp, char to)
{
   int done = 0;
   init_stack();   // 초기화
   while(!done)
   {
      while(n > 1)
      {
          push(to);
          push(tmp);
          push(from);
          push(n);
          n--;
          push(to);
          to = tmp;
          tmp = pop();
      }

      move(n, from, to);  // 종료
      if(!is_stack_empty()) // (top < 0) -> !(top < 0)
      {
          n = pop();
          from = pop();
          tmp = pop();
          to = pop();
          move(n, from, to);
          n--;
          push(from);
          from = tmp;
          tmp = pop();
       }
       else
          done = 1;  // 스택이 비면 끝
   }
}



int main(void){
    clock_t start, stop;
    double duration;
    start=clock();
    hanoi_iter(5,'A','B','C');
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("time: %f sec\n",duration);
    return 0;
}
//2018920065 루안리치 자료구조 과제1 : 하노이탑 반복적인 방법
