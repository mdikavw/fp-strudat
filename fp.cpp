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
    printf("Masukkan barang setelah (ketik 'depan' jika ingin memasukkan barang di depan): ");
    scanf(" %s", masukkanSetelah);

    if(strcmp(masukkanSetelah, "depan") == 0){
        pNew->next = *pHead;
        *pHead = pNew;
        return;
    }

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

void hapusBarang(ListNode ** pHead){
    ListNode * pPrev, * pCur;
    char namaBarang[30];
    
    pCur = *pHead;
    pPrev = NULL;
    if(pCur == NULL){
        printf("Daftar produk kosong\n");
        system("pause");
        return;
    }
    traverseList(*pHead);
    printf("Masukkan nama barang yang akan dihapus: ");
    scanf(" %s", namaBarang);

    while(pCur != NULL && strcmp(pCur->nama, namaBarang) != 0){
        pPrev = pCur;
        pCur = pCur->next;
    }
    if(pCur == NULL){
        printf("Nama barang tidak ditemukan\n");
        system("pause");
        return;
    }
    if(pCur == *pHead){
        *pHead = pCur->next;
        free(pCur);
        return;
    }
    if(pCur->next == NULL){
        pPrev->next = NULL;
        free(pCur);
        return;
    }
    pPrev->next = pCur->next;
    free(pCur);
    return;
}


void enQueue(Queue * pQueue, ListNode * pHead){
    int MAX = 5;
    QueueNode * pNew;
    ListNode * pCur;
    char namaBarang[30], namaPembeli[30];
    if(pQueue->length >= MAX){
        printf("Antrian telah melebihi batas\n");
        system("pause");
        return;
    }
    traverseList(pHead);
    printf("Masukkan nama barang: ");
    scanf(" %s", namaBarang);
    printf("Masukkan nama pembeli: ");
    scanf(" %s", namaPembeli);

    pCur = pHead;
    while(pCur != NULL && strcmp(strlwr(pCur->nama), strlwr(namaBarang)) != 0){
        pCur = pCur->next;
    }
    if(pCur == NULL){
        printf("Produk tidak tersedia\n");
        system("pause");
        return;
    }

    pNew = (QueueNode *)malloc(sizeof(QueueNode));
    if(pNew == NULL){
        printf("Memori tidak cukup\n");
        system("pause");
        return;
    }
    strcpy(pNew->namaBarang, namaBarang);
    strcpy(pNew->namaPembeli, namaPembeli);
    if(pQueue->front == NULL){
        pQueue->front = pNew;
        pQueue->rear = pNew;
        pNew->next = NULL;
        pQueue->length++;
        system("pause");
        return;
    }
    pQueue->rear->next = pNew;
    pQueue->rear = pNew;
    pNew->next = NULL;
    pQueue->length++;
}

void deQueue(Queue * pQueue){
    QueueNode * pCur;
    pCur = pQueue->front;
    if(pCur == NULL){
        printf("Antrian kosong\n");
        system("pause");
        return;
    }
    if(pCur->next == NULL){
        pQueue->front = NULL;
        pQueue->rear = NULL;
        system("pause");
    } else {
        pQueue->front = pCur->next;
    }
    free(pCur);
    pQueue->length--;
    system("pause");
    return;
}

void traverseQueue(Queue pQueue){
    QueueNode * pCur;
    pCur = pQueue.front;
    if(pCur != NULL){
        while(pCur != pQueue.rear){
            printf("%s (%s) -> ", pCur->namaPembeli, pCur->namaBarang);
            pCur = pCur->next;
        }
        printf("%s (%s) -> ", pCur->namaPembeli, pCur->namaBarang);
    }
    printf("NULL\n");
    printf("Panjang antrian: %i\n", pQueue.length);
}

int main(){
    char pilihan, option;

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
                scanf(" %c", &option);
                if(option == '1'){
                    traverseList(pHead);
                    system("pause");
                } else if(option == '2'){
                    addBarang(&pHead);
                } else if(option == '3'){
                   hapusBarang(&pHead);
                } else if(option == '4'){
                    traverseQueue(pQueue);
                    system("pause");
                } else if(option == '5'){
                    deQueue(&pQueue);
                }
                system("cls");
            } while (option != 'q');
        } else if(pilihan == '2'){
            do{
                printf("Pilihan Menu: \n");
                printf("1. Lihat daftar produk\n");
                printf("2. Pesan produk\n");
                printf("q. Keluar\n");
                printf("Masukkan pilihan: ");
                scanf(" %c", &option);
                if(option == '1'){
                    traverseList(pHead);
                } else if(option == '2'){
                    enQueue(&pQueue, pHead);
                } 
                system("cls");
            } while (option != 'q');
        }
    } while (pilihan != 'q');
    
    return 0;
}
