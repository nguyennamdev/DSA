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
struct Node* insertNodeTo(struct Node *newNode, struct Node * head, int position);
int lengthOfList(struct Node *i, struct Node *head);
int searchNode(struct Node* i,struct Node* head, int f);

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
    head = insertNodeTo(newNode4, head,0);
    struct Node *i;
    printf("number of element : %d\n",lengthOfList(i, head));
    printElement(i,head);

    // search node 
    int resultSearch;
    int f = 10;
    resultSearch = searchNode(i,head,f);
    if(resultSearch == 0){
        printf("can't found");
    }
    else{
        printf("found node on position : %d", resultSearch);
    }
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

struct Node * insertNodeTo(struct Node *newNode,struct Node * head,  int position)
{
    struct Node *countNode;
    countNode = head;
    int i = 0;
    if(position < 0 || position > lengthOfList(countNode, head)){
        printf("Didn't insert element\n");
    }
    else{
        if(position == 0){
            head = addNodeToHead(newNode,head);
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
    return head;
}

int searchNode(struct Node* countNode, struct Node* head, int f){
    int result = 0;
    countNode = head;
    while(countNode != NULL && countNode->value != f){
        countNode = countNode -> next;
        result++;
    }
    if(countNode != NULL){
        return result;
    }
    else{
        return 0;
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