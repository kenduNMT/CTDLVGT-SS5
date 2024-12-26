#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* createNode(int value){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

Node* createList(int n){
    if(n <= 0 ) return NULL;
    Node* head= NULL;
    Node* tail= NULL;

    for(int i = 0; i<n; i++){
        int value;
        printf("nhap gia tri cua phan tu %d :" , i+1);
        scanf("%d", &value);
        Node* newNode = createNode(value);
        if( head == NULL){
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

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL && current->prev != NULL) {
        current = current->prev;
    }
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

Node* reverseList(Node* head) {
    // Nếu danh sách rỗng hoặc chỉ có 1 phần tử
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *current = head;
    Node *temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}
void printfList(Node* head){
    Node* current= head;
    while (current !=NULL)
    {
        printf("%d", current -> data);
        if( current ->next != NULL){
            printf("<->");
        }
        current = current -> next;
    }
    printf("<-> NULL");
}
int main(){
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    
    Node* head = createList(n);
    printfList(head);
    printf("\n");
    
    head = reverseList(head);
    printfList(head);
    printf("\n");
    
    freeList(head);
    return 0;
}