#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createList(int n) {
    if (n <= 0) return NULL;
    Node* head = NULL;
    Node* tail = NULL;
    printf("Nhap gia tri: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return tail;  
}

void printList(Node* tail) {
    Node* current = tail;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->prev != NULL) {
            printf(" <-> ");
        }
        current = current->prev;
    }
    printf(" <-> NULL\n");
}

void freeList(Node* tail) {
    Node* current = tail;
    while (current != NULL && current->prev != NULL) {
        current = current->prev;
    }
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    
    Node* tail = createList(n);
    printf("Danh sach sau khi nhap: ");
    printList(tail);
    
    freeList(tail);
    return 0;
}