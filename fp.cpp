#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {
    int kode;
    char nama[30];
    listNode * next;
};
typedef struct listNode listNode;

struct queueNode {
    int kodeBarang;
    queueNode * next;
};
typedef struct queueNode queueNode;

int main(){
    return 0;
}