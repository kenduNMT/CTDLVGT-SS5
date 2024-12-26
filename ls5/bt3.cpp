#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node Node;

Node* createNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev= NULL;
    return newNode;
}
Node* createList(int n){
    if( n<=0) return NULL;
    Node* head= NULL;
    Node* tail = NULL;
    for( int i=0; i<n; i++){
        int value;
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);
        Node* newNode= createNode(value);
        if(head == NULL){
            head= newNode;
            tail= newNode;
        }else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }

    }
    return head; 
}
void printList(Node* head){
    Node* current= head;
    while (current  != NULL)
    {
        printf("%d",current->data);
        if(current ->next != NULL){
            printf(" <-> ");
        }
        current =current -> next;
    }
    printf("<-> NULL\n");
}
Node* findTail(Node* head) {
    if (!head) return NULL;
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    return current;
}
Node* deleteNodeTail(Node* tail){
    if(tail == NULL) return NULL;
    Node* temp = tail->prev;
    if(temp != NULL){
        temp-> next = NULL;
    }
    free(tail);
    return temp;
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Nhap do dai lien ket: ");
    scanf("%d", &n);
    Node* head = createList(n);
    Node* tail = findTail(head);
    
    printList(head);
    tail = deleteNodeTail(tail);
    printList(head);
    
    freeList(head);
    return 0;
}