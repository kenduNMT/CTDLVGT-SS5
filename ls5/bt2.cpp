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
    printf("Nhap gia tri: ");
    for (int i = 0; i < n; i++)
    {
        int value;
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

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf(" <-> NULL\n");
}

Node *addNodeInIndex(Node *head, int index, int value)
{

    if (index < 0)
    {
        printf("Invalid index\n");
        return head;
    }

    Node *newNode = createNode(value);

    if (head == NULL)
    {
        if (index == 0)
            return newNode;
        free(newNode);
        return NULL;
    }

    if (index == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node *current = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (current->next == NULL)
        {

            free(newNode);
            printf("Index out of bounds\n");
            return head;
        }
        current = current->next;
    }

    if (current->next == NULL)
    {
        current->next = newNode;
        newNode->prev = current;
    }
    else
    {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    return head;
}

void freeList(Node *head)
{
    Node *current = head;
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
    printf("Danh sach sau khi nhap: ");
    printList(head);

    int index, value;
    printf("Nhap vi tri va gia tri can chen: ");
    scanf("%d %d", &index, &value);

    head = addNodeInIndex(head, index, value);
    printf("Danh sach sau khi chen: ");
    printList(head);

    freeList(head);
    return 0;
}