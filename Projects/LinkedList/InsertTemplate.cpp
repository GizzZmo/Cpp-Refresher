#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
};

void Insert(Node**, int);
void Print(Node*);

void Insert(Node** ptrhead, int data) {
    Node *temp = new Node;
    temp -> data = data;
    temp -> next = *ptrhead;
    *ptrhead = temp;
}

void Print(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data << "\t";
        temp = temp->next;
    }
}


