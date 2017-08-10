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
int deleteNode(struct Node** head, int x);
int editNode(struct Node *head, int eValue,int fValue);
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
    struct Node *current;
    printf("number of element : %d\n",lengthOfList(current, head));
    printElement(current,head);

    // search node 
    int resultSearch;
    int f = 10;
    resultSearch = searchNode(current,head,f);
    if(resultSearch == 0){
        printf("can't found\n");
    }
    else{
        printf("found node on position : %d", resultSearch);
    }
    
    //delete node

    if (!deleteNode(&head, 10))
    {
        printf("Can't delete\n");
    }else{
        printf("Deleted number %d", 10);
    }

    // edit node 
    int kq = editNode(head,3,2);
    if(kq == 0){
        printf("Can't edit that");
    }
    else{
        printf("Edited %d to %d\n", 2, 3);
        printElement(current,head);
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

int deleteNode(struct Node** head, int x){
    struct Node* current = *head;
    struct Node* pre = *head;
    while(current != NULL && current->value != x){
            pre = current;
            current = current -> next;
    }
    if (current == NULL)
    {
        return 0;
    }
    else{
        if(current == *head){
            *head = current ->next;
        }else{
            pre->next = current->next;
        }
        free(current);
        return 1;
    }
}

int editNode(struct Node* head, int eValue, int fValue){
    struct Node* current = head;
    int position = 0;
    while(current != NULL && current->value != fValue){
        current = current->next;
    }
    if(current == NULL){
        return 0;
    }
    else{
        current->value = eValue;
        return 1;
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