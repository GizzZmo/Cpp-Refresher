#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
};

void Insert(Node**, int);
void Print(Node*);

int main(int argc, char const *argv[])
{
    Node* head = nullptr;
    Insert(&head, 25);
    Insert(&head, 45);
    Insert(&head, 55);
    Insert(&head, 25);
    Print(head);
    return 0;
}

void Insert(Node** ptrhead, int data) {
    Node *temp = new Node;
    temp -> data = data;
    temp -> next = *ptrhead;
    *ptrhead = temp;
    cout<< *ptrhead << endl;
    cout<< (*ptrhead)->data << endl;
    cout<< (*ptrhead)->next << endl;
}

void Print(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout<< "temp at " << temp << endl;
        cout<< "temps data " << temp->data << endl;
        cout<< "temps next " << temp->next << endl;
        temp = temp->next;
    }
    cout<<"reached null";
}


