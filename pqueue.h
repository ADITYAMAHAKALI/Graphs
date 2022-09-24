#include"stdio.h"
#include"stdlib.h"
#include"time.h"

typedef struct Pair{
  int dest;
  int cost;
}pair;
typedef struct priorityQueue{
    pair *arr;
    int n;
    int curr_size;
}pqueue;

void swap(pair *a, pair *b){
    pair t = *a;
    *a = *b;
    *b = t; 
}

void heapify(pqueue *pq, int i) {
  if (pq->curr_size == 1) {
    //printf("Single element in the heap");
  } else {
    // Find the smallest among root, left child and right child
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < pq->curr_size && pq->arr[l].cost < pq->arr[smallest].cost)
      smallest = l;
    if (r < pq->curr_size && pq->arr[r].cost < pq->arr[smallest].cost)
      smallest = r;
    
    // Swap and continue heapifying if root is not largest
    if (smallest != i) {
      swap(&pq->arr[i], &pq->arr[smallest]);
      heapify(pq,smallest);
    }
  }
}

void initializePQueue(pqueue *pq,int n){
    pq->arr = (pair *)malloc(sizeof(pair)*n);
    pq->n = n;
    pq->curr_size = 0;
}

void insertInPQueue(pqueue *pq,int x,int cost){
    if(pq->curr_size == 0){
        pq->arr[0].dest = x;
        pq->arr[0].cost = cost;
        pq->curr_size+=1;
    }else{
        pq->arr[pq->curr_size].cost = cost;
        pq->arr[pq->curr_size++].dest = x;
        for(int i = pq->curr_size/2 -1;i>=0;i--){
            heapify(pq,i);
        }
    }
}

void deleteRoot(pqueue *pq, int dest) {
  int i;
  for (i = 0; i < pq->curr_size; i++) {
    if (dest == pq->arr[i].dest)
      break;
  }
  swap(&pq->arr[i], &pq->arr[pq->curr_size - 1]);
  pq->curr_size -= 1;
  for (int i = pq->curr_size / 2 - 1; i >= 0; i--) {
    heapify(pq,  i);
  }
}
pair removePriorityNode(pqueue *pq){
  pair P = pq->arr[0];
  int i=0;
  swap(&pq->arr[i], &pq->arr[pq->curr_size - 1]);
  pq->curr_size -= 1;
  for (int i = pq->curr_size / 2 - 1; i >= 0; i--) {
    heapify(pq,  i);
  }
  return P;
}
void printPQueue(pqueue *pq) {
  for (int i = 0; i < pq->curr_size; ++i)
    printf("dest:%d cost:%d", pq->arr[i].dest,pq->arr[i].cost);
  printf("\n");
}
