//
//  2018920065 luan li chi
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100

//heap
typedef struct{
    int heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

void initHeap(HeapType* h){
    h->heap_size=0;
}

void upHeap(HeapType* h){
    int i = h->heap_size;
    int key = h->heap[i];
    
    while((i != 1) && (key < h->heap[i/2])){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = key;
}

void insertItem(HeapType* h, int key){
    h->heap_size += 1;
    h->heap[h->heap_size] = key;
    upHeap(h);
}




void printHeap(HeapType* h){
    for(int i=1; i<=h->heap_size; i++){
        printf("[%d]", h->heap[i]);
    }
    printf("\n");
}

//stack
typedef struct{
    int stack[MAX_ELEMENT];
    int st_top;
}StackType;

void initStack(StackType* s){
    s->st_top=-1;
}

int isEmpty(StackType* s){
    if(s->st_top == -1){
        return 1;
    }
    else return 0;
}

void push(StackType* s, int key){
    s->st_top += 1;
    s->stack[s->st_top] = key;
}

int pop(StackType* s){
    if(isEmpty(s) == 1){
        printf("empty.\n");
        return -1;
    }
    else return s->stack[s->st_top--];
}

void printStack(StackType* s){
    printf("\nbinary: ");
    for(int i=s->st_top; i>=0; i--){
        printf("%d",s->stack[i]);
    }
    printf("\n\n");
}

void binaryExpansion(int i, StackType* s){
    while(i >= 2){
        push(s, i%2);
        i=i/2;
    }
    push(s, i);
    printStack(s);
}

int findLastNode(HeapType* h){
    int bit, value=0;
    int n = h->heap_size;   //n
    int i=1;    //root of the heap, heap[1]
    StackType stack;    //stack 생성
    initStack(&stack);  //stack 초기화
    binaryExpansion(n, &stack);     //2진수로 변환하기
    pop(&stack);    //첫 숫자를 제거하기
    printf("[%d] ",h->heap[i]);
    while(isEmpty(&stack) == 0){
        bit=pop(&stack);
        if(bit==0){
            i=i*2;      //leftChild
            value = h->heap[i];
            printf("-l-> [%d] ",value);    //show the path
        }
        else{
            i=i*2+1;    //rightChild
            value = h->heap[i];
            printf("-r-> [%d] ",value);
        }
    }
    return value;
}


void main(){
    HeapType heap;
    int num, size;
    initHeap(&heap);    //힙 초기화
    srand(time(NULL));
    size=(rand()%100)+2;
    for(int i=1;i<size; i++){   //랜덤으로 힙 생성
        num=(rand()%100)+1;
        insertItem(&heap,num);
    }
    printHeap(&heap);
    printf("\n\nvalue of last node : [%d]\n\n",findLastNode(&heap));
}




   
