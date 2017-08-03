#include <stdio.h>
#include <stdlib.h>

struct Book
{
    char title[100];
    char author[100];
    double price;
};

struct Node
{
    int value;
    struct Node *next;
};

// function
struct Node *addNodeToHead(struct Node *newNode, struct Node *head);
struct Node *makeNewNode(struct Node *newNode, int value);
void insertNodeTo(struct Node *newNode, struct Node * head, int position);
int lengthOfList(struct Node *i, struct Node *head);
struct Node *initLinkedList(struct Node *head){
    return head = NULL;
}
void printElement(struct Node *i, struct Node * head);

///////////////////////////////////////////////////////////

int main(int count, const char *args[])
{
    struct Node *head;
    initLinkedList(head);
    // add element
    struct Node *newNode1 = makeNewNode(newNode1, 1);
    head = addNodeToHead(newNode1, head);
    struct Node *newNode2 = makeNewNode(newNode2, 2);
    head = addNodeToHead(newNode2, head);

    struct Node *newNode3 = makeNewNode(newNode3, 7);
    head = addNodeToHead(newNode3, head);

    struct Node *newNode4 = makeNewNode(newNode4, 5);
    insertNodeTo(newNode4, head,1);
    // foreach
    struct Node *i;
    printf("number of element : %d\n",lengthOfList(i, head));
    printElement(i,head);
    return 0;
}

struct Node *addNodeToHead(struct Node *newNode, struct Node *head)
{
    if (head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
    }
    head = newNode;
    return head;
}

struct Node *makeNewNode(struct Node *newNode, int x)
{
    newNode = (struct Node *)malloc(sizeof(struct Node)); // cap phat bo nho cho newNode
    newNode->value = x;
    return newNode;
}

void insertNodeTo(struct Node *newNode,struct Node * head,  int position)
{
    struct Node *countNode;
    countNode = head;
    int i = 0;
    if(position < 1 || position > lengthOfList(countNode, head) + 1){
        printf("Didn't insert element");
    }
    else{
        while(countNode != NULL && i != position - 1){
            i++;
            countNode = countNode -> next;
        }
        newNode -> next = countNode->next;
        countNode -> next = newNode;
    }
}

int lengthOfList(struct Node* i, struct Node *head)
{
    int length = 0;
    i = head;
    while (i != NULL)
    {
        i = i -> next;
        length++;
    }
    return length;
}

void printElement(struct Node* i, struct Node *head){
    i = head;
    while(i != NULL){
        printf("%d\n", i->value);
        i = i -> next;
    }
}