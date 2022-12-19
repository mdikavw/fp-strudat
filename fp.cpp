#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {
    char nama[30];
    listNode * next;
};
typedef struct listNode listNode;

struct queueNode {
    char namaBarang[30];
    char namaPembeli[30];
    queueNode * next;
};
typedef struct queueNode queueNode;

int main(){
    return 0;
}