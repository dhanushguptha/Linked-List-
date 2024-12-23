#include <stdio.h>
#include <stdlib.h>

// Node structure for Singly Linked List
typedef struct SinglyNode {
    int data;
    struct SinglyNode* next;
} SinglyNode;

// Node structure for Doubly Linked List
typedef struct DoublyNode {
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
} DoublyNode;

// Node structure for Circular Linked List
typedef struct CircularNode {
    int data;
    struct CircularNode* next;
} CircularNode;

// Functions for Singly Linked List
SinglyNode* createSinglyNode(int data) {
    SinglyNode* newNode = (SinglyNode*)malloc(sizeof(SinglyNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSinglyAtEnd(SinglyNode** head, int data) {
    SinglyNode* newNode = createSinglyNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    SinglyNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printSinglyList(SinglyNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Functions for Doubly Linked List
DoublyNode* createDoublyNode(int data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertDoublyAtEnd(DoublyNode** head, int data) {
    DoublyNode* newNode = createDoublyNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    DoublyNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printDoublyList(DoublyNode* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Functions for Circular Linked List
CircularNode* createCircularNode(int data) {
    CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertCircularAtEnd(CircularNode** head, int data) {
    CircularNode* newNode = createCircularNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    CircularNode* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void printCircularList(CircularNode* head) {
    if (head == NULL) return;
    CircularNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main Function
int main() {
    // Singly Linked List
    SinglyNode* singlyHead = NULL;
    insertSinglyAtEnd(&singlyHead, 10);
    insertSinglyAtEnd(&singlyHead, 20);
    insertSinglyAtEnd(&singlyHead, 30);
    printf("Singly Linked List:\n");
    printSinglyList(singlyHead);

    // Doubly Linked List
    DoublyNode* doublyHead = NULL;
    insertDoublyAtEnd(&doublyHead, 40);
    insertDoublyAtEnd(&doublyHead, 50);
    insertDoublyAtEnd(&doublyHead, 60);
    printf("\nDoubly Linked List:\n");
    printDoublyList(doublyHead);

    // Circular Linked List
    CircularNode* circularHead = NULL;
    insertCircularAtEnd(&circularHead, 70);
    insertCircularAtEnd(&circularHead, 80);
    insertCircularAtEnd(&circularHead, 90);
    printf("\nCircular Linked List:\n");
    printCircularList(circularHead);

    return 0;
}
