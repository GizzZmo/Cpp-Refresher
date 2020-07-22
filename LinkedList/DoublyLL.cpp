#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};
Node *head;

Node* GetNewNode(int);
void Insert(int);
void Print(Node *);
void PrintReverse(Node *);

int main(int argc, char const *argv[])
{
    head = nullptr;
    Insert(10);
    Insert(4);
    Insert(5);
    Insert(6);
    cout << "Printing elements " << endl;
    Print(head);
    cout << endl << "Printing in reverse" << endl;
    PrintReverse(head);
    return 0;
}

void Insert(int data) {
    Node *temp = GetNewNode(data);
    if(head == nullptr) {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

Node* GetNewNode(int dataVar){
    Node *temp = new Node;
    temp->data = dataVar;
    temp->prev = nullptr;
    temp->next = nullptr;
    return temp;
}

void Print(Node *headPtr) {
    if(headPtr!=nullptr) {
        cout<< headPtr->data << "\t";
        Print(headPtr->next);
    }
}

void PrintReverse(Node *headPtr) {
    if(headPtr!=nullptr) {
        PrintReverse(headPtr->next);
        cout<< headPtr->data << "\t";
    }
}