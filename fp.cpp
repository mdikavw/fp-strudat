#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char nama[30];
    int stok;
    ListNode * next;
};
typedef struct listNode listNode;
void addBarang(ListNode **Head);

struct QueueNode {
    char namaBarang[30];
    char namaPembeli[30];
    QueueNode * next;
};
typedef struct queueNode queueNode;

struct Queue {
    int length;
    QueueNode * front;
    QueueNode * rear;
};
typedef struct Queue Queue;

void traverseList(ListNode * pHead){
    ListNode * pCur;
    pCur = pHead;
    if(pCur != NULL){
        while(pCur != NULL){
            printf("%s(%i) -> ", pCur->nama, pCur->stok);
            pCur = pCur->next;
        }
    }
    printf("NULL\n");
    return;
}

void addBarang(ListNode ** pHead){
    char nama[30], masukkanSetelah[30];
    int stok;
    ListNode * pNew, * pCur;
    printf("Masukkan nama barang: ");
    scanf(" %s", nama);
    printf("Masukkan stok barang: ");
    scanf("%i", &stok);

    pNew = (ListNode *)malloc(sizeof(ListNode));
    if(pNew == NULL){
        printf("Memori tidak cukup\n");
        system("pause");
        return;
    }
    strcpy(pNew->nama, nama);
    pNew->stok = stok;
    pNew->next = NULL;

    pCur = *pHead;

    if(pCur == NULL){
        *pHead = pNew;
        return;
    }
  traverseList(*pHead);
    printf("Masukkan barang setelah: ");
    scanf(" %s", masukkanSetelah);

    while(pCur != NULL && strcmp(pCur->nama, masukkanSetelah) != 0){
        pCur = pCur->next;
    }

    if(pCur == NULL){
        printf("Barang tidak ditemukan\n");
        system("pause");
        return;
    }

    if(pCur->next == NULL){
        pNew->next = NULL;
    } else {
        pNew->next = pCur->next;
    }
    pCur->next = pNew;
}

void traverseQueue(Queue pQueue){
    QueueNode * pCur;
    pCur = pQueue.front;
    if(pCur != NULL){
        while(pCur != pQueue.rear){
            printf("%s (%s) -> ", pCur->namaPembeli, pCur->namaBarang);
        }
        printf("%s (%s) -> ", pCur->namaPembeli, pCur->namaBarang);
    }
    printf("NULL\n");
}

int main(){
    char pilihan;

    ListNode * pHead;
    pHead = NULL;

    Queue pQueue;
    pQueue.length = 0;
    pQueue.front = NULL;
    pQueue.rear = NULL;

    printf("Program Pemesanan dan Penjualan Online Shop\n");
    do{
        printf("Masuk sebagai: \n");
        printf("1. Penjual\n");
        printf("2. Pembeli\n");
        printf("q. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%c", &pilihan);
        system("cls");
        if(pilihan == '1'){
            do{
                printf("Pilihan Menu: \n");
                printf("1. Lihat daftar produk\n");
                printf("2. Tambah produk baru\n");
                printf("3. Hapus produk\n\n");
                printf("4. Lihat antrian\n");
                printf("5. Proses antrian terdepan\n");
                printf("q. Keluar\n");
                printf("Masukkan pilihan: ");
                scanf("%c", &pilihan);
                if(pilihan == '1'){
                    traverseList(pHead);
                    system("pause");
                } else if(pilihan == '2'){
                    addBarang(&pHead);
                } else if(pilihan == '3'){
                    continue;
                } else if(pilihan == '4'){
                    traverseQueue(pQueue);
                    system("pause");
                }
                system("cls");
            } while (pilihan != 'q');
        } else if(pilihan == '2'){
            do{
                printf("Pilihan Menu: \n");
                printf("1. Lihat daftar produk\n");
                printf("2. Pesan produk\n");
                printf("q. Keluar\n");
                printf("Masukkan pilihan: ");
                scanf("%c", &pilihan);
                system("cls");
            } while (pilihan != 'q');
        }
    } while (pilihan != 'q');
    
    return 0;
}
