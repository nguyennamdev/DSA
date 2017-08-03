#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

struct Node* addNodeToHead(struct Node* newNode, struct Node *head);
struct Node* makeNewNode(struct Node* newNode, int value);


int main(int count, const char * args[]){
    struct Node* head;
    head = NULL;
    struct Node* newNode1 = makeNewNode(newNode1, 1);
    head = addNodeToHead(newNode1, head);

    struct Node *newNode2 = makeNewNode(newNode2, 2);
    head = addNodeToHead(newNode2, head);

    struct Node* i;
    i = head;
    int dem = 0;
    while(i != NULL){
        struct Node e = *i;
        printf("%d \n", e.value);
        i = e.next;
        dem++;
    }
    printf("number of node is : %d", dem);

    return 0;


}

struct Node* addNodeToHead(struct Node* newNode, struct Node *head){
    if(head == NULL){
        newNode -> next = NULL;
    }
    else{
        newNode -> next = head;
    }
    head = newNode;
    return head;
}

struct Node *makeNewNode(struct Node *newNode, int x){
    newNode = (struct Node*)malloc(sizeof(struct Node)); // cap phat bo nho cho newNode
    newNode -> value = x;
    return newNode;
}