#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node *createList(int n)
{
    if (n <= 0)
        return NULL;
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("nhap gia tri %d: ", i + 1);
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}
int count(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {

        count++;

        current = current->next;
    }
    return count;
}

void freeList(Node *tail)
{
    Node *current = tail;
    while (current != NULL && current->prev != NULL)
    {
        current = current->prev;
    }
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    Node *head = createList(n);
    printf("so luong phan tu cua lien ket la : %d", count(head));
    return 0;
}