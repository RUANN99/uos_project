//
//  main.c
//  alg_practice
//
//  Created by RUAN on 2021/06/07.
//

#include <stdio.h>
#include <stdlib.h>

#define N 7
#define INF 1000000

typedef struct Edge{
    int vNum1, vNum2;
    int weight;
    struct Edge* next;
}Edge;

typedef struct IncidentEdge{
    int adjVertex;
    int weight;
    Edge* e;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex{
    int num;
    int isFresh;
    struct Vertex* next;
    IncidentEdge* top;
}Vertex;

Vertex* vHead = NULL;
Edge* eHead = NULL;
int vCount, eCount;
int dist[N];

void makeVertices(){
    Vertex* p = (Vertex*)malloc(sizeof(Vertex));
    p->num = ++vCount;
    p->top = NULL;
    p->next = NULL;
    p->isFresh = 0;
    Vertex* q = vHead;
    if(q==NULL){
        vHead = p;
    }
    else{
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
}

Vertex* findVertex(int v){
    Vertex* p = vHead;
    while(p->num != v){
        p = p->next;
    }
    return p;
}

void insertIncidentEdge(Vertex* v, int av, Edge* e){
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->adjVertex = av;
    p->weight = e->weight;
    p->e = e;
    p->next = NULL;
    IncidentEdge* q = v->top;
    if(q == NULL){
        v->top = p;
    }
    else{
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
}

void insertEdge(int v1, int v2, int w){
    Edge* p = (Edge*)malloc(sizeof(Edge));
    p->vNum1 = v1;
    p->vNum2 = v2;
    p->weight = w;
    p->next = NULL;
    Edge* q = eHead;
    if(q == NULL){
        eHead = p;
    }
    else{
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
    
    Vertex* v = findVertex(v1);
    insertIncidentEdge(v, v2, p);
    v = findVertex(v2);
    insertIncidentEdge(v, v1, p);
}

void dfs(Vertex* v){
    IncidentEdge* q;
    if(v->isFresh == 0){
        printf("[%d] ", v->num);
        v->isFresh = 1;
    }
    for(q = v->top; q != NULL; q = q->next){
        v = findVertex(q->adjVertex);
        if(v->isFresh == 0){
            dfs(v);
        }
    }
}

int getMinVertex(){
    int v;
    Vertex* p = vHead;
    for(; p!=NULL; p=p->next){
        if(p->isFresh == 0){
            v = p->num-1;
            break;
        }
    }
    for(p = vHead; p!=NULL; p=p->next){
        if(p->isFresh == 0 && (dist[p->num-1] < dist[v])){
            v = p->num-1;
        }
    }
    return v;
}

void prim(Vertex* v){
    IncidentEdge* q;
    Vertex* p;
    int u;
    
    for(int i=0; i<N; i++){
        dist[i] = INF;
    }
    
    dist[v->num-1] = 0;
    
    for(int i=0; i<N; i++){
        u = getMinVertex();
        p = findVertex(u+1);
        p->isFresh = 1;
        printf("[%d] ", p->num);
        for(q=p->top; q!=NULL; q=q->next){
            p = findVertex(q->adjVertex);
            if(p->isFresh == 0){
                dist[q->adjVertex-1] = q->weight;
            }
        }
    }
}


void printing(){
    Vertex* p = vHead;
    IncidentEdge* q;
    for(; p != NULL; p = p->next){
        printf("정점 %d : ", p->num);
        for(q = p->top; q != NULL; q = q->next){
            printf("[%d (%d)] ", q->adjVertex, q->weight);
        }
        printf("\n");
    }
}

Edge* e[14];

//void printEdge(){}

int main(){
    for(int i=0; i<N; i++){
        makeVertices();
    }
    
    insertEdge(1, 2, 10);
    insertEdge(1, 3, 15);
    insertEdge(1, 4, 8);
    insertEdge(1, 5, 27);
    insertEdge(2, 4, 25);
    insertEdge(2, 5, 4);
    insertEdge(3, 4, 13);
    insertEdge(3, 6, 32);
    insertEdge(3, 7, 8);
    insertEdge(4, 5, 10);

    
    printing();
    
    prim(vHead);
    printf("\n");
    
    return 0;
}


